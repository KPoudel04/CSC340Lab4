#include <iostream> //
#include <iomanip>
#include <string>

#include "fileIOS_wordPairs.h"

using namespace std;

int main()
{
    string fname = "SteveJobsSpeech2005.txt";
    vector<string> vectorTest;
    F_WORDSPAIRS::sentenceSplitter(fname, vectorTest);

    return 0;
}