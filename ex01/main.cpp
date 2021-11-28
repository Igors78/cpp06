/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:15:19 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/28 15:32:08 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <stdint.h>
#include <iostream>

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data data;

	data.n = 42;
	std::cout << " Value : " << data.n << " Home address : "
			  << &data.n << std::endl;
	uintptr_t raw = serialize(&data);
	std::cout << "Serialized address : " << &raw << std::endl;
	Data *nn = deserialize(raw);
	std::cout << " Value : " << nn->n << " Deserialized address : "
			  << &nn->n << std::endl;
}