#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat	a("Sr. Bacalhau", 4);
	Bureaucrat	b = a;
	Bureaucrat	natas("Natas", 1);
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

	f1.beSigned(natas);
	std::cout << f1 << std::endl;

	return (0);
}