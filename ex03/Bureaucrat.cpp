/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:29:31 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/27 23:29:33 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) // default constructor //should i remove?
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) // constructor
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) // copy constructor
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) // operator overload
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() // default destructor
{}

// getters
std::string Bureaucrat::getName() const {return _name;}

int	Bureaucrat::getGrade() const {return _grade;}

// exceptions
void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &f)
{
    try
	{
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
	}
    catch (std::exception &e)
	{
        std::cout << _name << " couldn't sign " << f.getName()
				  << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because " << e.what() << "." << std::endl;
	}
}

// msgs virtual overload
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

// operator<< overload
std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}
