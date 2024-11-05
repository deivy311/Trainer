#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Contact {
    std::string firstName;
    std::string lastName;
    std::string primaryPhone;
    std::string secondaryPhone;
    std::string email;
    std::string address;
    std::string company;
    std::string group;
};

// Function to add a new contact
void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Enter First Name: ";
    std::cin >> newContact.firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> newContact.lastName;
    std::cout << "Enter Primary Phone Number: ";
    std::cin >> newContact.primaryPhone;
    std::cout << "Enter Secondary Phone Number: ";
    std::cin >> newContact.secondaryPhone;
    std::cout << "Enter Email: ";
    std::cin >> newContact.email;
    std::cout << "Enter Address: ";
    std::cin.ignore();
    std::getline(std::cin, newContact.address);
    std::cout << "Enter Company: ";
    std::cin >> newContact.company;
    std::cout << "Enter Group (Friends, Family, Coworker, Acquaintance): ";
    std::cin >> newContact.group;
    
    contacts.push_back(newContact);
}

// Function to display all contacts sorted by first or last name
void displaySortedContacts(std::vector<Contact>& contacts, bool sortByFirstName) {
    std::sort(contacts.begin(), contacts.end(), [sortByFirstName](const Contact& a, const Contact& b) {
        return sortByFirstName ? a.firstName < b.firstName : a.lastName < b.lastName;
    });
    for (const auto& contact : contacts) {
        std::cout << contact.firstName << " " << contact.lastName << ", " << contact.primaryPhone << "\n";
    }
}

// Function to display only first name with primary number
void displayFirstNameWithPrimary(const std::vector<Contact>& contacts) {
    for (const auto& contact : contacts) {
        std::cout << contact.firstName << ": " << contact.primaryPhone << "\n";
    }
}

// Function to display contacts from the same company
void displayByCompany(const std::vector<Contact>& contacts, const std::string& company) {
    for (const auto& contact : contacts) {
        if (contact.company == company) {
            std::cout << contact.firstName << " " << contact.lastName << ", " << contact.primaryPhone << "\n";
        }
    }
}

// Function to display contacts based on group type
void displayByGroup(const std::vector<Contact>& contacts, const std::string& group) {
    for (const auto& contact : contacts) {
        if (contact.group == group) {
            std::cout << contact.firstName << " " << contact.lastName << ", " << contact.primaryPhone << "\n";
        }
    }
}

// Function to search for a contact by first or last name
void searchByName(const std::vector<Contact>& contacts, const std::string& name, bool searchByFirstName) {
    for (const auto& contact : contacts) {
        if ((searchByFirstName && contact.firstName == name) ||
            (!searchByFirstName && contact.lastName == name)) {
            std::cout << contact.firstName << " " << contact.lastName << ", " << contact.primaryPhone << "\n";
        }
    }
}

// Function to display count of contacts by company and group
void displayCountByCompanyAndGroup(const std::vector<Contact>& contacts) {
    std::unordered_map<std::string, int> companyCount;
    std::unordered_map<std::string, int> groupCount;

    for (const auto& contact : contacts) {
        companyCount[contact.company]++;
        groupCount[contact.group]++;
    }

    std::cout << "Contacts by Company:\n";
    for (const auto& [company, count] : companyCount) {
        std::cout << company << ": " << count << "\n";
    }

    std::cout << "Contacts by Group:\n";
    for (const auto& [group, count] : groupCount) {
        std::cout << group << ": " << count << "\n";
    }
}

// Main menu to interact with the user
void menu() {
    std::vector<Contact> contacts;
    int choice;

    while (true) {
        std::cout << "\n1. Add Contact\n";
        std::cout << "2. Display All Contacts (Sorted by First or Last Name)\n";
        std::cout << "3. Display First Name with Primary Phone Number Only\n";
        std::cout << "4. Display Contacts by Company\n";
        std::cout << "5. Display Contacts by Group\n";
        std::cout << "6. Search Contact by First or Last Name\n";
        std::cout << "7. Display Count of Contacts by Company and Group\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 8) break;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2: {
                bool sortByFirstName;
                std::cout << "Sort by First Name (1) or Last Name (0): ";
                std::cin >> sortByFirstName;
                displaySortedContacts(contacts, sortByFirstName);
                break;
            }
            case 3:
                displayFirstNameWithPrimary(contacts);
                break;
            case 4: {
                std::string company;
                std::cout << "Enter company name: ";
                std::cin >> company;
                displayByCompany(contacts, company);
                break;
            }
            case 5: {
                std::string group;
                std::cout << "Enter group type (Friends, Family, Coworker, Acquaintance): ";
                std::cin >> group;
                displayByGroup(contacts, group);
                break;
            }
            case 6: {
                std::string name;
                bool searchByFirstName;
                std::cout << "Search by First Name (1) or Last Name (0): ";
                std::cin >> searchByFirstName;
                std::cout << "Enter the name to search: ";
                std::cin >> name;
                searchByName(contacts, name, searchByFirstName);
                break;
            }
            case 7:
                displayCountByCompanyAndGroup(contacts);
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
