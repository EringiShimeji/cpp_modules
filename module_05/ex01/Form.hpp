#ifndef CPP_MODULES_FORM_HPP
#define CPP_MODULES_FORM_HPP

#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	Form();
	Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
	throw(GradeTooHighException, GradeTooLowException);
	Form(const Form &other);
	~Form();
	Form &operator=(const Form &other);
	const std::string &getName() const;
	bool getIsSigned() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException);

private:
	const std::string name_;
	bool isSigned_;
	const unsigned int gradeToSign_;
	const unsigned int gradeToExecute_;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
