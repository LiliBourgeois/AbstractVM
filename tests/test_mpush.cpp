/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_mpush.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_mpush, test_bigdecimal_push)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v = fct.createOperand(avm::eOperandType::BIGDECIMAL, "4");

    avm::mpush(v, &stack);

    cr_assert_eq(4, std::stold(stack.at(0)->toString()));
    cr_assert_eq(avm::eOperandType::BIGDECIMAL, stack.at(0)->getType());
}