#include <cstdlib>
#include "RobotomyRequestForm.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
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

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[RobotomyRequestForm] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &rh_instance) {
	if (this != &rh_instance) {
		this->setSignedStatus(rh_instance.getSignedStatus());
		this->target = rh_instance.getTarget();
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE RobotomyRequestForm CLASS.
//==============================================================================
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
