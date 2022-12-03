Spacy-cpp
=========

| **Linux** |
|-----------|
| [![Linux](https://github.com/d99kris/spacy-cpp/workflows/Linux/badge.svg?branch=master)](https://github.com/d99kris/spacy-cpp/actions?query=workflow%3ALinux) |

Spacy-cpp is a C++ wrapper library for the NLP library
[spaCy](https://spacy.io/). This project is not affiliated with spaCy, it is
however distributed under the same type of license (MIT).

The goal of spacy-cpp is to expose the functionality of spaCy to C++
applications, and to provide an API that is similar to that of spaCy,
enabling rapid development in Python and simple porting to C++.

Spacy-cpp is under development and does not yet support all API's of spaCy,
refer to the API Documentation section below.


Example Usage
=============
Simple POS tagging example using spacy-cpp:
```cpp
Spacy::Spacy spacy;
auto nlp = spacy.load("en_core_web_sm");
auto doc = nlp.parse("This is a sentence.");
for (auto& token : doc.tokens())
    std::cout << token.text() << " [" << token.pos_() << "]\n";
```

For reference - doing the same using the spaCy API in Python:
```python
import spacy
nlp = spacy.load("en_core_web_sm")
doc = nlp(u"This is a sentence.")
for token in doc:
    print(token.text + " [" + token.pos_ + "]")
```


Supported Platforms
===================
Spacy-cpp is implemented using C++11 with the intention of being portable.
Current version has been tested on:
- Ubuntu 22.04 LTS


Pre-requisites
==============
Spacy-cpp requires python development library, pip, spaCy and typically a
spaCy model.

Ubuntu
------
Install build dependencies:

    sudo apt install cmake python3-pip libpython3-dev

Install spaCy and an English model:

    pip3 install -U spacy
    python3 -m spacy download en_core_web_sm


Installation
============
Spacy-cpp can be used either as a shared library or as a header-only library.

Shared Library
--------------
Build and install spacy-cpp:

    mkdir -p build && cd build && cmake .. && make && sudo make install

Link library:

    -lspacy

Include header (convenience header including all modules):

    #include <spacy/spacy>


Header-only Library
-------------------
Copy the src/spacy directory to the source directory of your project. Then
define SPACY_HEADER_ONLY and include headers needed (spacy/spacy includes
all headers):

    #define SPACY_HEADER_ONLY
    #include <spacy/spacy>


API Documentation
=================
Spacy-cpp is under development and does not support the complete spaCy API yet.

Supported Classes
-----------------
- [Attrs](https://github.com/d99kris/spacy-cpp/blob/master/src/spacy/attrs.h)
- [Doc](https://github.com/d99kris/spacy-cpp/blob/master/src/spacy/doc.h)
- [Nlp](https://github.com/d99kris/spacy-cpp/blob/master/src/spacy/nlp.h)
- [Spacy](https://github.com/d99kris/spacy-cpp/blob/master/src/spacy/spacy.h)
- [Span](https://github.com/d99kris/spacy-cpp/blob/master/src/spacy/span.h)
- [StringStore](https://github.com/d99kris/spacy-cpp/blob/master/src/spacy/stringstore.h)
- [Token](https://github.com/d99kris/spacy-cpp/blob/master/src/spacy/token.h)
- [Vocab](https://github.com/d99kris/spacy-cpp/blob/master/src/spacy/vocab.h)

Supported Methods / Attributes
------------------------------
**Attrs** supports all attribute constants.

**Doc** supports the following methods / attributes:
- count_by()
- ents()
- has_vector()
- is_parsed()
- is_tagged()
- noun_chunks()
- sentiment()
- sents()
- similarity()
- text()
- text_with_ws()
- tokens()
- vector_norm()

**Nlp** supports the following methods / attributes:
- parse()
- vocab()

**Spacy** supports the following methods / attributes:
- load()
- attrs()

**Span** supports the following methods / attributes:
- doc()
- label()
- label_()
- lemma_()
- orth_()
- root()
- sentiment()
- text()
- text_with_ws()
- tokens()
- vector_norm()

**StringStore** supports the following methods / attributes:
- add()

**Token** supports the following methods / attributes:
- check_flag()
- children()
- cluster()
- dep()
- dep_()
- ent_iob_()
- has_vector()
- i()
- idx()
- is_alpha()
- is_ascii()
- is_bracket()
- is_digit()
- is_left_punct()
- is_lower()
- is_oov()
- is_punct()
- is_quote()
- is_right_punct()
- is_space()
- is_stop()
- is_title()
- is_upper()
- lang()
- lang_()
- lemma()
- lemma_()
- like_email()
- like_num()
- like_url()
- lower()
- lower_()
- nbor()
- norm()
- norm_()
- orth()
- orth_()
- pos()
- pos_()
- prob()
- rank()
- sentiment()
- shape()
- shape_()
- tag()
- tag_()
- text()
- text_with_ws()
- whitespace_()

**Vocab** supports the following methods / attributes:
- strings()

Key Differences with spaCy
--------------------------
1. In spacy-cpp Nlp cannot be called as a method in order to perform parsing.
   Instead one need to use Nlp::parse().
2. In spacy-cpp Doc is not an iterable, instead one need to use Doc::token()
   to get a std::vector of the tokens in the Doc. Likewise for Span.
3. In spacy-cpp non-ASCII strings must be UTF-8 encoded in order to be
   correctly processed.


Technical Details
=================
Spacy-cpp uses cmake for its tests. Commands to build and execute the test
suite:

    mkdir -p build && cd build && cmake -DSPACYCPP_BUILD_TESTS=ON .. && make && ctest --output-on-failure ; cd -


License
=======
Spacy-cpp is distributed under the MIT license.
See [LICENSE](https://github.com/d99kris/spacy-cpp/blob/master/LICENSE) file.


Contributions
=============
Bugs, PRs, etc are welcome on the GitHub project page
https://github.com/d99kris/spacy-cpp


Keywords
========
c++, c++11, natural language processing, nlp, spacy.

