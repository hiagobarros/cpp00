

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

class Contact 
{
    private:
        std::string _index;
        std::string _fst_name;
        std::string _lst_name;
        std::string _nickname;
        std::string _number;
        std::string _darkest_secret;
    public:
        Contact(std::string index = "", std::string fst_name = "", std::string lst_name = "", std::string nickname = "", std::string number = "", std::string darkest_secret = "");
        ~Contact( void );
        std::string to_string_int(int value);
        std::string getvalue(e_opt opt);
        void setIndex(int index);
        std::string getIndex();
};

#endif
