/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:43:56 by mki               #+#    #+#             */
/*   Updated: 2021/09/19 16:18:54 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int isimpossible(std::string _input)
{
    if (_input == "nan" || _input == "+inf" || _input == "-inf" || _input == "inf")
    {
        return (IMPOSSIBLE);
    }
    else if (_input == "nanf" || _input == "+inff" || _input == "-inff" || _input == "inff")
    {
        return (IMPOSSIBLE_FLOAT);
    }
    return (0);
}

Convert::Convert(char *argv)
{
    input = argv;
    memset(flag, 0, 4);
}
Convert::Convert(const Convert &convert)
{
    *this = convert;
}
Convert &Convert::operator=(const Convert &convert)
{
    if (this == &convert)
    {
        return (*this);
    }
    this->input = convert.input;
    return (*this);
}
Convert::~Convert()
{
}
char Convert::convertChar(double _valueDouble)
{
    if (_valueDouble > 127)
    {
        flag[CHAR] = 1;
    }
    valueChar = static_cast<char>(_valueDouble);
    return (valueChar);
}
int Convert::convertInt(double _valueDouble)
{
    if (_valueDouble > INT32_MAX || _valueDouble < INT32_MIN)
    {
        flag[INT] = 1;
    }
    valueInt = static_cast<int>(_valueDouble);
    return (valueInt);
}
float Convert::convertFloat(double _valueDouble)
{
    valueFloat = static_cast<float>(_valueDouble);
    return (valueFloat);
}
double Convert::convertDouble(std::string _input)
{
    valueDouble = std::stod(_input);
    return (valueDouble);
}
void Convert::convertAll()
{
    convertDouble(input);
    convertChar(valueDouble);
    convertInt(valueDouble);
    convertFloat(valueDouble);
}
void Convert::printChar(char _valueChar)
{
    if (isimpossible(input) || flag[CHAR] == 1)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (isprint(_valueChar) != 1)
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: " << _valueChar << std::endl;
    }
}
void Convert::printInt(int _valueInt)
{
    if (isimpossible(input) || flag[INT] == 1)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << _valueInt << std::endl;
    }
}
void Convert::printFloat(float _valueFlaot)
{
    if (isimpossible(input) == IMPOSSIBLE)
    {
        std::cout << "float: " << input << "f" << std::endl;
    }
    else if (isimpossible(input) == IMPOSSIBLE_FLOAT)
    {
        std::cout << "float: " << input << std::endl;
    }
    else if (_valueFlaot - static_cast<int>(_valueFlaot) != 0 || _valueFlaot / 1000000 >= 1 || _valueFlaot / 1000000 <= -1)
    {
        std::cout << "float: " << _valueFlaot << "f" << std::endl;
    }
    else
    {
        std::cout << "float: " << _valueFlaot << ".0f" << std::endl;
    }
}
void Convert::printDouble(double _valueDouble)
{
    if (isimpossible(input) == IMPOSSIBLE)
    {
        std::cout << "double: " << input << std::endl;
    }
    else if (isimpossible(input) == IMPOSSIBLE_FLOAT)
    {
        std::cout << "double: ";
        if (input == "nanf")
        {
            std::cout << "nan" << std::endl;
        }
        else if (input == "+inff")
        {
            std::cout << "+inf" << std::endl;
        }
        else if (input == "-inff")
        {
            std::cout << "-inf" << std::endl;
        }
        else if (input == "inff")
        {
            std::cout << "inf" << std::endl;
        }
    }
    else if (_valueDouble - static_cast<int>(_valueDouble) != 0 || _valueDouble / 1000000 >= 1 || _valueDouble / 1000000 <= -1)
    {
        std::cout << "double: " << _valueDouble << std::endl;
    }
    else
    {
        std::cout << "double: " << _valueDouble << ".0" << std::endl;
    }
}
void Convert::printAll()
{
    printChar(valueChar);
    printInt(valueInt);
    printFloat(valueFloat);
    printDouble(valueDouble);
}
