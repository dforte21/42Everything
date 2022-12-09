#include "PhoneBook.hpp"
#include <limits>

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

    char choice[100];

    while (1)
    {
        memset(choice, 0, 100);
        std::cout << "\nScelte disponibili:\n\n\t0 - ADD\n\t1 - SEARCH\n\t2 - EXIT\n\n->";
        std::cin.getline(choice, 100);
        if (strlen(choice) > 1)
            choice[0] = '3';
        switch(choice[0])
        {
            case ADD:
                this->add();
                break ;
            case SEARCH:
                this->search();
                break ;
            case EXIT:
                return ;
            default:
                std::cout << "Scelta non valida, riprova!\n\n";
        }
    }
}

void    PhoneBook::add(void)
{
    this->contact[this->index % 8].index = this->index + 1 ;
    this->contact[this->index % 8].initinfo();
    std::cout << "First name: ";
    std::cin.getline(this->contact[this->index % 8].info[0], 1000);
    this->checkStr(0);
    std::cout << "Last name: ";
    std::cin.getline(this->contact[this->index % 8].info[1], 1000);
    this->checkStr(1);
    std::cout << "Nickname: ";
    std::cin.getline(this->contact[this->index % 8].info[2], 1000);
    this->checkStr(2);
    std::cout << "Phone number: ";
    std::cin.getline(this->contact[this->index % 8].info[3], 1000);
    this->checkStr(3);
    std::cout << "Darkest secret: ";
    std::cin.getline(this->contact[this->index % 8].info[4], 1000);
    this->checkStr(4);
    this->index++;
}

void    PhoneBook::checkStr(int i){

    while (strlen(this->contact[this->index % 8].info[i]) == 0)
    {
        std::cout << "Empty string not allowed: " ;
        std::cin.getline(this->contact[this->index % 8].info[i], 1000);
    }
}

void    PhoneBook::search(void)
{
    int i, search = 0, k, len, nlen = 0;
    char info[100];
    
    for (i = 0; this->contact[i].index != 0 && i < 8; i++)
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
    if (i > 0)
    {
        memset(info, 0, 100);
        std::cout << "\nInserisci l'indice del contatto che vuoi visualizzare: " ;
        std::cin.getline(info, 100);
        search = atoi(info);
        if (this->contact[(search - 1) % 8].index == search && search >= 1)
            std::cout << "\nFirst name: " << this->contact[(search - 1) % 8].info[0] << "\nLast name: " << this->contact[(search - 1) % 8].info[1] << "\nNickname: " << this->contact[(search - 1) % 8].info[2] << "\nPhone number: " << this->contact[(search - 1) % 8].info[3] << "\nDarkes secreat: " << this->contact[(search - 1) % 8].info[4] << std::endl;
        else
            std::cout << "\nError, contact not found\n";
    }
    else
        std::cout << "\nError, there are no contacts\n" ;
}