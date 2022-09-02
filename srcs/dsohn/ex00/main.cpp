#include <iostream>

void printToChar(std::string value)
{
	std::cout << "char: ";
	try {
		int ret = stoi(value);
		if (32 < ret && ret < 127)
			std::cout << "'" << static_cast<char>(ret) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	} catch(std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}

void printToInt(std::string value)
{
	std::cout << "int: ";
	try {
		int ret = stoi(value);
		std::cout << ret <<  std::endl;
	} catch(std::exception &e) {
		std::cout << "impossible" << std::endl;
	}
}

void printToFloat(std::string value)
{
	std::cout << "float: ";
	try {
		float ret = stof(value);
		if (ret - static_cast<int>(ret) == 0)
		{
			if (ret < 1000000)
				std::cout << ret << ".0f" << std::endl;
			else
				std::cout << ret << "f" << std::endl;
		}
		else
		{
			std::cout << ret << "f" << std::endl;
		}
	} catch(std::out_of_range &e) {
		std::cout << "inff" << std::endl;
	} catch(std::invalid_argument &e) {
		std::cout << "nanf" << std::endl;
	}
}

void printToDouble(std::string value)
{
	std::cout << "double: ";
	try {
		double ret = stod(value);
		if (ret - static_cast<int>(ret) == 0)
		{
			if (ret < 1000000)
				std::cout << ret << ".0" << std::endl;
			else
				std::cout << ret << std::endl;
		}
		else
		{
			std::cout << ret << std::endl;
		}
	} catch(std::out_of_range &e) {
		std::cout << "inf" << std::endl;
	} catch(std::invalid_argument &e) {
		std::cout << "nan" << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "convert: error: bad arguments\n" << std::endl;
		return 1;
	}
	std::string value = argv[1];

	printToChar(value);
	printToInt(value);
	printToFloat(value);
	printToDouble(value);

	return 0;
}
