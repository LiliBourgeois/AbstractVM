/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** abstractVM.cpp
*/

#include <vector>
#include <map>

#include "Stack.hpp"
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

int avm::AbstractVMCore(Instruction_t *instructions)
{
    int (*vpf[])(avm::IOperand *, std::vector<avm::IOperand *> *) = {
        avm::mpush, avm::massert, avm::mload, avm::mstore
    };
    int (*pf[])(std::vector<avm::IOperand *> *) = {
        avm::mpop, avm::mdump, avm::mclear, avm::mdup, avm::mswap,
        avm::madd, avm::msub, avm::mmul, avm::mdiv, avm::mmod, avm::mprint
    };
    std::vector<avm::IOperand *> stack;
    Instruction_t *tmp = instructions;
    int retval;

    while (tmp != NULL) {
        std::cout << tmp->instruction << "\n";
        if (tmp->instruction <= 3) {
            retval = vpf[tmp->instruction](tmp->value, &stack);
        } else 
            retval = pf[tmp->instruction - 4](&stack);
        std::cout << stack.at(0)->getType() << "\n" << stack.at(0)->toString() << "\n";
        if (retval == 84)
            return 84;
        tmp = tmp->next;
    }
    return 0;
}

int avm::AbstractVM(std::string codeAsm)
{
    avm::Instruction_t *instructionsAsm;
    bool isCodeCorrect;

    codeAsm = GetRidOfComment(codeAsm);
    isCodeCorrect = avm::CheckCode(codeAsm);
    if (!isCodeCorrect)
        return 84;
    instructionsAsm = getTab(codeAsm);
    if (instructionsAsm == NULL) {
        std::cout << "ASM EST NUL\n";
        return 84;
    }
    while (instructionsAsm->next) {
        if (instructionsAsm->instruction <= 3)
            std::cout << "VALUE:\n" << instructionsAsm->value->toString() << "\n";
        instructionsAsm = instructionsAsm->next;
    }
    return (AbstractVMCore(instructionsAsm));
}