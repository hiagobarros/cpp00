
#include "main.hpp"











int main()
{
    PhoneBook phonebook;

    std::string fst_name;
    std::string lst_name;
    std::string nickname;
    std::string number;
    std::string darkest_secret;
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
    //std::string index;
    while (!std::cin.eof())
    {
		std::cout<<GRN"type a COMAND: "<<RST;
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
        {
            try
            {
                std::cout<<"first name:";
                std::getline(std::cin, fst_name);
                if(fst_name.empty())
                    throw std::runtime_error(RED"INVALID FIST NAME!");
                std::cout<<"last name:";
                std::getline(std::cin, lst_name);
                if(lst_name.empty())
                    throw std::runtime_error(RED"INVALID LAST NAME!");
                std::cout<<"nickname:";
                std::getline(std::cin, nickname);
                if(nickname.empty())
                    throw std::runtime_error(RED"INVALID NICKNAME!");
                std::cout<<"number:";
                std::getline(std::cin, number);
                if(number.empty())
                    throw std::runtime_error(RED"INVALID NUMBER!");
                std::cout<<"darkest secret:";
                std::getline(std::cin, darkest_secret);
                if(darkest_secret.empty())
                    throw std::runtime_error(RED"INVALID DARKEST SECRET!");
                phonebook.PhoneBook::addContact(Contact("", fst_name, lst_name, nickname, number, darkest_secret));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what()<<RST<<std::endl;
            }
            

        }
        else if (cmd == "SEARCH")
        {
            phonebook.PhoneBook::searchContact();
            std::cout<<"type index:";
            std::getline(std::cin, cmd);
            if(cmd.length() == 1)
            {
                std::istringstream res_index(cmd);
                int num;
                res_index >> num;
                if(num > 0 && num <= 8)
                    phonebook.PhoneBook::printFUllInfoByIndex(num);
                else
                    std::cout<<RED<<"INPUT INVALID!"<<RST<<std::endl;
            }
            else
                std::cout<<RED<<"IMPUT INVALID!"<<RST<<std::endl;

        }
        else if (cmd == "EXIT")
            std::exit(0);
        else
            std::cout<<RED"**COMMAND \""<<cmd<<"\" NOT EXIST!** "<<std::endl<<YLW"Please try ADD, SEARCH or EXIT!"<<std::endl<<RST;

    }
}

