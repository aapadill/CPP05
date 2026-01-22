/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 01:33:26 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/22 14:12:48 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//default ctor
Form::Form() : _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{}

//ctor
//if constructor throws, it was never built
Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 | gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 | gradeToExec > 150)
		throw GradeTooLowException();
	_gradeToSign = gradeToSign;
}

//copy ctor
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), gradeToExec(other._gradeToExec)
{}

//operator= overload
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = 
}

Form::~Form(){}

//getters
const std::string &Form::getName() const 
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

//actual functions
void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}
