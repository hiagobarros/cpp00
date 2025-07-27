/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-barr <hde-barr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:57:31 by hde-barr          #+#    #+#             */
/*   Updated: 2025/07/27 21:32:46 by hde-barr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.hpp"



    Contact::Contact(std::string index, std::string fst_name, std::string lst_name, std::string number )
        {
            _index = index;
            _fst_name = fst_name;
            _lst_name = lst_name;
			_number = number;
        }

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
			case NUMBER: 
				return (_number);
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

