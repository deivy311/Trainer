#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <set> // Corrected: This is where std::multiset is defined

class Inventory {
public:
    // Function declarations
    void addItem(const std::string& name, int quantity, const std::string& category, double price);
    void updateItem(const std::string& name, int quantity);
    void removeItem(const std::string& name);
    void printInventory() const;
    void printPopularItems() const;

private:
    // Data members
    std::map<std::string, int> items;                 // item name -> quantity
    std::set<std::string> categories;                 // unique categories
    std::multiset<std::string> popularItems;          // track popular items
    std::unordered_map<std::string, double> prices;   // item name -> price
};

#endif // INVENTORY_HPP
