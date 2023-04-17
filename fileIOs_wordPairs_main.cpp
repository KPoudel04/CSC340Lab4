#include <iostream> //
#include <iomanip>
#include <string>
#include <fstream>

#include "fileIOS_wordPairs.h"

using namespace std;

int main()
{
    vector<string> sentences;
    string fname = "SteveJobsSpeech2005.txt";
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

        cerr << "Unable to open file: " << fname << "\n";
        return 1;
    }
    else
    {
        std::cout << "File opened successfully.\n";
    }

    // * add each line of the file to line + call sentenceSplitter
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

        F_WORDSPAIRS::sentenceSplitter(line, sentences); // * Split the line into sentences and append them to the sentences vector
    }

    // * print vector containing every line splitted from file fname
    for (auto sentence : sentences)
    {
        cout << sentence << "\n";
    }

    file.close(); // close the file

    return 0;
}