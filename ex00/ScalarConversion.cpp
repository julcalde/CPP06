/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:00:33 by julcalde          #+#    #+#             */
/*   Updated: 2026/01/16 14:56:31 by julcalde         ###   ########.fr       */
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
	long val = std::strtol(literal.c_str(), &end, 10);
	// Ensure that the entire string was consumed and it's not "-0"
	return (*end == '\0' && literal != "-0" && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
}

static bool isFloat(const std::string& literal)
{
	// Check for special float literals. -inff means negative infinity float
	// +inff means positive infinity float, nanf means not a number float
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-infF" || literal == "+infF" || literal == "nanF")
		return (true);
	// A valid float must end with 'f'
	char suffix = literal[literal.length() - 1];
	if (suffix != 'f' && suffix != 'F')
		return (false);
	// Use strtof to check if the string (excluding the last 'f') is a valid float
	char *end;
	std::strtof(literal.c_str(), &end);
	return ((*end == 'f' || *end == 'F') && *(end + 1) == '\0');
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

static void printFloat(double value, bool uppercase, int precision)
{
	std::string fsuffix = uppercase ? "F" : "f";
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nan" << fsuffix << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << fsuffix << std::endl;
	else
		std::cout << std::fixed << std::setprecision(precision) << static_cast<float>(value) << fsuffix << std::endl;

}

static void printDouble(double value, int precision)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(precision) << value << std::endl;
}

/* MAIN CONVERSION FUNCTION */

void ScalarConversion::convert(const std::string& literal)
{
	double value = 0.0;
	bool isFloatLiteral = false;
	bool uppercase = false;
	int precision = 1;
	
/* DETERMINE THE TYPE OF LITERAL AND CONVERT TO DOUBLE */
	if (isChar(literal))
		value = static_cast<double>(literal[0]);
	else if (isInt(literal))
		value = std::strtod(literal.c_str(), NULL);
	else if (isFloat(literal))
	{
		isFloatLiteral = true;
		uppercase = (literal[literal.length() -1] == 'F');
		value = std::strtod(literal.c_str(), NULL);
	}
	else if (isDouble(literal))
		value = std::strtod(literal.c_str(), NULL);
	else
		return (std::cout << "Invalid input" << std::endl, void());
	
	/* DETERMINE PRECISION */
	bool is_pseudo = std::isnan(value) || std::isinf(value);
	if (!is_pseudo)
	{
		std::string num_str = literal;
		if (isFloatLiteral)
			num_str = literal.substr(0, literal.length() - 1); // Remove 'f' or 'F'
		size_t dot_pos = num_str.find('.'); // Find decimal point
		if (dot_pos != std::string::npos) // If there's a decimal point
			precision = num_str.length() - dot_pos - 1; // Count digits after decimal
		if (precision == 0) // If no digits after decimal, set precision to 1
			precision = 1;
	}
	
	/* PRINT ALL TYPES */
	
	printChar(value);
	printInt(value);
	printFloat(value, uppercase, precision);
	printDouble(value, precision);
}