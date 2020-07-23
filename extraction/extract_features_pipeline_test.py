import csv
import os
import pickle
import shutil
import subprocess

from merge_milepost_features import merge_features
from text_features import generate_text_features

pwd = os.getcwd()
tmpdir = os.path.join(pwd, "result_test", "milepost_features")
if os.path.isdir(tmpdir):
    shutil.rmtree(tmpdir)
os.mkdir(tmpdir)

paths = []
pairs = pickle.load(open(os.path.join(pwd, "result_test", "pairs_graph.pkl"), "rb"))
# PATH_PREFIX = "/home/data/plag-detect-psrl/code_pairs_test"
PATH_PREFIX = "/home/data/plag-detect-psrl/code_pairs_train/"

for pair in pairs:
    paths.append(PATH_PREFIX + os.path.basename(pair[0]))
    paths.append(PATH_PREFIX + os.path.basename(pair[1]))

for path in paths:
    subprocess.run(
        [
            "docker",
            "exec",
            "-it",
            "psrl_plagdetect",
            "bash",
            "/home/data/plag-detect-psrl/extraction/milepost_features.sh",
            "test",
            path,
        ]
    )
# merge_features(
#     os.path.join("result_test", "Before", "merged_milepost_features_diff.pkl"),
#     root_dir=os.path.join("result_test", "Before"),
# )
# print("Merged features Before")
# merge_features(
#     os.path.join("result_test", "After", "merged_milepost_features_diff.pkl"),
#     root_dir=os.path.join("result_test", "After"),
# )
# print("Merged features After")
merge_features(
    os.path.join("result_test", "merged_milepost_features_diff.pkl"),
    proc="test",
    pairs_file="pairs_graph.pkl",
)
print("Merged features")

# generate_text_features(train=False, res_dir=os.path.join("result_test", "Before"))
# print("Extracted text features Before")
# os.chdir(pwd)
# generate_text_features(train=False, res_dir=os.path.join("result_test", "After"))
# print("Extracted text features After")
# os.chdir(pwd)
generate_text_features(
    train=False, pairs_file="pairs_graph.pkl",
)
print("Extracted text features")
os.chdir(pwd)

# with open(os.path.join("result_test", "Before", "features.csv"), "w") as writefile:
#     mp_feat = pickle.load(
#         open(
#             os.path.join("result_test", "Before", "merged_milepost_features_diff.pkl"),
#             "rb",
#         )
#     )
#     txt_feat_1 = pickle.load(
#         open(os.path.join("result_test", "Before", "text_features", "ad.pkl"), "rb")
#     )
#     txt_feat_2 = pickle.load(
#         open(os.path.join("result_test", "Before", "text_features", "cc_rat.pkl"), "rb")
#     )
#     txt_feat_3 = pickle.load(
#         open(os.path.join("result_test", "Before", "text_features", "cl_rat.pkl"), "rb")
#     )
#     txt_feat_4 = pickle.load(
#         open(os.path.join("result_test", "Before", "text_features", "ed.pkl"), "rb")
#     )
#     txt_feat_5 = pickle.load(
#         open(os.path.join("result_test", "Before", "text_features", "ld_rat.pkl"), "rb")
#     )
#     pair_type = pickle.load(
#         open(os.path.join("result_test", "Before", "pairs.pkl"), "rb")
#     )
#     writer = csv.writer(writefile)
#     for features in zip(
#         mp_feat, txt_feat_1, txt_feat_2, txt_feat_3, txt_feat_4, txt_feat_5, pair_type
#     ):
#         fl = []
#         fl.extend(features[0])
#         fl.extend(features[1:-1])
#         fl.append(int(features[-1][2] == "p"))
#         writer.writerow(fl)
#
# with open(os.path.join("result_test", "After", "features.csv"), "w") as writefile:
#     mp_feat = pickle.load(
#         open(
#             os.path.join("result_test", "After", "merged_milepost_features_diff.pkl"),
#             "rb",
#         )
#     )
#     txt_feat_1 = pickle.load(
#         open(os.path.join("result_test", "After", "text_features", "ad.pkl"), "rb")
#     )
#     txt_feat_2 = pickle.load(
#         open(os.path.join("result_test", "After", "text_features", "cc_rat.pkl"), "rb")
#     )
#     txt_feat_3 = pickle.load(
#         open(os.path.join("result_test", "After", "text_features", "cl_rat.pkl"), "rb")
#     )
#     txt_feat_4 = pickle.load(
#         open(os.path.join("result_test", "After", "text_features", "ed.pkl"), "rb")
#     )
#     txt_feat_5 = pickle.load(
#         open(os.path.join("result_test", "After", "text_features", "ld_rat.pkl"), "rb")
#     )
#     pair_type = pickle.load(
#         open(os.path.join("result_test", "After", "pairs.pkl"), "rb")
#     )
#     writer = csv.writer(writefile)
#     for features in zip(
#         mp_feat, txt_feat_1, txt_feat_2, txt_feat_3, txt_feat_4, txt_feat_5, pair_type
#     ):
#         fl = []
#         fl.extend(features[0])
#         fl.extend(features[1:-1])
#         fl.append(int(features[-1][2] == "p"))
#         writer.writerow(fl)

with open(os.path.join("result_test", "features.csv"), "w") as writefile:
    mp_feat = pickle.load(
        open(os.path.join("result_test", "merged_milepost_features_diff.pkl"), "rb",)
    )
    txt_feat_1 = pickle.load(
        open(os.path.join("result_test", "text_features", "ad.pkl"), "rb")
    )
    txt_feat_2 = pickle.load(
        open(os.path.join("result_test", "text_features", "cc_rat.pkl"), "rb")
    )
    txt_feat_3 = pickle.load(
        open(os.path.join("result_test", "text_features", "cl_rat.pkl"), "rb")
    )
    txt_feat_4 = pickle.load(
        open(os.path.join("result_test", "text_features", "ed.pkl"), "rb")
    )
    txt_feat_5 = pickle.load(
        open(os.path.join("result_test", "text_features", "ld_rat.pkl"), "rb")
    )
    pair_type = pickle.load(open(os.path.join("result_test", "pairs_graph.pkl"), "rb"))
    writer = csv.writer(writefile)
    for features in zip(
        mp_feat, txt_feat_1, txt_feat_2, txt_feat_3, txt_feat_4, txt_feat_5, pair_type
    ):
        fl = []
        fl.extend(features[0])
        fl.extend(features[1:-1])
        fl.append(int(features[-1][-1] == "p"))
        writer.writerow(fl)
