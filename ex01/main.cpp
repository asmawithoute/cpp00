#include "Phonebook.hpp"

int main()
{
    PhoneBook phone;
    std::string input;

    std::cout << "welcome to the phonebook\n";
    while (1)
    {
        std::cout << "enter 'ADD to add a new contact , 'SEARCH' to search for existing contacts or 'EXIT' to exit from the phonebook\n";
        getline(std::cin , input);
        if (input == "EXIT" || std::cin.eof())
            exit(0);
        if (input == "ADD")
            phone.add();
        else if (input == "SEARCH")
            phone.search();
        else
            std::cout << "cmd (" << input << ") doesn't exist!"<< std::endl;
    }
    return 0;
}
