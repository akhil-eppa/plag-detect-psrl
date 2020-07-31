import csv
import pickle
import shutil
import subprocess
from pathlib import Path

from ..utils.extractTextFeatures import extractTextFeatures
from .mergeMilepostFeatures import mergeMilepostFeatures


def extractMilepostFeatures(file_pairs, root_dir, train=False):
    pwd = Path.cwd()
    res_dir = Path("lib/milepostExtraction/result")
    tmpdir = res_dir / "milepost_features"
    tmpdir.mkdir(parents=True, exist_ok=True)
    try:
        subprocess.run(
            [
                "docker",
                "run",
                "--mount",
                "type=bind,source=/home/anirudh/Projects/PlagDetect/plag-detect-psrl/src/lib,target=/home/src",
                "--mount",
                f"type=bind,source={root_dir},target=/home/data",
                "--name=psrl_plagdetect",
                "-it",
                "-d",
                "ctuning/ck-milepost-gcc-ubuntu16.04",
                "/bin/bash",
            ],
            check=True,
        )
    except:
        subprocess.run(["docker", "start", "psrl_plagdetect",], check=True)

    paths = set()
    if train:
        yval = []

    for pair in file_pairs:
        paths.add(pair[0])
        paths.add(pair[1])
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
                "/home/src/milepostExtraction/milepost_features.sh",
                path,
            ],
            check=True,
        )
    mp_feat = mergeMilepostFeatures(
        res_dir / "merged_milepost_features.pkl", paths, res_dir / "milepost_features",
    )
    print("Merged features")

    txt_feat_1, txt_feat_2, txt_feat_3, txt_feat_4, txt_feat_5 = extractTextFeatures(
        file_pairs, Path(root_dir), res_dir / "text_features",
    )
    print("Extracted text features")

    with open(res_dir / "features.csv", "w") as writefile:
        # mp_feat = pickle.load(open(res_dir / "merged_milepost_features.pkl", "rb",))
        # txt_feat_1 = pickle.load(open(res_dir / "text_features" / "ad.pkl", "rb"))
        # txt_feat_2 = pickle.load(open(res_dir / "text_features" / "cc_rat.pkl", "rb"))
        # txt_feat_3 = pickle.load(open(res_dir / "text_features" / "cl_rat.pkl", "rb"))
        # txt_feat_4 = pickle.load(open(res_dir / "text_features" / "ed.pkl", "rb"))
        # txt_feat_5 = pickle.load(open(res_dir / "text_features" / "ld_rat.pkl", "rb"))
        writer = csv.writer(writefile)
        for idx, features in enumerate(
            zip(file_pairs, txt_feat_1, txt_feat_2, txt_feat_3, txt_feat_4, txt_feat_5,)
        ):
            fl = []
            mp = [
                abs(i - j)
                for i, j in zip(mp_feat[features[0][0]], mp_feat[features[0][1]])
            ]
            fl.extend(mp)
            fl.extend(features[1:])
            if train:
                fl.append(yval[idx])
            writer.writerow(fl)

    shutil.rmtree(tmpdir)
    subprocess.run(["docker", "stop", "psrl_plagdetect"], check=True)
