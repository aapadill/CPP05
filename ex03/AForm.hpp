/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapadill <aapadill@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:29:25 by aapadill          #+#    #+#             */
/*   Updated: 2026/01/27 23:29:26 by aapadill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm { //abstract class
	private: //from pdf -> form's atts need to remain priv and belong to base class
		const std::string _name;
		bool _isSigned; //at construction it's false
		const int _gradeToSign;
		const int _gradeToExec;

	protected:
		virtual void executeAction() const = 0; //pure virtual function //protected so derived can use it
	
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		//getters
		const std::string &getName() const; //trick to avoid creating a copy
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		//actual functions
		void beSigned(Bureaucrat const &b);
		void execute(Bureaucrat const &executor) const;

		//exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const AForm &f);
