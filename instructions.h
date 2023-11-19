#include <string>
#include <vector>
#include <map>

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

struct Memory {
    std::vector<int32_t> mem;
    std::map<std::string, int32_t> regi;
    int32_t high;
    int32_t low;
    uint32_t pc;
    Memory(int var);
};
// R-TYPE INSTRUCTIONS
void Xor(Memory& mips, std::string rs, std::string rt, std::string rd);

void addu(Memory& mips, std::string rs, std::string rt, std::string rd);

void add(Memory& mips, std::string rs, std::string rt, std::string rd);

void sub(Memory& mips, std::string rs, std::string rt, std::string rd);

void subu(Memory& mips, std::string rs, std::string rt, std::string rd);

void And(Memory& mips, std::string rs, std::string rt, std::string rd);

void Or(Memory& mips, std::string rs, std::string rt, std::string rd);

void mfhi(Memory& mips, std::string rd);

void mflo(Memory& mips, std::string rd);

void mthi(Memory& mips, std::string rs);

void mtlo(Memory& mips, std::string rs);

void slt(Memory& mips, std::string rs, std::string rt, std::string rd);

void sltu(Memory& mips, std::string rs, std::string rt, std::string rd);

void sll(Memory& mips, std::string rt, uint32_t shamt,std::string rd);

void srl(Memory& mips, std::string rt, uint32_t shamt,std::string rd);

void sra(Memory& mips, std::string rt, uint32_t shamt,std::string rd);

void mult(Memory& mips, std::string rs, std::string rt);

void multu(Memory& mips, std::string rs, std::string rt);

void div(Memory& mips, std::string rs, std::string rt);

void divu(Memory& mips, std::string rs, std::string rt);

// I-TYPE INSTRUCTIONS

void lw(Memory& mips, std::string rs, std::string rt, int32_t offset);

void addi(Memory& mips, std::string rs, std::string rt, int32_t imm);

void sw(Memory& mips, std::string rs, std::string rt, int32_t offset);

#endif