#!/usr/env bash

[ "$1" != "train" ] && [ "$1" != "test" ] && exit 1
mkdir -p /home/data/plag-detect-psrl/extraction/result_$1/milepost_features

for i in /home/data/plag-detect-psrl/code_pairs/*.c ; do
	cp $i /home/data/plag-detect-psrl/extraction/
	bash /home/data/plag-detect-psrl/extraction/_use_ctuning_cc_directly_extract_features.sh >	/home/data/plag-detect-psrl/extraction/tmplog.txt 2>&1
	grep "error" /home/data/plag-detect-psrl/extraction/tmplog.txt && echo $(basename $i) >> /home/data/plag-detect-psrl/extraction/error_log.txt
	for j in /tmp/ici_features_function* ; do
		mv $j /home/data/plag-detect-psrl/extraction/result_$1/milepost_features/$(basename $i)_$(basename $j)
	done
	rm -f /home/data/plag-detect-psrl/extraction/$(basename $i)
	rm -rf /tmp/
done
