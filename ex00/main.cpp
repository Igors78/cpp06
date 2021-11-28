/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:43:31 by ioleinik          #+#    #+#             */
/*   Updated: 2021/11/28 14:44:26 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Scalar n(argv[1]);

		std::cout << n;
	}
	else
		std::cout << "Usage: ./convert <number>" << std::endl;
	return 0;
}