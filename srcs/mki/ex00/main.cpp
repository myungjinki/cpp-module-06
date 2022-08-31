/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:43:09 by mki               #+#    #+#             */
/*   Updated: 2021/09/19 13:31:49 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return (0);
    }
    else
    {
        Convert convert(argv[1]);
        try
        {
            convert.convertAll();
            convert.printAll();
        }
        catch (std::exception e)
        {
            std::cout << e.what() << ": wrong input" << std::endl;
        }
    }
    return (0);
}
