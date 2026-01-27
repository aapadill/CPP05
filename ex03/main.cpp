/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:31:24 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/27 23:31:37 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	AForm *scf = someRandomIntern.makeForm("shrubbery creation", "garden");
	if (scf)
	{
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (ppf)
	{
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}

	AForm *bad = someRandomIntern.makeForm("coffee request", "Office");
	if (bad)
		delete bad;

	return 0;
}
