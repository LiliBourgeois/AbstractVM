/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** IOperand.hpp
*/

#ifndef ABSTRACTVM_IOPERAND_HPP_
    #define ABSTRACTVM_IOPERAND_HPP_

    #include <string>

    namespace avm {
        enum eOperandType {
            INT8, INT16, INT32, FLOAT, DOUBLE, BIGDECIMAL, UNKNOWN
        };

        class IOperand
        {
        public:
            virtual ~IOperand() {};
            virtual std::string toString() const = 0;
            virtual eOperandType getType() const = 0;
            virtual unsigned int getPrecision() const = 0;
            virtual long double getMaxValue() const = 0;
            virtual long double getMinValue() const = 0;
            virtual IOperand* operator+(const IOperand &rhs) const = 0;
            virtual IOperand* operator-(const IOperand &rhs) const = 0;
            virtual IOperand* operator*(const IOperand &rhs) const = 0;
            virtual IOperand* operator/(const IOperand &rhs) const = 0;
            virtual IOperand* operator%(const IOperand &rhs) const = 0;
        };
    };

#endif