#include "PresidentialPardonForm.hpp"

/* # Canonical declaration */

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", 25, 5),
	target("UNNAMED") {
	std::cout << "[PresidentialPardonForm] Default constructor.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &_target) :
	Form("PresidentialPardonForm", 25, 5),
	target(_target) {
	std::cout << "[PresidentialPardonForm] String constructor.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	Form(src) {
	*this = src;
	std::cout << "[PresidentialPardonForm] Copy constructor.\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[PresidentialPardonForm] Destructor.\n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src) {
		this->setSignedStatus(src.getSignedStatus());
		this->target = src.getTarget();
	}
	return (*this);
}

/* ===================== */

/* 	PresidentialPardonForm's methods */

std::string	PresidentialPardonForm::getTarget() const {
	return (this->target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	try {
		if (this->getSignedStatus() && executor.getGrade() <= this->getGradeToExecute()) {
			std::cout << this->getTarget()
					  << " has been pardoned by Zaphod Beeblebrox.\n";
		}
		else
			throw GradeTooLowException();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}