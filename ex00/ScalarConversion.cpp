/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:00:33 by julcalde          #+#    #+#             */
/*   Updated: 2026/01/15 14:20:09 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

/* HELPER FUNCTIONS TO IDENTIFY THE TYPE OF LITERAL */

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

/* PRINTERS FOR EACH TYPE */

static void printChar(double value)
{
	// char limits are from 0 to 127 in ASCII
	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	// Check if the char is printable using isprint from <cctype>
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
	// Check for NaN, infinity and out of int range
	// int limits are from -2147483648 to 2147483647
	if (std::isnan(value) || std::isinf(value) ||  value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value, bool isFloatLiteral)
{
	// Use std::isnan and std::isinf to check for special float values
	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
	// Check if the float is an integer value to decide precision
	else
	// boolean isFloatLiteral is set to true eitherway if the original literal was a float
		std::cout << "float: " << std::fixed << std::setprecision(isFloatLiteral ? 1 : 1) << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value)
{
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
	// Check if the double is an integer value to decide precision
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

/* MAIN CONVERSION FUNCTION */

void ScalarConversion::convert(const std::string& literal)
{
	double value = 0.0;
	bool isFloatLiteral = false;

	if (isChar(literal))
		value = static_cast<double>(literal[0]);
	else if (isInt(literal))
		value = static_cast<double>(std::atoi(literal.c_str()));
	else if (isFloat(literal))
	{
		isFloatLiteral = true;
		if (literal == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "-inff")
			value = -std::numeric_limits<double>::infinity();
		else if (literal == "+inff")
			value = std::numeric_limits<double>::infinity();
		else
			value = std::atof(literal.c_str());
	}
	else if (isDouble(literal))
	{	
		if (literal == "nan")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "-inf")
			value = -std::numeric_limits<double>::infinity();
		else if (literal == "+inf")
			value = std::numeric_limits<double>::infinity();
		else
			value = std::atof(literal.c_str());
	}
	else
		return (std::cout << "Invalid input" << std::endl, void());
	
	/* PRINT ALL TYPES */
	
	printChar(value);
	printInt(value);
	printFloat(value, isFloatLiteral);
	printDouble(value);
}