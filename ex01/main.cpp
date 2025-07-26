#include <iostream>
#include <string>
#include "FixedArray.hpp"
#define RED "\033[31m"
#define YLW "\033[33m"
#define GRN "\033[32m"
#define RST "\033[0m"
#define SNK "\033[4m"

enum e_opt{
    FULLNAME,
    FIRSTNAME,
    LASTNAME,
	NUMBER
};

class Contact 
{
    private:
        std::string _index;
        std::string _fst_name;
        std::string _lst_name;
		std::string _number;
    public:
        Contact(std::string index = "", std::string fst_name = "", std::string lst_name = "", std::string number = "")
        {
            _index = index;
            _fst_name = fst_name;
            _lst_name = lst_name;
			_number = number;
        }

    std::string getvalue(e_opt opt)
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
    void setIndex(int index)
    { 
        _index = std::to_string(index);
    }

    std::string getIndex()
    {
        return _index;
    }

};

class PhoneBook
{
    private:
        std::array<Contact, 8> _list;
        
    public:
        
        PhoneBook()
        {
            for (size_t i = 0; i < _list.size(); i++)
                _list[i] = Contact(std::to_string(i + 1), "", "");
        }

    Contact getContact(int index)
    {
        return _list[index];
    }

    void addContact(Contact newContact)
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

	void printLineInfo(int i, e_opt opt)
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
			if(j > 9 - _list[i].getvalue(opt).length())
				std::cout<<SNK<<GRN<<_list[i].getvalue(opt).at(x++)<<RST;
			else if (_list[i].getvalue(opt).length() == 10)
				std::cout<<SNK<<GRN<<_list[i].getvalue(opt).at(x++)<<RST;
			else
				std::cout<<SNK<<GRN<<" "<<RST;
			
		}
	}
	}

    void searchContact()
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
            std::cout<<"|"<<YLW<<SNK"##["<<std::to_string(i+1)<<"]##-->"<<RST;
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

};

int main()
{
    PhoneBook phonebook;
    //std::cout<<phonebook.getContact(7).getname()<<std::endl;

    std::string fst_name;
    std::string lst_name;
    std::string number;
    std::string cmd;
	std::string wcm_msg =" /$$      /$$ /$$$$$$$$ /$$       /$$        /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$    \n\
| $$  /$ | $$| $$_____/| $$      | $$       /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/    \n\
| $$ /$$$| $$| $$      | $$      | $$      | $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$          \n\
| $$/$$ $$ $$| $$$$$   | $$      | $$      | $$      | $$  | $$| $$ $$/$$ $$| $$$$$       \n\
| $$$$_  $$$$| $$__/   | $$      | $$      | $$      | $$  | $$| $$  $$$| $$| $$__/       \n\
| $$$/ \\  $$$| $$      | $$      | $$      | $$    $$| $$  | $$| $$\\  $ | $$| $$          \n\
| $$/   \\  $$| $$$$$$$$| $$$$$$$$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \\/  | $$| $$$$$$$$    \n\
|__/     \\__/|________/|________/|________/ \\______/  \\______/ |__/     |__/|________/    \n\
                                                                                          \n\
                                                                                          \n\
                                                                                          \n\
                                     /$$$$$$$$ /$$$$$$                                    \n\
                                    |__  $$__//$$__  $$                                   \n\
                                       | $$  | $$  \\ $$                                   \n\
                                       | $$  | $$  | $$                                   \n\
                                       | $$  | $$  | $$                                   \n\
                                       | $$  | $$  | $$                                   \n\
                                       | $$  |  $$$$$$/                                   \n\
                                       |__/   \\______/                                    \n\
                                                                                          \n\
                                                                                          \n\
                                                                                          \n\
 /$$$$$$$  /$$   /$$  /$$$$$$  /$$   /$$ /$$$$$$$$ /$$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$\n\
| $$__  $$| $$  | $$ /$$__  $$| $$$ | $$| $$_____/| $$__  $$ /$$__  $$ /$$__  $$| $$  /$$/\n\
| $$  \\ $$| $$  | $$| $$  \\ $$| $$$$| $$| $$      | $$  \\ $$| $$  \\ $$| $$  \\ $$| $$ /$$/ \n\
| $$$$$$$/| $$$$$$$$| $$  | $$| $$ $$ $$| $$$$$   | $$$$$$$ | $$  | $$| $$  | $$| $$$$$/  \n\
| $$____/ | $$__  $$| $$  | $$| $$  $$$$| $$__/   | $$__  $$| $$  | $$| $$  | $$| $$  $$  \n\
| $$      | $$  | $$| $$  | $$| $$\\  $$$| $$      | $$  \\ $$| $$  | $$| $$  | $$| $$\\  $$\n\
| $$      | $$  | $$|  $$$$$$/| $$ \\  $$| $$$$$$$$| $$$$$$$/|  $$$$$$/|  $$$$$$/| $$ \\  $$\n\
|__/      |__/  |__/ \\______/ |__/  \\__/|________/|_______/  \\______/  \\______/ |__/  \\__/\n\
                                                                                          \n\
                                                                    						";
    std::cout<<GRN + wcm_msg + RST<<std::endl;
    while (1)
    {
		std::cout<<GRN"type a COMAND: "<<RST;
        std::cin>>cmd;
        if (cmd == "ADD")
        {
            if (std::cout<<"first name:" && std::cin>>fst_name \
            && std::cout<<"last name:" && std::cin>>lst_name\
            && std::cout<<"number:" && std::cin>>number)
                phonebook.addContact(Contact("", fst_name, lst_name, number));
        }
        else if (cmd == "SEARCH")
            phonebook.searchContact();
        else if (cmd == "EXIT")
            exit(0);
        else
            std::cout<<RED"**COMMAND \""<<cmd<<"\" NOT EXIST!** "<<std::endl<<YLW"Please try ADD, SEARCH or EXIT!"<<std::endl<<RST;

    }
}