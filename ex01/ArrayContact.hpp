
#ifndef ARRAY_CONTACT_HPP
#define ARRAY_CONTACT_HPP

#include "main.hpp"

class Contact;

class ArrayContact
{
    private:
        static const int n;
        static Contact _arr[8];
    public:
        ArrayContact(void);
        ~ArrayContact(void);
        Contact& operator[](int index);
        const Contact& operator[](int index) const;
        int size() const;
        Contact* begin();
        Contact* end();
        const Contact* begin() const;
        const Contact* end() const;
};

#endif

