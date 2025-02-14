from transformers import AutoTokenizer, AutoModelForSequenceClassification
import torch

def classify_message(sentence):
    model_name = 's-nlp/russian_toxicity_classifier'  # Пример модели 1
    tokenizer = AutoTokenizer.from_pretrained(model_name)
    model = AutoModelForSequenceClassification.from_pretrained(model_name)
    # print("text of message in python", sentence)
    inputs = tokenizer(sentence, return_tensors="pt", truncation=True, padding=True, max_length = 512)
    with torch.no_grad():
        logits = model(**inputs).logits
    probs = torch.sigmoid(logits).squeeze().numpy()
    return probs[1]  # Вероятность токсичности
