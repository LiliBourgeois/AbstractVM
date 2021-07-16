/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_mload.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_mload, test_load)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::FLOAT, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::FLOAT, "3");
    avm::IOperand *v3 = fct.createOperand(avm::eOperandType::FLOAT, "2");
    avm::IOperand *v4 = fct.createOperand(avm::eOperandType::FLOAT, "1");
    avm::IOperand *v5 = fct.createOperand(avm::eOperandType::FLOAT, "0");
    avm::IOperand *src = fct.createOperand(avm::eOperandType::INT8, "1");

    avm::mpush(v1, &stack);
    avm::mpush(v2, &stack);
    avm::mpush(v3, &stack);
    avm::mpush(v4, &stack);
    avm::mpush(v5, &stack);

    avm::mload(src, &stack);

    cr_assert_eq(1, std::stold(stack.at(0)->toString()));
    cr_assert_eq(avm::eOperandType::FLOAT, stack.at(0)->getType());
    cr_assert_eq(0, std::stold(stack.at(1)->toString()));
    cr_assert_eq(avm::eOperandType::FLOAT, stack.at(1)->getType());
    cr_assert_eq(1, std::stold(stack.at(2)->toString()));
    cr_assert_eq(avm::eOperandType::FLOAT, stack.at(2)->getType());
}