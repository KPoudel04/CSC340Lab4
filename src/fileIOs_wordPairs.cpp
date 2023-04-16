#ifndef FILE_IO_WORDPAIRS_CPP_INCLUDE
#define FILE_IO_WORDPAIRS_CPP_INCLUDE

#include "fileIOs_wordPairs.h"

std::vector<std::string> getWordList(const std::string& sentence) {
  char ch;                               // Holds the current character
  std::string word = "";                 // Holds the current word
  std::vector<std::string> sentenceList; // Holds list of words

  for (int i = 0; i < sentence.size(); i++) {
    ch = std::tolower(sentence.at(i));
    
    // Words may only contain alphabetic characters or a hyphen
    if (std::isalpha(ch)) {
      word += ch;
    }    
    else if (ch == '-') {
      word += ch;
    }
    // End word and add to vector at space or newline
    else if (ch == ' ' || ch == '\n' || ch == '!' || ch == '.' ||
             ch == '?') { 
      sentenceList.push_back(word);
      word = "";
    }
  }

  return sentenceList;
}

void wordpairMapping(std::vector<std::string>& sentences,
  std::map<std::pair<std::string, std::string>, int>& wordpairFreq_map) {
  
  std::vector<std::string> wordList;
  std::pair<std::string, std::string> wordPair;
  std::string w1, w2;

  for (int s = 0; s < sentences.size(); s++) {
    wordList = getWordList(sentences.at(s));

    for (int i = 0; i < wordList.size() - 1; i++) {
      w1 = wordList.at(i);

      for (int j = i + 1; j < wordList.size(); j++) {
        w2 = wordList.at(j);

        // Input words into worpairs by alphabetical order
        if (w1 < w2) {
          wordPair.first = w1;
          wordPair.second = w2;
        }
        else {
          wordPair.first = w2;
          wordPair.second = w1;
        }

        if (wordpairFreq_map.find(wordPair) != wordpairFreq_map.end()) {
          wordpairFreq_map[wordPair]++;
        }
        else {
          wordpairFreq_map[wordPair] = 1; 
        }
      }
    }
  }
}

#endif
