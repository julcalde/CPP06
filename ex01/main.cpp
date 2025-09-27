/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:23:30 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/27 16:34:19 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data(42);
	Data *ptr = &data;

	std::cout << "Original pointer: " << ptr << " value: " << ptr->value << std::endl;

	uintptr_t serialized = Serializer::serialize(ptr);
	std::cout << "Serialized value: " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized pointer: " << deserialized << ", value: " << deserialized->value << std::endl;

	if (ptr == deserialized)
		std::cout << "Deserialization successful, pointers match!" << std::endl;
	else
		std::cout << "Deserialization failed, pointers do not match!" << std::endl;

	return (0);
}