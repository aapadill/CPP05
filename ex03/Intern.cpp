/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:29:49 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/27 23:29:50 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

static AForm *make_shrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *make_robotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *make_pardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	struct FormPair {
		const char *name;
		AForm *(*create)(const std::string &);
	};

	static const FormPair forms[] = {
		{ "shrubbery creation", &make_shrubbery },
		{ "robotomy request", &make_robotomy },
		{ "presidential pardon", &make_pardon }
	};

	for (int i = 0; i < 3; ++i)
	{
		if (name == forms[i].name)
		{
			AForm *form = forms[i].create(target);
			std::cout << "Intern creates " << name << std::endl;
			return form;
		}
	}
	std::cout << "Intern cannot create \"" << name << "\" because it does not exist." << std::endl;
	return 0;
}
