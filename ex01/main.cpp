#include <iostream>
#include "Bureaucrat.h"
#include "Form.h"

int main() {
	Bureaucrat	smith("Mr Smith", 4);
	Bureaucrat	smith2 = smith;
	Bureaucrat	neo("NEO", 1);
	Form		f1("f1", 3, 2);
	Form		f2 = f1;

	std::cout << smith << std::endl;
	std::cout << f1 << std::endl;
	std::cout << "=========================\n";
	f1.beSigned(smith);
	smith.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << "=========================\n";
	f1.beSigned(smith2);
	smith2.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << "=========================\n";
	f1.beSigned(neo);
	std::cout << f1 << std::endl;

	return (0);
}