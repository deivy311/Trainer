#include <iostream>
#include <string>

// Factory function template to create an instance of any type T
template <typename T, typename... Args>
T* CreateObject(Args&&... args) {
    return new T(std::forward<Args>(args)...);
}

// Example classes for demonstration
class Employee {
public:
    Employee(const std::string& name, int id, double salary)
        : name(name), id(id), salary(salary) {}
    
    void display() const {
        std::cout << "Employee: " << name << ", ID: " << id << ", Salary: $" << salary << "\n";
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
        std::cout << "Contact: " << name << ", Phone: " << phone << ", Address: " << address << ", Email: " << email << "\n";
    }

private:
    std::string name;
    int phone;
    std::string address;
    std::string email;
};

// Example usage of the CreateObject factory function
int main() {
    int* p1 = CreateObject<int>(5);  // Creates an int with value 5
    std::cout << "Integer: " << *p1 << std::endl;
    delete p1;

    std::string* s = CreateObject<std::string>();  // Creates an empty std::string
    *s = "Hello, Factory!";
    std::cout << "String: " << *s << std::endl;
    delete s;

    Employee* emp = CreateObject<Employee>("Bob", 101, 1000);  // Creates an Employee
    emp->display();
    delete emp;

    Contact* p = CreateObject<Contact>("Joey", 987654321, "Boulevard Road, Sgr", "joey@poash.com");  // Creates a Contact
    p->display();
    delete p;

    return 0;
}
