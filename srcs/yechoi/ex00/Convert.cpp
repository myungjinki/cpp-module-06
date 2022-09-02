/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:00:31 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/24 22:00:31 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(std::string str, double value)
    :_str(str), _double(value)
{
}

Convert::Convert(const Convert& ref)
{
    *this = ref;
}

Convert&    Convert::operator=(const Convert& ref)
{
    if (this == &ref)
        return (*this);
    _str = ref.getStr();
    _double = ref.getDouble();
    return (*this);
}

Convert::~Convert()
{
}

std::string Convert::getStr() const
{
    return (_str);
}

double      Convert::getDouble() const
{
    return (_double);
}  

void    Convert::toChar()
{
    int integer;

    std::cout << "char: ";
    integer = static_cast<int>(_double);
    if (integer - _double != 0)
        throw Convert::ImpossibleException();
    else if (integer >= 32 && integer <= 126)
        std::cout << "'" << static_cast<char>(_double) << "'" << std::endl;
    else
        throw Convert::NonDisplayableException();
}

void    Convert::toInt()
{
    long comp;

    std::cout << "int: ";
    if (std::isnan(_double) || std::isinf(_double))
        throw Convert::ImpossibleException();
    comp = stol(_str);
    if (comp > INT_MAX || comp < INT_MIN)
        throw Convert::ImpossibleException();
    std::cout << static_cast<int>(_double) << std::endl;
}

void    Convert::toFloat()
{
    int integer;

    std::cout << "float: ";
    std::cout << static_cast<float>(_double);

    integer = static_cast<int>(_double);
    if (integer - _double != 0)
        std::cout << "f" << std::endl;
    else
        std::cout << ".0f" << std::endl;
}

void    Convert::toDouble()
{
    int integer;

    std::cout << "double: ";
    std::cout << static_cast<double>(_double);

    integer = static_cast<int>(_double);
    if (integer - _double == 0)
        std::cout << ".0" ;
    std::cout << std::endl;
}

const char* Convert::ImpossibleException::what() const throw()
{
    return (" impossible");
}

const char* Convert::NonDisplayableException::what() const throw()
{
    return (" Non displayable");
}