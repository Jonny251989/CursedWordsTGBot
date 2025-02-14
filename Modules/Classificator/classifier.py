from transformers import AutoTokenizer, AutoModelForSequenceClassification
import torch
import sys
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

if __name__ == "__main__":
    # Получаем сообщение из аргумента командной строки
    if len(sys.argv) < 2:
        print("Ошибка: Не передано сообщение для классификации.")
        sys.exit(1)
    
    # Аргумент командной строки, который передается C++ кодом
    message = sys.argv[1]
    
    # Классифицируем сообщение и получаем вероятность токсичности
    toxicity_prob = classify_message(message)
    
    # Выводим результат, который C++ сможет считать
    print(toxicity_prob)