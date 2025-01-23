/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:47:52 by pleander          #+#    #+#             */
/*   Updated: 2025/01/17 14:51:42 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main(void)
{
	Data d{"foo", 42, 42.42f};

	std::cout << "Address of original data: " << &d << std::endl;

	uintptr_t raw = Serializer::serialize(&d);
	Data *deserialized = Serializer::deserialize(raw);

	std::cout << "Address of deserialized data: " << deserialized << std::endl;
	std::cout << "Data: (" << d.msg << ", " << d.num << ", " << d.f << ")\n";
}
