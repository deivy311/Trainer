#include <iostream>
#include <string>
#include <utility> // For std::forward

// The Factory class that will create objects of different types
class Factory {
public:
    // Static template function to create an object of type T
    template <typename T, typename... Args>
    static T* CreateObject(Args&&... args) {
        return new T(std::forward<Args>(args)...);
    }
};

// Example classes that we'll use with the factory

// Employee Class
class Employee {
public:
    Employee(const std::string& name, int id, double salary)
        : name(name), id(id), salary(salary) {}

    void Display() const {
        std::cout << "Employee: " << name << ", ID: " << id << ", Salary: " << salary << std::endl;
    }

private:
    std::string name;
    int id;
    double salary;
};

// Contact Class
class Contact {
public:
    Contact(const std::string& name, int phone, const std::string& address, const std::string& email)
        : name(name), phone(phone), address(address), email(email) {}

    void Display() const {
        std::cout << "Contact: " << name << ", Phone: " << phone
                  << ", Address: " << address << ", Email: " << email << std::endl;
    }

private:
    std::string name;
    int phone;
    std::string address;
    std::string email;
};

// Main function demonstrating usage of the Factory class
int main() {
    // Creating an int object using the factory
    int* p1 = Factory::CreateObject<int>(5);
    std::cout << "Integer: " << *p1 << std::endl;
    delete p1; // Clean up memory

    // Creating a std::string object using default constructor
    std::string* s = Factory::CreateObject<std::string>();
    std::cout << "String: '" << *s << "'" << std::endl;
    delete s; // Clean up memory

    // Creating an Employee object
    Employee* emp = Factory::CreateObject<Employee>("Bob", 101, 1000.0);
    emp->Display();
    delete emp; // Clean up memory

    // Creating a Contact object
    Contact* contact = Factory::CreateObject<Contact>("Joey", 987654321, "Boulevard Road, Sgr", "joey@poash.com");
    contact->Display();
    delete contact; // Clean up memory

    return 0;
}
