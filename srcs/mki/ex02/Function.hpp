/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Function.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:31:36 by mki               #+#    #+#             */
/*   Updated: 2021/09/14 14:29:16 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
