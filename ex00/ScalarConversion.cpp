/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:00:33 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/27 15:36:36 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <iostream>	// For std::cout, std::cerr, std::endl
#include <iomanip>	// For std::setprecision and std::fixed
#include <limits>	// For std::numeric_limits and std::isinf
#include <cmath>	// For std::isnan, std::isinf and std::fabs
#include <cstdlib>	// For std::strtod, std::strtol and std::strtof
#include <cctype>	// For std::isdigit and std::isprint


static bool isChar(const std::string& literal)
{
	// A single character that is not a digit is considered a char literal
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

static bool isInt(const std::string& literal)
{
	// Use strtol to check if the entire string is a valid integer
	char *end;
	std::strtol(literal.c_str(), &end, 10);
	// Ensure that the entire string was consumed and it's not "-0"
	return (*end == '\0' && literal != "-0");
}

static bool isFloat(const std::string& literal)
{
	// Check for special float literals. -inff means negative infinity float
	// +inff means positive infinity float, nanf means not a number float
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);
	// A valid float must end with 'f'
	if (literal[literal.length() - 1] != 'f')
		return (false);
	// Use strtof to check if the string (excluding the last 'f') is a valid float
	char *end;
	std::strtof(literal.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDouble(const std::string& literal)
{
	// Same as float but without 'f' at the end and strtod instead of strtof
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);
	char *end;
	std::strtod(literal.c_str(), &end);
	return (*end == '\0');
}

static void printChar(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
	if (std::isnan(value) || std::isinf(value) ||  value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value, bool isFloatLiteral)
{
	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(isFloatLiteral ? 1 : 1) << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value)
{
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}