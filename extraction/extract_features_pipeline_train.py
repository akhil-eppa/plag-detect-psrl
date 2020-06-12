import subprocess
import os
from merge_milepost_features import merge_features
from text_features import generate_text_features

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
merge_features(os.path.join("result_train", "merged_milepost_features_diff.pkl"), "train")
generate_text_features()

