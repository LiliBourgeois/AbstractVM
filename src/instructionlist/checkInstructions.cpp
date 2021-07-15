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

size_t GetTypeSize(std::string value)
{
    if(value.find("int8") != std::string::npos) {
        return 4;
    } else if (value.find("int16") != std::string::npos) {
        return 5;
    } else if (value.find("int32") != std::string::npos) {
        return 5;
    } else if (value.find("float") != std::string::npos) {
        return 5;
    } else if (value.find("double") != std::string::npos) {
        return 6;
    } else if (value.find("bigdecimal") != std::string::npos) {
        return 10;
    }
    return 0;
}

bool CheckTheNb(std::string line, avm::eOperandType type)
{
    size_t i = 0;
    int dotCount = 0;
    int operatorCount = 0;

    while (i < line.length())
    {
        if (line[i] == '.' && dotCount == 0 && i != 0 && type >= 3) {
            dotCount += 1;
        } else if ((line[i] == '+' || line[i] == '-') && operatorCount == 0) {
            operatorCount += 1;
        } else if ((line[i] == '+' || line[i] == '-') && operatorCount > 0) {
            return false;
        } else if (line[i] == '.' && (dotCount > 0 || i == 0 || type < 3)) {
            return false;
        } else {
            if (line[i] < 48 || line[i] > 57) {
                return false;
            }
        }
        i += 1;
    }
    return true;
}

bool CheckSyntacticalError(std::string line, avm::eInstruction enumInstruction, const char *strInstruction[])
{
    size_t instructionSize = strlen(strInstruction[enumInstruction]); 
    size_t typeSize = 0;
    avm::eOperandType type = avm::getType(line);

    if (enumInstruction > 3) {
        if (line.length() != instructionSize) {
            return false;
        }
    } else if (0 <= enumInstruction && enumInstruction <= 3) {
        line.erase(0, instructionSize + 1);
        typeSize = GetTypeSize(line);
        if (typeSize == 0) {
           return false;
        }
        line.erase(0, typeSize);
        if (line[0] != '(' || line.back() != ')') {
            return false;
        }
        line.erase(0, 1);
        line.pop_back();
        if (CheckTheNb(line, type) == false) {
            std::cerr << "error: invalid number\n";
            return false;
        }
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
            if (!line.empty() && line.find(strInstruction[enumInstruction]) != std::string::npos) {
                foundInstruction = 1;
                if (CheckSyntacticalError(line, enumInstruction, strInstruction) == false) {
                    std::cerr << "error: syntactical error\n";
                    return false;
                }
                enumInstruction = avm::eInstruction(18);
            }
            enumInstruction = avm::eInstruction(enumInstruction + 1);
        }
        if (!line.empty() && foundInstruction == 0) {
            std::cerr << "error: wrong instruction\n";
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
        std::cerr << "error: no exit\n";
        return false;
    }
    if (!FindInstruction(codeAsm, strInstruction))
        return false;
    return true;
}