import pickle

import numpy as np
from sklearn.metrics import classification_report
from transformers import (AutoModelForSequenceClassification, AutoTokenizer,
                          pipeline)


def evaluate(file_pairs, root_dir):
    file_pairs = [(root_dir / i, root_dir / j) for i, j in file_pairs]
    model_name = "huggingface/CodeBERTa-language-id"
    model = AutoModelForSequenceClassification.from_pretrained(model_name)
    tokenizer = AutoTokenizer.from_pretrained(model_name)
    pipe = pipeline("feature-extraction", model=model, tokenizer=tokenizer)

    cache = {}

    def get_vector(path):
        y = open(path, "r")
        x = y.read()
        if cache.get(x, None) is not None:
            return cache[x]
        vec = [0 for i in range(6)]
        l = len(x)
        if l < 512:
            vec = pipe(x)
            vec = np.array(vec)
        else:
            temp = []
            for i in range(512, l, 100):
                temp.append(x[i - 512 : i])
            pred = pipe(temp)
            vec = np.mean(pred, axis=0)
        cache[x] = vec
        return vec

    diff = []
    # y_actual = []
    for idx, pair in enumerate(file_pairs, 1):
        print(f"{idx}/{len(file_pairs)}")
        diff.append(np.linalg.norm(get_vector(pair[0]) - get_vector(pair[1])))
        # y_actual.append(1 if pair[-1] == "p" else 0)

    y_pred = [0 if x > 1.50 else 1 for x in diff]
    return y_pred

    # print(classification_report(y_actual, y_pred))
