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

    namespace avm {

        enum eInstruction {
            PUSH, ASSERT, LOAD, STORE, POP, DUMP, CLEAR, DUP, SWAP, ADD, SUB, MUL, DIV, MOD, PRINT, EXIT
        };
 
        struct Instruction_t {
            eInstruction instruction;
            avm::IOperand *value;
            struct Instruction_t *next;
            struct Instruction_t *prev; 
        };
        int AbstractVM(std::string codeAsm);
    }

    avm::Instruction_t *getTab(std::string codeAsm);
    bool CheckCode(std::string codeAsm);

#endif 