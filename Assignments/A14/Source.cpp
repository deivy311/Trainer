#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

std::map<std::string, int> inventory;
std::set<std::string> categories;
std::multiset<std::string> popularItems;
std::unordered_map<std::string, double> prices;

void addItem(const std::string &name, int quantity, const std::string &category, double price)
{
    inventory[name] = quantity;
    categories.insert(category);
    prices[name] = price;
    popularItems.insert(name);
}

void updateItem(const std::string &name, int quantity)
{
    if (inventory.find(name) != inventory.end())
    {
        inventory[name] = quantity;
        popularItems.insert(name);
    }
    else
    {
        std::cout << "Item not found.\n";
    }
}

void removeItem(const std::string &name)
{
    inventory.erase(name);
    prices.erase(name);
}

void printAll()
{
    std::cout << "Inventory:\n";
    for (const auto &item : inventory)
    {
        std::cout << "Item: " << item.first << ", Quantity: " << item.second
                  << ", Price: " << prices[item.first] << " AED \n";
    }
}

void printPopular()
{
    std::map<std::string, int> popularCount;
    for (const auto &item : popularItems)
    {
        popularCount[item]++;
    }
    std::cout << "\nMost Popular Items:\n";
    for (const auto &item : popularCount)
    {
        std::cout << "Item: " << item.first << ", Access number: " << item.second << "\n";
    }
}

int main()
{
    addItem("Jetson Nano", 10, "Edge Devices", 99.0);
    addItem("Jetson Orin Nano", 5, "Edge Devices", 199.0);
    addItem("Jetson Orin NX", 3, "Edge Devices", 399.0);
    addItem("Camera Module", 15, "Accessories", 25.0);
    addItem("Power Supply for Jetson", 10, "Power Solutions", 15.0);

    updateItem("Jetson Nano", 12);
    updateItem("Camera Module", 18);

    addItem("SD Card 128GB", 50, "Storage", 20.0);
    addItem("Micro USB Cable", 100, "Accessories", 5.0);

    removeItem("Power Supply for Jetson");

    printAll();
    printPopular();

    return 0;
}
