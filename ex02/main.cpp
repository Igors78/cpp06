/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:40:37 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/28 16:11:35 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <iostream>

Base *generate()
{
	switch (rand() % 3)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

void identify(Base *base)
{
	A *a = dynamic_cast<A *>(base);
	if (a)
	{
		std::cout << "A" << std::endl;
		return;
	}

	B *b = dynamic_cast<B *>(base);
	if (b)
	{
		std::cout << "B" << std::endl;
		return;
	}

	C *c = dynamic_cast<C *>(base);
	if (c)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base &base)
{
	try
	{
		(void)dynamic_cast<A &>(base);
		std::cout << "A" << std::endl;
	}
	catch (std::exception)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(base);
		std::cout << "B" << std::endl;
	}
	catch (std::exception)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(base);
		std::cout << "C" << std::endl;
	}
	catch (std::exception)
	{
	}
}

int main()
{
	srand(time(NULL));
	Base *base[5];
	for (int i = 0; i < 5; i++)
		base[i] = generate();
	std::cout << "Identity with pointer" << std::endl;
	for (int i = 0; i < 5; i++)
		identify(base[i]);
	std::cout << "Identity with reference" << std::endl;
	for (int i = 0; i < 5; i++)
		identify(*base[i]);
}