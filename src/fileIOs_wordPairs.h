#ifndef FILE_IO_WORDPAIRDS_H_INCLUDE
#define FILE_IO_WORDPAIRDS_H_INCLUDE

#include <iostream>
#include <map>
#include <string>
#include <vector>

void wordpairMapping(std::vector<std::string>& sentences,
                     std::map<std::pair<std::string, std::string>, int>& wordpairFreq_map);

#endif
