/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:08:35 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/27 16:40:16 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* The Serializer class provides static methods to serialize and deserialize
   pointers to Data objects. The serialize method converts a Data pointer
   into an unsigned integer representation (uintptr_t), and the deserialize method
   converts the unsigned integer back into a Data pointer.
*/
/* reinterpret_cast is used to perform the conversions, ensuring that the pointer
   and integer types are treated correctly without changing the underlying bit pattern.
*/

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}