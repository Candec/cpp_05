#include <iostream>
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main() {
	Bureaucrat	smith("Mr Smith", 4);
	Bureaucrat	neo("NEO", 1);
	ShrubberyCreationForm		s1("s1");
	RobotomyRequestForm			r1("r1");
	PresidentialPardonForm		p1("p1");
	ShrubberyCreationForm		s2 = s1;
	RobotomyRequestForm			r2 = r1;
	PresidentialPardonForm		p2 = p1;

	std::cout << "=========================\n";
	std::cout << smith << std::endl;
	std::cout << s1 << std::endl;
	std::cout << "=========================\n";
	s1.beSigned(smith);
	smith.signForm(s1);
	std::cout << s1 << std::endl;
	std::cout << "=========================\n";
	smith.executeForm(s1);
	std::cout << "=========================\n";
	s1.beSigned(neo);
	s1.execute(smith);
	r1.beSigned(neo);
	p1.beSigned(neo);
	r1.execute(neo);
	p1.execute(neo);
	std::cout << s1 << std::endl;

	return (0);
}