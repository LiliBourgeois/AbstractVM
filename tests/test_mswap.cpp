/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_mswap.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_mswap, test_swap)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT32, "-23");

    avm::mpush(v1, &stack);
    avm::mpush(v2, &stack);

    avm::mswap(&stack);

    cr_assert_eq(4, std::stod(stack.at(0)->toString()));
    cr_assert_eq(avm::eOperandType::BIGDECIMAL, stack.at(0)->getType());
    cr_assert_eq(-23, std::stod(stack.at(1)->toString()));
    cr_assert_eq(avm::eOperandType::INT32, stack.at(1)->getType());
}