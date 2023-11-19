#include "runInstruction.h"

// Determines which instruction to run based on the string (the first element in the vector).
// The function is then called using the appropriate parameters found in the rest of the vector.
// The memory struct and the vector of parameters are used as input parameters for the function.
// There is no return value, since the function already does everything that is needed.
void executeInstruction(Memory& mips, std::vector<std::string> instruction) {
    if (instruction[0] == "xor") {
        Xor(mips, instruction[2], instruction[3], instruction[1]);

    } else if (instruction[0] == "addu") {
        addu(mips, instruction[2], instruction[3], instruction[1]);

    } else if (instruction[0] == "add") {
        add(mips, instruction[2], instruction[3], instruction[1]);

    } else if (instruction[0] == "sub") {
        sub(mips, instruction[2], instruction[3], instruction[1]);

    } else if (instruction[0] == "subu") {
        subu(mips, instruction[2], instruction[3], instruction[1]);

    } else if (instruction[0] == "and") {
        And(mips, instruction[2], instruction[3], instruction[1]);

    } else if (instruction[0] == "or") {
        Or(mips, instruction[2], instruction[3], instruction[1]);

    } else if (instruction[0] == "mfhi") {
        mfhi(mips, instruction[1]);

    } else if (instruction[0] == "mflo") {
        mflo(mips, instruction[1]);

    } else if (instruction[0] == "mthi") {
        mthi(mips, instruction[1]);

    } else if (instruction[0] == "mtlo") {
        mtlo(mips, instruction[1]);

    } else if (instruction[0] == "slt") {
        slt(mips, instruction[2], instruction[3], instruction[1]);

    } else if (instruction[0] == "sltu") {
        sltu(mips, instruction[2], instruction[3], instruction[1]);

    } else if (instruction[0] == "sll") {
        sll(mips, instruction[2], (uint32_t) stoi(instruction[3]), instruction[1]);

    } else if (instruction[0] == "srl") {
        srl(mips, instruction[2], (uint32_t) stoi(instruction[3]), instruction[1]);

    } else if (instruction[0] == "sra") {
        sra(mips, instruction[2], (uint32_t) stoi(instruction[3]), instruction[1]);

    } else if (instruction[0] == "mult") {
        mult(mips, instruction[1], instruction[2]);

    } else if (instruction[0] == "multu") {
        multu(mips, instruction[1], instruction[2]);

    } else if (instruction[0] == "div") {
        div(mips, instruction[1], instruction[2]);

    } else if (instruction[0] == "divu") {
        divu(mips, instruction[1], instruction[2]);

    } else if (instruction[0] == "lw") {
        lw(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "lb") {
        lb(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "lbu") {
        lbu(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "sw") {
        sw(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "addi") {
        addi(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "addiu") {
        addiu(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "slti") {
        slti(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "sltiu") {
        sltiu(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "andi") {
        andi(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "ori") {
        ori(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "xori") {
        xori(mips, instruction[2], instruction[1], (int32_t) stoi(instruction[3]));

    } else if (instruction[0] == "lui") {
        lui(mips, instruction[1], (int32_t) stoi(instruction[2]));

    }
}