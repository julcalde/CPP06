/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:08:38 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/27 16:14:49 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

/* Data is a simple struct with an integer member.
   It has a constructor to initialize the value. */
struct Data
{
	int value;
	Data(int v = 0) : value(v) {}
};

class Serializer
{
	// Orthodox Canonical Form, but private to prevent instantiation
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);

	public:
		// Converts a pointer to Data into an integer representation
		static uintptr_t serialize(Data *ptr);
		// Converts an integer back into a pointer to Data
		static Data *deserialize(uintptr_t raw);
};

#endif