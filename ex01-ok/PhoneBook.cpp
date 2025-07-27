/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-barr <hde-barr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:06:30 by hde-barr          #+#    #+#             */
/*   Updated: 2025/07/27 21:48:01 by hde-barr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


        ArrayContact PhoneBook::_list;

        PhoneBook::PhoneBook()
        {
            for (int i = 0; i < _list.size(); i++)
                _list[i] = Contact(to_string_int(i + 1), "", "");
        }

    Contact PhoneBook::getContact(int index)
    {
        return _list[index];
    }

    std::string PhoneBook::to_string_int(int value)
    {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }

    void PhoneBook::addContact(Contact newContact)
    {
        static int n = 0;
        n %= 8;
        newContact.setIndex(n);
        _list[n] = newContact;
        std::cout<<"added new contact!"<<std::endl;
        std::cout<<"name: " + newContact.getvalue(FULLNAME)<<std::endl;
        std::cout<<_list[0].getvalue(FULLNAME)<<std::endl;
        std::cout<<_list.begin()->getIndex()<<std::endl;
        n++;
    }

	void PhoneBook::printLineInfo(int i, e_opt opt)
	{
	for(int j = 0, x = 0; j < 10; j++)
	{

		
		if(_list[i].getvalue(opt).length() > 10)
		{
			if(j < 9)
				std::cout<<SNK<<GRN<<_list[i].getvalue(opt).at(j)<<RST;
            else if (j == 9 )
				std::cout<<SNK<<GRN"."<<RST;
		}
		else
		{
			if(j > (int)(9 - _list[i].getvalue(opt).length()))
				std::cout<<SNK<<GRN<<_list[i].getvalue(opt).at(x++)<<RST;
			else if (_list[i].getvalue(opt).length() == 10)
				std::cout<<SNK<<GRN<<_list[i].getvalue(opt).at(x++)<<RST;
			else
				std::cout<<SNK<<GRN<<" "<<RST;
			
		}
	}
	}

    void PhoneBook::searchContact()
    {
		std::cout<<" "<<YLW<<SNK"                                           "<<RST<<std::endl;
		std::cout<<YLW<<\
		"|"<<SNK<<"     INDEX|"\
				 <<"FISRT NAME"\
		 <<YLW"|"<<" LAST NAME"\
		 	  "|"<<"    NUMBER"
		<<RST<<"|"<<std::endl;
        for(int i = 0; i < _list.size(); i++)
        {
            std::cout<<"|"<<YLW<<SNK"##["<<to_string_int(i+1)<<"]##-->"<<RST;
            if(_list[i].getvalue(FIRSTNAME) != "")
            {
				std::cout<<"|";

				printLineInfo(i, FIRSTNAME);
                std::cout<<"|";
				printLineInfo(i, LASTNAME);
                std::cout<<"|";
				printLineInfo(i, NUMBER);
				std::cout<<"|"<<std::endl;
            }
            else
			{				
                std::cout<<"|"<<RED<<SNK"   <Empty>"<<RST;
                std::cout<<"|"<<RED<<SNK"   <Empty>"<<RST;
                std::cout<<"|"<<RED<<SNK"   <Empty>"<<RST<<"|"<<std::endl;
			}
        }
    }
