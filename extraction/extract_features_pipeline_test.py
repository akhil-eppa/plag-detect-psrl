import subprocess
import os
from merge_milepost_features import merge_features

subprocess.run(["docker", "exec", "-it", "psrl_plagdetect", "sh", "/home/data/plag-detect-psrl/extraction/milepost_features.sh"])
merge_features(os.path.join("result_test", "merged_milepost_features.pkl")

