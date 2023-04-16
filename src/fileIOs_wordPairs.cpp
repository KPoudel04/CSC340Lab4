
#ifndef FILE_IO_WORDPAIRS_CPP_INCLUDE
#define FILE_IO_WORDPAIRS_CPP_INCLUDE

#include "fileIOs_wordPairs.h"

std::vector<std::string> getWordList(const std::string& sentence) {
  char ch;                               // Holds the current character
  std::string word = "";                 // Holds the current word
  std::vector<std::string> sentenceList(0); // Holds list of words

  for (int i = 0; i < sentence.size(); i++) {
    ch = std::tolower(sentence.at(i));
    
    if (ch == '!' || ch == '.' || ch == '?') { 
      sentenceList.push_back(word);
      word = "";
    }
    else if(ch == ' ' || ch == '\n') {
      if (word.size() != 0) {
        sentenceList.push_back(word);
        word = "";
      }
    }
    else {
      word += ch;
    }

    if (i == sentence.size() - 1 && word.size() != 0) {
        sentenceList.push_back(word);
        word = "";
    }
  }

  return sentenceList;
}

void wordpairMapping(std::vector<std::string>& sentences,
  std::map<std::pair<std::string, std::string>, int>& wordpairFreq_map) {
  
  std::vector<std::string> wordList(0);
  std::pair<std::string, std::string> wordPair;
  std::string w1, w2;

  for (int s = 0; s < sentences.size(); s++) {
    if (sentences.at(s).size() != 0) {
        wordList = getWordList(sentences.at(s));

        for (int i = 0; i < wordList.size() - 1; i++)
        {
        w1 = wordList.at(i);

        for (int j = i + 1; j < wordList.size(); j++)
        {
          w2 = wordList.at(j);

          // Input words into worpairs by alphabetical order
          if (w1 < w2)
          {
            wordPair.first = w1;
            wordPair.second = w2;
          }
          else
          {
            wordPair.first = w2;
            wordPair.second = w1;
          }

          if (wordpairFreq_map.find(wordPair) != wordpairFreq_map.end())
          {
            wordpairFreq_map[wordPair]++;
          }
          else
          {
            wordpairFreq_map[wordPair] = 1;
          }
        }
      }
    }
  }
}

void printWordList(const std::vector<std::string>& sentence_vector) {
  if (sentence_vector.size() == 0) return;

  std::vector<std::string> wl;
  for (const auto& s : sentence_vector) {
    if (s.size() != 0) {
      wl = getWordList(s);

      for (const std::string &w : wl)
      {
        std::cout << w << std::endl;
      }
    }
  }
}

void printWordpairMap(const std::map<std::pair<std::string, std::string>, int>& wp_map) {
  if (wp_map.size() == 0) return;

  std::pair<std::string, std::string> currWp;
  for (const auto& wp : wp_map) {
    currWp = wp.first;
    std::cout << "[" << currWp.first << ", " << currWp.second << "]: " << wp.second
    << std::endl;
  }
}

void freqWordpair(const std::string& filename) {
  std::ifstream infile(filename);
  if (!infile.good()) {
    std::cerr << "Error opening file " << filename << std::endl;
    return;
  }

  std::string line;
  std::vector<std::string> sentences;

  // Read lines from file and add to vector of sentences
  while (std::getline(infile, line)) {
    sentences.push_back(line);
  }

  infile.close();

  std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;

  // Map word pairs and their frequencies
  wordpairMapping(sentences, wordpairFreq_map);

  // Print word pair frequency map
  printWordpairMap(wordpairFreq_map);
}



#endif