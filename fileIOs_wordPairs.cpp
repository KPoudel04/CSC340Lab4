#include <iostream> 
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

#include "fileIOs_wordPairs.h"

namespace F_WORDSPAIRS
{
    using std::ifstream;
    using std::string;
    using std::vector;

    // * function implementation
    void sentenceSplitter(string &fname, vector<string> &sentences) // ? fname should be renamed line as it takes a line and split at each delimiters
    {
    ifstream file(fname);

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
            //return 1 (needs to be changed since void can't return a value)
        }
        else
        {
            std::cout << "File opened successfully.\n";
        }

    
        // * add each line of the file to line 
        string line;
        while (getline(file, line)) // Read each line from the file until there is no more line to read
        {
            // std::cout << "Line read : \n";
            // std::cout << line << "\n";

            // Check if the line is empty or contains only whitespace characters
            if (line.empty() || line.find_first_not_of(" \t") == string::npos)
            {
                // std::cout << "SKIP EMPTY LINE\n";
                continue; // skip to the next line
            }

            // Check if the line ends with a colon character
            while (line.back() == ':')
            {
                string nextLine;
                if (!getline(file, nextLine)) // checks if there are any more lines to read from the file. If not, the loop is exited.
                {
                    break;
                }
                line += nextLine; // appends the next line to the current line
            }

            // cout << "\nLine to be append to the sentenceSplitter function :\n "
            //      << line << "\n";

            //F_WORDSPAIRS::sentenceSplitter(line, sentences); // * Split the line into sentences and append them to the sentences vector
            
            string phrase = "";
            int startI = 0;

            // loop through every character of the input line
            while (startI < line.length())
            {
                // find the position of the first occurrence of a period, question mark, or newline character
                size_t newline_pos = line.find_first_of(".?\n", startI);

                // if the end of the line has been reached, set the newline position to the end of the line
                if (newline_pos == string::npos)
                {
                    newline_pos = line.length();
                }

                // check if the next character after the newline is a double quotation mark
                if ((newline_pos + 1) < line.length() && line.at(newline_pos + 1) == '\"')
                {
                    // if it is, append the current phrase and the next character (double quotation mark) to the sentences vector
                    phrase = line.substr(startI, newline_pos + 1 - startI);
                    sentences.push_back(phrase);
                    startI = newline_pos + 2; // set the starting index of the next sentence to the character after the double quotation mark
                    continue;
                }

                // if the next character after the newline is not a double quotation mark, append the current phrase to the sentences vector
                phrase = line.substr(startI, newline_pos - startI);
                sentences.push_back(phrase);
                startI = newline_pos + 1; // set the starting index of the next sentence to the character after the period or question mark
                 
            }//end of while(getline(file, line))
        }

        /*
        // * print vector containing every line splitted from file fname
        for (auto sentence : sentences)
        {
        std::cout << sentence << "\n";
        }
        */

        file.close(); //closes the file at end of sentenceSplitter
    }

}
