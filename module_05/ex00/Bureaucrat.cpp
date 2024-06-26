#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : grade_(150) {}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
throw(GradeTooHighException, GradeTooLowException): name_(name), grade_(grade) {
	if (grade_ < 1) {
		throw GradeTooHighException();
	} else if (grade_ > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->grade_ = other.grade_;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return name_;
}

unsigned int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException) {
	if (grade_ - 1 < 1) {
		throw GradeTooHighException();
	}
	grade_--;
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException) {
	if (grade_ + 1 > 150) {
		throw GradeTooLowException();
	}
	grade_++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
