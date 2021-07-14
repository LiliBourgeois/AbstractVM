/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_mpop.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_mpop, test_pop)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::FLOAT, "89.9002");

    avm::mpush(v1, &stack);
    avm::mpush(v2, &stack);
    avm::mpop(&stack);

    cr_assert_eq(4, std::stod(stack.at(0)->toString()));
    cr_assert_eq(avm::eOperandType::BIGDECIMAL, stack.at(0)->getType());
}