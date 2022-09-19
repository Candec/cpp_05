#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
	explicit RobotomyRequestForm(const std::string& _target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(const RobotomyRequestForm &src);
	virtual void			execute(const Bureaucrat& executor) const;
	std::string				getTarget() const;

private:
	RobotomyRequestForm();
	std::string	target;
};

#endif
