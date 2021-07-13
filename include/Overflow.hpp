/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** Overflow.hpp
*/

#ifndef ABSTRACTVM_OVERFLOW_HPP_
    #define ABSTRACTVM_OVERFLOW_HPP_

    namespace avm {
        bool isAddOverflowing(long double max, long double min, long double x, long double y);
        bool isSubOverflowing(long double max, long double min, long double x, long double y);
        bool isMulOverflowing(long double max, long double min, long double x, long double y);
    };

#endif