#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

struct Contact
{
    std::string first_name;
    std::string last_name;
    std::string primary_phone;
    std::string secondary_phone;
    std::string email;
    std::string address;
    std::string company;
    std::string group;
};

extern std::vector<Contact> contacts;

void addContact(const Contact &contact);
void displayContactsSorted(bool sortByFirstName);
void displayFirstNameWithPrimary();
void displayContactsByCompany(const std::string &company);
void displayContactsByGroup(const std::string &group);
void searchContact(const std::string &name);
void displayCountByCompany();
void displayCountByGroup();

#endif
