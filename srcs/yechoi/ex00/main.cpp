/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:01:53 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/24 22:01:53 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int     main(int argc, char** argv)
{
    double input;

    if (argc != 2)
        return 0;
    try
    {
        input = std::stof(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid Argument" << std::endl;
        return 0;
    }

    Convert C(argv[1], input);
    try
    {
        C.toChar();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C.toInt();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C.toFloat();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C.toDouble();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}