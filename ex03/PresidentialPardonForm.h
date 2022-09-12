#ifndef EX02_PRESIDENTIALPARDONFORM_H
#define EX02_PRESIDENTIALPARDONFORM_H

#include "Form.h"

class PresidentialPardonForm : public Form {
public:
	explicit PresidentialPardonForm(const std::string& _target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm &rh_instance);
	virtual void			execute(const Bureaucrat& executor) const;
	std::string				getTarget() const;

private:
	PresidentialPardonForm();
	std::string	target;
};

#endif //EX02_PRESIDENTIALPARDONFORM_H
