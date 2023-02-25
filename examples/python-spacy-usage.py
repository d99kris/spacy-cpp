#!/usr/bin/env python3

import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"This is a sentence.")
for token in doc:
    print(token.text + " [" + token.pos_ + "]")
