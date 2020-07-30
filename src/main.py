import argparse
import csv
import pickle
from pathlib import Path

from milepostExtraction.extractMilepostFeatures import extractMilepostFeatures
from milepostPredictions.evalProb import evaluate
from utils import listUtils

ROOT_DIR = Path("../code_sample").resolve()
files = listUtils.getSubmissions(ROOT_DIR)
pairs = listUtils.getCombinations(files)
pickle.dump(pairs, open("pairs.pkl", "wb"))
extractMilepostFeatures(pairs, ROOT_DIR, train=False)
y_pred, y_prob = evaluate("milepostExtraction/result/features.csv")
with open("result/report.csv", "w") as wr:
    writer = csv.writer(wr)
    writer.writerow(['File 1', 'File 2', 'Plagiarised', 'Probability'])
    print("Plagiarised pairs: ")
    for (f1, f2), prob, pred in zip(pairs, y_prob[:, 1], y_pred):
        writer.writerow([f1, f2, pred, prob])
        if pred:
            print(f"{f1}  --->  {f2}")
