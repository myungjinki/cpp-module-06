/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:03:13 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/24 22:03:13 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cmath>

class Convert
{
    private:
        std::string _str;
        double      _double;
        Convert();
    public:
        Convert(std::string str, double value);
        Convert(const Convert& ref);
        Convert&    operator=(const Convert& ref);
        ~Convert();

        std::string getStr() const;
        double      getDouble() const;

        class ImpossibleException : public std::exception
        {
            public:
                virtual const char* what() const throw();

        };
        class NonDisplayableException : public std::exception
        {
            public:
                virtual const char* what() const throw();

        };

        void    toChar();
        void    toInt();
        void    toFloat();
        void    toDouble();
};

# endif