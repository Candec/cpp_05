#ifndef EX02_SHRUBBERYCREATIONFORM_H
#define EX02_SHRUBBERYCREATIONFORM_H

#include "Form.h"

class ShrubberyCreationForm : public Form {
public:
	explicit ShrubberyCreationForm(const std::string& _target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &rh_instance);
	virtual void			execute(const Bureaucrat& executor) const;
	std::string				getTarget() const;

private:
	ShrubberyCreationForm();
	std::string	target;
};

#endif //EX02_SHRUBBERYCREATIONFORM_H
