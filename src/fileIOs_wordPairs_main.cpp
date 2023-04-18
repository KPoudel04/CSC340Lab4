#include "fileIOs_wordPairs.h"

int main() {
  std::multimap<int, std::pair<std::string, std::string>> wordpair_mm;

  std::string word1 = "hello";
  std::string word2 = "world";

  int freq = 3;

  std::pair<std::string, std::string> wordpair;
  wordpair.first = word1;
  wordpair.second = word2;

  std::pair<int, std::pair<std::string, std::string>> pair_mm = {freq, wordpair};

  wordpair_mm.insert(pair_mm);

  word1 = "good";
  word2 = "bye";
  wordpair.first = word1;
  wordpair.second = word2;

  pair_mm = {freq, wordpair};
  wordpair_mm.insert(pair_mm);

  printWordpairs(wordpair_mm, "test.txt", 1, 1);

  return 0;
}
