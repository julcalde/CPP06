/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:50:57 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/27 15:05:36 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

# include <string>

class ScalarConversion
{
	// Orthodox Canonical Form, but private to prevent instantiation
	private:
		ScalarConversion();
		~ScalarConversion();
		ScalarConversion(const ScalarConversion& other);
		ScalarConversion& operator=(const ScalarConversion& other);
		
	public:
		static void convert(const std::string& input);
};

#endif