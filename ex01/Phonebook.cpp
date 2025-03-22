#include "phonebook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string input;

    std::cout << "welcome to the phonebook\n";
    while (1)
    {
        std::cout << "enter 'ADD to add a new contact , 'SEARCH' to search for existing contacts or 'EXIT' to exit from the phonebook\n";
        getline(std::cin , input);
        if (input == "EXIT")
            exit(0);
        if (input == "ADD")
            add(&phonebook);
        else if (input == "SEARCH")
            search(&phonebook);
        else
            std::cout << "cmd (" << input << ") doesn't exist!"<< std::endl;
    }
    return 0;
}
