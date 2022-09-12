#ifndef EX03_INTERN_H
#define EX03_INTERN_H

#include <iostream>
#include <string>
#include "Form.h"

#define NB_FORMS	3

class Intern {
public:
	Intern();
	Intern(const Intern &src);
	virtual ~Intern();

	Intern&	operator=(const Intern &rh_instance);
	Form*	makeForm(const std::string& _name, const std::string& target);
	Form*	makeP(const std::string& _target);
	Form*	makeR(const std::string& _target);
	Form*	makeS(const std::string& _target);

private:
	/* Note the syntax of pointer to a function. Compare it to what it would
	look like if it was just a function:
			Form*	func(const std::string& _target); */
	typedef Form*	(Intern::*func)(const std::string& target);
	func	ptr_f[NB_FORMS];
};

#endif //EX03_INTERN_H
