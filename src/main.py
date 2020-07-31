import argparse
import csv
import pickle
from pathlib import Path

from lib.milepostExtraction.extractMilepostFeatures import extractMilepostFeatures
from lib.milepostPredictions import mpEval
from lib.rnnPredictions.extractRnnFeatures import extractRnnFeatures
from lib.rnnPredictions import rnnEval
from lib.utils import listUtils

ROOT_DIR = Path("../code_sample").resolve()
files = listUtils.getSubmissions(ROOT_DIR)
pairs = listUtils.getCombinations(files)
pickle.dump(pairs, open("result/pairs.pkl", "wb"))
# extractMilepostFeatures(pairs, ROOT_DIR, train=False)
# y_pred, y_prob = mpEval.evaluate("milepostExtraction/result/features.csv")
extractRnnFeatures(pairs, ROOT_DIR)
y_pred = rnnEval.evaluate("lib/rnnPredictions/result/X.pkl")

with open("result/report_rnn.csv", "w") as wr:
    writer = csv.writer(wr)
    # writer.writerow(['File 1', 'File 2', 'Plagiarised', 'Probability'])
    writer.writerow(['File 1', 'File 2', 'Plagiarised'])
    print("Plagiarised pairs: ")
    # for (f1, f2), prob, pred in zip(pairs, y_prob[:, 1], y_pred):
    for (f1, f2), pred in zip(pairs, y_pred):
        writer.writerow([f1, f2, pred])
        if pred:
            print(f"{f1}  --->  {f2}")
