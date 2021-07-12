/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** bigdecimal.hpp
*/

#ifndef ABSTRACT_BIGDECIMAL_HPP_
    #define ABSTRACT_BIGDECIMAL_HPP_

    #include <string>

    #include "Operand.hpp"

    namespace avm {
        class myBigdecimal : Operand
        {
        public:
            myBigdecimal(const std::string &value);
            ~myBigdecimal();
        };
    };

#endif