#include <iostream>
#include "Intern.h"

int main() {
	Intern	intern;
	Form*	form1;
	Form*	form2;

	std::cout << "=========================\n";
	form1 = intern.makeForm("PresidentialPardonForm", "a");
	std::cout << "=========================\n";
	if (form1)
		std::cout << *form1 << std::endl;
	std::cout << "=========================\n";
	form2 = intern.makeForm("other", "a");
	std::cout << "=========================\n";
	if (form2)
		std::cout << *form2 << std::endl;
	delete form1;
	delete form2;
	return (0);
}