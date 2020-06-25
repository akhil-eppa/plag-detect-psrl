#!/usr/bin/env bash
###########################################################
# Change the following values to preprocess a new dataset.
# TRAIN_DIR, VAL_DIR and TEST_DIR should be paths to      
#   directories containing sub-directories with .java files
# DATASET_NAME is just a name for the currently extracted 
#   dataset.                                              
# MAX_DATA_CONTEXTS is the number of contexts to keep in the dataset for each 
#   method (by default 1000). At training time, these contexts
#   will be downsampled dynamically to MAX_CONTEXTS.
# MAX_CONTEXTS - the number of actual contexts (by default 200) 
# that are taken into consideration (out of MAX_DATA_CONTEXTS)
# every training iteration. To avoid randomness at test time, 
# for the test and validation sets only MAX_CONTEXTS contexts are kept 
# (while for training, MAX_DATA_CONTEXTS are kept and MAX_CONTEXTS are
# selected dynamically during training).
# SUBTOKEN_VOCAB_SIZE, TARGET_VOCAB_SIZE -   
#   - the number of subtokens and target words to keep 
#   in the vocabulary (the top occurring words and paths will be kept). 
# NUM_THREADS - the number of parallel threads to use. It is 
#   recommended to use a multi-core machine for the preprocessing 
#   step and set this value to the number of cores.
# PYTHON - python3 interpreter alias.
#TRAIN_DIR=D:/Study/PSRL/ASTMiner/dataset/train
#VAL_DIR=D:/Study/PSRL/ASTMiner/dataset/val
#TEST_DIR=D:/Study/PSRL/ASTMiner/dataset/test
DATASET_NAME=my_dataset
MAX_DATA_CONTEXTS=1000
MAX_CONTEXTS=200
SUBTOKEN_VOCAB_SIZE=186277
TARGET_VOCAB_SIZE=26347
NUM_THREADS=4
PYTHON=python3
###########################################################

TRAIN_DATA_FILE=D:/Study/PSRL/ASTMiner/dataset/train/path_contexts.csv
VAL_DATA_FILE=D:/Study/PSRL/ASTMiner/dataset/val/path_contexts.csv
TEST_DATA_FILE=D:/Study/PSRL/ASTMiner/dataset/test/path_contexts.csv
#EXTRACTOR_JAR=JavaExtractor/JPredict/target/JavaExtractor-0.0.1-SNAPSHOT.jar

mkdir -p data
mkdir -p data/${DATASET_NAME}

TARGET_HISTOGRAM_FILE=D:/Study/PSRL/PathMiner/repo/code2seq/data/${DATASET_NAME}/${DATASET_NAME}.histo.tgt.c2s
SOURCE_SUBTOKEN_HISTOGRAM=D:/Study/PSRL/PathMiner/repo/code2seq/data/${DATASET_NAME}/${DATASET_NAME}.histo.ori.c2s
NODE_HISTOGRAM_FILE=D:/Study/PSRL/PathMiner/repo/code2seq/data/${DATASET_NAME}/${DATASET_NAME}.histo.node.c2s

echo "Creating histograms from the training data"
cat ${TRAIN_DATA_FILE} | cut -d' ' -f1 | tr '|' '\n' | awk '{n[$0]++} END {for (i in n) print i,n[i]}' > ${TARGET_HISTOGRAM_FILE}
cat ${TRAIN_DATA_FILE} | cut -d' ' -f2- | tr ' ' '\n' | cut -d',' -f1,3 | tr ',|' '\n' | awk '{n[$0]++} END {for (i in n) print i,n[i]}' > ${SOURCE_SUBTOKEN_HISTOGRAM}
cat ${TRAIN_DATA_FILE} | cut -d' ' -f2- | tr ' ' '\n' | cut -d',' -f2 | tr '|' '\n' | awk '{n[$0]++} END {for (i in n) print i,n[i]}' > ${NODE_HISTOGRAM_FILE}

${PYTHON} preprocess.py --train_data ${TRAIN_DATA_FILE} --test_data ${TEST_DATA_FILE} --val_data ${VAL_DATA_FILE} \
  --max_contexts ${MAX_CONTEXTS} --max_data_contexts ${MAX_DATA_CONTEXTS} --subtoken_vocab_size ${SUBTOKEN_VOCAB_SIZE} \
  --target_vocab_size ${TARGET_VOCAB_SIZE} --subtoken_histogram ${SOURCE_SUBTOKEN_HISTOGRAM} \
  --node_histogram ${NODE_HISTOGRAM_FILE} --target_histogram ${TARGET_HISTOGRAM_FILE} --output_name data/${DATASET_NAME}/${DATASET_NAME}
    
# If all went well, the raw data files can be deleted, because preprocess.py creates new files 
# with truncated and padded number of paths for each example.
#rm ${TRAIN_DATA_FILE} ${VAL_DATA_FILE} ${TEST_DATA_FILE} ${TARGET_HISTOGRAM_FILE} ${SOURCE_SUBTOKEN_HISTOGRAM} \
# ${NODE_HISTOGRAM_FILE}


#cat D:/Study/PSRL/ASTMiner/dataset/train/path_contexts.csv | cut -d' ' -f1 | tr '|' '\n' | awk '{n[$0]++} END {for (i in n) print i,n[i]}' > D:/Study/PSRL/PathMiner/repo/code2seq/data/train_set/train_set.histo.tgt.c2s
#cat D:/Study/PSRL/ASTMiner/dataset/train/path_contexts.csv | cut -d' ' -f2- | tr ' ' '\n' | cut -d',' -f1,3 | tr ',|' '\n' | awk '{n[$0]++} END {for (i in n) print i,n[i]}' > D:/Study/PSRL/PathMiner/repo/code2seq/data/train_set/train_set.histo.ori.c2s
#cat D:/Study/PSRL/ASTMiner/dataset/train/path_contexts.csv | cut -d' ' -f2- | tr ' ' '\n' | cut -d',' -f2 | tr '|' '\n' | awk '{n[$0]++} END {for (i in n) print i,n[i]}' > D:/Study/PSRL/PathMiner/repo/code2seq/data/train_set/train_set.histo.node.c2s


#python3 preprocess.py --train_data D:/Study/PSRL/ASTMiner/dataset/train/path_contexts.csv --test_data D:/Study/PSRL/ASTMiner/dataset/test/path_contexts.csv --val_data D:/Study/PSRL/ASTMiner/dataset/val/path_contexts.csv \
  --max_contexts 200 --max_data_contexts 1000 --subtoken_vocab_size 186277 \
  --target_vocab_size 26347 --subtoken_histogram D:/Study/PSRL/PathMiner/repo/code2seq/data/train_set/train_set.histo.ori.c2s \
  --node_histogram $D:/Study/PSRL/PathMiner/repo/code2seq/data/train_set/train_set.histo.node.c2s --target_histogram D:/Study/PSRL/PathMiner/repo/code2seq/data/train_set/train_set.histo.tgt.c2s --output_name data/train_set/train_set