/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:43:27 by mki               #+#    #+#             */
/*   Updated: 2021/09/19 14:13:09 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <climits>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

#define IMPOSSIBLE 1
#define IMPOSSIBLE_FLOAT 2

class Convert
{
private:
    std::string input;
    char valueChar;
    int valueInt;
    float valueFloat;
    double valueDouble;
    int flag[4];

    Convert() {}
    char convertChar(double valueDouble);
    int convertInt(double valueDouble);
    float convertFloat(double valueDouble);
    double convertDouble(std::string input);
    void printChar(char valueChar);
    void printInt(int valueInt);
    void printFloat(float valueFlaot);
    void printDouble(double valueDouble);

public:
    Convert(char *argv);
    Convert(const Convert &convert);
    Convert &operator=(const Convert &convert);
    ~Convert();
    void convertAll();
    void printAll();
};

#endif
