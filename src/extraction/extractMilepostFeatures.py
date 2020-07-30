import csv
import os
import pickle
import shutil
import subprocess

from .extractTextFeatures import extractTextFeatures
from .mergeMilepostFeatures import mergeMilepostFeatures


def extractMilepostFeatures(file_pairs, root_dir, train=False):
    pwd = os.getcwd()
    tmpdir = os.path.join(pwd, "result", "milepost_features")
    os.mkdir(tmpdir)
    subprocess.run(
        [
            "docker",
            "run",
            "--mount",
            "type=bind,source=/home/anirudh/Projects/PlagDetect/plag-detect-psrl/src,target=/home/src",
            "--mount",
            f"type=bind,source={root_dir},target=/home/data",
            "--name=psrl_plagdetect",
            "-it",
            "-d",
            "ctuning/ck-milepost-gcc-ubuntu16.04",
            "/bin/bash",
        ]
    )

    paths = []
    if train:
        yval = []

    for pair in file_pairs:
        paths.extend(pair[0:2])
        if train:
            yval.append(pair[2])

    for path in paths:
        subprocess.run(
            [
                "docker",
                "exec",
                "-it",
                "psrl_plagdetect",
                "bash",
                "/home/src/extraction/milepost_features.sh",
                path,
            ]
        )
    mergeMilepostFeatures(
        os.path.join("result", "merged_milepost_features_diff.pkl"),
        file_pairs,
        os.path.join("result", "milepost_features"),
    )
    print("Merged features")

    extractTextFeatures(
        file_pairs, os.path.join("result", "text_features"),
    )
    print("Extracted text features")

    with open(os.path.join("result", "features.csv"), "w") as writefile:
        mp_feat = pickle.load(
            open(os.path.join("result", "merged_milepost_features_diff.pkl"), "rb",)
        )
        txt_feat_1 = pickle.load(
            open(os.path.join("result", "text_features", "ad.pkl"), "rb")
        )
        txt_feat_2 = pickle.load(
            open(os.path.join("result", "text_features", "cc_rat.pkl"), "rb")
        )
        txt_feat_3 = pickle.load(
            open(os.path.join("result", "text_features", "cl_rat.pkl"), "rb")
        )
        txt_feat_4 = pickle.load(
            open(os.path.join("result", "text_features", "ed.pkl"), "rb")
        )
        txt_feat_5 = pickle.load(
            open(os.path.join("result", "text_features", "ld_rat.pkl"), "rb")
        )
        writer = csv.writer(writefile)
        for idx, features in enumerate(
            zip(mp_feat, txt_feat_1, txt_feat_2, txt_feat_3, txt_feat_4, txt_feat_5,)
        ):
            fl = []
            fl.extend(features[0])
            fl.extend(features[1:])
            if train:
                fl.append(yval[idx])
            writer.writerow(fl)

    shutil.rmtree(tmpdir)
    subprocess.run(["docker", "stop", "psrl_plagdetect"])
