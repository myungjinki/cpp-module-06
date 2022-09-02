#include <cstdlib>
#include <iostream>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

char randomAlnum()
{
	return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[std::rand() % 62];
}

void *serialize(void)
{
	char *ptr = new char[20];
	for (int i = 0;i < 8;i++)
	{
		ptr[i] = randomAlnum();
		ptr[12 + i] = randomAlnum();
	}
	*reinterpret_cast<int*>(ptr + 8) = std::rand() % 100;
	return static_cast<void*>(ptr);
}

Data *deserialize(void *raw)
{
	Data *d = new Data;
	d->s1 = std::string(static_cast<char*>(raw), 8);
	d->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);
	d->s2 = std::string(static_cast<char*>(raw) + 12, 8);
	return d;
}

int main()
{
	std::srand(std::time(NULL));
	void *raw = serialize();
	Data* d = deserialize(raw);
	std::cout << "Data string 1 : " << d->s1 << std::endl;
	std::cout << "Data n : "<< d->n << std::endl;
	std::cout << "Data string 2 : "<< d->s2 << std::endl;
	delete d;
	delete[] static_cast<char*>(raw);
	return 0;
}