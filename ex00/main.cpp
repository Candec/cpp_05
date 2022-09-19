#include "Bureaucrat.hpp"

int main() {
	Bureaucrat a("Sr. Bacalhau", 42);
	Bureaucrat b = a;
	Bureaucrat c(a);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	
	std::cout << "Changing grades" << std::endl;
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