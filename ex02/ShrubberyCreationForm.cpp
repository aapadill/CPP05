/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 23:02:55 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/23 23:02:56 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target)
{}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
	{
		AForm::operator=(other);
        _target = other._target;
	}
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out)
		throw std::runtime_error("could not create shrubbery file");
	out << "       _-_" << std::endl;
	out << "    /~~   ~~\\" << std::endl;
	out << " /~~         ~~\\" << std::endl;
	out << "{               }" << std::endl;
	out << " \\  _-     -_  /" << std::endl;
	out << "   ~  \\\\ //  ~" << std::endl;
	out << "_- -   | | _- _" << std::endl;
	out << "  _ -  | |   -_" << std::endl;
	out << "      // \\\\" << std::endl;
}
