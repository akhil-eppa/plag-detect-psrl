import os
import pickle
import time

import mosspy
import numpy as np
from bs4 import BeautifulSoup

userid = 831327210

m = mosspy.Moss(userid, "c")

m.options["m"] = 10000000

table1 = []
# Submission Files
for i in range(6):
    # m.addFilesByWildcard(f"code_pairs_eval/{i}/*.c")
    # url = m.send()  # Submission Report URL
    # print("Report Url: " + url)
    # # Save report file
    # m.saveWebPage(url, f"result/report{i}.html")

    html = open(f"result/report{i}.html").read()
    soup = BeautifulSoup(html, "lxml")
    table = soup.table
    table_rows = table.find_all("tr")
    for row in table_rows:
        cols = row.find_all("td")
        content = [i.text.split()[0].strip() for i in cols]
        if content:
            table1.append(content)
    time.sleep(10)

pairs = pickle.load(open("extraction/result_test/pairs_graph.pkl", "rb"))
chk = [0] * len(pairs)
mapchk = dict((os.path.basename(pair[0]), idx) for idx, pair in enumerate(pairs))
map2 = dict((os.path.basename(pair[1]), idx) for idx, pair in enumerate(pairs))
mapchk.update(map2)
mappair1 = dict(
    (os.path.basename(pair[0]), os.path.basename(pair[1])) for pair in pairs
)
mappair2 = dict(
    (os.path.basename(pair[1]), os.path.basename(pair[0])) for pair in pairs
)
mapclass = dict()

tot = [0] * 6
for pair in pairs:
    tot[pair[2]] += 1
    mapclass[os.path.basename(pair[0])] = pair[2]
    mapclass[os.path.basename(pair[1])] = pair[2]

cnt = [0] * 6

for row in table1:
    row[0] = os.path.basename(row[0])
    row[1] = os.path.basename(row[1])
    if not chk[mapchk[row[0]]]:
        pair = mappair1.get(row[0], mappair2.get(row[0]))
        if row[1] == pair:
            cnt[mapclass[pair]] += 1
            chk[mapchk[row[0]]] = 1

yval = np.array(cnt) / np.array(tot) * 100
print(yval)
pickle.dump(yval, open("acc_moss.pkl", "wb"))
