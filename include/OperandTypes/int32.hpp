/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** int32.hpp
*/

#ifndef ABSTRACT_INT32_HPP_
    #define ABSTRACT_INT32_HPP_

    #include <string>

    #include "Operand.hpp"

    namespace avm {
        class myInt32 : Operand
        {
        public:
            myInt32(const std::string &value);
            ~myInt32();
        };
    };

#endif