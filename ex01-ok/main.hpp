/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-barr <hde-barr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:45:25 by hde-barr          #+#    #+#             */
/*   Updated: 2025/07/27 20:13:19 by hde-barr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

enum e_opt{
    FULLNAME,
    FIRSTNAME,
    LASTNAME,
	NUMBER
};

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "ArrayContact.hpp"

#define RED "\033[31m"
#define YLW "\033[33m"
#define GRN "\033[32m"
#define RST "\033[0m"
#define SNK "\033[4m"




#endif