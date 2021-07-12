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
            int8, int16, int32, Float, Double, BigDecimal
        };

        class IOperand
        {
        public:
            virtual ~IOperand() {};
            virtual std::string toString() const = 0;
            virtual eOperandType getType() const = 0;
            virtual unsigned int getPrecision() const = 0;
            virtual IOperand* operator+(const IOperand &rhs) const = 0;
            virtual IOperand* operator-(const IOperand &rhs) const = 0;
            virtual IOperand* operator*(const IOperand &rhs) const = 0;
            virtual IOperand* operator/(const IOperand &rhs) const = 0;
            virtual IOperand* operator%(const IOperand &rhs) const = 0;
        };
    };

#endif