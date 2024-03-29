#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form(const std::string& _name, const int to_sign, const int to_exec);
	Form(const Form &src);
	virtual ~Form();
	Form&				operator=(const Form &src);

	const std::string	getName() const;
	bool				getSignedStatus() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	Form&				setSignedStatus(bool status);
	Form&				beSigned(const Bureaucrat& target);

	class GradeTooHighException : public std::exception {
	public:
		const char*		what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char*		what() const throw();
	};

private:
	Form();
	const std::string	name;
	bool				signed_status;
	const int			grade_to_sign;
	const int			grade_to_execute;
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif
