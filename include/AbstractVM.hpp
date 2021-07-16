/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** AbstractVM.hpp
*/

#ifndef ABSTRACT_VM_HPP_
    #define ABSTRACT_VM_HPP_

    #include "IOperand.hpp"
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>

    namespace avm {

        enum eInstruction {
            PUSH, ASSERT, LOAD, STORE, POP, DUMP, CLEAR, DUP, SWAP, ADD, SUB, MUL, DIV, MOD, PRINT, EXIT, UNKNOWN_INSTRUCTION
        };
 
        struct Instruction_t {
            eInstruction i;
            avm::IOperand *value;
        };

        std::string GetRidOfComment(std::string codeAsm);
        int AbstractVM(std::string codeAsm);
        int AbstractVMCore(std::vector<Instruction_t *> &iList);
        bool CheckCode(std::string codeAsm);
        void getTab(std::string codeAsm, std::vector<Instruction_t *> &iList);
    }


#endif 