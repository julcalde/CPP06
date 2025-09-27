/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:45:44 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/27 17:16:11 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

// Base class with virtual destructor
class Base
{
	public:
		virtual ~Base() {};
};

// Derived classes
class A : public Base {};
class B : public Base {};
class C : public Base {};

// Function prototypes for generating and identifying objects of derived classes
Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif