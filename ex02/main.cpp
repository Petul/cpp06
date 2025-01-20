/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:14:33 by pleander          #+#    #+#             */
/*   Updated: 2025/01/17 20:33:13 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"

Base *generate(void)
{
	float r = static_cast<float>(std::rand()) / RAND_MAX;
	if (r > 0 && r < 0.33)
	{
		return (new A());
	}
	else if (r >= 0.33 && r < 0.66)
	{
		return (new B());
	}
	else
	{
		return (new C());
	}
}

// dynamic_cast returns a null pointer for classes being pointed to
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
	}
}

// dynamic_cast cannot return null pointer for casts being referenced, so it
// throws std::bad_cast instead
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast &)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast &)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast &)
	{
	}
}
int main(void)
{
	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		Base *p = generate();
		identify(p);
		identify(*p);
		std::cout << "\n";
		delete p;
	}
}
