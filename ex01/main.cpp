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
#include "Form.hpp"
#include <iostream>

static void test_construct_valid()
{
	std::cout << "\n -- test_construct_valid -- \n";

	Bureaucrat a("Aaron", 42);
	std::cout << a << std::endl;
}

static void test_construct_invalid()
{	
	std::cout << "\n -- test_construct_valid -- \n";

	try {
		Bureaucrat x("testingTooHigh", 0);
		std::cout << x << std::endl; //shouldn't run
	} catch (std::exception &e) {	
		std::cout << "Caught: "  << e.what() << std::endl;
	}

	try {
		Bureaucrat y("testingTooLow", 151);
		std::cout << y << std::endl; //shouldn't run
	} catch (std::exception &e) {	
		std::cout << "Caught: "  << e.what() << std::endl;
	}
}

static void test_increment_decrement_edges()
{
	std::cout << "\n -- test_increment_decrement_edges -- \n";

	try {
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade(); //should throw
	} catch (std::exception &e) {
		std::cout << "Caught when incrementing max: " << e.what() << std::endl;
	}

	try {
		Bureaucrat low("Low", 150);
		std::cout << low << std::endl;
		low.decrementGrade(); //should throw
	} catch (std::exception &e) {
		std::cout << "Caught when decrementing min: " << e.what() << std::endl;
	}
}

static void test_copy_and_assign()
{
    std::cout << "\n -- test_copy_and_assign -- \n";

    Bureaucrat a("Aaron", 42);
    Bureaucrat b(a); //copy constructor using a as reference
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl; //a and b should be same

    Bureaucrat c("Clark", 10);
    std::cout << "c before: " << c << std::endl;
    c = a; //operator=
    std::cout << "c after : " << c << std::endl;
    //name should remain same, grade should change to 42
}


static void test_form_sign()
{
    std::cout << "\n -- test_form_sign -- \n";

    Form f("NDA", 50, 10);
    std::cout << f << std::endl;

    Bureaucrat good("Good", 10);
    Bureaucrat bad("Bad", 100);

    bad.signForm(f);   //should fail
    good.signForm(f);  //should succeed

    std::cout << f << std::endl;
}

int main()
{
	test_construct_valid();
	test_construct_invalid();
	test_increment_decrement_edges();
	test_copy_and_assign();
	test_form_sign();
	return 0;
}
