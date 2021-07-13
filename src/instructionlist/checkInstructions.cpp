/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** checkInstructions.cpp
*/

#include "AbstractVM.hpp"

bool sisgz(std::string codeAsm)
{
    if (codeAsm.find("exit\n"))
        return true;
}

bool CheckCode(std::string codeAsm)
{
    bool isUnknownInstruction = false;

    if (!codeAsm.find("exit\n"))
        return false;
    return true;
}