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
    void sentenceSplitter(string &fname, vector<string> &sentences)
    {
        ifstream file(fname); // open the specified file for input

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

            if (file.bad()) // check a non-recoverable (severe) error on the stream
            {

                /* Various reasons can explained bad()
                 -> error in the underlying file system
                 -> error in the I/O device
                */
                std::cout << "Bad file operation\n";
            }

            std::cerr << "Unable to open file: " << fname << "\n";
            // return 1; // TODO: to exit the function if file cannot be open
        }
        else
        {
            std::cout << "File opened successfully.\n";
        }

        // * read from file + extraction sentence
        int count = 0; // number of line read counter
        string line, sentence;
        while (getline(file, line)) {
            count++;

            //Splits the line into sentences based on the delimiters
            size_t pos = 0, end;
            while ((end = line.find_first_of(".?\"", pos)) != string::npos) {
                //quotation marks, doesn't seem to work i think
                if (line[end] == '"' && end < line.length() - 1) {
                    if (line[end + 1] == '.' || line[end + 1] == '?') {
                        end++;
                    }
                }
                //question marks
                if (line[end] == '?' && end < line.length() - 1) {
                    
                    if (line[end + 1] == '"') {
                        end++;
                    }
                }
                sentence += line.substr(pos, end - pos + 1);
                sentences.push_back(sentence);
                sentence.clear();
                pos = end + 1;
            }
            sentence += line.substr(pos) + " ";
        }

        // Add the last sentence to the vector, if not empty
        if (!sentence.empty()) {
            sentences.push_back(sentence);
        }  

        // print all vector data
        for (auto sentence : sentences)
        {
            std::cout << sentence << "\n";
        }

        // * all file data read checking
        if (file.eof() && count > 0)
        {
            /* count provides accurate verification of eof() to check,
            -> if there are blank lines
            -> other extraneous content at the end of the file
            */
            std::cout << "Every input of the file have been read\n";
        }
        else
        {
            std::cout << "NOT Every input of the file have been read\n";
        }

        file.close(); // close the file
    }

}
