/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:57:14 by pleander          #+#    #+#             */
/*   Updated: 2025/01/17 10:50:12 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !isprint(*argv[1]))
	{
		std::cout << "Error: usage ./convert <printable literal>" << std::endl;
		exit(1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
