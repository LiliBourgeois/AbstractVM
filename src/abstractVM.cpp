/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** abstractVM.cpp
*/

#include "AbstractVM.hpp"

int avm::AbstractVM(std::string codeAsm)
{
    avm::Instruction_t *instructionsAsm;
    bool isCodeCorrect = CheckCode(codeAsm);

    if (!isCodeCorrect)
        return 84;
    instructionsAsm = getTab(codeAsm);
    while (instructionsAsm->next != NULL) {
        printf("%d\n", instructionsAsm->instruction);
        instructionsAsm = instructionsAsm->next;
    }
    return 0;
}