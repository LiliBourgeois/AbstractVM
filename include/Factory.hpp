/*
** EPITECH PROJECT, 2021
** B-SYN-400-BDX-4-1-abstractVM-lili.bourgeois
** File description:
** Factory.hpp
*/

#ifndef ABSTRACTVM_FACTORY_HPP_
    #define ABSTRACTVM_FACTORY_HPP_

    #include "IOperand.hpp"

    namespace avm {
        class Factory
        {
        private:
            IOperand* createInt8(const std::string& value);
            IOperand* createInt16(const std::string& value);
            IOperand* createInt32(const std::string& value);
            IOperand* createFloat(const std::string& value);
            IOperand* createDouble(const std::string& value);
            IOperand* createBigDecimal(const std::string& value);
        public:
            IOperand *createOperand(eOperandType type, const std::string &value);
            Factory();
            ~Factory();
        };
    };

#endif