/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** bigdecimal.hpp
*/

#ifndef ABSTRACT_BIGDECIMAL_HPP_
    #define ABSTRACT_BIGDECIMAL_HPP_

    #include <string>

    #include "IOperand.hpp"

    namespace avm {
        class myBigdecimal : public IOperand
        {
        protected:
            std::string value;
            avm::eOperandType type;
            unsigned int precision;
        public:
            myBigdecimal(const std::string &value);
            ~myBigdecimal();

            std::string toString() const override;
            eOperandType getType() const override;
            unsigned int getPrecision() const override;

            avm::IOperand *operator+(const IOperand &rhs) const override;
            avm::IOperand *operator-(const IOperand &rhs) const override;
            avm::IOperand *operator*(const IOperand &rhs) const override;
            avm::IOperand *operator/(const IOperand &rhs) const override;
            avm::IOperand *operator%(const IOperand &rhs) const override;
        };
    };

#endif