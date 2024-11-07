#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <set>
#include <vector>

// Inventory management system class
class InventoryManagementSystem {
private:
    std::map<std::string, int> items; // Map to store item name as key and quantity as value
    std::set<std::string> categories; // Set to store unique item categories
    std::unordered_map<std::string, double> prices; // Unordered map for quick access to item prices
    std::multiset<std::string> popularItems; // Multiset to track frequently added/updated items

public:
    // Function to add a new item or update an existing item
    void addItem(const std::string& name, int quantity, const std::string& category, double price) {
        // Add quantity if item exists, otherwise initialize with the quantity
        items[name] += quantity;
        
        // Add the category to the set of categories
        categories.insert(category);

        // Update or set the price of the item
        prices[name] = price;

        // Track the popularity of the item by inserting it into the multiset
        popularItems.insert(name);

        // Print confirmation message
        std::cout << "Added/Updated item: " << name << ", Quantity: " << quantity
                  << ", Category: " << category << ", Price: " << price << std::endl;
    }

    // Function to update the quantity of an existing item
    void updateItem(const std::string& name, int quantity) {
        // Check if the item exists in the inventory
        if (items.find(name) != items.end()) {
            // Update the quantity of the item
            items[name] += quantity;

            // Track popularity by adding it to the multiset again
            popularItems.insert(name);

            // Print confirmation message
            std::cout << "Updated item: " << name << ", New Quantity: " << items[name] << std::endl;
        } else {
            // Item does not exist in inventory
            std::cout << "Item " << name << " not found in inventory." << std::endl;
        }
    }

    // Function to remove an item from the inventory
    void removeItem(const std::string& name) {
        // Erase the item from the items map and check if it was removed
        if (items.erase(name)) {
            // Also remove the item from the prices map
            prices.erase(name);
            std::cout << "Removed item: " << name << std::endl;
        } else {
            // Item was not found in the inventory
            std::cout << "Item " << name << " not found in inventory." << std::endl;
        }
    }

    // Function to print all items with their details
    void printInventory() const {
        std::cout << "Inventory List:" << std::endl;
        
        // Iterate through the items map and print each item with its details
        for (const auto& item : items) {
            std::cout << "Item: " << item.first
                      << ", Quantity: " << item.second
                      << ", Price: " << prices.at(item.first) << std::endl;
        }
    }

    // Function to print popular items based on their frequency of addition/updating
    void printPopularItems() const {
        // Use a temporary map to count occurrences of each item in the multiset
        std::map<std::string, int> popularity;
        for (const auto& item : popularItems) {
            popularity[item]++;
        }

        // Print out the popular items with their frequency
        std::cout << "Popular Items:" << std::endl;
        for (const auto& item : popularity) {
            std::cout << "Item: " << item.first << ", Count: " << item.second << std::endl;
        }
    }
};

int main() {
    // Create an instance of InventoryManagementSystem
    InventoryManagementSystem ims;

    // Add some sample items
    ims.addItem("Laptop", 10, "Electronics", 999.99);
    ims.addItem("Shirt", 20, "Clothing", 29.99);

    // Update an item's quantity
    ims.updateItem("Laptop", 5);

    // Remove an item
    ims.removeItem("Shirt");

    // Print the full inventory
    ims.printInventory();

    // Print the popular items
    ims.printPopularItems();

    return 0;
}
