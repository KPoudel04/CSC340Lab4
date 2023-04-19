#ifndef FILE_IO_WORDPAIRDS_H_INCLUDE
#define FILE_IO_WORDPAIRDS_H_INCLUDE

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// This function converts a text file with the name fname into a list of sentences.  The list of
// sentences will be stored in the sentences vector in the same order as it appears in the input file.
void sentenceSplitter(std::string& fname, std::vector<std::string>& sentence);

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

// This function flips the wordpairFreq_map such that the frequencies will be the keys and word-pairs
// will be the values
void freqWordpairMmap(std::map<std::pair<std::string, std::string>, int>& wordpairFreq_map,
  std::multimap<int, std::pair<std::string, std::string>>& freqWordpair_mmap);

// This function writes the topCnt most frequent word-pairs and the botCnt least frequent word-pairs
// to a file of the name outFname
void printWordpairs(std::multimap<int, std::pair<std::string, std::string>>& freqWordpair_multimap,
  std::string outFname, int topCnt, int botCnt);

void printWordList(const std::vector<std::string>& wl);
void printWordpairMap(const std::map<std::pair<std::string, std::string>, int>& wp_map);

#endif
