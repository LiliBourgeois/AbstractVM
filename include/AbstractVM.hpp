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
            push, pop, dump, clear, dup, swap, assert, add, sub, mul, div, mod, load, store, print, exit
        };
        static const char *strInstruction[] = {"push", "pop", "dump", "clear", "dup", "swap", "assert", "add", "sub", "mul", "div", "mod", "load", "store", "print", "exit"};

        struct Instruction_t {
            eInstruction instruction;
            std::string *value;
            avm::eOperandType type;
        };
        int AbstractVM(std::string codeAsm);
    }

#endif 