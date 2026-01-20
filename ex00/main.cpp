/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:38:36 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/20 23:04:03 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

static void test_construct_valid()
{
	std::cout << "\n -- test_construct_valid -- \n";
	Bureaucrat a("Aaron", 42);
	std::cout << a << std::endl;
}

int main()
{
	test_construct_valid();
}
