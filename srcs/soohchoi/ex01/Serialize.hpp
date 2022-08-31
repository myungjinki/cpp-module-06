#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

typedef struct s_data
{
    char value_char;
    int value_int;
    std::string value_string;
} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
