/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_mdiv.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_mdiv, test_int8_div)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT8, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT8, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mdiv(&stack);

    cr_assert_eq(2, std::stod(stack.at(0)->toString()));
}

Test(test_mdiv, test_int16_div)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT16, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT16, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mdiv(&stack);

    cr_assert_eq(2, std::stod(stack.at(0)->toString()));
}

Test(test_mdiv, test_int32_div)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT32, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT32, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mdiv(&stack);

    cr_assert_eq(2, std::stod(stack.at(0)->toString()));
}

Test(test_mdiv, test_float_div)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::FLOAT, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::FLOAT, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mdiv(&stack);

    cr_assert_eq(2.5, std::stod(stack.at(0)->toString()));
}

Test(test_mdiv, test_double_div)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::DOUBLE, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::DOUBLE, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mdiv(&stack);

    cr_assert_eq(2.5, std::stod(stack.at(0)->toString()));
}

Test(test_mdiv, test_bigdecimal_div)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "10");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::mdiv(&stack);

    cr_assert_eq(2, std::stod(stack.at(0)->toString()));
}