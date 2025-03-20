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
        self.cache_dir = os.path.join(os.path.dirname(__file__), 'hf_cache')
        
        try:
            logger.info(f"Loading model from cache: {self.cache_dir}")
            
            self.tokenizer = AutoTokenizer.from_pretrained(
                self.model_name,
                cache_dir=self.cache_dir,
                local_files_only=True
            )
            
            self.model = AutoModelForSequenceClassification.from_pretrained(
                self.model_name,
                cache_dir=self.cache_dir,
                local_files_only=True
                #device_map="auto"
            )
            
            logger.info("Model and tokenizer loaded successfully")
            
        except Exception as e:
            logger.error(f"Error loading model: {e}")
            raise

    def ClassifyMessage(self, request, context):
        logger.info(f"Received message: {request.message}")
        try:
            inputs = self.tokenizer(
                request.message,
                return_tensors="pt",
                truncation=True,
                padding=True,
                max_length=512
            )
            
            with torch.no_grad():
                logits = self.model(**inputs).logits
                
            probs = torch.sigmoid(logits).squeeze().numpy()
            logger.info(f"Toxicity probability: {probs[1]}")
            
            return toxicity_classifier_pb2.MessageResponse(
                toxicity_probability=probs[1]
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