#include <iostream>
#include <cstdlib>
#include <iomanip>

class Contact
{
    public :
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

class PhoneBook
{
    public :
        Contact mycontacts[8];
        int num_of_contacts;
};



void    add(PhoneBook* phone)
{
    Contact cont;
    std::string input{};

    std::cout << "enter a new contact\n";
    getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "plz enter a first name" << std::endl;
        getline(std::cin, input);
    }
    cont.first_name = input;
    std::cout << "plz enter a last name" << std::endl;
    getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "plz enter a last name" << std::endl;
        getline(std::cin, input);
    }
    cont.last_name = input;
    std::cout << "plz enter a nickname" << std::endl;
    getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "plz enter a nickname" << std::endl;
        getline(std::cin, input);
    }
    cont.nickname = input;
    std::cout << "plz enter a phone number" << std::endl;
    getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "plz enter a phone number" << std::endl;
        getline(std::cin, input);
    }
    cont.phone_number = input;
    std::cout << "plz enter the contact's darkest secret" << std::endl;
    getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "plz enter the contact's darkest secret" << std::endl;
        getline(std::cin, input);
    }
    cont.darkest_secret = input;
    phone->mycontacts[phone->num_of_contacts] = cont;
    phone->num_of_contacts++;
    if(phone->num_of_contacts == 8)
        phone->num_of_contacts = 0;
}
void    search(PhoneBook *phone)
{
    int input;
    if (phone->num_of_contacts == 0)
    {
        std::cout << "you don't have contacts\nenter add to add a new contact\n";
        return;
    }
    for (int i = 0; i < phone->num_of_contacts; i++)
        std::cout << std::setw(10) << std::right << i << "|" << std::setw(10) << std::right << phone->mycontacts[i].first_name << "|" << std::setw(10) << std::right << phone->mycontacts[i].last_name << "|" << std::setw(10) << std::right << phone->mycontacts[i].nickname << std::endl;
    std::cout << "enter an index" << std::endl;
    std::cin >> input;
    if (input > phone->num_of_contacts - 1 || input < 0)
    {
        std::cout << "contact doesn't exist" << std::endl;
        return;
    }
    std::cout << "first name : " << phone->mycontacts[input].first_name << std::endl;
    std::cout << "last name : " << phone->mycontacts[input].last_name << std::endl;
    std::cout << "nickname : " << phone->mycontacts[input].nickname << std::endl;
    std::cout << "phone number : " << phone->mycontacts[input].phone_number << std::endl;
    std::cout << "darkest secret : " << phone->mycontacts[input].darkest_secret << std::endl; 
}   

int main()
{
    // std::cout << "welcome to the phonebook ,enter :\nADD to add a new contact\n";
    PhoneBook phonebook;

    phonebook.num_of_contacts = 0;
    std::string input;

    std::cin >> input;
    while (input != "exit")
    {
        if (input == "add")
            add(&phonebook);
        else if (input == "search")
            search(&phonebook);
        else
            std::cout << "cmd doesn't exist !" << std::endl;
        std::cin >> input;
    }
    exit(0);
    // std::cout << asma ;
    // std::string asma2 = "asmawithoute";
    // if (asma1 != asma2)
    //     std::cout << "diff";
    return 0;
}
