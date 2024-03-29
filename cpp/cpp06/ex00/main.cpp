/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:58:53 by san               #+#    #+#             */
/*   Updated: 2022/08/05 14:58:56 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "put one parameter plz." << std::endl;
		return (1);
	}
	std::string	value = av[1];

	Convert convert(value);
	convert.conversion();
	
	return (0);
}
