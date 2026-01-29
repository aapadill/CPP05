/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:29:14 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/27 23:29:18 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//ctor
//if constructor throws, it was never built
AForm::AForm()
: _name("AForm"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec)
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

//copy ctor
AForm::AForm(const AForm &other)
: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{}

//operator= overload
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm(){}

//getters
const std::string &AForm::getName() const 
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

//actual functions
void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	executeAction(); //calling polyform call, depends on derived implementations
}

//void Bureaucrat::executeForm(Aform const &form) const //wrapper of form.execute(), try, if not catch

// what()
const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

// operator<<
std::ostream &operator<<(std::ostream &o, const AForm &f)
{
    o << f.getName()
      << " (signed: " << (f.getIsSigned() ? "true" : "false")
      << ", gradeToSign: " << f.getGradeToSign()
      << ", gradeToExec: " << f.getGradeToExec()
      << ")";
    return o;
}
