#ifndef EX01_FORM_H
#define EX01_FORM_H

#include <string>
#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form {
public:
	Form(const std::string& _name, const int to_sign, const int to_exec);
	Form(const Form &src);
	virtual ~Form();

	Form&				operator=(const Form &rh_instance);
	const std::string	getName() const;
	bool				getSignedStatus() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	Form&				setSignedStatus(bool status);
	Form&				beSigned(const Bureaucrat& target);
	virtual void		execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char*		what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char*		what() const throw();
	};

protected:
	Form();

private:
	const std::string	name;
	bool				signed_status;
	const int			grade_to_sign;
	const int			grade_to_execute;
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif //EX01_FORM_H
