#include "Contact.hpp"

Contact::Contact(void){

    memset(this->info[0], '\0', 1000);
    memset(this->info[1], '\0', 1000);
    memset(this->info[2], '\0', 1000);
    memset(this->info[3], '\0', 1000);
    memset(this->info[4], '\0', 1000);
    return ;
}

Contact::~Contact(void){

    return ;
}

void    Contact::initinfo(void){

    memset(this->info[0], '\0', 1000);
    memset(this->info[1], '\0', 1000);
    memset(this->info[2], '\0', 1000);
    memset(this->info[3], '\0', 1000);
    memset(this->info[4], '\0', 1000);
}