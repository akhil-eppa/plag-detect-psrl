import pickle


def mergeMilepostFeatures(out_file, files, feat_dir):
    prog_vecs = {}
    for prog in files:
        merged_vecs = {}
        counter = 0
        for k in feat_dir.glob(f"{prog}*.fre.ft"):
            with open(k) as cur_vecs:
                lines = cur_vecs.read().strip().split(",")
            for line in lines:
                key, val = line.strip().split("=")
                try:
                    merged_vecs[key] += float(val)
                except:
                    merged_vecs[key] = float(val)
                counter += 1
        for key in merged_vecs:
            merged_vecs[key] /= counter

        vec_array = []
        for i in range(1, 66):
            vec_array.append(merged_vecs.get(f"ft{i}", 0.0))
        prog_vecs[prog] = vec_array

    pickle.dump(prog_vecs, open(out_file, "wb"))
