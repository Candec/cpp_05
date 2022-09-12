#ifndef EX02_ROBOTOMYREQUESTFORM_H
#define EX02_ROBOTOMYREQUESTFORM_H

#include "Form.h"

class RobotomyRequestForm : public Form {
public:
	explicit RobotomyRequestForm(const std::string& _target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(const RobotomyRequestForm &rh_instance);
	virtual void			execute(const Bureaucrat& executor) const;
	std::string				getTarget() const;

private:
	RobotomyRequestForm();
	std::string	target;
};

#endif //EX02_ROBOTOMYREQUESTFORM_H
