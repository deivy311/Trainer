#include <iostream>
#include <string>
// CreateObject function template using variadic templates
template <typename T, typename... Args>
T *CreateObject(Args &&...args)
{
    // Forward the arguments to the constructor of T and return a new instance of T
    return new T(std::forward<Args>(args)...);
}

class Employee
{
public:
    std ::string name;
    int id;
    double salary;

    Employee(const std::string &name, int id, double salary) : name(name), id(id), salary(salary)
    {
    }

    void display() const
    {
        std::cout << "Employee Name: " << name << ", ID: " << id << ", Salary: " << salary << std::endl;
    }
};

class Contact
{
public:
    std ::string name;
    int phoneNumber;
    std ::string address;
    std ::string email;

    Contact(const std::string &name, int phoneNumber, const std::string &address, const std::string &email)
        : name(name), phoneNumber(phoneNumber), address(address), email(email) {}

    void display() const
    {
        std::cout << "Contact Name: " << name << ", Phone: " << phoneNumber
                  << ", Address: " << address << ", Email: " << email << std::endl;
    }
};

int main()
{
    // Example 1: Create an int object
    int* p1 = CreateObject<int>(5);
    std::cout << "Created int: " << *p1 << std::endl;
    delete p1;  //free the allocated memory!

    // Example 2: Create a default-constructed std::string object
    std::string* s = CreateObject<std::string>();
    std::cout << "Created std::string: " << *s << std::endl;
    delete s;

    // Example 3: Create an Employee object
    Employee* emp = CreateObject<Employee>("Bob", 101, 1000.0);
    emp->display();
    delete emp;

    // Example 4: Create a Contact object
    Contact* contact = CreateObject<Contact>("Joey", 987654321, "Boulevard Road, Sgr", "joey@poash.com");
    contact->display();
    delete contact;


    return 0;
}
