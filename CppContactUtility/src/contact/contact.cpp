// Contact.cpp
#include "contact.hpp"
#include <iostream>

Contact::Contact() {
    
}

Contact::Contact(const std::string& name, const std::string& phone_number)
    : name(name), phone_number(phone_number) {
}

std::string Contact::get_name() const {
    return name;
}

std::string Contact::get_phone_number() const {
    return phone_number;
}

void Contact::display_contact() const {
    std::cout << "Name: " << name << "\nPhone Number: " << phone_number << std::endl;
}
