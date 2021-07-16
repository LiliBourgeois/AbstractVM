/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_abstractVM.cpp
*/

#include <string>
#include <criterion/criterion.h>

#include "AbstractVM.hpp"

Test(test_abstractvm, test_abstractvm_legal_all_cmd_code)
{
    cr_assert_eq(avm::AbstractVM("push int8(78)\npush int16(300)\nadd\ndump\npush int16(90)\nsub\ndump\npush int8(-1)\nmul\ndump\npush int8(2)\ndiv\ndump\npush int8(5)\nmod\ndump\ndup\npop\npush bigdecimal(9.99)\npush float(0.00007)\npush double(56789)\nswap\nstore int8(3)\nload int8(3)\npush int32(555)\nassert int32(555)\nclear\npush int8(89)\nprint\nexit"), 0);
}