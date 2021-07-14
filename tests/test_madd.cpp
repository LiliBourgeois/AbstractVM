/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_madd.cpp
*/

#include <criterion/criterion.h>
#include <string>

#include "Factory.hpp"
#include "IOperand.hpp"
#include "Stack.hpp"

Test(test_madd, test_int8_add)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT8, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT8, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::madd(&stack);

    cr_assert_eq(7, std::stod(stack.at(0)->toString()));
}

Test(test_madd, test_int16_add)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT16, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT16, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::madd(&stack);

    cr_assert_eq(7, std::stod(stack.at(0)->toString()));
}

Test(test_madd, test_int32_add)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::INT32, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::INT32, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::madd(&stack);

    cr_assert_eq(7, std::stod(stack.at(0)->toString()));
}

Test(test_madd, test_float_add)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::FLOAT, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::FLOAT, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::madd(&stack);

    cr_assert_eq(7, std::stod(stack.at(0)->toString()));
}

Test(test_madd, test_double_add)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::DOUBLE, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::DOUBLE, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::madd(&stack);

    cr_assert_eq(7, std::stod(stack.at(0)->toString()));
}

Test(test_madd, test_bigdecimal_add)
{
    std::vector<avm::IOperand *> stack;
    avm::Factory fct;
    avm::IOperand *v1 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "4");
    avm::IOperand *v2 = fct.createOperand(avm::eOperandType::BIGDECIMAL, "3");

    stack.push_back(v1);
    stack.push_back(v2);
    avm::madd(&stack);

    cr_assert_eq(7, std::stod(stack.at(0)->toString()));
}