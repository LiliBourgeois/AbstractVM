/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** float.hpp
*/

#ifndef ABSTRACT_FLOAT_HPP_
    #define ABSTRACT_FLOAT_HPP_

    #include <string>

    #include "IOperand.hpp"

    namespace avm {
        class myFloat : public IOperand
        {
        protected:
            std::string value;
            avm::eOperandType type;
            unsigned int precision;
        public:
            myFloat(const std::string &value);
            ~myFloat();

            std::string toString() const override;
            eOperandType getType() const override;
            unsigned int getPrecision() const override;
            long double getMaxValue() const override;
            long double getMinValue() const override;

            avm::IOperand *operator+(const IOperand &rhs) const override;
            avm::IOperand *operator-(const IOperand &rhs) const override;
            avm::IOperand *operator*(const IOperand &rhs) const override;
            avm::IOperand *operator/(const IOperand &rhs) const override;
            avm::IOperand *operator%(const IOperand &rhs) const override;
        };
    };

#endif