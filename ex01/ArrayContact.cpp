
#include "main.hpp"
        const int ArrayContact::n = 8;
        Contact ArrayContact::_arr[8];

        ArrayContact::ArrayContact(){}
        ArrayContact::~ArrayContact(){}

        Contact& ArrayContact::operator[](int index)
        {
            return _arr[index];
        }
        const Contact& ArrayContact::operator[](int index) const 
        {
            return _arr[index];
        }
        int ArrayContact::size() const 
        {
            return n;
        }
        Contact* ArrayContact::begin()
        {
            return _arr;
        }
        Contact* ArrayContact::end()
        {
            return _arr + n;
        }
        const Contact* ArrayContact::begin() const
        {
            return _arr;
        }
        const Contact* ArrayContact::end() const
        {
            return _arr + n;
        }