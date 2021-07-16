/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** test_checkcode.cpp
*/

#include <criterion/criterion.h>

#include "AbstractVM.hpp"

Test(test_checkcode, test_legal_code_all_cmd)
{
    std::string code = ";;;;;;;;;;;;;;\n;header\n;this is a file\n;;;;;;;;;;;;;;\npush int8(78)\npush int16(300)\nadd\ndump\t;should be 378\npush int16(90)\nsub\ndump\t;should be 288\npush int8(-1)\nmul\ndump\t;should be -288\npush int8(2)\ndiv\ndump\t;should be -144\npush int8(5)\nmod\ndump\t;should be -4\n    ;;;OPP END;;;\nexit";
    cr_assert(avm::CheckCode(code));
}