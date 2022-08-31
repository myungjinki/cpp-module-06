#include "Serialize.hpp"

int main()
{
	Data* original = new Data;
	uintptr_t Serialized;
	Data* Deserialized;
	std::cout << "==== Original Value ====" << std::endl;
	original->value_int = 42;
	original->value_char = 'S';
	original->value_string = "Hello World!";
	std::cout << "int: " << original->value_int << std::endl;
	std::cout << "char: " << original->value_char << std::endl;
	std::cout << "string: " << original->value_string << std::endl;
	std::cout << "pointer: " << original << std::endl;

	std::cout << "\n==== Serialize ====" << std::endl;
	Serialized = serialize(original);
	std::cout << Serialized << std::endl;

	std::cout << "\n==== Deserialize ====" << std::endl;
	Deserialized = deserialize(Serialized);
	std::cout << Deserialized << std::endl;

	std::cout << "\n==== Compare Value ====" << std::endl;
	std::cout << "---- Original ----" << std::endl;
	std::cout << "int: " << original->value_int << std::endl;
	std::cout << "char: " << original->value_char << std::endl;
	std::cout << "string: " << original->value_string << std::endl;
	std::cout << "pointer: " << original << std::endl;

	std::cout << "---- After Serialization ----" << std::endl;
	std::cout << "int: " << Deserialized->value_int << std::endl;
	std::cout << "char: " << Deserialized->value_char << std::endl;
	std::cout << "string: " << Deserialized->value_string << std::endl;
	std::cout << "pointer: " << Deserialized << std::endl;
	delete (original);
	return (0);
}