#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact {

    public:

        int index;
        char info[5][1000];

        Contact(void);
        ~Contact(void);

        void initinfo (void);

    private:
};

#endif