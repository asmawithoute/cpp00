#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>

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
        int index;
        PhoneBook();
};

PhoneBook::PhoneBook()
{
    this->num_of_contacts = 0;
    this->index = 0;
}



void    add(PhoneBook* phone)
{
    Contact cont;
    std::string input;

    std::cout << "enter a new contact : " << std::endl;
    std::cout << "plz enter a first name : " << std::endl;
    getline(std::cin, input);
    while (input.empty())
    {
        if (std::cin.eof())
            exit(0);
        std::cout << "plz enter a first name : " << std::endl;
        getline(std::cin, input);
    }
    cont.first_name = input;
    std::cout << "plz enter a last name : " << std::endl;
    getline(std::cin, input);
    while (input.empty())
    {
        if (std::cin.eof())
            exit(0);
        std::cout << "plz enter a last name : " << std::endl;
        getline(std::cin, input);
    }
    cont.last_name = input;
    std::cout << "plz enter a nickname : " << std::endl;
    getline(std::cin, input);
    while (input.empty())
    {
        if (std::cin.eof())
            exit(0);
        std::cout << "plz enter a nickname : " << std::endl;
        getline(std::cin, input);
    }
    cont.nickname = input;
    std::cout << "plz enter a phone number : " << std::endl;
    getline(std::cin, input);
    while (input.empty())
    {
        if (std::cin.eof())
            exit(0);
        std::cout << "plz enter a phone number : " << std::endl;
        getline(std::cin, input);
    }
    cont.phone_number = input;
    std::cout << "plz enter the contact's darkest secret : " << std::endl;
    getline(std::cin, input);
    while (input.empty())
    {
        if (std::cin.eof())
            exit(0);
        std::cout << "plz enter the contact's darkest secret : " << std::endl;
        getline(std::cin, input);
    }
    cont.darkest_secret = input;
    std::cout << "contact added successfully !!!" << std::endl;
    if(phone->index == 8)
        phone->index = 0;
    phone->mycontacts[phone->index] = cont;
    phone->index++;
    phone->num_of_contacts++;
    if (phone->num_of_contacts > 8)
        phone->num_of_contacts = 8;
}

void    search(PhoneBook *phone)
{
    std::string fname;
    std::string lname;
    std::string nname;
    int input;
    if (phone->num_of_contacts == 0)
    {
        std::cout << "you don't have any contacts\n";
        return;
    }
    for (int i = 0; i < phone->num_of_contacts; i++)
    {
        fname = phone->mycontacts[i].first_name;
        lname = phone->mycontacts[i].last_name;
        nname = phone->mycontacts[i].nickname;
        if (fname.length() > 10)
            fname = phone->mycontacts[i].first_name.substr(0, 9) + ".";
        if (lname.length() > 10)
            lname = phone->mycontacts[i].last_name.substr(0, 9) + ".";
        if (nname.length() > 10)
            nname = phone->mycontacts[i].nickname.substr(0, 9) + ".";
        std::cout << std::setw(10) << std::right << i << "|" ;
        std::cout << std::setw(10) << std::right << fname << "|";
        std::cout << std::setw(10) << std::right << lname << "|" ;
        std::cout << std::setw(10) << std::right << nname << std::endl;

    }
    std::cout << "enter an index" << std::endl;
    std::cin >> input;
    if (std::cin.fail())
    {
        std::cout << "invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return;
    }
    else if (input < phone->num_of_contacts && input >= 0)
    {
        std::cout << "first name : " << phone->mycontacts[input].first_name << std::endl;
        std::cout << "last name : " << phone->mycontacts[input].last_name << std::endl;
        std::cout << "nickname : " << phone->mycontacts[input].nickname << std::endl;
        std::cout << "phone number : " << phone->mycontacts[input].phone_number << std::endl;
        std::cout << "darkest secret : " << phone->mycontacts[input].darkest_secret << std::endl; 
    }
    else
        std::cout << "contact doesn't exist" << std::endl;
    // std::cin.clear();
    std::cin.ignore(1000, '\n');
    return;
}
