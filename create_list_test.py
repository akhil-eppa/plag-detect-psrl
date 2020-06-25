import os
import pickle
from itertools import combinations

before = []
after = []

for folder in ("Before", "After"):
    root_path = os.path.join("code_pairs_test", folder)
    for sf in os.listdir(root_path):
        root_file_path = os.path.join(root_path, sf)
        files = os.listdir(root_file_path)
        res = ""
        prefix = files[0]
        for string in files[1:]:
            while string[: len(prefix)] != prefix and prefix:
                prefix = prefix[: len(prefix) - 1]
            if not prefix:
                break
        res = prefix

        for pair in combinations(files, 2):
            if ("_" in pair[0] and "-" not in pair[1]) or (
                "_" in pair[1] and "-" not in pair[0]
            ):
                sample = (
                    os.path.join(root_file_path, pair[0]),
                    os.path.join(root_file_path, pair[1]),
                    "p",
                )
            else:
                sample = (
                    os.path.join(root_file_path, pair[0]),
                    os.path.join(root_file_path, pair[1]),
                    "np",
                )

            if folder == "Before":
                before.append(sample)
            else:
                after.append(sample)

with open(os.path.join("extraction", "result_test",  "Before", "pairs.pkl"), "wb") as wr:
    pickle.dump(before, wr)
with open(os.path.join("extraction", "result_test", "After", "pairs.pkl"), "wb") as wr:
    pickle.dump(after, wr)
