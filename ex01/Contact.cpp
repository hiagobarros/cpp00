/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-barr <hde-barr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:57:31 by hde-barr          #+#    #+#             */
/*   Updated: 2025/07/29 18:29:20 by hde-barr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.hpp"



    Contact::Contact(std::string index, std::string fst_name, std::string lst_name, std::string nickname, std::string number, std::string darkest_secret )
        {
            _index = index;
            _fst_name = fst_name;
            _lst_name = lst_name;
            _nickname = nickname;
			_number = number;
            _darkest_secret = darkest_secret;
        }
    Contact::~Contact( void ){}

    std::string Contact::to_string_int(int value)
    {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }

    std::string Contact::getvalue(e_opt opt)
    {
        switch (opt)
        {
			case FULLNAME:
				return (_fst_name + " " + _lst_name);
			case FIRSTNAME:
				return (_fst_name);
			case LASTNAME:
				return (_lst_name);
            case NICKNAME:
                return (_nickname);
			case NUMBER: 
				return (_number);
            case DARKEST_SECRET:
                return (_darkest_secret);
			default:
				return (_fst_name);
        }
    }
    void Contact::setIndex(int index)
    { 
        _index = to_string_int(index);
    }

    std::string Contact::getIndex()
    {
        return _index;
    }

