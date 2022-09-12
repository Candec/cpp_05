#include <fstream>
#include "ShrubberyCreationForm.h"

//==============================================================================
// 	CONSTRUCTORS
//==============================================================================
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

//==============================================================================
// 	DESTRUCTORS
//==============================================================================

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[ShrubberyCreationForm] Destructor.\n";
}

//==============================================================================
// 	OPERATOR OVERLOADS
//==============================================================================

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rh_instance) {
	if (this != &rh_instance) {
		this->setSignedStatus(rh_instance.getSignedStatus());
		this->target = rh_instance.getTarget();
	}
	return (*this);
}

//==============================================================================
// 	METHODS OF THE ShrubberyCreationForm CLASS.
//==============================================================================
std::string ShrubberyCreationForm::getTarget() const {
	return (this->target);
}

/*
 * Note that error messages should print to std::cerr and not std::cout.
 */
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	try {
		if (this->getSignedStatus() && executor.getGrade() <= this->getGradeToExecute()) {
			std::ofstream	ofs;

			ofs.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out);
			if (!ofs.is_open())
				std::cerr << "Could not open file.\n";
			else {
				ofs << "         v .   ._, |_  .,\n"
					   "    `-._\\/  .  \\ /    |/_\n"
					   "    \\  _\\, y | \\//\n"
					   "         _\\_.___\\, \\/ -.\\||\n"
					   "            `7-,--.`._||  / / ,\n"
					   "            /'     `-. `./ / |/_.'\n"
					   "                     |    |//\n"
					   "                     |_    /\n"
					   "                     |-   |\n"
					   "                     |   =|\n"
					   "                     |    |\n"
					   "--------------------/ ,  . \\--------._\n";
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
