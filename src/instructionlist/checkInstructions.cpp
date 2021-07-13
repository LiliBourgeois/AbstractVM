/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** checkInstructions.cpp
*/

#include <string>
#include <iostream>
#include <sstream>
#include <string.h>

#include "AbstractVM.hpp"

bool CheckSyntacticalError(std::string line, avm::eInstruction enumInstruction, const char *strInstruction[])
{
    size_t instructionSize = strlen(strInstruction[enumInstruction]); //TODO

    if (enumInstruction > 3) {
        std::cout << "line" << line.length() << "\n";
        std::cout << "instruction" << instructionSize << "\n";
        if (line.length() != instructionSize) {
            std::cout << "ça marche\n";
            return false;
        }
    } else if (0 <= enumInstruction && enumInstruction <= 3) {
       return true;
    }
    return true;
}

bool FindInstruction(std::string codeAsm, const char *strInstruction[])
{
    avm::eInstruction enumInstruction = avm::eInstruction(0);
    std::istringstream tmp;
    int foundInstruction = 0;

    tmp.str(codeAsm);
    for (std::string line; std::getline(tmp, line); ) {
        while (enumInstruction < 16) {
            std::cout << "line = " << line << "\n";
            if (!line.empty() && line.find(strInstruction[enumInstruction]) != std::string::npos) {
                foundInstruction = 1;
                std::cout << "enuminstruction :" << enumInstruction << "\n";
                std::cout << "instruction :" << strInstruction[enumInstruction] << "\n\n\n\n";
                if (CheckSyntacticalError(line, enumInstruction, strInstruction) == false) {
                    std::cout << "syntactical error \n";
                    return false;
                }
                enumInstruction = avm::eInstruction(18);
            }
            enumInstruction = avm::eInstruction(enumInstruction + 1);
        }
        if (!line.empty() && foundInstruction == 0) {
                return false;
        }
        foundInstruction = 0;
        enumInstruction = avm::eInstruction(0);
    }
    return true;
}

bool avm::CheckCode(std::string codeAsm)
{
    const char *strInstruction[] = {"push", "assert", "load", "store", "pop", "dump", "clear", "dup", "swap", "add", "sub", "mul", "div", "mod", "print", "exit"};

    if (codeAsm.find("exit") == std::string::npos) {
        std::cout << "no exit\n"; //TODO : check tout
        return false;
    }
    if (!FindInstruction(codeAsm, strInstruction))
        return false;
    return true;
}