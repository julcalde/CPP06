/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:45:42 by julcalde          #+#    #+#             */
/*   Updated: 2026/01/15 14:51:42 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	// Generate a random number between 0 and 2 by modulus operation by 3
	int choice = std::rand() % 3;
	switch (choice)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL); // just for safety, but should never reach here
	}
}

/* Identify the type of the object pointed to by p using dynamic_cast */
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

/* Identify the type of the object referred to by p using dynamic_cast and handle exceptions.
	This function tries to cast the reference to each derived class type.
	If the cast is successful, it prints the corresponding class name.
	If the cast fails, it catches the std::bad_cast exception and tries the next type.
	If none of the casts are successful, it does nothing. But in practice, one of the casts should succeed.
*/
void identify(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}