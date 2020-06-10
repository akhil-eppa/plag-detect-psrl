for i in ../code_pairs/*.c ; do
	cp $i ./
	./_use_ctuning_cc_directly_extract_features.sh
	for j in tmp/ici_features_function* ; do
		mv $j result/milepost_features/$(basename $i)_$(basename $j)
	done
	rm -f $(basename $i)
	rm -rf tmp
done
