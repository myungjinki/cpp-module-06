#include "Convert.hpp"

Convert::Convert()
{
}

Convert::~Convert()
{
}

Convert::Convert(const std::string &input)
{
	if (!isprint(input[0]) ||
	(input.size() > 1 && !isdigit(input[0]) &&
		!(input == "-inff" || input =="inff" || input == "+inff" || input == "nanf" ||
		input == "-inf" || input =="inf" || input == "+inf" || input == "nan" ))
	)
		throw Convert::ErrorException();
	this->raw_input = input;
}

Convert::Convert(const Convert &other)
{
	*this = other;
}

Convert& Convert::operator=(const Convert& other)
{
	this->raw_input = other.raw_input;
	this->value_char = other.value_char;
	this->value_int = other.value_int;
	this->value_float = other.value_float;
	this->value_double = other.value_double;
	return *this;
}

void Convert::setType()
{
	if (this->raw_input.size() == 1 && !isdigit(this->raw_input[0]))
	{
		this->value_double = static_cast<double>(this->raw_input[0]);
		return ;
	}
	this->value_double = stod(this->raw_input);
}

void Convert::printChar()
{
	this->value_char = static_cast<char>(this->value_double);
	std::cout << "char: ";
	if (this->value_double != this->value_double ||
		this->value_double > std::numeric_limits<char>::max() ||
		this->value_double < std::numeric_limits<char>::min())
		std::cout << "impossible" << std::endl;
	else if (!isprint(this->value_char))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << this->value_char << "'" << std::endl;
}

void Convert::printInt()
{
	this->value_int = static_cast<int>(this->value_double);
	std::cout << "int: ";
	if (this->value_double != this->value_double ||
		this->value_double > std::numeric_limits<int>::max() ||
		this->value_double < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->value_int << std::endl;
}

void Convert::printFloat()
{
	this->value_float = static_cast<float>(this->value_double);
	std::cout << "float: ";
	if (this->value_float == static_cast<int>(this->value_float))
		std::cout << this->value_float << ".0f" << std::endl;
	else
		std::cout << this->value_float << "f" << std::endl;
}

void Convert::printDouble()
{
	std::cout << "double: ";
	if (this->value_double == static_cast<int>(this->value_double))
		std::cout << this->value_double << ".0" << std::endl;
	else
		std::cout << this->value_double << std::endl;
}

void Convert::printAll()
{
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}

const char* Convert::ErrorException::what() const throw()
{
	return "ErrorException: Conversion doesn't make sense.";
}