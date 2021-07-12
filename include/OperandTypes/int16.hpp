/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int16.hpp
*/

#ifndef ABSTRACT_INT16_HPP_
    #define ABSTRACT_INT16_HPP_

    #include <string>

    #include "Operand.hpp"

    namespace avm {
        class myInt16 : Operand
        {
        public:
            myInt16(const std::string &value);
            ~myInt16();
        };
    };

#endif