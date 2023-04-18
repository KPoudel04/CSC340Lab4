#ifndef FILE_IO_WORDPAIRS_CPP_INCLUDE
#define FILE_IO_WORDPAIRS_CPP_INCLUDE

#include "fileIOs_wordPairs.h"

// * function implementation
void sentenceSplitter(std::string &fname, std::vector<std::string> &sentences)
{
  std::ifstream file(fname);

  // * check if the file is successfully opened or not
  if (!file.is_open())
  {
    if (file.fail()) // check the most recent input/output on the stream failed
    {
      /* Various reasons can explained fail()
         -> reaching the end of the file
         -> encountering an invalid input
         -> an error in the underlying system
         */
      std::cout << "Failed to open file\n";
    }

    if (file.bad()) // check a non-recoverabl (severe) error on the stream
    {

      /* Various reasons can explained bad()
         -> error in the underlying file system
         -> error in the I/O device
         */
      std::cout << "Bad file operation\n";
    }

    std::cerr << "Unable to open file: " << fname << "\n";
    return void();
    // return 1 (needs to be changed since void can't return a value)
  }
  else
  {
    std::cout << "File opened successfully.\n";
  }

  // * add each line of the file to line
  std::string line;
  while (std::getline(file, line)) // Read each line from the file until there is no more line to read
  {
    // std::cout << "Line read : \n";
    // std::cout << line << "\n";

    // Check if the line is empty or contains only whitespace characters
    if (line.empty() || line.find_first_not_of(" \t") == std::string::npos)
    {
      // std::cout << "SKIP EMPTY LINE\n";
      continue; // skip to the next line
    }

    // // Check if the line ends with a colon character
    // while (line.back() == ':')
    // {
    //   std::string nextLine;
    //   if (!std::getline(file, nextLine)) // checks if there are any more lines to read from the
    //                                 // file. If not, the loop is exited.
    //   {
    //     break;
    //   }
    //   line += nextLine; // appends the next line to the current line
    // }

    // cout << "\nLine to be append to the sentenceSplitter function :\n "
    //      << line << "\n";

    // F_WORDSPAIRS::sentenceSplitter(line, sentences); // * Split the line into sentences and append them to the sentences vector

    std::string phrase = "";
    unsigned int startI = 0;

    // loop through every character of the input line
    while (startI < line.length())
    {
      // find the position of the first occurrence of a period, question mark, or newline
      // character
      size_t newline_pos = line.find_first_of(".?\n", startI);

      // if the end of the line has been reached, set the newline position to the end of the
      // line
      if (newline_pos == std::string::npos)
      {
        newline_pos = line.length();
      }

      // check if the next character after the newline is a double quotation mark
      if ((newline_pos + 1) < line.length() && line.at(newline_pos + 1) == '\"')
      {
        // if it is, append the current phrase and the next character (double quotation
        // mark) to the sentences vector
        phrase = line.substr(startI, newline_pos + 1 - startI);
        sentences.push_back(phrase);
        startI = newline_pos + 2; // set the starting index of the next sentence to the
                                  // character after the double quotation mark
        continue;
      }

      // if the next character after the newline is not a double quotation mark, append the
      // current phrase to the sentences vector
      phrase = line.substr(startI, newline_pos - startI);
      sentences.push_back(phrase);
      startI = newline_pos + 1; // set the starting index of the next sentence to the
                                // character after the period or question mark

    } // end of while(getline(file, line))
  }

  file.close(); // closes the file at end of sentenceSplitter
}

