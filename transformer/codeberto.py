# -*- coding: utf-8 -*-
"""
Created on Wed Jul 22 13:05:07 2020

@author: Akhil
"""

'''
pip install git+https://github.com/huggingface/transformers
pip list | grep -E 'transformers|tokenizers'
'''
import os
os.system('pip install git+https://github.com/huggingface/transformers')
os.system('pip list | grep -E \'transformers|tokenizers\'')
from pathlib import Path

from tokenizers import CharBPETokenizer

paths = [str(x) for x in Path(".").glob("**/*.txt")]

# Initialize a tokenizer
tokenizer = CharBPETokenizer()

# Customize training
tokenizer.train(files=paths, vocab_size=52_000, min_frequency=2, special_tokens=[
    "<s>",
    "<pad>",
    "</s>",
    "<mask>",
    "<unk>"
])

os.system('mkdir CodeBERTo')
tokenizer.save_model("CodeBERTo")

from tokenizers.implementations import ByteLevelBPETokenizer
from tokenizers.processors import BertProcessing


tokenizer = ByteLevelBPETokenizer(
    "./CodeBERTo/vocab.json",
    "./CodeBERTo/merges.txt",
)

tokenizer._tokenizer.post_processor = BertProcessing(
    ("</s>", tokenizer.token_to_id("</s>")),
    ("<s>", tokenizer.token_to_id("<s>")),
)
tokenizer.enable_truncation(max_length=512)
#testing
print(tokenizer.encode("#include <stdio.h>").tokens)
                 
from transformers import RobertaTokenizerFast
tokenizer = RobertaTokenizerFast.from_pretrained("./CodeBERTo", max_len=512)

from transformers import XLMRobertaConfig
config = XLMRobertaConfig(
    vocab_size=52_000,
    max_position_embeddings=514,
    num_attention_heads=12,
    num_hidden_layers=6,
    type_vocab_size=1,
)

from transformers import XLMRobertaForMaskedLM
model = XLMRobertaForMaskedLM(config=config)
print(model.num_parameters())

from transformers import LineByLineTextDataset

dataset = LineByLineTextDataset(
    tokenizer=tokenizer,
    file_path="./linux.txt",
    block_size=128,
)

from transformers import DataCollatorForLanguageModeling

data_collator = DataCollatorForLanguageModeling(
    tokenizer=tokenizer, mlm=True, mlm_probability=0.15
)

from transformers import Trainer, TrainingArguments

training_args = TrainingArguments(
    output_dir="./CodeBERTo",
    overwrite_output_dir=True,
    num_train_epochs=1,
    per_gpu_train_batch_size=64,
    save_steps=10_000,
    save_total_limit=2,
)

trainer = Trainer(
    model=model,
    args=training_args,
    data_collator=data_collator,
    train_dataset=dataset,
    prediction_loss_only=True,
)

trainer.train()

trainer.save_model("./CodeBERTo")
from transformers import pipeline
get_features = pipeline(
    "feature-extraction",
    model="./CodeBERTo",
    tokenizer=tokenizer
)

print(get_features("#include <stdio.h>"))