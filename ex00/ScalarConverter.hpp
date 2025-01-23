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

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	VOID,
};

class ScalarConverter
{
   private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();
	static bool is_char(std::string value);
	static bool is_int(std::string value);
	static bool is_float(std::string value);
	static bool is_double(std::string value);
	static Type find_type(std::string value);
	static void output(char val);
	static void output(int val);
	static void output(float val);
	static void output(double val);
	static void print_char(double);
	static void print_int(double);
	static void print_float(double);
	static void print_double(double);

   public:
	static void convert(std::string value);
};

#endif
