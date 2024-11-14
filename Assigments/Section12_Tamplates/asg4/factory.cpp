#include <iostream>
#include <string>
#include <utility>  // For std::forward

// Factory function template
template <typename T, typename... Args>
T* CreateObject(Args&&... args) {
    return new T(std::forward<Args>(args)...);  // Forward arguments to T's constructor
}


// Example classes to test the factory
class Employee {
public:
    Employee(const std::string& name, int id, double salary)
        : name(name), id(id), salary(salary) {}

    void display() const {
        std::cout << "Employee: " << name << ", ID: " << id << ", Salary: " << salary << "\n";
    }

private:
    std::string name;
    int id;
    double salary;
};

class Contact {
public:
    Contact(const std::string& name, int phone, const std::string& address, const std::string& email)
        : name(name), phone(phone), address(address), email(email) {}

    void display() const {
        std::cout << "Contact: " << name << ", Phone: " << phone
                  << ", Address: " << address << ", Email: " << email << "\n";
    }

private:
    std::string name;
    int phone;
    std::string address;
    std::string email;
};



//----------------------------------------------------------------------------------

int main() {
    // Usage examples of the factory function

    // 1. Creating an integer pointer
    int* p1 = CreateObject<int>(5);
    std::cout << "Integer value: " << *p1 << "\n";
    delete p1;  // Clean up allocated memory

    // 2. Creating a default-constructed string
    std::string* s = CreateObject<std::string>();
    *s = "Hello, World!";
    std::cout << "String value: " << *s << "\n";
    delete s;

    // 3. Creating an Employee object
    Employee* emp = CreateObject<Employee>("Bob", 101, 1000.0);
    emp->display();
    delete emp;

    // 4. Creating a Contact object
    Contact* contact = CreateObject<Contact>("Joey", 987654321, "Boulevard Road, Sgr", "joey@poash.com");
    contact->display();
    delete contact;

    return 0;
}
