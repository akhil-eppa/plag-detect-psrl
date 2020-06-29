import pickle
import os

pairs = pickle.load(open("pairs.pkl", "rb"))
for pair in pairs:
  if pair[-1] == "p":
    print(f"{os.path.basename(pair[0])} - {os.path.basename(pair[1])}")
