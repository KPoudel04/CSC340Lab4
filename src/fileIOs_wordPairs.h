
#ifndef FILE_IO_WORDPAIRDS_H_INCLUDE
#define FILE_IO_WORDPAIRDS_H_INCLUDE

#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// Takes a sentence stored in string sentence and returns a vector of all the words in
// the sentence
std::vector<std::string> getWordList(const std::string& sentence);

// Given a list of sentences stored in the first argument sentences, this function
// identifies all the unique word-pairs and each word-pairs' frequency.  The identified
// (word-pair, frequency)'s will be stored into wordpairFreq_map which is a map of (key, 
// value) pairs.  The key of this map a word-pair and the value is the frequency of this
// word-pair.
void wordpairMapping(std::vector<std::string>& sentences,
  std::map<std::pair<std::string, std::string>, int>& wordpairFreq_map);

void printWordList(const std::vector<std::string>& wl);
void printWordpairMap(const std::map<std::pair<std::string, std::string>, int>& wp_map);


void freqWordpair(const std::string& filename);
// }

#endif




