import os
import glob
import pickle


def merge_features(out_file, proc):
    if proc not in ("train", "test"):
        raise ValueError('proc must be one of  "train", "test"')
    prog_list = pickle.load(open(os.path.join(f"result_{proc}", "pairs.pkl"), "rb"))
    progs = [[], []]
    for prog in prog_list:
        for idx in (0, 1):
            merged_vecs = {}
            counter = 0
            for k in glob.glob(
                os.path.join(
                    "result_train", "milepost_features", f"{prog[idx]}*.fre.ft"
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
        print(pair_a, pair_b)
        features = []
        for key in order:
            features.append(pair_a[key] - pair_b[key])
        prog_diff.append(features)

    pickle.dump(prog_diff, open(out_file, "wb"))

merge_features("merged_milepost_features_diff.pkl", "train")
