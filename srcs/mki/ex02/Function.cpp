/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Function.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:31:34 by mki               #+#    #+#             */
/*   Updated: 2021/09/14 14:46:02 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Function.hpp"

Base *generate(void)
{
    srand(time(NULL));
    int randValue = rand() % 3;

    switch (randValue)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    default:
        return NULL;
    }
}
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
}
void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception e)
    {
        (void)e;
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch (std::exception e)
    {
        (void)e;
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch (std::exception e)
    {
        (void)e;
    }
}
