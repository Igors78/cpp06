/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:02:30 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/28 14:37:54 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>

class Scalar
{

public:
	Scalar();
	Scalar(std::string const &num);
	Scalar(Scalar const &src);
	~Scalar();

	Scalar &operator=(Scalar const &rhs);

	double getValue() const;

	static void putChar(std::ostream &os, Scalar const &i);
	static void putInt(std::ostream &os, Scalar const &i);
	static void putFloat(std::ostream &os, Scalar const &i);
	static void putDouble(std::ostream &os, Scalar const &i);

	operator float(void) const;
	operator double(void) const;
	operator int(void) const;
	operator char(void) const;

	class TooBigException : public std::exception
	{
		char const *what() const throw();
	};
	class TooSmallException : public std::exception
	{
		char const *what() const throw();
	};
	class NotANumberException : public std::exception
	{
		char const *what() const throw();
	};

private:
	double _value;
};

std::ostream &operator<<(std::ostream &o, Scalar const &i);

#endif /* ********************************************************** SCALAR_H */