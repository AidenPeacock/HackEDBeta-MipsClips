#include <iostream>
#include <vector>
#include <map>
#include <string>

struct Memory{
    std::vector<int32_t> mem;
    std::map<std::string, int32_t> regi;
    int32_t high;
    int32_t low;
    uint32_t pc;
    // Constructor for memory, which sets the size of the memory and initializes registers to 0
    Memory(int var) {
        mem.resize(var);
        regi["$zero"] = 0;
        regi["$at"] = 0;
        regi["$v0"] = 0;
        regi["$v1"] = 0;
        regi["$a0"] = 0;
        regi["$a1"] = 0;
        regi["$a2"] = 0;
        regi["$a3"] = 0;
        regi["$t0"] = 0;
        regi["$t1"] = 0;
        regi["$t2"] = 0;
        regi["$t3"] = 0;
        regi["$t4"] = 0;
        regi["$t5"] = 0;
        regi["$t6"] = 0;
        regi["$t7"] = 0;
        regi["$s0"] = 0;
        regi["$s1"] = 0;
        regi["$s2"] = 0;
        regi["$s3"] = 0;
        regi["$s4"] = 0;
        regi["$s5"] = 0;
        regi["$s6"] = 0;
        regi["$s7"] = 0;
        regi["$t8"] = 0;
        regi["$t9"] = 0;
        regi["$k0"] = 0;
        regi["$k1"] = 0;
        regi["$gp"] = 0;
        regi["$sp"] = 0;
        regi["$fp"] = 0;
        regi["$ra"] = 0;
    }
};

// R-TYPE INSTRUCTIONS
void Xor(Memory& mips, std::string rs, std::string rt, std::string rd){
    mips.regi[rd] = mips.regi[rt]^mips.regi[rs];
    mips.pc += 1;
}


void addu(Memory& mips, std::string rs, std::string rt, std::string rd){
    uint32_t rs1 = (mips.regi[rs]);
    uint32_t rt1 = (mips.regi[rt]);
    mips.regi[rd] = static_cast<uint32_t>(rs1+rt1);
    mips.pc += 1;

}

void add(Memory& mips, std::string rs, std::string rt, std::string rd){
    mips.regi[rd] = mips.regi[rs] + mips.regi[rt];
    mips.pc += 1;
}

void addi(Memory& mips, std::string rs, std::string rt, int32_t imm){
    mips.regi[rt] = mips.regi[rs] + imm;
    mips.pc += 1;
}

void sub(Memory& mips, std::string rs, std::string rt, std::string rd){
    mips.regi[rd] = mips.regi[rs] - mips.regi[rt];
    mips.pc += 1;
}

void subu(Memory& mips, std::string rs, std::string rt, std::string rd){
    uint32_t rs1 = mips.regi[rs];
    uint32_t rt1 = mips.regi[rt];
    mips.regi[rd] = static_cast<uint32_t>(rs1-rt1);
    mips.pc += 1;
}

void And(Memory& mips, std::string rs, std::string rt, std::string rd){
    mips.regi[rd] = mips.regi[rs] & mips.regi[rt];
    mips.pc += 1;
}

void Or(Memory& mips, std::string rs, std::string rt, std::string rd){
    mips.regi[rd] = mips.regi[rs] | mips.regi[rt];
    mips.pc += 1;
}

void mfhi(Memory& mips, std::string rd){
    mips.regi[rd] = mips.high;
    mips.pc += 1;
}

void mflo(Memory& mips, std::string rd){
    mips.regi[rd] = mips.low;
    mips.pc += 1;
}

void mthi(Memory& mips, std::string rs){
    mips.high = mips.regi[rs];
    mips.pc += 1;
}

void mtlo(Memory& mips, std::string rs){
    mips.low = mips.regi[rs];
    mips.pc += 1;
}

void slt(Memory& mips, std::string rs, std::string rt, std::string rd){
    if(mips.regi[rs] < mips.regi[rt]){
        mips.regi[rd] = 1;
    }
    else{
        mips.regi[rd] = 0;
    }
    mips.pc += 1;
}

void sltu(Memory& mips, std::string rs, std::string rt, std::string rd){
    uint32_t rs1 = (mips.regi[rs]);
    uint32_t rt1 = (mips.regi[rt]);
    if (rs1 < rt1){
        mips.regi[rd] = 1;
    }
    else{
        mips.regi[rd] = 0;
    }
    mips.pc += 1;
}

void sll(Memory& mips, std::string rt, uint32_t shamt,std::string rd){
    mips.regi[rd] = mips.regi[rt] << shamt;
    mips.pc += 1;
}

void srl(Memory& mips, std::string rt, uint32_t shamt,std::string rd){
    uint32_t final = static_cast<uint32_t>(mips.regi[rt]);
    mips.regi[rd] = static_cast<uint32_t>(final >> shamt);
    mips.pc += 1;
}

void sra(Memory& mips, std::string rt, uint32_t shamt,std::string rd){
    mips.regi[rd] = (mips.regi[rt] >> shamt);
    mips.pc += 1;
}

void mult(Memory& mips, std::string rs, std::string rt){
    int64_t container1 = mips.regi[rs];
    int64_t container2 = mips.regi[rt];
    int64_t product = container1*container2;
    mips.high = (product >> 32);
    mips.low = (product << 32) >> 32;
    mips.pc += 1;

}

void multu(Memory& mips, std::string rs, std::string rt){
    uint64_t container1 = (uint64_t)mips.regi[rs];
    uint64_t container2 = (uint64_t)mips.regi[rt];
    uint64_t product = container1*container2;
    mips.high = (product >> 32);
    mips.low = (product << 32) >> 32;
    mips.pc += 1;

}

void div(Memory& mips, std::string rt, std::string rs){
    int32_t dividend = mips.regi[rs];
    int32_t divisor = mips.regi[rt];
    if (divisor == 0){
        return;
    }
    mips.high = dividend % divisor;
    mips.low = dividend/divisor;
    mips.pc += 1;
}

void divu(Memory& mips, std::string rt, std::string rs){
    uint32_t dividend = mips.regi[rs];
    uint32_t divisor = mips.regi[rt];
    if (divisor == 0){
        return;
    }
    mips.high = static_cast<uint32_t>(dividend % divisor);
    mips.low = static_cast<uint32_t>(dividend/divisor);
    mips.pc += 1;
}

// I-TYPE INSTRUCTIONS

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


int main(){
    Memory m(0x0FFFFFFF);
    addu(m, "$s0", "$s1", "$s2");
    std::cout << (m.regi["$s2"]) << std::endl;
}
