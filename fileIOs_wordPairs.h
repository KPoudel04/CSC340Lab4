// header file

#ifndef FILEIOS_WORDSPAIRS_H
#define FILEIOS_WORDSPAIRS_H

#include <vector>
#include <string>

namespace F_WORDSPAIRS
{
    using std::string;
    using std::vector;

    // * function prototype

    // converts a text file with the name fname into a list of sentences
    void sentenceSplitter(string &fname, vector<string> &sentences);
}

#endif
