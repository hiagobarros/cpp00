

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
        
    PhoneBook( void );
    ~PhoneBook( void );

    Contact getContact(int index);

    std::string to_string_int(int value);

    void addContact(Contact newContact);

    void printFUllInfoByIndex(int index);

	void printLineInfo(int i, e_opt opt);

    static bool number_validator(std::string num);

    static bool inter(char num);

    void searchContact();

};

#endif