// ContactManager.h
#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include "../contact/contact.hpp"
#include <vector>

class ContactManager {
public:
    ContactManager();
    void add_contact(const Contact& contact);
    void display_contact() const;
    void save_contacts_to_file(const std::string& file_name) const;
    void load_contacts_from_file(const std::string& file_name);

private:
    std::vector<Contact> contacts;
};

#endif // CONTACT_MANAGER_H
