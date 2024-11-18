#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Contact {   //A struct is used to group related variables into a single unit
    std::string firstName;
    std::string lastName;
    std::string primaryPhone;
    std::string secondaryPhone;
    std::string email;
    std::string address;
    std::string company;
    std::string group;
};


// 1. Display All Contacts Sorted by First or Last Name
// void displaySortedContacts(std::vector<Contact>& contacts, bool sortByFirstName) {
//     if (sortByFirstName) {
//         std::sort(contacts.begin(), contacts.end(),
//                   [](const Contact& a, const Contact& b) { return a.firstName < b.firstName; });
//     } else {
//         std::sort(contacts.begin(), contacts.end(),
//                   [](const Contact& a, const Contact& b) { return a.lastName < b.lastName; });
//     }

//     for (const auto& contact : contacts) {
//         std::cout << contact.firstName << " " << contact.lastName << "\n";
//     }
// }



// Function to display contacts sorted by first or last name
void displaySortedContacts(std::vector<Contact>& contacts, const std::string& sortBy) {
    if (sortBy == "firstName") {
        // Sort by first name
        std::sort(contacts.begin(), contacts.end(),
                  [](const Contact& a, const Contact& b) { return a.firstName < b.firstName; });
    } else if (sortBy == "lastName") {
        // Sort by last name
        std::sort(contacts.begin(), contacts.end(),
                  [](const Contact& a, const Contact& b) { return a.lastName < b.lastName; });
    } else {
        std::cout << "Invalid sorting option. Use 'firstName' or 'lastName'.\n";
        return;
    }

    // Display sorted contacts
    for (const auto& contact : contacts) {
        std::cout << contact.firstName << " " << contact.lastName << "\n";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 2. Display Only First Name with Primary Number
void displayFirstNameWithPrimaryNumber(const std::vector<Contact>& contacts) {
    for (const auto& contact : contacts) {
        std::cout << contact.firstName << ": " << contact.primaryPhone << "\n";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 3. Display Contacts from the Same Company
void displayContactsByCompany(const std::unordered_map<std::string, std::vector<Contact>>& contactsByCompany,
                              const std::string& company) {
    auto it = contactsByCompany.find(company);
    if (it != contactsByCompany.end()) {
        for (const auto& contact : it->second) {
            std::cout << contact.firstName << " " << contact.lastName << "\n";
        }
    } else {
        std::cout << "No contacts found for company: " << company << "\n";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 4. Display Contacts Based on Group Type
void displayContactsByGroup(const std::unordered_map<std::string, std::vector<Contact>>& contactsByGroup,
                            const std::string& group) {
    auto it = contactsByGroup.find(group);
    if (it != contactsByGroup.end()) {
        for (const auto& contact : it->second) {
            std::cout << contact.firstName << " " << contact.lastName << "\n";
        }
    } else {
        std::cout << "No contacts found in group: " << group << "\n";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 5. Allow Contact Search by First or Last Name

void searchContactByName(const std::vector<Contact>& contacts, const std::string& name) {
    auto it = std::find_if(contacts.begin(), contacts.end(),
                           [&name](const Contact& contact) {
                               return contact.firstName == name || contact.lastName == name;
                           });

    if (it != contacts.end()) {
        std::cout << "Contact found: " << it->firstName << " " << it->lastName << "\n";
    } else {
        std::cout << "No contact found with name: " << name << "\n";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 6. Display Count of Contacts by Company and Group

void displayContactCounts(const std::unordered_map<std::string, std::vector<Contact>>& contactsByCompany,
                          const std::unordered_map<std::string, std::vector<Contact>>& contactsByGroup) {
    std::cout << "Contacts by Company:\n";
    for (const auto& pair : contactsByCompany) {
        std::cout << pair.first << ": " << pair.second.size() << " contacts\n";
    }

    std::cout << "\nContacts by Group:\n";
    for (const auto& pair : contactsByGroup) {
        std::cout << pair.first << ": " << pair.second.size() << " contacts\n";
    }
}







// Functions declared above

int main() {

    // used a std::vector to store all the contacts:
    std::vector<Contact> contacts = {
        {"Fatmah", "Rashed", "12345", "67890", "Fatmah@example.com", "123 Main St", "ADASI", "Friends"},
        {"Mohammed", "Ahmed", "54321", "98765", "Mohammed@example.com", "456 Elm St", "EDGE", "Family"},
        {"Mariam", "Ahmed", "999", "66666", "Mariam@example.com", "789 Pine St", "HALCON", "Coworker"}
    };

    // Group contacts by company and group
    std::unordered_map<std::string, std::vector<Contact>> contactsByCompany;
    std::unordered_map<std::string, std::vector<Contact>> contactsByGroup;

    for (const auto& contact : contacts) {
        contactsByCompany[contact.company].push_back(contact);
        contactsByGroup[contact.group].push_back(contact);
    }

    // User decides to sort by first or last name
    std::string sortBy;
    std::cout << "\nEnter sorting option ('firstName or lastName'):\n";
    std::cin >> sortBy;
    displaySortedContacts(contacts, sortBy);



    // Display first name with primary number
    std::cout << "\nFirst name with primary number:\n";
    displayFirstNameWithPrimaryNumber(contacts);

    // Display contacts by company
    std::cout << "\nContacts at ADASI:\n";
    displayContactsByCompany(contactsByCompany, "ADASI");

    // Display contacts by group
    std::cout << "\nContacts in Family group:\n";
    displayContactsByGroup(contactsByGroup, "Family");

    // Search contact by name
    std::cout << "\nSearching for 'Fatmah':\n";
    searchContactByName(contacts, "Fatmah");

    // Display counts by company and group
    std::cout << "\nCounts by company and group:\n";
    displayContactCounts(contactsByCompany, contactsByGroup);

    return 0;
}
