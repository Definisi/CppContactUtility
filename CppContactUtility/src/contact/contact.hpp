// Contact.h
#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
    Contact();
    Contact(const std::string& name, const std::string& phone_number);

    std::string get_name() const;
    std::string get_phone_number() const;

    void display_contact() const;

private:
    std::string name;
    std::string phone_number;
};

#endif // CONTACT_H
