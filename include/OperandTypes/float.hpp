/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** float.hpp
*/

#ifndef ABSTRACT_FLOAT_HPP_
    #define ABSTRACT_FLOAT_HPP_

    #include <string>

    #include "Operand.hpp"

    namespace avm {
        class myFloat : Operand
        {
        public:
            myFloat(const std::string &value);
            ~myFloat();
        };
    };

#endif