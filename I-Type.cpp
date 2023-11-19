#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "instructions.h"

// C++ equivalent of I-Type MIPS instructions.
void lw(Memory& mips, std::string rs, std::string rt, int32_t offset){
    uint32_t addr = offset + mips.regi[rs];
    if (addr%4 != 0){
        return;
    }
    // Memory is emulated as collection of int32 so addresses must be divided by 4 to
    // access required location
    mips.regi[rt] = mips.mem[addr/4];
    mips.pc += 1;

}

void lb(Memory& mips, std::string rs, std::string rt, int32_t offset){
    uint32_t addr = offset + mips.regi[rs];
    int32_t word = mips.mem[addr/4];
    if (addr%4 == 0){
        // Mips is little endian
        mips.regi[rt] =  (int8_t)((word & 0xFF000000) >> 24);
    }
    if (addr%4 == 1){
        mips.regi[rt] =  (int8_t)((word & 0x00FF0000) >> 16);
    }
    if (addr%4 == 2){
        mips.regi[rt] =  (int8_t)((word & 0x0000FF00) >> 8);
    }
    if (addr%4 == 3){
        mips.regi[rt] =  (int8_t)((word & 0x000000FF));
    }
    mips.pc += 1;

}

void lbu(Memory& mips, std::string rs, std::string rt, int32_t offset){
    uint32_t addr = offset + mips.regi[rs];
    int32_t word = mips.mem[addr/4];
    if (addr%4 == 0){
        mips.regi[rt] =  (u_int8_t)((word & 0xFF000000) >> 24);
    }
    if (addr%4 == 1){
        mips.regi[rt] =  (u_int8_t)((word & 0x00FF0000) >> 16);
    }
    if (addr%4 == 2){
        mips.regi[rt] =  (u_int8_t)((word & 0x0000FF00) >> 8);
    }
    if (addr%4 == 3){
        mips.regi[rt] =  (u_int8_t)((word & 0x000000FF));
    }
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

void addiu(Memory& mips, std::string rs, std::string rt, uint32_t imm){
    mips.regi[rt] = mips.regi[rs] + imm;
    mips.pc += 1;
}

void slti(Memory& mips, std::string rs, std::string rt, int32_t imm){
    mips.regi[rt] = mips.regi[rs] < imm;
    mips.pc += 1;
}

void sltiu(Memory& mips, std::string rs, std::string rt, uint32_t imm){
    mips.regi[rt] = (uint32_t)mips.regi[rs] < imm;
    mips.pc += 1;
}

void andi(Memory& mips, std::string rs, std::string rt, uint32_t imm){
    mips.regi[rt] = mips.regi[rs] & imm;
    mips.pc += 1;
}

void ori(Memory& mips, std::string rs, std::string rt, uint32_t imm){
    mips.regi[rt] = mips.regi[rs] | imm;
    mips.pc += 1;
}

void xori(Memory& mips, std::string rs, std::string rt, uint32_t imm){
    mips.regi[rt] = mips.regi[rs] ^ imm;
    mips.pc += 1;
}

void lui(Memory& mips, std::string rt, int32_t imm){
    mips.regi[rt] = imm << 16;
    mips.pc += 1;
}
