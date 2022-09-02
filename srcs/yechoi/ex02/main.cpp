/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:28:52 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/25 22:28:52 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base    *generate(void)
{
    Base    *p;
    int     num = rand();

    if (num % 3 == 0)
        return (p = new A);
    else if (num % 3 == 1)
        return (p = new B);
    else
        return (p = new C);
}

void    identify_from_pointer(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "This is A Class." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "This is B Class." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "This is C Class" << std::endl;
}

void    identify_from_reference(Base &p)
{
    try
    {
        Base &ref = dynamic_cast<A&>(p);
        (void)ref;
        std::cout << "This is A Class." << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base &ref = dynamic_cast<B&>(p);
        (void)ref;
        std::cout << "This is B Class." << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base &ref = dynamic_cast<C&>(p);
        (void)ref;
        std::cout << "This is C Class." << std::endl;
    }
    catch(const std::exception& e)
    {
    }
}

int     main(void)
{
    srand(time(0));

    Base* p;
    p = generate();
    identify_from_pointer(p);
    identify_from_reference(*p);
    delete p;

    std::cout << "============" << std::endl;
    
    Base* p2;
    p2 = generate();
    identify_from_pointer(p2);
    identify_from_reference(*p2);
    delete p2;

    std::cout << "============" << std::endl;
    
    Base* p3;
    p3 = generate();
    identify_from_pointer(p3);
    identify_from_reference(*p3);
    delete p3;

    std::cout << "============" << std::endl;
    
    Base* p4;
    p4 = generate();
    identify_from_pointer(p4);
    identify_from_reference(*p4);
    delete p4;

    std::cout << "============" << std::endl;
    
    Base* p5;
    p5 = generate();
    identify_from_pointer(p5);
    identify_from_reference(*p5);
    delete p5;

    std::cout << "============" << std::endl;
    
    Base* p6;
    p6 = generate();
    identify_from_pointer(p6);
    identify_from_reference(*p6);
    delete p6;
}