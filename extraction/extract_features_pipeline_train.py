import csv
import os
import pickle
import subprocess

from merge_milepost_features import merge_features
from text_features import generate_text_features

pwd = os.getcwd()
subprocess.run(
    [
        "docker",
        "exec",
        "-it",
        "psrl_plagdetect",
        "sh",
        "/home/data/plag-detect-psrl/extraction/milepost_features.sh",
        "train",
    ]
)
merge_features(
    os.path.join("result_train", "merged_milepost_features_diff.pkl"), proc="train"
)
print("Finished merging features")
generate_text_features()
print("Generated text features")

os.chdir(pwd)
with open(os.path.join("result_train", "feat_v1.csv"), "w") as writefile:
    mp_feat = pickle.load(
        open(os.path.join("result_train", "merged_milepost_features_diff.pkl"), "rb")
    )
    txt_feat_1 = pickle.load(
        open(os.path.join("result_train", "text_features", "ad.pkl"), "rb")
    )
    txt_feat_2 = pickle.load(
        open(os.path.join("result_train", "text_features", "cc_rat.pkl"), "rb")
    )
    txt_feat_3 = pickle.load(
        open(os.path.join("result_train", "text_features", "cl_rat.pkl"), "rb")
    )
    txt_feat_4 = pickle.load(
        open(os.path.join("result_train", "text_features", "ed.pkl"), "rb")
    )
    txt_feat_5 = pickle.load(
        open(os.path.join("result_train", "text_features", "ld_rat.pkl"), "rb")
    )
    pair_type = pickle.load(open(os.path.join("result_train", "pairs.pkl"), "rb"))
    writer = csv.writer(writefile)
    for features in zip(
        mp_feat, txt_feat_1, txt_feat_2, txt_feat_3, txt_feat_4, txt_feat_5, pair_type
    ):
        fl = []
        fl.extend(features[0])
        fl.extend(features[1:-1])
        fl.append(int(features[-1][2] == "p"))
        writer.writerow(fl)
