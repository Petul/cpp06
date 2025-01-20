/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:06:54 by pleander          #+#    #+#             */
/*   Updated: 2025/01/17 20:16:13 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
   public:
	virtual ~Base()
	{
	}
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};
#endif
