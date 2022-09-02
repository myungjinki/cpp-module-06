/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:34:05 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/25 17:34:05 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

struct Data
{
    std::string s1;
    int         n;
    std::string s2;
};

void    *serialize(void)
{
    char        *ptr;
    std::string s1 = "";
    std::string s2 = "";
    int         integer;
    char        alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyz";

    srand(time(0));
    for (int i = 0; i < 8; i++)
    {
        s1 += alphanum[rand() % 35];
        s2 += alphanum[rand() % 35];
    }
    integer = rand();
    ptr = new char[sizeof(std::string) * 2 + sizeof(int)];
    memcpy(ptr, reinterpret_cast<char*>(&s1), 24);
    memcpy(ptr + 24, reinterpret_cast<char*>(&integer), 4);
    memcpy(ptr + 28, reinterpret_cast<char*>(&s2), 24);
    return (ptr);
}

Data    *deserialize(void *raw)
{
    Data *dd = new Data;

    dd->s1 = std::string(static_cast<char*>(raw));
    dd->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 24);
    dd->s2 = std::string(static_cast<char*>(raw) + 28);
    return (dd);
}

int main(void)
{
    char    *ptr = reinterpret_cast<char*>(serialize());
    Data    *des = deserialize(ptr);

    std::cout << des->s1 << std::endl;
    std::cout << des->n << std::endl;
    std::cout << des->s2 << std::endl;
    delete des;
}