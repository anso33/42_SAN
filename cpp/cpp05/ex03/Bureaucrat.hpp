/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:14:35 by san               #+#    #+#             */
/*   Updated: 2022/08/05 10:14:36 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class	Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat	&operator=(const Bureaucrat &bureaucrat);

		const std::string	getName() const;
		int					getGrade() const;
		void				upGrade();
		void				downGrade();
		void				signForm(Form &form);
		void				executeForm(const Form &form);

		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
