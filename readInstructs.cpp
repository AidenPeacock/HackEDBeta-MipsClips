#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

std::vector<std::string> parseLine(std::string &line) {
    std::vector<std::string> params;
    
    if ((line.find("(") != std::string::npos) && line.find(")") != std::string::npos) {
        // For load/store instructions

        // Get instruction
        std::string instruction = line.substr(0, line.find(" "));
        params.push_back(instruction);
        line.erase(0, line.find(" ") + 1);

        // Get rt
        std::string rt = line.substr(0, line.find(","));
        params.push_back(rt);
        line.erase(0, line.find(" ") + 1);

        // Get offset
        std::string offset = line.substr(0, line.find("("));
        params.push_back(offset);
        line.erase(0, line.find("(") + 1);
        
        // Get rs
        std::string rs = line.substr(0, line.find(")"));
        params.push_back(rs);
        
        // Swap rs and offset
        std::string swap = params[2];
        params[2] = params[3];
        params[3] = swap;
    } else {
        // For all other instructions

        // Remove all commas from the line
        line.erase(remove(line.begin(), line.end(), ','), line.end());

        while (line.find(" ") != std::string::npos) {
            params.push_back(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);
        }
        params.push_back(line);
    }

    return params;
}

// Read each line of the MIPS program from a file.
std::vector<std::vector<std::string> > readProg(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::vector<std::string> > instructions;

    if (file.is_open()) {
        while (getline(file, line)) {
            instructions.push_back(parseLine(line));
        }
    }

    return instructions;
}

int main() {

    // Test code
    // std::vector<std::vector<std::string> > instructions = readProg("test.txt");

    // for (int i = 0; i < instructions.size(); i++) {
    //     for (int j = 0; j < instructions[i].size(); j++) {
    //         std::cout << instructions[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}