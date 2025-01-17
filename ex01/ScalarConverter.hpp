/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConveter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:09:33 by pleander          #+#    #+#             */
/*   Updated: 2025/01/17 10:35:45 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter
{
   public:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter&) = delete;
	ScalarConverter& operator=(const ScalarConverter&) = delete;
	~ScalarConverter() = delete;

	static void convert(std::string value);
};

#endif
