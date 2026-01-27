/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:38:28 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/21 05:11:51 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(); // default constructor
		Bureaucrat(std::string name, int grade); // constructor
		Bureaucrat(const Bureaucrat &other); // copy constructor
		Bureaucrat &operator=(const Bureaucrat & other); // operator overload
		~Bureaucrat(); // default destructor

		// getters
		std::string getName() const;
		int			getGrade() const;

		// actual functions
		void incrementGrade();
		void decrementGrade();

		// ex02
		void signForm(AForm &f);
		void executeForm(AForm const &form) const;

		// exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw(); //from cpp11 onwards we use noexcept
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw(); //from cpp11 onwards we use noexcept
		};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);
