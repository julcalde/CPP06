/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:50:57 by julcalde          #+#    #+#             */
/*   Updated: 2026/01/10 16:43:52 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP
# include <iostream>	// For std::cout, std::cerr, std::endl
# include <iomanip>	// For std::setprecision and std::fixed
# include <limits>	// For std::numeric_limits and std::isinf
# include <cmath>	// For std::isnan, std::isinf and std::fabs
# include <cstdlib>	// For std::strtod, std::strtol and std::strtof
# include <cctype>	// For std::isdigit and std::isprint
# include <string>

class ScalarConversion
{
	// Orthodox Canonical Form, but private to prevent instantiation
	private:
		ScalarConversion();
		~ScalarConversion();
		ScalarConversion(const ScalarConversion&);
		ScalarConversion& operator=(const ScalarConversion&);
		
	public:
		static void convert(const std::string& literal);
};

#endif