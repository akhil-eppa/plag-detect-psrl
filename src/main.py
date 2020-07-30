import argparse
from pathlib import Path
from utils import listUtils
from extraction.extractMilepostFeatures import extractMilepostFeatures

ROOT_DIR = Path("../code_sample").resolve()
files = listUtils.getSubmissions(ROOT_DIR)
pairs = listUtils.getCombinations(files)
extractMilepostFeatures(pairs, ROOT_DIR, train=False)
pickle.dump(pairs, open("pairs.pkl", "wb"))
