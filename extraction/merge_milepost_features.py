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
            progs[idx].append(merged_vecs)

    pickle.dump(progs, open(out_file, "wb"))
