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

    // split a line into multiple sentence and add to vector sentences
    void sentenceSplitter(string &fname, vector<string> &sentences);
}

#endif
