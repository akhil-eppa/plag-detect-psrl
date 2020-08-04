import argparse
import csv
import pickle
from pathlib import Path

from lib.codebertPredictions import cbEval
from lib.milepostExtraction.extractMilepostFeatures import \
    extractMilepostFeatures
from lib.milepostPredictions import mpEval
from lib.rnnPredictions import rnnEval
from lib.rnnPredictions.extractRnnFeatures import extractRnnFeatures
from lib.utils import listUtils

parser = argparse.ArgumentParser()
parser.add_argument(
    "root_dir",
    help="The directory with all submissions. If PAIRS_FILE is specified, used as the root directory for the filenames in PAIRS_FILE",
)
parser.add_argument(
    "-p",
    "--pairs_file",
    help="A pickled file with a list of tuples. Each tuple should have two file names and optionally, a boolean flag to indicate whether the pair is plagiarised (required for training)",
)
parser.add_argument(
    "-m",
    "--method",
    choices=["milepost", "rnn", "codebert"],
    default="codebert",
    help="The evaluation metric to use",
)
parser.add_argument(
    "--train",
    action="store_true",
    help="Use programs in ROOT_DIR to train models (for milepost and rnn only)",
)
parser.add_argument(
    "-o",
    "--output_file",
    default="result/report.csv",
    help="Path to report file (must be a csv file)",
)
args = parser.parse_args()


def take_prob(elem):
    return elem[2]


def main(args):
    if args.train and args.method == "codebert":
        raise ValueError("Training is only used for 'milepost' and 'rnn' metrics")
    root_dir = Path(args.root_dir).resolve()
    res_file = Path(args.output_file).resolve()
    if res_file.suffix != ".csv":
        raise ValueError("OUTPUT_FILE must be a csv file")
    if args.pairs_file:
        pairs = pickle.load(open(args.pairs_file, "rb"))
    else:
        files = listUtils.getSubmissions(root_dir)
        pairs = listUtils.getCombinations(files)
        pickle.dump(pairs, open("result/pairs.pkl", "wb"))
    if args.method == "milepost":
        extractMilepostFeatures(pairs, root_dir, train=args.train)
        y_pred, y_prob = mpEval.evaluate(
            "lib/milepostExtraction/result/features.csv", train=args.train
        )
    elif args.method == "rnn":
        extractRnnFeatures(pairs, root_dir, train=args.train)
        y_pred, y_prob = rnnEval.evaluate(
            "lib/rnnPredictions/result/X.pkl", train=args.train
        )
    elif args.method == "codebert":
        y_pred = cbEval.evaluate(pairs, root_dir)
    l = []
    if not args.train:
        with open(res_file, "w") as wr:
            writer = csv.writer(wr)
            print("Plagiarised pairs: ")
            if args.method == "codebert":
                writer.writerow(["File 1", "File 2", "Plagiarised"])
                for (f1, f2), pred in zip(pairs, y_pred):
                    writer.writerow([f1, f2, pred])
                    if pred:
                        print(f"{f1}  --->  {f2}")
            else:
                writer.writerow(["File 1", "File 2", "Plagiarised", "Probability"])
                for (f1, f2), prob, pred in zip(pairs, y_prob[:, 1], y_pred):
                    writer.writerow([f1, f2, pred, prob])
                    l.append([f1, f2, prob])
                    if pred:
                        print(f"{f1}  --->  {f2}")
                for i in files:
                    z = [x for x in l if x[0] == i or x[1] == i]
                    z.sort(key=take_prob)
                    if len(z) < 3:
                        print("top matches of", i)
                        for i in z:
                            print(
                                i[0], "and", i[1], "have", i[2] * 100, "% similarity."
                            )
                    else:
                        print("top 3 matches of", i)
                        for i in z:
                            print(
                                i[0], "and", i[1], "have", i[2] * 100, "% similarity."
                            )
                    print()


if __name__ == "__main__":
    main(args)
