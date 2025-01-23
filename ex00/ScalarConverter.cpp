/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConveter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:38:03 by pleander          #+#    #+#             */
/*   Updated: 2025/01/17 10:50:08 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return (*this);
}
ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::is_char(std::string value)
{
	if (value.length() == 1 && !isdigit(value[0]) && isprint(value[0]))
	{
		return (true);
	}
	return (false);
}

bool ScalarConverter::is_int(std::string value)
{
	for (int i = 0; i < static_cast<int>(value.size()); i++)
	{
		if (i == 0 && value[i] == '-')
		{
			continue;
		}
		if (!isdigit(value[i]))
		{
			return (false);
		}
	}
	return (true);
}

bool ScalarConverter::is_float(std::string value)
{
	if (value == "-inff" || value == "+inff" || value == "nanf")
	{
		return (true);
	}
	char *endp;
	strtof(value.c_str(), &endp);
	return (*endp == 'f' && endp != value.c_str());
}

bool ScalarConverter::is_double(std::string value)
{
	if (value == "-inf" || value == "+inf" || value == "nan")
	{
		return (true);
	}
	char *endp;
	strtod(value.c_str(), &endp);
	return (*endp == '\0' && endp != value.c_str());
}

Type ScalarConverter::find_type(std::string value)
{
	if (is_char(value))
	{
		return (CHAR);
	}
	else if (is_int(value))
	{
		return (INT);
	}
	else if (is_float(value))
	{
		return (FLOAT);
	}
	else if (is_double(value))
	{
		return (DOUBLE);
	}
	return (VOID);
}

void ScalarConverter::output(char val)
{
	print_char(val);
	print_int(val);
	print_float(val);
	print_double(val);
}

void ScalarConverter::output(int val)
{
	print_char(val);
	print_int(val);
	print_float(val);
	print_double(val);
}

void ScalarConverter::output(float val)
{
	print_char(val);
	print_int(val);
	print_float(val);
	print_double(val);
}

void ScalarConverter::output(double val)
{
	print_char(val);
	print_int(val);
	print_float(val);
	print_double(val);
}

void ScalarConverter::print_char(double val)
{
	if (val > std::numeric_limits<char>::max() ||
	    val < std::numeric_limits<char>::lowest() || std::isnan(val))
	{
		std::cout << "char: impossible";
	}
	else if (!isprint(val))
	{
		std::cout << "char: Non displayable";
	}
	else
	{
		std::cout << "char: '" << static_cast<char>(val) << "'";
	}
}

void ScalarConverter::print_int(double val)
{
	if (val < std::numeric_limits<int>::lowest() ||
	    val > std::numeric_limits<int>::max() || std::isnan(val))
	{
		std::cout << "\nint: impossible";
	}
	else
	{
		std::cout << "\nint: " << static_cast<int>(val);
	}
}

void ScalarConverter::print_float(double val)
{
	if (val < std::numeric_limits<float>::lowest() ||
	    val > std::numeric_limits<float>::max())
	{
		std::cout << "\nfloat: impossible";
	}
	else
	{
		std::cout << std::setprecision(1) << std::fixed
		          << "\nfloat: " << static_cast<float>(val) << "f";
	}
}

void ScalarConverter::print_double(double val)
{
	std::cout << std::setprecision(1) << std::fixed << "\ndouble: " << val
	          << std::endl;
}

void ScalarConverter::convert(std::string value)
{
	Type type{find_type(value)};
	switch (type)
	{
		case CHAR:
			output(value[0]);
			break;
		case INT:
			output(std::stoi(value));
			break;
		case FLOAT:
			output(std::stof(value));
			break;
		case DOUBLE:
			output(std::stod(value));
			break;
		case VOID:
			std::cout << "Error: Unknown literal." << std::endl;
			break;
	}
}
