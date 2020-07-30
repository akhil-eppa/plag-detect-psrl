import argparse
import os
from utils import listUtils
from extraction.extractMilepostFeatures import extractMilepostFeatures

ROOT_DIR = os.path.abspath("../code_sample")
files = listUtils.getSubmissions(ROOT_DIR)
pairs = listUtils.getCombinations(files)
print(pairs)
extractMilepostFeatures(pairs, ROOT_DIR, train=False)
