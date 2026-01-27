/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:38:36 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/21 01:08:51 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static void test_execute_before_sign()
{
	std::cout << "\n -- test_execute_before_sign -- \n";
	Bureaucrat boss("Boss", 1);
	ShrubberyCreationForm shrub("home");
	boss.executeForm(shrub); // should fail (not signed)
}

static void test_sign_and_execute()
{
	std::cout << "\n -- test_sign_and_execute -- \n";
	Bureaucrat signer("Signer", 1);
	ShrubberyCreationForm shrub_garden("garden");
	ShrubberyCreationForm shrub_home("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	signer.signForm(shrub_garden);
	signer.signForm(shrub_home);
	signer.signForm(robot);
	signer.signForm(pardon);

	signer.executeForm(shrub_garden);
	signer.executeForm(shrub_home);
	signer.executeForm(robot);
	signer.executeForm(pardon);
}

static void test_low_grade_execute()
{
	std::cout << "\n -- test_low_grade_execute -- \n";
	Bureaucrat low("Low", 150);
	RobotomyRequestForm robot("Marvin");

	low.signForm(robot);   // should fail (grade too low)
	low.executeForm(robot); // should fail (not signed / low grade)
}

int main()
{
	test_execute_before_sign();
	test_sign_and_execute();
	test_low_grade_execute();
	return 0;
}
