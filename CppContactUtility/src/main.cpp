#include "contactmanager/contactmanager.hpp"
#include <iostream>

int main() {
    ContactManager m_contact_manager;
    int choice;

    do {
        std::cout << "\nContact Manager Menu:\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display Contacts\n";
        std::cout << "3. Save Contacts to File\n";
        std::cout << "4. Load Contacts from File\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cin.ignore(); // Clear the input buffer before getline
            std::string name, phone_number;
            std::cout << "Enter contact name: ";
            std::getline(std::cin, name);
            std::cout << "Enter contact phone number: ";
            std::getline(std::cin, phone_number);
            m_contact_manager.add_contact(Contact(name, phone_number));
            break;
        }
        case 2:
            m_contact_manager.display_contact();
            break;
        case 3: {
            std::string file_name;
            std::cout << "Enter file name to save contacts: ";
            std::cin >> file_name;
            m_contact_manager.save_contacts_to_file(file_name);
            break;
        }
        case 4: {
            std::string file_name;
            std::cout << "Enter file name to load contacts from: ";
            std::cin >> file_name;
            m_contact_manager.load_contacts_from_file(file_name);
            break;
        }
        case 5:
            std::cout << "Exiting Contact Manager.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
