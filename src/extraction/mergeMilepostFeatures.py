import glob
import os
import pickle
from math import fabs


def mergeMilepostFeatures(out_file, file_pairs, feat_dir):
    progs = [[], []]
    for prog in file_pairs:
        for idx in (0, 1):
            merged_vecs = {}
            counter = 0
            for k in glob.glob(
                os.path.join(feat_dir, f"{os.path.basename(prog[idx])}*.fre.ft",)
            ):
                with open(k) as cur_vecs:
                    lines = cur_vecs.read().strip().split(",")
                for line in lines:
                    key, val = line.strip().split("=")
                    try:
                        merged_vecs[key] += float(val)
                    except:
                        merged_vecs[key] = float(val)
                    counter += 1
            for key in merged_vecs:
                merged_vecs[key] /= counter
            progs[idx].append(merged_vecs)

    prog_diff = []
    order = sorted(list(progs[0][0].keys()))
    for pair_a, pair_b in zip(progs[0], progs[1]):
        features = []
        for key in order:
            val1 = pair_a.get(key, 0)
            val2 = pair_b.get(key, 0)
            features.append(fabs(val1 - val2))
        prog_diff.append(features)

    pickle.dump(prog_diff, open(out_file, "wb"))
