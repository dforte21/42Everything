#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

enum menu { ADD = '0', SEARCH = '1', EXIT = '2'};

class PhoneBook {
    
    private:
        int         index;
        Contact     contact[8];


    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void menu(void);
        void add(void);
        void search(void);
        void checkStr(int i);
};

#endif