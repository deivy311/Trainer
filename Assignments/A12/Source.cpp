#include "functions.h"

int main()
{
    // Adding contacts for testing
    addContact({"Latifa", "Alkaabi", "0501234567", "0501266567", "latifa.ali@adasi.com", "Abu Dhabi", "ADASI", "Coworker"});
    addContact({"Ali", "Alshamsi", "0501277567", "0501239967", "ali.shamsi@edge.com", "Dubai", "EDGE", "Friend"});
    addContact({"Saeed", "Asaedi", "0501231167", "0501239067", "saeed.saedi@halcon.com", "Sharjah", "HALCON", "Family"});
    addContact({"Sultan", "Alneyadi", "0501884567", "0501434567", "sultan.neyadi@nimr.com", "Al Ain", "NIMR", "Coworker"});

    std::cout << "Contacts sorted by first name:\n";
    displayContactsSorted(true);
    std::cout << "###################################\n";

    std::cout << "Contacts sorted by last name:\n";
    displayContactsSorted(false);
    std::cout << "###################################\n";

    std::cout << "First name with primary number:\n";
    displayFirstNameWithPrimary();
    std::cout << "###################################\n";

    std::cout << "Contacts from ADASI:\n";
    displayContactsByCompany("ADASI");
    std::cout << "###################################\n";

    std::cout << "Contacts in Friends group:\n";
    displayContactsByGroup("Friend");
    std::cout << "###################################\n";

    std::cout << "Search results for contact name 'Ali':\n";
    searchContact("Ali");
    std::cout << "###################################\n";

    std::cout << "Count of contacts by company:\n";
    displayCountByCompany();
    std::cout << "###################################\n";

    std::cout << "Count of contacts by group:\n";
    displayCountByGroup();
    std::cout << "###################################\n";

    return 0;
}
