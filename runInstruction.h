#ifndef RUNINSTRUCTION_H
#define RUNINSTRUCTION_H

#include <vector>
#include <string>
#include "instructions.h"

bool executeInstruction(Memory &mips, std::vector<std::string> instruction);

#endif