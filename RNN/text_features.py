# -*- coding: utf-8 -*-
"""
Created on Tue Jun  2 13:45:23 2020

@author: Akhil
"""
import os
import pickle
import re
from difflib import Differ

import Levenshtein


def get_comments(text):
    pattern = r"(\".*?\"|\'.*?\')|(/\*.*?\*/|//[^\r\n]*$)"
    regex = re.compile(pattern, re.MULTILINE | re.DOTALL)
    comments = [m.group(2) for m in regex.finditer(text) if m.group(2)]
    return comments


def file_length(fname):
    sumlength = 0  # to store avg line length
    with open(fname) as f:
        for i, l in enumerate(f):
            sumlength += len(l)  # finds total number of characters
    sumlength = sumlength / (i + 1)  # find avg by dividing by line count
    return i + 1, sumlength


def generate_text_features(train=True, pairs_file="pairs.pkl", res_dir=None):
    if not res_dir:
        if train:
            res_dir = "result_train"
        else:
            res_dir = "result_test"
    with open(os.path.join(res_dir, pairs_file), "rb") as f:
        prog = pickle.load(f)
    os.chdir("..")
    line_diff = []  # list containing line difference for every pair
    line_diff_ratio = []
    av_diff = []  # list containing avg line difference for every pair
    edit_dist = []
    common_line = []
    common_line_ratio = []
    common_comment = []
    common_comment_ratio = []
    d = Differ()
    for i in range(len(prog)):
        l1, a1 = file_length(prog[i][0])
        l2, a2 = file_length(prog[i][1])
        diff = abs(l1 - l2)
        diff2 = abs(a1 - a2)
        line_diff.append(diff)
        line_diff_ratio.append(diff / max(l1, l2))
        av_diff.append(diff2)
        # Below is to find edit distance
        f1 = open(prog[i][0], "r")
        f2 = open(prog[i][1], "r")
        x1 = f1.read()
        x2 = f2.read()
        # print(x1)
        # print(x2)
        diff3 = Levenshtein.distance(x1, x2)
        edit_dist.append(diff3)
        # Below is to find the number of common lines of code
        count = 0
        p1 = x1.splitlines()
        p2 = x2.splitlines()
        if "" in p1:
            p1.remove("")
        if "" in p2:
            p2.remove("")
        for line in d.compare(p1, p2):
            if line.startswith(" "):
                count = count + 1
        common_line.append(count)
        common_line_ratio.append(count / max(len(p1), len(p2)))
        c1 = get_comments(x1)
        c2 = get_comments(x2)
        count = 0
        for line in d.compare(c1, c2):
            if line.startswith(" "):
                count = count + 1
        common_comment.append(count)
        temp = max(len(c1), len(c2))
        if temp != 0:
            common_comment_ratio.append(count / temp)
        else:
            common_comment_ratio.append(0)
        f1.close()
        f2.close()

    features_path = os.path.join("RNN", "text_features")
    if not os.path.isdir(features_path):
        os.mkdir(features_path)
    with open(os.path.join(features_path, "ld.pkl"), "wb") as f:
        pickle.dump(line_diff, f)
    with open(os.path.join(features_path, "ld_rat.pkl"), "wb") as f:
        pickle.dump(line_diff_ratio, f)
    with open(os.path.join(features_path, "ad.pkl"), "wb") as f:
        pickle.dump(av_diff, f)
    with open(os.path.join(features_path, "ed.pkl"), "wb") as f:
        pickle.dump(edit_dist, f)
    with open(os.path.join(features_path, "cl.pkl"), "wb") as f:
        pickle.dump(common_line, f)
    with open(os.path.join(features_path, "cl_rat.pkl"), "wb") as f:
        pickle.dump(common_line_ratio, f)
    with open(os.path.join(features_path, "cc.pkl"), "wb") as f:
        pickle.dump(common_comment, f)
    with open(os.path.join(features_path, "cc_rat.pkl"), "wb") as f:
        pickle.dump(common_comment_ratio, f)


# print(line_diff)
# print(line_diff_ratio)
# print(av_diff)
# print(edit_dist)
# print(common_line)
# print(common_line_ratio)
# print(common_comment)
# print(common_comment_ratio)
