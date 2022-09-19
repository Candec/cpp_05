#include "ShrubberyCreationForm.hpp"

/* # Canonical declaration */

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("ShrubberyCreationForm", 145, 137),
	target("UNNAMED") {
	std::cout << "[ShrubberyCreationForm] Default constructor.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target) :
	Form("ShrubberyCreationForm", 145, 137),
	target(_target) {
	std::cout << "[ShrubberyCreationForm] String constructor.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	Form(src) {
	*this = src;
	std::cout << "[ShrubberyCreationForm] Copy constructor.\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[ShrubberyCreationForm] Destructor.\n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {
		this->setSignedStatus(src.getSignedStatus());
		this->target = src.getTarget();
	}
	return (*this);
}

/* ===================== */
/* 	ShrubberyCreationForm's methods */

std::string ShrubberyCreationForm::getTarget() const {
	return (this->target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	try {
		if (this->getSignedStatus() && executor.getGrade() <= this->getGradeToExecute()) {
			std::ofstream	ofs;

			ofs.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out);
			if (!ofs.is_open())
				std::cerr << "Could not open file.\n";
			else {
				ofs <<  "         #o#\n"
       					"		####o#\n"
						"      #o# \\#|_#,###\n"
						"     ###\\ |/   #o####  #\n"
						"      # {}{      #######\n"
						"	      }{{\n"
						"_______,'  `__________\n"
						"\\____________________/";
				ofs.close();
			}
		}
		else
			throw GradeTooLowException();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
