#include "Form.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Form::Form() : name("UNNAMED"), signed_status(false), grade_to_sign(-2), grade_to_execute(-1) {
	std::cout << "[Form] Default constructor.\n";
}

Form::Form(const std::string &_name, const int to_sign, const int to_exec) :
	name(_name),
	signed_status(false),
	grade_to_sign(to_sign),
	grade_to_execute(to_exec) {
	std::cout << "[Form] Proper constructor.\n";
	try {
		if (to_sign < 1 || to_exec < 1)
			throw GradeTooHighException();
		else if (to_sign > 150 || to_exec > 150)
			throw GradeTooLowException();
	}
	catch (std::exception& a) {
		std::cout << a.what() << std::endl;
	}
}

Form::Form(const Form &src) :
		name(src.name),
		signed_status(src.signed_status),
		grade_to_sign(src.grade_to_sign),
		grade_to_execute(src.grade_to_execute) {
	*this = src;
	std::cout << "[Form] Copy constructor.\n";
}

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Form::~Form() {
	std::cout << "[Form] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Form &Form::operator=(const Form &rh_instance) {
	if (this != &rh_instance)
		this->signed_status = rh_instance.signed_status;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName()
	   << (obj.getSignedStatus() ? " IS" : " is NOT")
	   << " signed and needs grade "
	   << obj.getGradeToSign()
	   << " to sign and grade "
	   << obj.getGradeToExecute()
	   << " to execute.";
	return (os);
}

//==============================================================================
// 	METHODS OF THE Form CLASS.
//==============================================================================
const std::string	Form::getName() const {
	return (this->name);
}

bool Form::getSignedStatus() const {
	return (this->signed_status);
}

int	Form::getGradeToSign() const {
	return (this->grade_to_sign);
}

int Form::getGradeToExecute() const {
	return (this->grade_to_execute);
}

Form &Form::setSignedStatus(bool status) {
	this->signed_status = status;
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("[FORM] Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("[FORM] Grade is too low!");
}

Form&	Form::beSigned(const Bureaucrat &target) {
	try {
		if (target.getGrade() <= this->grade_to_sign)
			this->signed_status = true;
		else
			throw GradeTooLowException();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (*this);
}