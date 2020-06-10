# import os
import glob
import pickle

progs = [[], []]
for i in range(1, 301):
    for j in (1, 2):
        merged_vecs = {}
        for k in glob.glob(f"result/milepost_features/n_{i}_{j}*.fre.ft"):
            with open(k) as cur_vecs:
                lines = cur_vecs.read().strip().split(",")
            for line in lines:
                k, v = line.strip().split("=")
                # print(k,v)
                try:
                    merged_vecs[k] += float(v)
                except:
                    merged_vecs[k] = float(v)
        progs[j-1].append(merged_vecs)

pickle.dump(progs, open("result/merged_milepost_features.pkl", "wb"))
