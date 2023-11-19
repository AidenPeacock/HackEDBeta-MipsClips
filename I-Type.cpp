#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "instructions.h"

void lw(Memory& mips, std::string rs, std::string rt, int32_t offset){
    uint32_t addr = offset + mips.regi[rs];
    if (addr%4 != 0){
        return;
    }
    mips.regi[rt] = mips.mem[addr/4];
    mips.pc += 1;

}

void sw(Memory& mips, std::string rs, std::string rt, int32_t offset){
    uint32_t addr = offset + mips.regi[rs];
    if (addr%4 != 0){
        return;
    }
    mips.mem[addr/4] = mips.regi[rt];
    mips.pc += 1;
}

void addi(Memory& mips, std::string rs, std::string rt, int32_t imm){
    mips.regi[rt] = mips.regi[rs] + imm;
    mips.pc += 1;
}