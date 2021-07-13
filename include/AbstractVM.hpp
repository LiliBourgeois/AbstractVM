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
            PUSH, POP, DUMP, CLEAR, DUP, SWAP, ASSERT, ADD, SUB, MUL, DIV, MOD, LOAD, STORE, PRINT, EXIT
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