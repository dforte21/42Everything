#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

enum menu { ADD = '0', SEARCH = '1', EXIT = '2'};

class PhoneBook {
    
    public:

        int         index;
        Contact     contact[8];

        PhoneBook(void);
        ~PhoneBook(void);

        void menu(void);
        void add(Contact *contact);
        void search(Contact *contact);
};

#endif