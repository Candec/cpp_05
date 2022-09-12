#include "Bureaucrat.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
Bureaucrat::Bureaucrat() {
	std::cout << "[Bureaucrat] Default constructor.\n";
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name)  {
	std::cout << "[Bureaucrat] Grade constructor.\n";
	try {
		if (_grade < 1)
			throw GradeTooHighException();
		else if (_grade > 150)
			throw GradeTooLowException();
		else
			grade = _grade;
	}
	catch (std::exception& a) {
		std::cout << a.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) :
		name(src.getName()) {
	*this = src;
	std::cout << "[Bureaucrat] Copy constructor.\n";
}


//==============================================================================
// 	DESTRUCTORS
//==============================================================================

Bureaucrat::~Bureaucrat() {
	std::cout << "[Bureaucrat] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &rh_instance) {
	if (this != &rh_instance)
		this->grade = rh_instance.getGrade();
	return (*this);
}

Bureaucrat&	Bureaucrat::operator++() {
	try {
		if (grade - 1 < 1)
			throw GradeTooHighException();
		else
			this->grade--;
	}
	catch (std::exception& a) {
		std::cout << a.what() << std::endl;
	}
	return (*this);
}

Bureaucrat&	Bureaucrat::operator--() {
	try {
		if (grade + 1 > 150)
			throw GradeTooLowException();
		else
			this->grade++;
	}
	catch (std::exception& a){
		std::cout << a.what() << std::endl;
	}
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int) {
	try {
		if (this->grade - 1 < 1)
			throw GradeTooHighException();
		else
			this->grade--;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int) {
	try {
		if (this->grade + 1 > 150)
			throw GradeTooLowException();
		else
			this->grade++;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& rh_instance) {
	out << rh_instance.getName()
		<< ", bureaucrat grade "
		<< rh_instance.getGrade()
		<< ".";
	return out;
}

//==============================================================================
// 	METHODS OF THE Bureaucrat CLASS.
//==============================================================================

std::string	Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

Bureaucrat &Bureaucrat::setGrade(int _grade) {
	this->grade = _grade;
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("[BUREAUCRAT] Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("[BUREAUCRAT] Grade is too low!");
}

Bureaucrat &Bureaucrat::signForm(Form &_form) {
	try {
		if (this->getGrade() <= _form.getGradeToSign()) {
			std::cout << this->getName()
					  << " signed "
					  << _form.getName()
					  << std::endl;
			_form.setSignedStatus(true);
		}
		else {
			std::cout << this->getName()
					  << " could not sign "
					  << _form.getName()
					  << " due to low grade.\n";
			throw GradeTooLowException();
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (*this);
}

/*
 * Note that execute() must be const, because here we are calling it from a
 * const Form object.
 */
void	Bureaucrat::executeForm(const Form& form) const {
	try {
		form.execute(*this);
		std::cout << this->getName()
				  << " just executed "
				  << form.getName()
				  << std::endl;
	}
	catch (std::exception& e) {
		std::cout << this->getName()
				  << " could not execute "
				  << form.getName()
				  << ", due to the following exception: "
				  << e.what()
				  << std::endl;
	}
}