/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:11:09 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:11:11 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("none")
{
	this->grade = 150;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
	{
		this->grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.getName())
{
	this->grade = bureaucrat.getGrade();
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	//const_cast can change this->name
	this->grade = bureaucrat.getGrade();

	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::upGrade()
{
	if (this->grade < 2)
		throw GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::downGrade()
{
	if (this->grade > 149)
		throw GradeTooLowException();
	this->grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade is over range (High)";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Grade is over range (Low)";
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << ", bureaucrat grade is " << bureaucrat.getGrade();
	return (out);
}
