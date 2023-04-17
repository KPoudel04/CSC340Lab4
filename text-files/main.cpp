/* This program takes 1 file as a command line argument and outputs it's contents to the screen line
 * by line, essentially a cat clone
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: Incorrect number of arguments.  Expecting 2, recieved " << argc << ".\n";
    return(-1);
  }

  std::string file_name = argv[1];
  std::ifstream in_file;
  in_file.open(file_name);

  if (in_file.fail()) {
    std::cerr << "Failed to open the file: " << file_name << std::endl;
    return(-1);
  }

  std::vector<std::string> sentence_vector(0);
  std::string str;
  char ch;

  bool in_quotes = false;

  while (in_file.get(ch)) {
    if (ch == '\n') ch = ' ';
    if (ch == ' ' && str.size() == 0) continue;
    if (ch == '\"' && str.size() == 0) continue;

    if (ch == '.' || ch == '!' || ch == '?') {
      sentence_vector.push_back(str);
      str = "";
    }
    else {
      str += ch;
    }
  }

  for (const std::string& sentence : sentence_vector) {
    std::cout << sentence << std::endl;
  }

  // Close file
  in_file.close();

  return 0;
}
