#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat	a("Sr Bacalhau", 4);
	Bureaucrat	b("Natas", 1);
	ShrubberyCreationForm		s1("s1");
	RobotomyRequestForm			r1("r1");
	PresidentialPardonForm		p1("p1");
	ShrubberyCreationForm		s2 = s1;
	RobotomyRequestForm			r2 = r1;
	PresidentialPardonForm		p2 = p1;

	std::cout << "/*******************/\n";
	std::cout << a << std::endl;
	std::cout << s1 << std::endl;
	std::cout << "/*******************/\n";

	s1.beSigned(a);
	a.signForm(s1);
	std::cout << s1 << std::endl;
	std::cout << "/*******************/\n";

	a.executeForm(s1);
	std::cout << "/*******************/\n";
	
	s1.beSigned(b);
	s1.execute(a);
	r1.beSigned(b);
	p1.beSigned(b);
	r1.execute(b);
	p1.execute(b);
	std::cout << s1 << std::endl;

	return (0);
}