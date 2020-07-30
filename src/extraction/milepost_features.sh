#!/usr/env bash

cp /home/data/$1 /home/src/extraction/
bash /home/src/extraction/_use_ctuning_cc_directly_extract_features.sh >	/home/src/extraction/tmplog.txt 2>&1
grep "error" /home/src/extraction/tmplog.txt && echo $(basename $1) >> /home/src/extraction/error_log.txt
for j in /tmp/ici_features_function* ; do
	mv $j /home/src/extraction/result/milepost_features/$(basename $1)_$(basename $j)
done
rm -f /home/src/extraction/$(basename $1)
rm -rf /tmp/
echo "Finished $(basename $1)"
