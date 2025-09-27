/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:45:40 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/27 17:31:26 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

/* In this main function we generate a random instance of one of the derived classes (A, B, or C)
   using the generate function. We then identify the type of the generated object
   using both pointer and reference versions of the identify function. Finally,
   we clean up by deleting the dynamically allocated object.
*/
int main(void)
{
	// randomly generate and identify multiple times to demonstrate functionality
	Base *obj1 = generate();
	std::cout << "Identifying using pointer: ";
	identify(obj1);
	std::cout << "Identifying using reference: ";
	identify(*obj1);
	delete obj1;

	// Repeat to show randomness
	Base *obj2 = generate();
	std::cout << "Identifying using pointer: ";
	identify(obj2);
	std::cout << "Identifying using reference: ";
	identify(*obj2);
	delete obj2;

	// Repeat to show randomness
	Base *obj3 = generate();
	std::cout << "Identifying using pointer: ";
	identify(obj3);
	std::cout << "Identifying using reference: ";
	identify(*obj3);
	delete obj3;

	// Repeat to show randomness
	Base *obj4 = generate();
	std::cout << "Identifying using pointer: ";
	identify(obj4);
	std::cout << "Identifying using reference: ";
	identify(*obj4);
	delete obj4;

	return (0);
}