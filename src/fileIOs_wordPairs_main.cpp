#include "fileIOs_wordPairs.h"
//Sample.txt:
/*
This is a sample file.
There are many like it but this one is mine.
This is not just any sample file.
This is my sample file.
*/


void unitTest1() {
    // Test sentenceSplitter
    std::vector<std::string> sentences;
    std::string inputFileName = "sample.txt";
    sentenceSplitter(inputFileName, sentences);

    std::vector<std::string> expectedSentences = {
        "This is a sample file",
        "There are many like it but this one is mine",
        "This is not just any sample file",
        "This is my sample file"
    };
    assert(sentences == expectedSentences);

    // Test getWordList
    std::vector<std::string> words = getWordList(sentences[0]);
    std::vector<std::string> expectedWords = {"This", "is", "a", "sample", "file"};
    assert(words == expectedWords);

    // Test wordpairMapping
    std::map<std::pair<std::string, std::string>, int> wordPairFreqMap;
    wordpairMapping(sentences, wordPairFreqMap);

    std::map<std::pair<std::string, std::string>, int> expectedWordPairFreqMap = {
        {{"This", "is"}, 3},
        {{"is", "a"}, 1},
        {{"a", "sample"}, 1},
        {{"sample", "file"}, 3},
        {{"There", "are"}, 1},
        {{"are", "many"}, 1},
        {{"many", "like"}, 1},
        {{"like", "it"}, 1},
        {{"it", "but"}, 1},
        {{"but", "this"}, 1},
        {{"this", "one"}, 1},
        {{"one", "is"}, 1},
        {{"is", "mine"}, 1},
        {{"is", "not"}, 1},
        {{"not", "just"}, 1},
        {{"just", "any"}, 1},
        {{"any", "sample"}, 1},
        {{"is", "my"}, 1},
        {{"my", "sample"}, 1}
    };
    assert(wordpairFreq_map == expectedWordPairFreqMap);

    // Test freqWordpairMmap
    std::multimap<int, std::pair<std::string, std::string>> freqWordPairMap;
    freqWordpairMmap(wordPairFreqMap, freqWordPairMap);

    std::multimap<int, std::pair<std::string, std::string>> expectedFreqWordPairMap = {
      {1, {"This", "is"}},
      {1, {"is", "a"}},
      {1, {"a", "sample"}},
      {3, {"sample", "file"}},
      {1, {"There", "are"}},
      {1, {"are", "many"}},
      {1, {"many", "like"}},
      {1, {"like", "it"}},
      {1, {"it", "but"}},
      {1, {"but", "this"}},
      {1, {"this", "one"}},
      {1, {"one", "is"}},
      {1, {"is", "mine"}},
      {1, {"is", "not"}},
      {1, {"not", "just"}},
      {1, {"just", "any"}},
      {1, {"any", "sample"}},
      {1, {"is", "my"}},
      {1, {"my", "sample"}}
  };
  assert(freqWordPairMap == expectedFreqWordPairMap);
  printWordList(sentences);
  // Test printWordpairs
  printWordpairs(freqWordPairMap);
}

int main() {
    unitTest1();
    return 0;
}

