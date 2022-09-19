#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

#define NB_FORMS	3

class Intern {
public:

	Intern();
	Intern(const Intern &src);
	virtual ~Intern();

	Intern&	operator=(const Intern &src);
	Form*	makeForm(const std::string& _name, const std::string& target);
	Form*	makeP(const std::string& _target);
	Form*	makeR(const std::string& _target);
	Form*	makeS(const std::string& _target);

private:

	typedef Form*	(Intern::*func)(const std::string& target);
	func	ptr_f[NB_FORMS];
};

#endif
