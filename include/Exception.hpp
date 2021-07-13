/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** Exception.hpp
*/

#ifndef ABSTRACTVM_EXCEPTION_HPP_
    #define ABSTRACTVM_EXCEPTION_HPP_

    #include <exception>

    namespace avm {
        class myException : std::exception 
        {
        public:
            myException();
            ~myException();
        };

        myException::myException()
        {
        }

        myException::~myException()
        {
        }
    };

#endif