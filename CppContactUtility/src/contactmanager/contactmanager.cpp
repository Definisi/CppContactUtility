#include "contactmanager.hpp"
#include <iostream>
#include <fstream>

ContactManager::ContactManager()
{
}

void ContactManager::add_contact(const Contact& contact)
{
	contacts.push_back(contact);
}

void ContactManager::display_contact() const
{
    if (contacts.empty()) {
        std::cout << "No contacts available.\n";
        return;
    }

    std::cout << "Contacts:\n";
    for (const auto& contact : contacts) {
        contact.display_contact();
        std::cout << "---------------------\n";
    }
}

void ContactManager::save_contacts_to_file(const std::string& file_name) const
{
    std::ofstream output_file(file_name);
    if (output_file.is_open()) {
        for (const auto& contact : contacts) {
            output_file << contact.get_name() << "," << contact.get_phone_number() << "\n";
        }
        output_file.close();
        std::cout << "Contacts saved to " << file_name << " successfully!\n";
    }
    else {
        std::cerr << "Unable to open file: " << file_name << "\n";
    }
}

void ContactManager::load_contacts_from_file(const std::string& file_name)
{
    std::ifstream input_file(file_name);
    if (input_file.is_open()) {
        std::string name, phone_number;
        while (getline(input_file, name, ',') && getline(input_file, phone_number)) {
            contacts.emplace_back(name, phone_number);
        }
        input_file.close();
        std::cout << "Contacts loaded from " << file_name << " successfully!\n";
    }
    else {
        std::cerr << "Unable to open file: " << file_name << "\n";
    }
}
