#!/usr/env bash

cp /home/data/$1 /home/src/milepostExtraction/
bash /home/src/milepostExtraction/_use_ctuning_cc_directly_extract_features.sh >	/home/src/milepostExtraction/tmplog.txt 2>&1
grep "error" /home/src/milepostExtraction/tmplog.txt && echo $(basename $1) >> /home/src/milepostExtraction/error_log.txt
for j in /tmp/ici_features_function* ; do
	mv $j /home/src/milepostExtraction/result/milepost_features/$(basename $1)_$(basename $j)
done
rm -f /home/src/milepostExtraction/$(basename $1)
rm -rf /tmp/
