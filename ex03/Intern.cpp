#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Intern::Intern() {
	this->ptr_f[0] = &Intern::makeP;
	this->ptr_f[1] = &Intern::makeR;
	this->ptr_f[2] = &Intern::makeS;
	std::cout << "[Intern] Default constructor.\n";
}

Intern::Intern(const Intern &src) {
	*this = src;
	std::cout << "[Intern] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Intern::~Intern() {
	std::cout << "[Intern] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Intern&	Intern::operator=(const Intern &rh_instance) {
	if (this != &rh_instance) {
		this->ptr_f[0] = rh_instance.ptr_f[0];
		this->ptr_f[1] = rh_instance.ptr_f[1];
		this->ptr_f[2] = rh_instance.ptr_f[2];
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE Intern CLASS.
//==============================================================================
Form*	Intern::makeForm(const std::string &_name, const std::string &_target) {
	for (int i = 0; i < NB_FORMS; i++) {
		Form* temp = (this->*(ptr_f[i]))(_target);
		if (_name == temp->getName()) {
			std::cout << "Intern creates form named "
					  << _name
					  << ".\n";
			return (temp);
		}
		delete (temp);
	}
	std::cout << "Intern cannot create form named "
			  << _name
			  << ".\n";
	return (0);
}

Form*	Intern::makeP(const std::string &_target) {
	return (new PresidentialPardonForm(_target));
}

Form*	Intern::makeR(const std::string &_target) {
	return (new RobotomyRequestForm(_target));
}

Form*	Intern::makeS(const std::string &_target) {
	return (new ShrubberyCreationForm(_target));
}
