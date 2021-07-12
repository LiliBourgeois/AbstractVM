/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int8.hpp
*/

#ifndef ABSTRACT_INT8_HPP_
    #define ABSTRACT_INT8_HPP_

    #include <string>

    #include "Operand.hpp"

    namespace avm {
        class myInt8 : Operand
        {
        public:
            myInt8(const std::string &value);
            ~myInt8();
        };
    };

#endif