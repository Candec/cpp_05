#include <iostream>
#include "Bureaucrat.h"

int main() {
	Bureaucrat a("Mr Smith", 3);
	Bureaucrat b = a;
	Bureaucrat c(a);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << "ola" << std::endl;
	a++;
	std::cout << a.getGrade() << std::endl;
	++a;
	std::cout << a.getGrade() << std::endl;
	++a;
	std::cout << a.getGrade() << std::endl;
	--a;
	std::cout << a.getGrade() << std::endl;
	a--;
	std::cout << a.getGrade() << std::endl;
	return (0);
}