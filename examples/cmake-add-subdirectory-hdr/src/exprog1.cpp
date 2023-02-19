#include <iostream>
#include <vector>

#define SPACY_HEADER_ONLY
#include <spacy/spacy>

int main()
{
  Spacy::Spacy spacy;
  auto nlp = spacy.load("en_core_web_sm");
  auto doc = nlp.parse("This is a sentence.");
  for (auto& token : doc.tokens())
  {
    std::cout << token.text() << " [" << token.pos_() << "]\n";
  }
}
