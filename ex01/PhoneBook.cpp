

#include "main.hpp"


        ArrayContact PhoneBook::_list;

        PhoneBook::PhoneBook()
        {
            for (int i = 0; i < _list.size(); i++)
                _list[i] = Contact(to_string_int(i + 1), "", "", "", "", "");
        }
        PhoneBook::~PhoneBook(){}

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

    void PhoneBook::printFUllInfoByIndex(int index)
    {
        if(_list[index-1].getvalue(FIRSTNAME).length() > 0)
            std::cout<<GRN<<"First name ⬅️ :"<<RST<<_list[index-1].getvalue(FIRSTNAME)<<std::endl;
        else
            std::cout<<GRN<<"First name ⬅️ :"<<RED<<" <Empty>"<<RST<<std::endl;
            
        if(_list[index-1].getvalue(LASTNAME).length() > 0)
            std::cout<<BLU<<"Last name ➡️ :"<<RST<<_list[index-1].getvalue(LASTNAME)<<std::endl;
        else
            std::cout<<GRN<<"Last name ➡️ :"<<RED<<" <Empty>"<<RST<<std::endl;

        if(_list[index-1].getvalue(NICKNAME).length() > 0)
            std::cout<<YLW<<"Nickname 🥷:"<<RST<<_list[index-1].getvalue(NICKNAME)<<std::endl;
        else
            std::cout<<GRN<<"Nickname 🥷:"<<RED<<" <Empty>"<<RST<<std::endl;
        
        if(_list[index-1].getvalue(NUMBER).length() > 0)     
            std::cout<<GRY<<"Phone number ☎️ :"<<RST<<_list[index-1].getvalue(NUMBER)<<std::endl;
        else
            std::cout<<GRN<<"Phone number ☎️ :"<<RED<<" <Empty>"<<RST<<std::endl;
        
        if(_list[index-1].getvalue(DARKEST_SECRET).length() > 0)     
            std::cout<<RED<<"Darkest secret 😈:"<<RST<<_list[index-1].getvalue(DARKEST_SECRET)<<std::endl;
        else
            std::cout<<GRN<<"Darkest secret 😈:"<<RED<<" <Empty>"<<RST<<std::endl;    
    }

    void PhoneBook::searchContact()
    {
		std::cout<<" "<<YLW<<SNK"                                           "<<RST<<std::endl;
		std::cout<<YLW<<\
		"|"<<SNK<<"     INDEX|"\
				 <<"FISRT NAME"\
		 <<YLW"|"<<" LAST NAME"\
		 	  "|"<<"  NICKNAME"
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
				printLineInfo(i, NICKNAME);
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

    bool PhoneBook::inter(char num)
    {
        bool res = false;
        std::string nums = "0123456789";
        
        for(size_t i = 0; i < nums.length(); i++)
        {
            if(num == nums.at(i))
                res = true;
        }
        return(res);
    }
    
    bool PhoneBook::number_validator(std::string num)
    {
        for(size_t i = 0; i < num.length(); i++)
        {
            if(!inter(num.at(i)))
            {
                return (false);
            }
                //std::cout<<num.at(i)<<std::endl;
        }
        return(true);
    }
