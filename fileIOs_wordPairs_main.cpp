#include <iostream> //
#include <iomanip>
#include <string>
#include <fstream>

#include "fileIOs_wordPairs.h"

using namespace std;

int main()
{
    vector<string> sentences;
    string fname = "SteveJobsSpeech2005.txt";
    F_WORDSPAIRS::sentenceSplitter(fname, sentences);
    
    return 0;
}