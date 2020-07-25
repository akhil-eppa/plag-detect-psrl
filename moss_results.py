import os
import pickle

import matplotlib.pyplot as plt
import mosspy
import numpy as np
from bs4 import BeautifulSoup

userid = 831327210

m = mosspy.Moss(userid, "c")


# Submission Files
m.addFilesByWildcard("code_pairs_eval/*.c")

url = m.send()  # Submission Report URL

print("Report Url: " + url)

# Save report file
m.saveWebPage(url, "result/report.html")

html = open("result/report.html").read()
soup = BeautifulSoup(html, "lxml")
table = soup.table
table_rows = table.find_all("tr")
table = []
for row in table_rows:
    cols = row.find_all("td")
    content = [i.text.split()[0].strip() for i in cols]
    if content:
        table.append(content)

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

for row in table:
    row[0] = os.path.basename(row[0])
    row[1] = os.path.basename(row[1])
    if not chk[mapchk[row[0]]]:
        pair = mappair1.get(row[0], mappair2.get(row[0]))
        if row[1] == pair:
            cnt[mapclass[pair]] += 1
            chk[mapchk[row[0]]] = 1

yval = np.array(cnt) / np.array(tot) * 100
pickle.dump(yval, open("acc_moss.pkl", "wb"))

x_labels = [
    "Variable name change",
    "Redundant lines",
    "Reorder lines",
    "Variable type change",
    "Change loop type",
    "Reorder blocks",
]
plt.bar(x_labels, yval)
plt.xticks(rotation=20)
plt.ylim(0,100)
plt.ylabel("Accuracy(%)")
plt.title("MOSS classification accuracy for various categories of plagiarism")
plt.show()
