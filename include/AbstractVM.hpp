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
        static const char *strInstruction[] = {"push", "pop", "dump", "clear", "dup", "swap", "assert", "add", "sub", "mul", "div", "mod", "load", "store", "print", "exit"};

        struct Instruction_t {
            eInstruction instruction;
            avm::IOperand *value;
        };
        int AbstractVM(std::string codeAsm);
    }

#endif 