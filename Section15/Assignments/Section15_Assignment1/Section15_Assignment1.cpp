#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <algorithm>
#include <set>


class Inventory {
private:
    std::map<std::string, int> items;                // item name and quantity
    std::set<std::string> categories;                // unique item categories
    std::unordered_map<std::string, double> prices;  // item name and price
    std::multiset<std::string> popularItems;         // tracks popular items

public:
    // Adds a new item with a given name, quantity, category, and price.
    void addItem(const std::string& name, int quantity, const std::string& category, double price) {
        items[name] = quantity;
        categories.insert(category);
        prices[name] = price;
        popularItems.insert(name);
        std::cout << "Added item: " << name << " (Quantity: " << quantity << ", Category: " << category << ", Price: $" << price << ")\n";
    }

    // Updates the quantity of an existing item.
    void updateItem(const std::string& name, int quantity) {
        if (items.find(name) != items.end()) {
            items[name] = quantity;
            popularItems.insert(name);  // Increment popularity
            std::cout << "Updated item: " << name << " (New Quantity: " << quantity << ")\n";
        } else {
            std::cout << "Item " << name << " does not exist in inventory.\n";
        }
    }

    // Removes an item from the inventory.
    void removeItem(const std::string& name) {
        if (items.find(name) != items.end()) {
            items.erase(name);
            prices.erase(name);
            // Remove all instances of the item from popularItems multiset
            popularItems.erase(name);
            std::cout << "Removed item: " << name << "\n";
        } else {
            std::cout << "Item " << name << " does not exist in inventory.\n";
        }
    }

    // Prints all items in the inventory along with their details.
    void printInventory() {
        std::cout << "\nInventory List:\n";
        for (const auto& item : items) {
            std::string name = item.first;
            int quantity = item.second;
            double price = prices[name];
            std::cout << "Item: " << name << " | Quantity: " << quantity << " | Price: $" << price << "\n";
        }
        std::cout << "Total Categories: " << categories.size() << "\n";
    }

    // Prints the most popular items based on the multiset count.
    void printPopularItems() {
        std::cout << "\nPopular Items:\n";
        std::map<std::string, int> frequency;
        for (const auto& item : popularItems) {
            frequency[item]++;
        }
        for (const auto& item : frequency) {
            std::cout << "Item: " << item.first << " | Times Updated: " << item.second << "\n";
        }
    }
};

int main() {
    Inventory inventory;

    // Sample operations
    inventory.addItem("Laptop", 10, "Electronics", 999.99);
    inventory.addItem("Apple", 50, "Groceries", 0.99);
    inventory.addItem("T-shirt", 20, "Clothing", 19.99);
    
    inventory.updateItem("Laptop", 5);
    inventory.updateItem("Apple", 60);

    inventory.printInventory();
    inventory.printPopularItems();

    inventory.removeItem("T-shirt");

    inventory.printInventory();
    inventory.printPopularItems();

    return 0;
}
