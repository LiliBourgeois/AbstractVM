/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** abstractVM.cpp
*/

#include <vector>

#include "AbstractVM.hpp"

std::string GetRidOfComment(std::string codeAsm)
{
    size_t semicolonPos = 0;
    size_t endCommentPos = 0;

    while (semicolonPos != std::string::npos) {
        semicolonPos = codeAsm.find_first_of(';', 0);
        endCommentPos = codeAsm.find_first_of('\n', semicolonPos);
        if (semicolonPos != std::string::npos) {
            if (endCommentPos == std::string::npos)
                endCommentPos = codeAsm.find_first_of('\0', semicolonPos);
            codeAsm.erase(semicolonPos, endCommentPos);
        }
    }
    return codeAsm;
}

/*int avm::AbstractVMCore(Instruction_t *instructions)
{
    std::vector<avm::IOperand *> *stack;
    return 0;
}*/

int avm::AbstractVM(std::string codeAsm)
{
    avm::Instruction_t *instructionsAsm;
    bool isCodeCorrect;

    codeAsm = GetRidOfComment(codeAsm);
    isCodeCorrect = avm::CheckCode(codeAsm);
    if (!isCodeCorrect)
        return 84;
    instructionsAsm = getTab(codeAsm);
    if (instructionsAsm == NULL)
        return 84;
    while (instructionsAsm->prev != NULL) {
        instructionsAsm = instructionsAsm->prev;
    }
    /*while (instructionsAsm->next != NULL) {
        std::cout << "on tente un truc :" << instructionsAsm->instruction << "\n";
        instructionsAsm = instructionsAsm->next;
    }*/
    return (/*AbstractVMCore(instructionsAsm)*/0);
}