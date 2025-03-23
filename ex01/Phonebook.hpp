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
        void add();
        void search();
};
