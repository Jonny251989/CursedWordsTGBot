import grpc
from concurrent import futures
import torch
from transformers import AutoTokenizer, AutoModelForSequenceClassification
import toxicity_classifier_pb2
import toxicity_classifier_pb2_grpc
import logging
import os

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class ToxicityClassifierServicer(toxicity_classifier_pb2_grpc.ToxicityClassifierServicer):
    def __init__(self):
        self.model_name = 's-nlp/russian_toxicity_classifier'
        try:
            # Загрузка токенизатора
            self.tokenizer = AutoTokenizer.from_pretrained(
                self.model_name,
                local_files_only=False  # Разрешить загрузку из интернета, если нет в кэше
            )
            
            # Загрузка модели
            self.model = AutoModelForSequenceClassification.from_pretrained(
                self.model_name,
                local_files_only=False  # Разрешить загрузку из интернета, если нет в кэше
            )
            
            logger.info("Model and tokenizer loaded successfully")
            
        except Exception as e:
            logger.error(f"Error loading model or tokenizer: {e}")
            raise

    def ClassifyMessage(self, request, context):
        logger.info(f"Received message: {request.message}")
        try:
            # Токенизация сообщения
            inputs = self.tokenizer(
                request.message,
                return_tensors="pt",
                truncation=True,
                padding=True,
                max_length=512
            )
            
            # Получение предсказания
            with torch.no_grad():
                logits = self.model(**inputs).logits
                
            # Вычисление вероятности токсичности
            probs = torch.sigmoid(logits).squeeze().numpy()
            toxicity_prob = probs[1]  # Предполагаем, что индекс 1 соответствует токсичности
            logger.info(f"Toxicity probability: {toxicity_prob}")
            
            # Возврат результата
            return toxicity_classifier_pb2.MessageResponse(
                toxicity_probability=toxicity_prob
            )
            
        except Exception as e:
            logger.error(f"Error processing message: {e}")
            context.set_code(grpc.StatusCode.INTERNAL)
            context.set_details(str(e))
            return toxicity_classifier_pb2.MessageResponse()

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    toxicity_classifier_pb2_grpc.add_ToxicityClassifierServicer_to_server(
        ToxicityClassifierServicer(), server
    )
    server.add_insecure_port('[::]:50051')
    logger.info("Server starting on [::]:50051")
    server.start()
    logger.info("Server started. Waiting for termination...")
    server.wait_for_termination()

if __name__ == '__main__':
    serve()