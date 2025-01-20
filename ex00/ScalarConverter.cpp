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
#include <iostream>
#include <limits>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	VOID,
};

bool is_char(std::string value)
{
	if (value.length() == 1 && !isdigit(value[0]) && isprint(value[0]))
	{
		return (true);
	}
	return (false);
}

bool is_int(std::string value)
{
	for (int i = 0; i < static_cast<int>(value.size()); i++)
	{
		if (!isdigit(value[i]))
		{
			return (false);
		}
	}
	return (true);
}

bool is_float(std::string value)
{
	if (value == "-inff" || value == "+inff" || value == "nanf")
	{
		return (true);
	}
	char *endp;
	strtof(value.c_str(), &endp);
	return (*endp == 'f' && endp != value.c_str());
}

bool is_double(std::string value)
{
	if (value == "-inf" || value == "+inf" || value == "nan")
	{
		return (true);
	}
	char *endp;
	strtod(value.c_str(), &endp);
	return (*endp == '\0' && endp != value.c_str());
}

Type find_type(std::string value)
{
	if (is_char(value))
	{
		std::cout << "type is char" << std::endl;
		return (CHAR);
	}
	if (is_int(value))
	{
		std::cout << "type is int" << std::endl;
		return (INT);
	}
	if (is_float(value))
	{
		std::cout << "type is float" << std::endl;
		return (FLOAT);
	}
	if (is_double(value))
	{
		std::cout << "type is double" << std::endl;
		return (DOUBLE);
	}
	return (VOID);
}

void print_int(long lv)
{
	if (lv > std::numeric_limits<int>::max() ||
	    lv < std::numeric_limits<int>::min())
	{
		std::cout << "impossible conversion" << std::endl;
		return;
	}
	int v = static_cast<int>(lv);

	if (v > std::numeric_limits<char>::max() ||
	    v < std::numeric_limits<char>::min())
	{
		std::cout << "char: impossible";
	}
	else if (!isprint(v))
	{
		std::cout << "char: Non displayable";
	}
	else
	{
		std::cout << "char: " << static_cast<char>(v);
	}
	std::cout << "\nint: " << static_cast<int>(v);
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "\nfloat: " << static_cast<float>(v) << "f";
	std::cout << "\ndouble: " << static_cast<double>(v) << std::endl;
}

void print_char(char v)
{
	if (isprint(v))
	{
		std::cout << "char: " << static_cast<char>(v);
	}
	else
	{
		std::cout << "char: Non displayable";
	}
	std::cout << "\nint: " << static_cast<int>(v);
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "\nfloat: " << static_cast<float>(v) << "f";
	std::cout << "\ndouble: " << static_cast<double>(v) << std::endl;
}

void print_float(double lv)
{
	if (lv > std::numeric_limits<float>::max() ||
	    lv < std::numeric_limits<float>::min())
	{
		std::cout << "impossible conversion" << std::endl;
		return;
	}
	float v = static_cast<float>(lv);
	if (std::isnan(v) || std::isinf(v))
	{
		std::cout << "char: impossible";
		std::cout << "\nint: impossible";
	}
	else
	{
		if (v > std::numeric_limits<char>::max() ||
		    v < std::numeric_limits<char>::min())
		{
			std::cout << "char: impossible";
		}
		else if (isprint(static_cast<char>(v)))
		{
			std::cout << "char: '" << static_cast<char>(v) << "'";
		}
		else
		{
			std::cout << "char: Non displayable";
		}
		if (static_cast<double>(v) < std::numeric_limits<int>::min() ||
		    static_cast<double>(v) > std::numeric_limits<int>::max())
		{
			std::cout << "\nint: impossible";
		}
		else
		{
			std::cout << "\nint: " << static_cast<int>(v);
		}
	}
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "\nfloat: " << static_cast<float>(v) << "f";
	std::cout << "\ndouble: " << static_cast<double>(v) << std::endl;
}

void print_double(long double lv)
{
	if (lv > std::numeric_limits<double>::max() ||
	    lv < std::numeric_limits<double>::min())
	{
		std::cout << "impossible conversion" << std::endl;
		return;
	}
	double v = static_cast<double>(lv);
	if (std::isnan(v) || std::isinf(v))
	{
		std::cout << "char: impossible";
		std::cout << "\nint: impossible";
	}
	else
	{
		if (v > std::numeric_limits<char>::max() ||
		    v < std::numeric_limits<char>::min())
		{
			std::cout << "char: impossible";
		}
		else if (isprint(static_cast<char>(v)))
		{
			std::cout << "char: '" << static_cast<char>(v) << "'";
		}
		else
		{
			std::cout << "char: Non displayable";
		}
		if (static_cast<double>(v) < std::numeric_limits<int>::min() ||
		    static_cast<double>(v) > std::numeric_limits<int>::max())
		{
			std::cout << "\nint: impossible";
		}
		else
		{
			std::cout << "\nint: " << static_cast<int>(v);
		}
	}
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "\nfloat: " << static_cast<float>(v) << "f";
	std::cout << "\ndouble: " << static_cast<double>(v) << std::endl;
}

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

void ScalarConverter::convert(std::string value)
{
	Type type{find_type(value)};

	switch (type)
	{
		case CHAR:
			print_char(value[0]);
			break;
		case INT:
			print_int(strtol(value.c_str(), NULL, 0));
			break;
		case FLOAT:
			print_float(strtod(value.c_str(), NULL));
			break;
		case DOUBLE:
			print_double(strtold(value.c_str(), NULL));
			break;
		case VOID:
			std::cout << "Error: Unkown literal." << std::endl;
			break;
	}
}
