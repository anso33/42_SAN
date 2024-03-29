/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:58:39 by san               #+#    #+#             */
/*   Updated: 2022/08/05 14:58:45 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Convert
{
	private:
		std::string	value;

	public:
		Convert();
		Convert(std::string value);
		Convert(const Convert &convert);
		~Convert();
		Convert	&operator=(const Convert &convert);

		void	conversion();
		void	convertChar(double d);
		void	convertInt(double d);
		void	convertFloat(double d);
		void	convertDouble(double d);

		bool	intBound(double d);
		bool	isNanInf();
		int		findd(char c);

		std::string getValue() const;
};

#endif
