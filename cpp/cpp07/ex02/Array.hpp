/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:02:18 by san               #+#    #+#             */
/*   Updated: 2022/08/05 15:02:19 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T> 
class Array
{
	private:
		T				*arr;
		unsigned int	len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &array);
		~Array();
		Array	&operator=(const Array<T> &array);
		T		&operator[](int i);

		unsigned int	size() const;

		class IndexOutOfBound : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

template <typename T>
Array<T>::Array()
{
	this->arr = NULL;
	len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	len = n;
	arr = new T[len];
	for (unsigned int i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}

template <typename T>
Array<T>::Array(const Array<T> &array)
{
	this->len = array.size();
	this->arr = new T[len];
	for (unsigned int i = 0; i < len; i++)
	{
		this->arr[i] = array.arr[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	if (this->arr[0])
		delete [] arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &array)
{
	if (this->arr)
		delete [] this->arr;
	this->len = array.size();
	this->arr = new T[len];
	for (unsigned int i = 0; i < len; i++)
	{
		this->arr[i] = array.arr[i];
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](int i)
{
	if (i >= static_cast<int>(len) || i < 0)
		throw (IndexOutOfBound());
	return (arr[i]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

template <typename T>
const char	*Array<T>::IndexOutOfBound::what() const throw()
{
	return "Index is OUT OF BOUND";
}

#endif
