/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-barr <hde-barr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:54:23 by hde-barr          #+#    #+#             */
/*   Updated: 2025/07/28 19:34:43 by hde-barr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"

class Contact;
class ArrayContact;

class PhoneBook
{
    private:
        static ArrayContact  _list;
        
    public:
        
    PhoneBook();

    Contact getContact(int index);

    std::string to_string_int(int value);

    void addContact(Contact newContact);

    void printFUllInfoByIndex(int index);

	void printLineInfo(int i, e_opt opt);

    void searchContact();

};

#endif