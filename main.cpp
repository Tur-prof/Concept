#include <iostream>
#include <concepts>
#include <string>

template <typename T>
concept ComplexConcept = requires(T val)
{
	{val.toString()} -> std::same_as<std::string>;
	{val.hash()} -> std::convertible_to<long>;
	std::has_virtual_destructor <T>::value;
};

class Check
{
	int n;
public:
	Check(int val) : n(val)
	{
		std::cout << "Constructor" << std::endl;
	}
	std::string toString() {
		return std::to_string(n);
	}
	int hash() {
		return n;
	}
	~Check() {
		std::cout << "Distructor" << std::endl;
	};
};

template <ComplexConcept T>
void conceptMetod(T data)
{
	std::cout << "Metod toString: " << data.toString() << std::endl;
	std::cout << "Metod hash: " << data.hash() << std::endl;
}

int main()
{
	Check test(10);
	conceptMetod(test);
	return 0;
}
