/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:11:44 by mki               #+#    #+#             */
/*   Updated: 2021/09/14 12:26:04 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
    Data data;
    uintptr_t serializeValue;
    Data *deserializeValue;

    data.name = "mki";
    data.age = 22;
    data.group = "42";

    serializeValue = serialize(&data);
    std::cout << "intptr: " << serializeValue << std::endl;
    std::cout << "intptr hex: " << std::hex << serializeValue << std::endl;

    deserializeValue = deserialize(serializeValue);
    std::cout << "name: " << deserializeValue->name << std::endl;
    std::cout << "age: " << deserializeValue->age << std::endl;
    std::cout << "group: " << deserializeValue->group << std::endl;

    return (0);
}
