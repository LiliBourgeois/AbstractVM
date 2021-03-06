/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** Exception.hpp
*/

#ifndef ABSTRACTVM_EXCEPTION_HPP_
    #define ABSTRACTVM_EXCEPTION_HPP_

    #include <iostream>
    #include <exception>

    namespace avm {
        class myException : public std::exception
        {
        public:
            void printError(const char *);
        };
    };

#endif