/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:07:26 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/28 14:57:25 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <limits.h>
#include <math.h>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Scalar::Scalar()
	: _value(0)
{
}

Scalar::Scalar(std::string const &num)
{
	this->_value = strtod(num.c_str(), 0);
}

Scalar::Scalar(const Scalar &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Scalar::~Scalar()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Scalar &Scalar::operator=(Scalar const &rhs)
{
	if (this != &rhs)
	{
		this->_value = rhs.getValue();
	}
	return *this;
}

Scalar::operator float(void) const
{
	return (static_cast<float>(this->_value));
}

Scalar::operator double(void) const
{
	return (static_cast<double>(this->_value));
}

Scalar::operator int(void) const
{
	if (isnan(this->_value))
		throw Scalar::NotANumberException();
	if (this->_value > static_cast<double>(INT_MAX))
		throw Scalar::TooBigException();
	if (this->_value < static_cast<double>(INT_MIN))
		throw Scalar::TooSmallException();
	return (static_cast<int>(this->_value));
}

Scalar::operator char(void) const
{
	if (isnan(this->_value))
		throw Scalar::NotANumberException();
	if (this->_value > static_cast<double>(CHAR_MAX))
		throw Scalar::TooBigException();
	if (this->_value < static_cast<double>(CHAR_MIN))
		throw Scalar::TooSmallException();
	return (static_cast<char>(this->_value));
}

std::ostream &operator<<(std::ostream &o, Scalar const &i)
{
	Scalar::putChar(o, i);
	Scalar::putInt(o, i);
	Scalar::putFloat(o, i);
	Scalar::putDouble(o, i);
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
char const *Scalar::TooBigException::what() const throw()
{
	return ("Number too big");
}

char const *Scalar::TooSmallException::what() const throw()
{
	return ("Number too small");
}

char const *Scalar::NotANumberException::what() const throw()
{
	return ("Not a number");
}

void Scalar::putChar(std::ostream &o, const Scalar &i)
{
	o << "Char: ";
	try
	{
		char c = static_cast<char>(i);
		if (std::isprint(c))
			o << c;
		else
			o << "Non displayable";
	}
	catch (std::exception &e)
	{
		o << "Impossible: " << e.what();
	}
	o << std::endl;
}

void Scalar::putInt(std::ostream &o, const Scalar &i)
{
	o << "Int: ";
	try
	{
		int n = static_cast<int>(i);
		o << n;
	}
	catch (std::exception &e)
	{
		o << "Impossible: " << e.what();
	}
	o << std::endl;
}

void Scalar::putFloat(std::ostream &o, const Scalar &i)
{
	o << "Float: ";
	float f = static_cast<float>(i);
	if (isinff(f) == 1)
		o << "+inf";
	else if (isinff(f) == -1)
		o << "-inf";
	else if (isnanf(f) == 1)
		o << "nan";
	else
	{
		o << f;
		if (f == 0)
			o << ".0";
	}
	o << "f" << std::endl;
}

void Scalar::putDouble(std::ostream &o, const Scalar &i)
{
	o << "Double: ";
	double d = static_cast<double>(i);
	if (isinff(d) == 1)
		o << "+inf";
	else if (isinff(d) == -1)
		o << "-inf";
	else if (isnan(d) == 1)
		o << "nan";
	else
	{
		o << d;
		if (d == 0)
			o << ".0";
	}
	o << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
double Scalar::getValue() const
{
	return this->_value;
}
/* ************************************************************************** */