#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
	explicit PresidentialPardonForm(const std::string& _target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm &src);
	virtual void			execute(const Bureaucrat& executor) const;
	std::string				getTarget() const;

private:
	PresidentialPardonForm();
	std::string	target;
};

#endif
