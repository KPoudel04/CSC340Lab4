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
        string phrase = "";
        int startI = 0;
        string line;
        int count = 0; // number of line read counter

        while (getline(file, line))
        {
            // print the current line
            std::cout << line << "\n";
            count++;

            // Find the position of the first ".", "?", "!", or new line character in the line
            size_t comma_pos = line.find_first_of(".?\"\n");
            int startI = 0;

            // If one of the characters is found
            if (comma_pos != string::npos)
            {
                std::cout << "[EXTRACTING SENTENCE FROM FILEX...]\n";

                phrase = line.substr(startI, comma_pos - startI); /* Extract the sentence from the line and add it to the vector of sentences
                                                                   starting at index startI and ending at the position of the first occurrence of ".", "?", "!"
                                                                   or newline character minus 1
                                                                  */

                sentences.push_back(phrase); // Add the extracted sentence to the vector of sentences

                startI = comma_pos + 1; /* Update startI to be the position of the first occurrence of ".", "?", "!"
                                         or newline character plus 1
                                         so that the next extracted sentence will start at the correct position
                                        */

                comma_pos = line.find_first_of(".?\"\n", startI); // Find the position of the next delimiter/ newline character, starting at index startI
            }
            else // If none of the characters is found
            {
                std::cout << "[NO MATCH FOUND]\n";

                // Extract the sentence from the line and add it to the vector of sentences
                phrase = line.substr(startI);
                sentences.push_back(phrase);
            }
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
