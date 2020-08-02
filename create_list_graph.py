import os
import pickle
import random
import shutil

prog = []
root_path = os.path.abspath("code_pairs_train")
copy_path = os.path.abspath("code_pairs_eval")

# a_plag = random.sample(range(1, 193), 20)
# a_nonplag = random.sample(range(193, 434), 20)
# n_plag = random.sample(range(1, 301), 20)
# n_nonplag = random.sample(range(301, 424), 20)
# s_plag = random.sample(range(1, 181), 20)
# s_nonplag = random.sample(range(181, 361), 20)

a_var_name_change = (6, 15, 24, 33, 42, 51, 60, 69, 78, 87, 96, 105, 114, 123)
n_var_name_change = (305, 311, 321, 327, 329, 339, 342)
a_redundant = (3, 12, 21, 30, 39, 48, 57, 66, 75, 84, 93, 102, 111, 120)
n_redundant = (301, 310, 317, 323, 326, 331, 335, 338, 341)
a_reorder_lines = (8, 17, 26, 35, 44, 53, 62, 71, 80, 89, 98, 107, 116, 125)
n_reorder_lines = (302, 314, 316, 319, 324, 328, 333, 337)
a_type_change = (2, 11, 20, 29, 38, 47, 56)
n_type_change = (303, 309, 315, 320, 325, 330, 334, 343)
a_loop_change = (9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126)
n_loop_change = (306, 313, 318, 336, 340, 345)
a_reorder_block = (7, 16, 25, 34, 43, 52, 61, 70, 79, 88, 97, 106, 115, 124)
n_reorder_block = (312,)

a_pairs = (
    a_loop_change,
    a_redundant,
    a_reorder_block,
    a_reorder_lines,
    a_type_change,
    a_var_name_change,
)

n_pairs = (
    n_loop_change,
    n_redundant,
    n_reorder_block,
    n_reorder_lines,
    n_type_change,
    n_var_name_change,
)

for idx, plagtype in enumerate(a_pairs):
    for i in plagtype:
        temp = []
        temp.append(os.path.join(root_path, str("a" + str(i) + "_1.c")))
        temp.append(os.path.join(root_path, str("a" + str(i) + "_2.c")))
        temp.append(idx)
        temp.append("p")
        prog.append(temp)

for idx, plagtype in enumerate(n_pairs):
    for i in plagtype:
        temp = []
        temp.append(os.path.join(root_path, str("n_" + str(i) + "_1.c")))
        temp.append(os.path.join(root_path, str("n_" + str(i) + "_2.c")))
        temp.append(idx)
        temp.append("p")
        prog.append(temp)

for f1, f2, cat, _ in prog:
    shutil.copyfile(f1, os.path.join(copy_path, str(cat), os.path.basename(f1)))
    shutil.copyfile(f2, os.path.join(copy_path, str(cat), os.path.basename(f2)))

# for i in a_plag:
#     temp = []
#     temp.append(os.path.join(root_path, str("a" + str(i) + "_1.c")))
#     temp.append(os.path.join(root_path, str("a" + str(i) + "_2.c")))
#     temp.append("p")
#     prog.append(temp)
# for i in a_nonplag:
#     temp = []
#     temp.append(os.path.join(root_path, str("a" + str(i) + "_1.c")))
#     temp.append(os.path.join(root_path, str("a" + str(i) + "_2.c")))
#     temp.append("np")
#     prog.append(temp)
# for i in n_plag:
#     temp = []
#     temp.append(os.path.join(root_path, str("n_" + str(i) + "_1.c")))
#     temp.append(os.path.join(root_path, str("n_" + str(i) + "_2.c")))
#     temp.append("p")
#     prog.append(temp)
# for i in n_nonplag:
#     temp = []
#     temp.append(os.path.join(root_path, str("n_" + str(i) + "_1.c")))
#     temp.append(os.path.join(root_path, str("n_" + str(i) + "_2.c")))
#     temp.append("np")
#     prog.append(temp)
# for i in s_plag:
#     temp = []
#     temp.append(os.path.join(root_path, str("s" + str(i) + "_1.c")))
#     temp.append(os.path.join(root_path, str("s" + str(i) + "_2.c")))
#     temp.append("p")
#     prog.append(temp)
# for i in s_nonplag:
#     temp = []
#     temp.append(os.path.join(root_path, str("s" + str(i) + "_1.c")))
#     temp.append(os.path.join(root_path, str("s" + str(i) + "_2.c")))
#     temp.append("np")
#     prog.append(temp)
with open(os.path.join("extraction", "result_test", "pairs_graph.pkl"), "wb") as f:
    pickle.dump(prog, f)
