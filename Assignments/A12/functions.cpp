#include "functions.h"
#include <algorithm>

std::vector<Contact> contacts;

void addContact(const Contact &contact)
{
    contacts.push_back(contact);
}

void displayContactsSorted(bool sortByFirstName)
{
    std::vector<Contact> sorted_contacts = contacts;
    if (sortByFirstName)
    {
        std::sort(sorted_contacts.begin(), sorted_contacts.end(), [](const Contact &a, const Contact &b)
                  { return a.first_name < b.first_name; });
    }
    else
    {
        std::sort(sorted_contacts.begin(), sorted_contacts.end(), [](const Contact &a, const Contact &b)
                  { return a.last_name < b.last_name; });
    }
    for (const auto &contact : sorted_contacts)
    {
        std::cout << contact.first_name << " " << contact.last_name << " - " << contact.primary_phone << "\n";
    }
}

void displayFirstNameWithPrimary()
{
    for (const auto &contact : contacts)
    {
        std::cout << contact.first_name << " - " << contact.primary_phone << "\n";
    }
}

void displayContactsByCompany(const std::string &company)
{
    for (const auto &contact : contacts)
    {
        if (contact.company == company)
        {
            std::cout << contact.first_name << " " << contact.last_name << " - " << contact.primary_phone << "\n";
        }
    }
}

void displayContactsByGroup(const std::string &group)
{
    for (const auto &contact : contacts)
    {
        if (contact.group == group)
        {
            std::cout << contact.first_name << " " << contact.last_name << " - " << contact.primary_phone << "\n";
        }
    }
}

void searchContact(const std::string &name)
{
    for (const auto &contact : contacts)
    {
        if (contact.first_name == name || contact.last_name == name)
        {
            std::cout << contact.first_name << " " << contact.last_name << " - " << contact.primary_phone << "\n";
        }
    }
}

void displayCountByCompany()
{
    std::unordered_map<std::string, int> company_count;
    for (const auto &contact : contacts)
    {
        company_count[contact.company]++;
    }
    for (const auto &pair : company_count)
    {
        std::cout << pair.first << ": " << pair.second << " contacts\n";
    }
}

void displayCountByGroup()
{
    std::unordered_map<std::string, int> group_count;
    for (const auto &contact : contacts)
    {
        group_count[contact.group]++;
    }
    for (const auto &pair : group_count)
    {
        std::cout << pair.first << ": " << pair.second << " contacts\n";
    }
}

