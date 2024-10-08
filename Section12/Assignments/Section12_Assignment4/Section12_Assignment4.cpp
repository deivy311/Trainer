#include <iostream>
#include <string>
#include <utility>

// Template factory function to create an object of any type T
template<typename T, typename... Args>
T* CreateObject(Args&&... args) {
    // Forward the arguments to the constructor of T and create the object
    return new T(std::forward<Args>(args)...);
}

// Example classes for demonstration
class Employee {
    std::string m_Name;
    int m_Id;
    double m_Salary;
public:
    // Constructor
    Employee(const std::string &name, int id, double salary) 
        : m_Name(name), m_Id(id), m_Salary(salary) {
        std::cout << "Employee created: Name = " << m_Name
                  << ", ID = " << m_Id
                  << ", Salary = " << m_Salary << std::endl;
    }
};

class Contact {
    std::string m_Name;
    long m_PhoneNumber;
    std::string m_Address;
    std::string m_Email;
public:
    // Constructor
    Contact(const std::string &name, long phone, const std::string &address, const std::string &email)
        : m_Name(name), m_PhoneNumber(phone), m_Address(address), m_Email(email) {
        std::cout << "Contact created: Name = " << m_Name
                  << ", Phone = " << m_PhoneNumber
                  << ", Address = " << m_Address
                  << ", Email = " << m_Email << std::endl;
    }
};

int main() {
    // Example 1: Create an int object
    int *p1 = CreateObject<int>(5);
    std::cout << "Integer created: " << *p1 << std::endl;
    delete p1; // Remember to delete dynamically allocated objects

    // Example 2: Create a std::string object with default constructor
    std::string *s = CreateObject<std::string>();
    std::cout << "String created: \"" << *s << "\"" << std::endl;
    delete s;

    // Example 3: Create an Employee object
    Employee *emp = CreateObject<Employee>("Bob", 101, 1000.0);
    delete emp;

    // Example 4: Create a Contact object
    Contact *contact = CreateObject<Contact>("Joey", 987654321, "Boulevard Road, Sgr", "joey@poash.com");
    delete contact;

    return 0;
}
