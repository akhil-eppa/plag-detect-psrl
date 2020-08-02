# -*- coding: utf-8 -*-
"""
Created on Mon Jun  1 12:45:17 2020

@author: Akhil
"""
# prog is a list of lists
# each element is prog is a list that contains the two programs of the pair
# and whether they are plagiarized or not.
# That is index 0 is the name of first program, index 1 is name of second program in pair
# index 2 is 'p' or 'np' denoting plagiarized or non plagiarized
import pickle
import os

prog = []
root_path = os.path.abspath("code_pairs_train")

"""
Pairs by Akhil
1 to 192 are plagiarized
193 to 373 are non plagiarized
"""
'''
added 374 to 434 non plagiarized
435 to 458 plagiarized
'''
for i in range(1, 459):
    temp = []
    temp.append(os.path.join(str("a" + str(i) + "_1.c")))
    temp.append(os.path.join(str("a" + str(i) + "_2.c")))
    if i <= 192:
        temp.append("p")
    elif i>192 and i<=434:
        temp.append("np")
    else:
        temp.append("p")
    prog.append(temp)
"""
Pairs by Anirudh
1 to 300 are non plagiarized
301 to 425 are plagiarized
"""
for i in range(1, 424):
    temp = []
    temp.append(os.path.join(str("n_" + str(i) + "_1.c")))
    temp.append(os.path.join(str("n_" + str(i) + "_2.c")))
    if i <= 300:
        temp.append("np")
    else:
        temp.append("p")
    prog.append(temp)
"""
Pairs by Santosh
1 to 180 are plagiarized
181 to 360 are non plagairized
"""
# for i in range(1, 361):
#     temp = []
#     temp.append(os.path.join(root_path, str("s" + str(i) + "_1.c")))
#     temp.append(os.path.join(root_path, str("s" + str(i) + "_2.c")))
#     if i <= 180:
#         temp.append("p")
#     else:
#         temp.append("np")
#     prog.append(temp)
np = 0
p = 0
for i in prog:
    print(i)
    if i[2] == "p":
        p = p + 1
    else:
        np = np + 1
print("Number of plagiarized pairs=", p)
print("Number of non plagiarized pairs=", np)
print("Total number of pairs=", len(prog))

with open("pairs.pkl", "wb") as f:
    pickle.dump(prog, f)


# To access file names from pickled list uncomment below code
"""
with open('pairs.pkl','rb') as f:
    prog=pickle.load(f)
for i in prog:
    print(i)
"""
