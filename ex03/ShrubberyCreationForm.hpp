#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {
public:
	explicit ShrubberyCreationForm(const std::string& _target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &src);
	virtual void			execute(const Bureaucrat& executor) const;
	std::string				getTarget() const;

private:
	ShrubberyCreationForm();
	std::string	target;
};

#endif
