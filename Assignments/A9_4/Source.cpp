#include <iostream>
#include <string>

template <typename T, typename... Args>
T* CreateObject(Args&&... args)
{
    return new T(std::forward<Args>(args)...);
}


class Employee {
public:
    std::string name;
    int id;
    double salary;

    Employee(const std::string& name, int id, double salary)
        : name(name), id(id), salary(salary) {}

    void display() const {
        std::cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << std::endl;
    }
};


class Contact {
public:
    std::string name;
    long phoneNumber;
    std::string address;
    std::string email;

    Contact(const std::string& name, long phoneNumber, const std::string& address, const std::string& email)
        : name(name), phoneNumber(phoneNumber), address(address), email(email) {}

    void display() const {
        std::cout << "Contact Name: " << name << ", Phone: " << phoneNumber << ", Address: " << address << ", Email: " << email << std::endl;
    }
};

int main()
{
    int* p1 = CreateObject<int>(5);
    std::cout << "Created int: " << *p1 << std::endl;
    delete p1;  


    std::string* s = CreateObject<std::string>();
    std::cout << "Created string (default): " << *s << std::endl;
    delete s;  


    Employee* emp = CreateObject<Employee>("Bob", 101, 1000.0);
    emp->display();
    delete emp;  

    Contact* p = CreateObject<Contact>("Joey", 987654321, "Boulevard Road, Sgr", "joey@poash.com");
    p->display();
    delete p; 

    return 0;
}

