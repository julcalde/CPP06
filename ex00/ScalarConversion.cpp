/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:00:33 by julcalde          #+#    #+#             */
/*   Updated: 2026/01/16 16:16:49 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

/* HELPER FUNCTIONS TO IDENTIFY THE TYPE OF LITERAL */

static bool isChar(const std::string& literal)
{
	// A single character that is not a digit is considered a char literal
	return (literal.length() == 1 && !std::isdigit(literal[0]) && !std::isdigit(literal[0]));
}

static bool isInt(const std::string& literal)
{
	// Use strtol to check if the entire string is a valid integer
	char *end;
	// strtol handles optional + or - signs, so we don't need to check them manually
	long val = std::strtol(literal.c_str(), &end, 10);
	// Ensure that the entire string was consumed and it's not "-0" and within int range
	return (*end == '\0' && literal != "-0" && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
}

static bool isFloat(const std::string& literal)
{
	// Check for special float literals. -inff means negative infinity float
	// +inff means positive infinity float, nanf means not a number float
	if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-infF" || literal == "+infF" || literal == "nanF")
		return (true);
	// A valid float must end with 'f' or 'F'
	if (literal.empty() || (literal.back() != 'f' && literal.back() != 'F'))
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
	// Use strtod to check if the entire string is a valid double
	char *end;
	std::strtod(literal.c_str(), &end);
	return (*end == '\0');
}

/* PRINTERS FOR EACH TYPE */

// Checks if value can be represented as char and print it
static void printChar(double value)
{
	std::cout << "char:	";
	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "impossible" <<  std::endl;
	else if (!std::isprint(static_cast<unsigned char>(value)))
		std::cout << "non displayablle" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

// Checks if value can be represented as int and print it
static void printInt(double value)
{
	std::cout << "int:	";
	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" <<  std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

// Checks if value can be represented as float and print it
static void printFloat(double value, bool uppercase)
{
	std::cout << "float:	";
	if (std:: isnan(value))
		std::cout << "nan" << (uppercase ? "F" : "f") << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << (uppercase ? "F" : "f") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << (uppercase ? "F" : "f") << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double:	";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

/* MAIN CONVERSION FUNCTION */

void ScalarConversion::convert(const std::string& literal)
{
	if (literal.empty())
	{
		std::cout << "char:		impossible" << std::endl;
		std::cout << "int:		impossible" << std::endl;
		std::cout << "float:	impossible" << std::endl;
		std::cout << "double:	impossible" << std::endl;
		return ;
	}
	bool uppercase = false;

	/* Char -case */
	if (isChar(literal))
	{
		char c = literal[0];
		double d = static_cast<double>(c);
		printChar(d);
		printInt(d);
		printFloat(d, uppercase);
		printDouble(d);
		return ;
	}

	/* Int -case */
	else if (isInt(literal))
	{
		int i = std::stoi(literal);
		double d = static_cast<double>(i);
		printChar(d);
		printInt(d);
		printFloat(d, uppercase);
		printDouble(d);
		return ;
	}

	/* Float - case */
	else if (isFloat(literal))
	{
		uppercase = (literal.back() == 'F');
		
		float f;
		if (literal == "nanf" || literal == "nanF")
			f = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff" || literal == "+infF")
			f = std::numeric_limits<float>::infinity();
		else if (literal == "-inff" || literal == "-infF")
			f = -std::numeric_limits<float>::infinity();
		else
			f = std::strtof(literal.c_str(), NULL);
		
		double d = static_cast<double>(f);
		printChar(d);
		printInt(d);
		printFloat(d, uppercase);
		printDouble(d);
		return ;
	}

	/* Double - case */
	else if (isDouble(literal))
	{
		double d;
		if (literal == "nan")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf")
			d = std::numeric_limits<double>::infinity();
		else if (literal == "-inf")
			d = -std::numeric_limits<double>::infinity();
		else
			d = std::strtod(literal.c_str(), NULL);
		
		printChar(d);
		printInt(d);
		printFloat(d, uppercase);
		printDouble(d);
		return ;
	}
}