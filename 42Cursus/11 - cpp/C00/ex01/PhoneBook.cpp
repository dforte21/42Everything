#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){

    this->index = 0;
    this->contact[0].index = 0;
    this->contact[1].index = 0;
    this->contact[2].index = 0;
    this->contact[3].index = 0;
    this->contact[4].index = 0;
    this->contact[5].index = 0;
    this->contact[6].index = 0;
    this->contact[7].index = 0;
    std::cout << "Created PhoneBook\n";
    return ;
}

PhoneBook::~PhoneBook(void){

    std::cout << "Destroyed PhoneBook\n";
    return ;
}

void    PhoneBook::menu(void){

    char choice;

    while (1)
    {
        std::cout << "Scelte disponibili:\n\n\t0 - ADD\n\t1 - SEARCH\n\t2 - EXIT\n\n->";
        std::cin >> choice;
        switch(choice)
        {
            case ADD:
                this->add(this->contact);
                break ;
            case SEARCH:
                this->search(this->contact);
                break ;
            case EXIT:
                return ;
            default:
                std::cout << "Scelta non valida, riprova!\n\n";
        }
    }
}

void    PhoneBook::add(Contact *contact)
{
    this->contact[this->index % 8].index = this->index + 1 ;
    this->contact[this->index % 8].initinfo();
    std::cout << "First name: ";
    std::cin >> this->contact[this->index % 8].info[0] ;
    std::cout << "Last name: ";
    std::cin >> this->contact[this->index % 8].info[1] ;
    std::cout << "Nickname: ";
    std::cin >> this->contact[this->index % 8].info[2] ;
    std::cout << "Phone number: ";
    std::cin >> this->contact[this->index % 8].info[3] ;
    std::cout << "Darkest secret: ";
    std::cin >> this->contact[this->index % 8].info[4] ;
    this->index++;
}

void    PhoneBook::search(Contact *contact)
{
    int k, len, nlen = 0;
    
    for (int i = 0; this->contact[i].index != 0 && i < 8; i++)
    {
        nlen = 0;
        for (int num = this->contact[i].index; num > 0; num /= 10)
            nlen++;
        for (;9 - nlen >= 0; nlen++)
            std::cout << " " ;
        std::cout << this->contact[i].index ;
        for (int j = 0; j < 5; j++)
        {
            std::cout << "|" ;
            for (len = strlen(this->contact[i].info[j]);9 - len >= 0; len++)
                std::cout << " " ;
            for (k = 0; k < 9; k++)
                std::cout << this->contact[i].info[j][k] ;
            if (strlen(this->contact[i].info[j]) > 9)
                std::cout << "." ;
        }
        std::cout << std::endl ;
    }
}