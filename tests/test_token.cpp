// test_token.cpp
//
// URL:      https://github.com/d99kris/spacy-cpp
//
// Copyright (C) 2017 Kristofer Berggren
// All rights reserved.
//
// spacy-cpp is distributed under the MIT license, see LICENSE for details.

#include <iostream>
#include <spacy/spacy>
#include "unittest.h"

int main()
{
  int rv = 0;

  try
  {
    // Prereq
    Spacy::Spacy spacy;
    Spacy::Nlp nlp = spacy.load("en_core_web_sm");
    Spacy::Attrs attrs = spacy.attrs();

    // Token
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token token = doc.tokens().at(0);
      unittest::ExpectEqual(std::string, token.text(), "Give");
    }

    // Token::check_flag
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token token = doc.tokens().at(0);
      unittest::ExpectTrue(token.check_flag(attrs.IS_TITLE()));
    }

    // Token::children
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      std::vector<Spacy::Token> give_children = doc.tokens().at(0).children();
      unittest::ExpectEqual(std::string, give_children.at(0).text(), "it");
      unittest::ExpectEqual(std::string, give_children.at(1).text(), "back");
      unittest::ExpectEqual(std::string, give_children.at(2).text(), "!");
    }

    // Token::cluster
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      Spacy::Token apples = doc.tokens().at(2);
      long cluster = apples.cluster();
      (void)(cluster);
    }

    // Token::dep
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token token = doc.tokens().at(0);
      unittest::ExpectEqual(long, token.dep(), nlp.vocab().strings().add("ROOT"));
    }

    // Token::dep_
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token token = doc.tokens().at(0);
      unittest::ExpectEqual(std::string, token.dep_(), "ROOT");
    }

    // Token::ent_iob_
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token token = doc.tokens().at(0);
      unittest::ExpectEqual(std::string, token.ent_iob_(), "O");
    }

    // Token::has_vector
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      Spacy::Token apples = doc.tokens().at(2);
      unittest::ExpectTrue(apples.has_vector());
    }

    // Token::i
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      Spacy::Token apples = doc.tokens().at(2);
      unittest::ExpectEqual(long, apples.i(), 2);
    }

    // Token::idx
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      Spacy::Token apples = doc.tokens().at(2);
      unittest::ExpectEqual(long, apples.idx(), 7);
    }

    // Token::is_alpha
    {
      Spacy::Doc doc = nlp.parse("5 apples");
      Spacy::Token five = doc.tokens().at(0);
      Spacy::Token apples = doc.tokens().at(1);
      unittest::ExpectTrue(!five.is_alpha());
      unittest::ExpectTrue(apples.is_alpha());
    }

    // Token::is_ascii
    {
      Spacy::Doc doc = nlp.parse("\xF0\x9F\x8D\x8C apples");
      Spacy::Token banana_emoji_utf8 = doc.tokens().at(0);
      Spacy::Token apples = doc.tokens().at(1);
      unittest::ExpectTrue(!banana_emoji_utf8.is_ascii());
      unittest::ExpectTrue(apples.is_ascii());
    }

    // Token::is_alpha
    {
      Spacy::Doc doc = nlp.parse("(5) [apples]");
      Spacy::Token left_parenthesis = doc.tokens().at(0);
      Spacy::Token five = doc.tokens().at(1);
      Spacy::Token right_parenthesis = doc.tokens().at(2);
      Spacy::Token left_bracket = doc.tokens().at(3);
      Spacy::Token apples = doc.tokens().at(4);
      Spacy::Token right_bracket = doc.tokens().at(5);
      unittest::ExpectTrue(left_parenthesis.is_bracket());
      unittest::ExpectTrue(!five.is_bracket());
      unittest::ExpectTrue(right_parenthesis.is_bracket());
      unittest::ExpectTrue(left_bracket.is_bracket());
      unittest::ExpectTrue(!apples.is_bracket());
      unittest::ExpectTrue(right_bracket.is_bracket());
    }
    
    // Token::is_digit
    {
      Spacy::Doc doc = nlp.parse("5 apples");
      Spacy::Token five = doc.tokens().at(0);
      Spacy::Token apples = doc.tokens().at(1);
      unittest::ExpectTrue(five.is_digit());
      unittest::ExpectTrue(!apples.is_digit());
    }

    // Token::is_left_punct
    {
      Spacy::Doc doc = nlp.parse("() []");
      Spacy::Token left_parenthesis = doc.tokens().at(0);
      Spacy::Token right_parenthesis = doc.tokens().at(1);
      Spacy::Token left_bracket = doc.tokens().at(2);
      Spacy::Token right_bracket = doc.tokens().at(3);
      unittest::ExpectTrue(left_parenthesis.is_left_punct());
      unittest::ExpectTrue(!right_parenthesis.is_left_punct());
      unittest::ExpectTrue(left_bracket.is_left_punct());
      unittest::ExpectTrue(!right_bracket.is_left_punct());
    }
    
    // Token::is_lower
    {
      Spacy::Doc doc = nlp.parse("Many BIG apples");
      Spacy::Token many = doc.tokens().at(0);
      Spacy::Token big = doc.tokens().at(1);
      Spacy::Token apples = doc.tokens().at(2);
      unittest::ExpectTrue(!many.is_lower());
      unittest::ExpectTrue(!big.is_lower());
      unittest::ExpectTrue(apples.is_lower());
    }

    // Token::is_oov
    {
      Spacy::Doc doc = nlp.parse("apples apppples");
      Spacy::Token apples = doc.tokens().at(0);
      Spacy::Token apppples = doc.tokens().at(1);
      // re-enable when spaCy returns correct value: unittest::ExpectTrue(!apples.is_oov());
      unittest::ExpectTrue(apppples.is_oov());
    }

    // Token::is_punct
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token give = doc.tokens().at(0);
      Spacy::Token exclamation_mark = doc.tokens().at(3);
      Spacy::Token period = doc.tokens().at(6);
      unittest::ExpectTrue(!give.is_punct());
      unittest::ExpectTrue(exclamation_mark.is_punct());
      unittest::ExpectTrue(period.is_punct());
    }

    // Token::is_quote
    {
      Spacy::Doc doc = nlp.parse("I \"like\" apples");
      Spacy::Token quote_start = doc.tokens().at(1);
      Spacy::Token like = doc.tokens().at(2);
      Spacy::Token quote_end = doc.tokens().at(3);
      unittest::ExpectTrue(quote_start.is_quote());
      unittest::ExpectTrue(!like.is_quote());
      unittest::ExpectTrue(quote_end.is_quote());
    }
    
    // Token::is_right_punct
    {
      Spacy::Doc doc = nlp.parse("() []");
      Spacy::Token left_parenthesis = doc.tokens().at(0);
      Spacy::Token right_parenthesis = doc.tokens().at(1);
      Spacy::Token left_bracket = doc.tokens().at(2);
      Spacy::Token right_bracket = doc.tokens().at(3);
      unittest::ExpectTrue(!left_parenthesis.is_right_punct());
      unittest::ExpectTrue(right_parenthesis.is_right_punct());
      unittest::ExpectTrue(!left_bracket.is_right_punct());
      unittest::ExpectTrue(right_bracket.is_right_punct());
    }

    // Token::is_space
    {
      Spacy::Doc doc = nlp.parse("I like apples");
      Spacy::Token apples = doc.tokens().at(2);
      unittest::ExpectTrue(!apples.is_space());
    }

    // Token::is_stop
    {
      Spacy::Doc doc = nlp.parse("apples are tasty");
      Spacy::Token apples = doc.tokens().at(0);
      Spacy::Token are = doc.tokens().at(1);
      unittest::ExpectTrue(!apples.is_stop());
      unittest::ExpectTrue(are.is_stop());
    }

    // Token::is_title
    {
      Spacy::Doc doc = nlp.parse("Many BIG apples");
      Spacy::Token many = doc.tokens().at(0);
      Spacy::Token big = doc.tokens().at(1);
      Spacy::Token apples = doc.tokens().at(2);
      unittest::ExpectTrue(many.is_title());
      unittest::ExpectTrue(!big.is_title());
      unittest::ExpectTrue(!apples.is_title());
    }

    // Token::is_upper
    {
      Spacy::Doc doc = nlp.parse("Many BIG apples");
      Spacy::Token many = doc.tokens().at(0);
      Spacy::Token big = doc.tokens().at(1);
      Spacy::Token apples = doc.tokens().at(2);
      unittest::ExpectTrue(!many.is_upper());
      unittest::ExpectTrue(big.is_upper());
      unittest::ExpectTrue(!apples.is_upper());
    }

    // Token::lang_
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token give = doc.tokens().at(0);
      unittest::ExpectEqual(std::string, give.lang_(), "en");
    }

    // Token::lemma_
    {
      Spacy::Doc doc = nlp.parse("I gave it all");
      Spacy::Token gave = doc.tokens().at(1);
      unittest::ExpectEqual(std::string, gave.lemma_(), "give");
    }

    // Token::like_email
    {
      Spacy::Doc doc = nlp.parse("user@example.com apple");
      Spacy::Token emailaddress = doc.tokens().at(0);
      Spacy::Token apple = doc.tokens().at(1);
      unittest::ExpectTrue(emailaddress.like_email());
      unittest::ExpectTrue(!apple.like_email());
    }

    // Token::like_num
    {
      Spacy::Doc doc = nlp.parse("3.14 apple");
      Spacy::Token pi = doc.tokens().at(0);
      Spacy::Token apple = doc.tokens().at(1);
      unittest::ExpectTrue(pi.like_num());
      unittest::ExpectTrue(!apple.like_num());
    }

    // Token::like_url
    {
      Spacy::Doc doc = nlp.parse("http://example.com apple");
      Spacy::Token url = doc.tokens().at(0);
      Spacy::Token apple = doc.tokens().at(1);
      unittest::ExpectTrue(url.like_url());
      unittest::ExpectTrue(!apple.like_url());
    }

    // Token::lower_
    {
      Spacy::Doc doc = nlp.parse("Many BIG apples");
      Spacy::Token many = doc.tokens().at(0);
      Spacy::Token big = doc.tokens().at(1);
      Spacy::Token apples = doc.tokens().at(2);
      unittest::ExpectEqual(std::string, many.lower_(), "many");
      unittest::ExpectEqual(std::string, big.lower_(), "big");
      unittest::ExpectEqual(std::string, apples.lower_(), "apples");
    }

    // Token::nbor
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token token = doc.tokens().at(0).nbor();
      unittest::ExpectEqual(std::string, token.text(), "it");
    }

    // Token::norm_
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token give = doc.tokens().at(0);
      unittest::ExpectEqual(std::string, give.norm_(), "give");
    }

    // Token::orth_
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token give = doc.tokens().at(0);
      Spacy::Token it = doc.tokens().at(1);
      Spacy::Token back = doc.tokens().at(2);
      unittest::ExpectEqual(std::string, give.orth_(), "Give");
      unittest::ExpectEqual(std::string, it.orth_(), "it");
      unittest::ExpectEqual(std::string, back.orth_(), "back");
    }

    // Token::pos_
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token give = doc.tokens().at(0);
      Spacy::Token it = doc.tokens().at(1);
      Spacy::Token back = doc.tokens().at(2);
      unittest::ExpectEqual(std::string, give.pos_(), "VERB");
      unittest::ExpectEqual(std::string, it.pos_(), "PRON");
    }

    // Token::prob
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token give = doc.tokens().at(0);
      Spacy::Token it = doc.tokens().at(1);
      Spacy::Token back = doc.tokens().at(2);
      (void)give.prob();
      (void)it.prob();
      (void)back.prob();
    }

    // Token::rank
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token give = doc.tokens().at(0);
      Spacy::Token it = doc.tokens().at(1);
      Spacy::Token back = doc.tokens().at(2);
      (void)give.rank();
      (void)it.rank();
      (void)back.rank();
    }
    
    // Token::sentiment
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token give = doc.tokens().at(0);
      Spacy::Token it = doc.tokens().at(1);
      Spacy::Token back = doc.tokens().at(2);
      (void)give.sentiment();
      (void)it.sentiment();
      (void)back.sentiment();
    }

    // Token::shape_
    {
      Spacy::Doc doc = nlp.parse("Many BIG cats");
      Spacy::Token many = doc.tokens().at(0);
      Spacy::Token big = doc.tokens().at(1);
      Spacy::Token cats = doc.tokens().at(2);
      unittest::ExpectEqual(std::string, many.shape_(), "Xxxx");
      unittest::ExpectEqual(std::string, big.shape_(), "XXX");
      unittest::ExpectEqual(std::string, cats.shape_(), "xxxx");
    }

    // Token::tag_
    {
      Spacy::Doc doc = nlp.parse("Give it back! He pleaded.");
      Spacy::Token give = doc.tokens().at(0);
      Spacy::Token it = doc.tokens().at(1);
      Spacy::Token back = doc.tokens().at(2);
      unittest::ExpectEqual(std::string, give.tag_(), "VB");
      unittest::ExpectEqual(std::string, it.tag_(), "PRP");
    }

    // Token::text
    {
      Spacy::Token token = nlp.parse("I like apples").tokens().at(2);
      unittest::ExpectEqual(std::string, token.text(), "apples");
    }

    // Token::text_with_ws
    {
      Spacy::Token token = nlp.parse("I like apples").tokens().at(1);
      unittest::ExpectEqual(std::string, token.text_with_ws(), "like ");
    }

    // Token::whitespace_
    {
      Spacy::Token token = nlp.parse("I like apples").tokens().at(1);
      unittest::ExpectEqual(std::string, token.whitespace_(), " ");
    }
  }
  catch(const std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
    rv = 1;
  }

  return rv;
}
