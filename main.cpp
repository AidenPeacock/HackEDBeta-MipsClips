#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "instructions.h"

// Initializes memory contents
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

// Displays a help message for the user
void help()
{
    std::cout << "Enter one of the following keys..." << std::endl;
    std::cout << "n: Execute next instruction" << std::endl;  
    std::cout << "i: Displays the next instruction to be executed" << std::endl;  
    std::cout << "m <address>: Displays the word at that memory address" << std::endl;    
    std::cout << "h: Displays this help message again" << std::endl;
    std::cout << "e: Exit the program" << std::endl;
}

int main()
{
    Memory m(0x0FFFFFFF);
    std::cout << "Welcome to the MIPS Debugger." << std::endl;
    help();
    std::string s;
    std::cin >> s;
    while (s != "e")
    {
        if (s == "n")
        {
            // For testing
            m.regi["$s1"] = 1;
            m.regi["$s0"] = 10;

            // Fetch and execute next instruction
            addu(m, "$s0", "$s1", "$s2");
            std::cout << "Executed Instruction: ";
            std::cout << "addu $s2, $s0, $s1" << std::endl;

            std::cout << "Registers:" << std::endl;
            int column = 0;
            // Display registers in 8 rows of 4 columns
            for (std::map<std::string, int>::iterator i = m.regi.begin(); i != m.regi.end(); i++)
            {               
                std::cout << i->first << ": " << i->second << " ";
                column++;               
                if (column == 4)
                {
                     // Start a new row
                     std::cout << std::endl;
                    column = 0;                    
                } 
            }
        }
        else if (s == "i")
        {
           std::cout << "addu $s2, $s0, $s1" << std::endl;
        }
        else if(s == "h")
        {
            help();
        }
        else if (s == "m")
        {
            int i;
            std::cin >> i;
            std::cout << m.mem[i/4] << std::endl;
        }
        std::cin >> s;
    }
}
