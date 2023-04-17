#include <iostream> //
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

#include "fileIOS_wordPairs.h"

namespace F_WORDSPAIRS
{
    using std::ifstream;
    using std::string;
    using std::vector;

    // * function implementation
    void sentenceSplitter(string &fname, vector<string> &sentences) // ? fname should be renamed line as it takes a line and split at each delimiters
    {
        string phrase = "";
        int startI = 0;

        // loop through every character of the input fname
        while (startI < fname.length())
        {
            // find the position of the first occurrence of a period, question mark, or newline character
            size_t newline_pos = fname.find_first_of(".?\n", startI);

            // if the end of the fname has been reached, set the newline position to the end of the fname
            if (newline_pos == string::npos)
            {
                newline_pos = fname.length();
            }

            // check if the next character after the newline is a double quotation mark
            if ((newline_pos + 1) < fname.length() && fname.at(newline_pos + 1) == '\"')
            {
                // if it is, append the current phrase and the next character (double quotation mark) to the sentences vector
                phrase = fname.substr(startI, newline_pos + 1 - startI);
                sentences.push_back(phrase);
                startI = newline_pos + 2; // set the starting index of the next sentence to the character after the double quotation mark
                continue;
            }

            // if the next character after the newline is not a double quotation mark, append the current phrase to the sentences vector
            phrase = fname.substr(startI, newline_pos - startI);
            sentences.push_back(phrase);
            startI = newline_pos + 1; // set the starting index of the next sentence to the character after the period or question mark
        }
    }

}
