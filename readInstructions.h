#ifndef READINSTRUCTIONS_H
#define READINSTRUCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

std::vector<std::string> parseLine(std::string &line);

std::vector<std::vector<std::string> > readProg(std::string filename);

#endif
