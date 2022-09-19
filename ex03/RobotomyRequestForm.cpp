#include <cstdlib>
#include "RobotomyRequestForm.hpp"

/* # Canonical declaration */

RobotomyRequestForm::RobotomyRequestForm() :
	Form("RobotomyRequestForm", 72, 45),
	target("UNNAMED") {
	std::cout << "[RobotomyRequestForm] Default constructor.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &_target) :
	Form("RobotomyRequestForm", 72, 45),
	target(_target) {
	std::cout << "[RobotomyRequestForm] String constructor.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	Form(src) {
	*this = src;
	std::cout << "[RobotomyRequestForm] Copy constructor.\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[RobotomyRequestForm] Destructor.\n";
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src) {
		this->setSignedStatus(src.getSignedStatus());
		this->target = src.getTarget();
	}
	return (*this);
}

/* ===================== */

/* 	RobotomyRequestForm's methods */

std::string RobotomyRequestForm::getTarget() const {
	return (this->target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	try {
		if (this->getSignedStatus() && executor.getGrade() <= this->getGradeToExecute()) {
			srand(static_cast<unsigned int>(time(NULL)));
			std::cout << "BRRRRRR  BRRRRRR BRRRRRR BRRRRRRRRRRRRRR!\n"
					  << this->getTarget()
					  << ((rand() % 2) ? " has been" : " FAILED being")
					  << " robotomized.\n";
		}
		else
			throw GradeTooLowException();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
