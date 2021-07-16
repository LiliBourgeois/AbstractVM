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
#include <algorithm>

#include "AbstractVM.hpp"
#include "Instruction.hpp"
#include "Exception.hpp"

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

std::string RemoveSpaces(std::string line)
{
    size_t i = 0;

    while (i < line.length()) {
        if (line[i] == ' ' || line[i] == '\t') {
            line.erase(i, 1);
        } else {
            i += 1;
        }
    }
    return line;
}

std::string RemoveSpacesUntilWord(std::string line)
{
    size_t i = 0;

    while (i < line.length() && line[i] == ' ') {
        if (line[i] == ' ' || line[i] == '\t') {
            line.erase(i, 1);
        } else {
            i += 1;
        }
    }
    return line;
}


bool CheckSyntacticalError(std::string line, avm::eInstruction enumInstruction, const char *strInstruction[])
{
    size_t instructionSize = strlen(strInstruction[enumInstruction]); 
    size_t typeSize = 0;
    avm::eOperandType type = avm::getType(line);
    avm::myException exc;

    if (enumInstruction > 3) {
        line = RemoveSpaces(line);
        if (line.length() != instructionSize) {
            return false;
        }
    } else if (0 <= enumInstruction && enumInstruction <= 3) {
        line = RemoveSpacesUntilWord(line);
        line.erase(0, instructionSize + 1);
        line = RemoveSpacesUntilWord(line);
        typeSize = GetTypeSize(line);
        if (typeSize == 0) {
            exc.printError("error: number type not valid\n");
            return false;
        }
        line.erase(0, typeSize);
        line = RemoveSpacesUntilWord(line);
        line.erase(line.find_last_not_of(' ') + 1);
        if (line[0] != '(' || line.back() != ')') {
            exc.printError("error: write correctly\n");
            return false;
        }
        line.erase(0, 1);
        line.pop_back();
        if (CheckTheNb(line, type) == false) {
            exc.printError("error: invalid number\n");
            return false;
        }
    }
    return true;
}

bool FindInstruction(std::string codeAsm, const char *strInstruction[])
{
    avm::eInstruction enumInstruction;
    std::istringstream tmp;
    avm::myException exc;

    tmp.str(codeAsm);
    for (std::string line; std::getline(tmp, line); ) {
        enumInstruction = avm::getInstruction(line);
        if (!line.empty() && enumInstruction != 16) {
            if (CheckSyntacticalError(line, avm::getInstruction(line), strInstruction) == false) {
                exc.printError("error: syntactical error\n");
                return false;
            }
        }
        if (!line.empty() && avm::HasOnlySpaces(line) != false && enumInstruction == 16) {
            exc.printError("error: wrong instruction\n");
            return false;
        }
        enumInstruction = avm::eInstruction(0);
    }
    return true;
}

bool avm::CheckCode(std::string  codeAsm)
{
    const char *strInstruction[] = {"push", "assert", "load", "store", "pop", "dump", "clear", "dup", "swap", "add", "sub", "mul", "div", "mod", "print", "exit"};
    avm::myException exc;

    if (codeAsm.find("exit") == std::string::npos) {
        exc.printError("error: no exit\n");
        return false;
    }
    if (!FindInstruction(codeAsm, strInstruction))
        return false;
    return true;
}