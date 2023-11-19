#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "instructions.h"


Memory::Memory(int var)
{
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

int main(){
    Memory m(0x0FFFFFFF);
    m.regi["$s1"] = 1;
    addu(m, "$s0", "$s1", "$s2");
    std::cout << (m.regi["$s2"]) << std::endl;
    std::cout << "Registers:" << std::endl;
    for(auto pair : m.regi)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
}
