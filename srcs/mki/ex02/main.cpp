/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:31:38 by mki               #+#    #+#             */
/*   Updated: 2021/09/14 14:43:32 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Function.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base *basePtr;
    basePtr = generate();
    identify(basePtr);
    identify(*basePtr);
    delete basePtr;

    return (0);
}
