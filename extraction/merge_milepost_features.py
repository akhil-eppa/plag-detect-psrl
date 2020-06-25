import os
import glob
import pickle
from math import fabs


def merge_features(out_file, proc=None, root_dir=None, pairs_file="pairs.pkl"):
    if not proc and not root_dir:
        raise ValueError("Either process or root directory must be specified")
    if not proc:
        pairs_path = os.path.join(root_dir, pairs_file)
    else:
        if proc not in ("train", "test"):
            raise ValueError('proc must be one of  "train", "test"')
        pairs_path = os.path.join(f"result_{proc}", pairs_file)
    prog_list = pickle.load(open(pairs_path, "rb"))
    progs = [[], []]
    for prog in prog_list:
        for idx in (0, 1):
            merged_vecs = {}
            counter = 0
            for k in glob.glob(
                os.path.join(
                    os.path.dirname(pairs_path), "milepost_features", f"{os.path.basename(prog[idx])}*.fre.ft"
                )
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
            features.append(fabs(pair_a[key] - pair_b[key]))
        prog_diff.append(features)

    pickle.dump(prog_diff, open(out_file, "wb"))
