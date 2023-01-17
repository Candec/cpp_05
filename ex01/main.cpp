#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat	a("Hermes Conrad", 4);
	Bureaucrat	b = a;
	Bureaucrat	Professor("Professor Hubert J. Farnsworth", 1);
	Form		f1("f1", 3, 2);
	Form		f2 = f1;

	std::cout << a << std::endl;
	std::cout << f1 << std::endl;
	std::cout << "/*******************/\n";

	f1.beSigned(a);
	a.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << "/*******************/\n";

	f1.beSigned(b);
	b.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << "/*******************/\n";

	f1.beSigned(Professor);
	std::cout << f1 << std::endl;

	return (0);
}