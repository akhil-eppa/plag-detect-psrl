# -*- coding: utf-8 -*-
"""
Created on Wed Jul 22 13:05:07 2020

@author: Akhil
"""

"""
pip install git+https://github.com/huggingface/transformers
pip list | grep -E 'transformers|tokenizers'
"""
import os
# os.system('pip install git+https://github.com/huggingface/transformers')
# os.system('pip list | grep -E \'transformers|tokenizers\'')
from pathlib import Path

import torch
from tokenizers import CharBPETokenizer
from tokenizers.implementations import ByteLevelBPETokenizer
from tokenizers.processors import BertProcessing
from torch.utils.data import Dataset
from transformers import (DataCollatorForLanguageModeling,
                          RobertaTokenizerFast, Trainer, TrainingArguments,
                          XLMRobertaConfig, XLMRobertaForMaskedLM, pipeline)

paths = [str(x) for x in Path(".").glob("*.txt")]

# Initialize a tokenizer
tokenizer = CharBPETokenizer()

# Customize training
tokenizer.train(
    files=paths,
    vocab_size=52_000,
    min_frequency=2,
    special_tokens=["<s>", "<pad>", "</s>", "<mask>", "<unk>"],
)

if not os.path.isdir("CodeBERTo"):
    os.mkdir("CodeBERTo")
tokenizer.save_model("CodeBERTo")


# tokenizer = ByteLevelBPETokenizer("./CodeBERTo/vocab.json", "./CodeBERTo/merges.txt",)
#
# tokenizer._tokenizer.post_processor = BertProcessing(
#     ("</s>", tokenizer.token_to_id("</s>")), ("<s>", tokenizer.token_to_id("<s>")),
# )
# tokenizer.enable_truncation(max_length=512)
# # testing
# print(tokenizer.encode("#include <stdio.h>").tokens)
#
#
tokenizer = RobertaTokenizerFast.from_pretrained("./CodeBERTo")
# print(tokenizer(["#include <stdio.h>", "#include <bool.h>"]).input_ids)


config = XLMRobertaConfig(
    vocab_size=52_000,
    max_position_embeddings=514,
    num_attention_heads=12,
    num_hidden_layers=6,
    type_vocab_size=1,
)


model = XLMRobertaForMaskedLM(config=config)
print(model.num_parameters())


class CDataset(Dataset):
    def __init__(self, batch_size, tokenizer, evaluate: bool = False):
        self.tokenizer = tokenizer

        src_file = open("./linux.txt")
        self.lines = [
            line
            for line in src_file.read().splitlines()
            if (len(line) > 0 and not line.isspace())
        ]
        self.lines_size = len(self.lines)
        self.batch_size = batch_size

    def __len__(self):
        return self.lines_size // self.batch_size

    def __getitem__(self, i):
        # We’ll pad at the batch level.
        batch = self.lines[i : i + self.batch_size]
        tokens = self.tokenizer(
            batch, padding="max_length", truncation=True, max_length=60
        ).input_ids
        print(tokens)
        return torch.tensor(tokens)


dataset = CDataset(60, tokenizer)


data_collator = DataCollatorForLanguageModeling(
    tokenizer=tokenizer, mlm=True, mlm_probability=0.15
)


training_args = TrainingArguments(
    output_dir="./CodeBERTo",
    overwrite_output_dir=True,
    num_train_epochs=1,
    per_gpu_train_batch_size=60,
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
#
trainer.train()

trainer.save_model("./CodeBERTo")

get_features = pipeline("feature-extraction", model="./CodeBERTo", tokenizer=tokenizer)

print(get_features("#include <stdio.h>"))