std::vector<std::string> getWordList(const std::string &sentence)
{
  char ch;                                  // Holds the current character
  std::string word = "";                    // Holds the current word
  std::vector<std::string> sentenceList(0); // Holds list of words
                                            //
  for (unsigned int i = 0; i < sentence.size(); i++)
  {
    ch = std::tolower(sentence.at(i)); // Tokens are case insensitive

    // Tokens can be seperated by end of sentence characters, spaces, or newlines
    if (ch == '!' || ch == '.' || ch == '?')
    {
      sentenceList.push_back(word);
      word = "";
    }
    else if (ch == ' ' || ch == '\n')
    {
      // If there isn't already characters in string word, we can ignore the current space or newline
      if (word.size() != 0)
      {
        sentenceList.push_back(word);
        word = "";
      }
    } // Append all other characters to the current token
    else
    {
      word += ch;
    }
    // Ensure last token gets added to sentence list
    if (i == sentence.size() - 1 && word.size() != 0)
    {
      sentenceList.push_back(word);
      word = "";
    }
  }

  return sentenceList;
}

void wordpairMapping(std::vector<std::string> &sentences,
                     std::map<std::pair<std::string, std::string>, int> &wordpairFreq_map)
{

  std::vector<std::string> wordList(0);
  std::pair<std::string, std::string> wordPair;
  std::string w1, w2; // Word 1 and word 2

  for (unsigned int s = 0; s < sentences.size(); s++)
  {
    if (sentences.at(s).size() != 0)
    { // Ignore all empty sentences
      wordList = getWordList(sentences.at(s));

      for (unsigned int i = 0; i < wordList.size() - 1; i++)
      {
        w1 = wordList.at(i);

        for (unsigned int j = i + 1; j < wordList.size(); j++)
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

          // Increment the word-pair frequency if it already exists, else create it
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

void freqWordpairMmap(std::map<std::pair<std::string, std::string>, int> &wordpairFreq_map,
                      std::multimap<int, std::pair<std::string, std::string>> &freqWordpair_mmap)
{

  for (const auto &wp : wordpairFreq_map)
  {
    std::pair<int, std::pair<std::string, std::string>> freqWpPair = {wp.second, wp.first};
    freqWordpair_mmap.insert(freqWpPair);
  }
}

void printWordpairs(std::multimap<int, std::pair<std::string, std::string>> &freqWordpair_multimap,
                    std::string outFname, int topCnt, int botCnt)
{

  std::ofstream ofile(outFname);
  if (!ofile)
  {
    std::cerr << "ERROR: Could not create/open file " << outFname << std::endl;
    return;
  }

  std::pair<std::string, std::string> wordpair;

  std::multimap<int, std::pair<std::string, std::string>>::iterator itr;
  for (itr = freqWordpair_multimap.begin();
       itr != std::next(freqWordpair_multimap.begin(), topCnt);
       itr++)
  {
    // TO-DO: Output topCnt most frequent word-pairs here
    wordpair = itr->second;
    ofile << "<" << wordpair.first << ", " << wordpair.second << ">: " << itr->first << std::endl;
  }

  std::multimap<int, std::pair<std::string, std::string>>::reverse_iterator itr_reverse;
  for (itr_reverse = freqWordpair_multimap.rbegin();
       itr_reverse != std::next(freqWordpair_multimap.rbegin(), botCnt);
       itr_reverse++)
  {
    // TO-DO: Output botCnt least frequent word-pairs here
    wordpair = itr_reverse->second;
    ofile << "<" << wordpair.first << ", " << wordpair.second << ">: " << itr_reverse->first
          << std::endl;
  }

  ofile.close();
}

void printWordList(const std::vector<std::string> &sentence_vector)
{
  if (sentence_vector.size() == 0)
    return;

  std::vector<std::string> wl;
  for (const auto &s : sentence_vector)
  {
    if (s.size() != 0)
    {
      wl = getWordList(s);

      for (const std::string &w : wl)
      {
        std::cout << w << std::endl;
      }
    }
  }
}

void printWordpairMap(const std::map<std::pair<std::string, std::string>, int> &wp_map)
{
  if (wp_map.size() == 0)
    return;

  std::pair<std::string, std::string> currWp;
  for (const auto &wp : wp_map)
  {
    currWp = wp.first;
    std::cout << "[" << currWp.first << ", " << currWp.second << "]: " << wp.second
              << std::endl;
  }
}

#endif
