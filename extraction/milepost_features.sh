#!/usr/env bash

[ "$1" != "train" ] && [ "$1" != "test" ] && exit 1
mkdir -p /home/data/plag-detect-psrl/extraction/result_$1/milepost_features

if [[ "$1" == "test" ]]; then
	echo "Running for test folder..."
	mkdir -p /home/data/plag-detect-psrl/extraction/result_$1/Before/milepost_features
	mkdir -p /home/data/plag-detect-psrl/extraction/result_$1/After/milepost_features
	for i in $(find /home/data/plag-detect-psrl/code_pairs_$1/ -name "*.c") ; do
		cp $i /home/data/plag-detect-psrl/extraction/
		bash /home/data/plag-detect-psrl/extraction/_use_ctuning_cc_directly_extract_features.sh >	/home/data/plag-detect-psrl/extraction/tmplog.txt 2>&1
		grep "error" /home/data/plag-detect-psrl/extraction/tmplog.txt && echo $i >> /home/data/plag-detect-psrl/extraction/error_log.txt
		for j in /tmp/ici_features_function* ; do
			mv $j /home/data/plag-detect-psrl/extraction/result_$1/Before/milepost_features/$(basename $i)_$(basename $j)
		done
		rm -f /home/data/plag-detect-psrl/extraction/$(basename $i)
		rm -rf /tmp/
		echo "Finished $(basename $i)"
	done
	for i in $(find /home/data/plag-detect-psrl/code_pairs_$1/ -name "*.c") ; do
		cp $i /home/data/plag-detect-psrl/extraction/
		bash /home/data/plag-detect-psrl/extraction/_use_ctuning_cc_directly_extract_features.sh >	/home/data/plag-detect-psrl/extraction/tmplog.txt 2>&1
		grep "error" /home/data/plag-detect-psrl/extraction/tmplog.txt && echo $i >> /home/data/plag-detect-psrl/extraction/error_log.txt
		for j in /tmp/ici_features_function* ; do
			mv $j /home/data/plag-detect-psrl/extraction/result_$1/After/milepost_features/$(basename $i)_$(basename $j)
		done
		rm -f /home/data/plag-detect-psrl/extraction/$(basename $i)
		rm -rf /tmp/
		echo "Finished $(basename $i)"
	done
	exit 0
fi

for i in $(find /home/data/plag-detect-psrl/code_pairs_$1/ -name "*.c") ; do
	cp $i /home/data/plag-detect-psrl/extraction/
	bash /home/data/plag-detect-psrl/extraction/_use_ctuning_cc_directly_extract_features.sh >	/home/data/plag-detect-psrl/extraction/tmplog.txt 2>&1
	grep "error" /home/data/plag-detect-psrl/extraction/tmplog.txt && echo $(basename $i) >> /home/data/plag-detect-psrl/extraction/error_log.txt
	for j in /tmp/ici_features_function* ; do
		mv $j /home/data/plag-detect-psrl/extraction/result_$1/milepost_features/$(basename $i)_$(basename $j)
	done
	rm -f /home/data/plag-detect-psrl/extraction/$(basename $i)
	rm -rf /tmp/
	echo "Finished $(basename $i)"
done
