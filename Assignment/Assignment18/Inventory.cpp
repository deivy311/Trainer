#include "Inventory.hpp"
#include <iostream>

// Add a new item to the inventory
void Inventory::addItem(const std::string& name, int quantity, const std::string& category, double price) {
    // Add to items
    items[name] += quantity;

    // Add to category set
    categories.insert(category);

    // Add to prices
    prices[name] = price;

    // Add to popular items
    for (int i = 0; i < quantity; ++i) {
        popularItems.insert(name);
    }

    std::cout << "Item added: " << name << ", Quantity: " << quantity << ", Category: " << category << ", Price: " << price << std::endl;
}

// Update the quantity of an existing item
void Inventory::updateItem(const std::string& name, int quantity) {
    if (items.find(name) != items.end()) {
        items[name] += quantity;

        // Update the popular items multiset
        for (int i = 0; i < quantity; ++i) {
            popularItems.insert(name);
        }

        std::cout << "Item updated: " << name << ", New Quantity: " << items[name] << std::endl;
    } else {
        std::cout << "Item not found: " << name << std::endl;
    }
}

// Remove an item from the inventory
void Inventory::removeItem(const std::string& name) {
    auto itemIt = items.find(name);
    if (itemIt != items.end()) {
        // Remove from items
        items.erase(itemIt);

        // Remove from prices
        prices.erase(name);

        // Remove from popularItems
        popularItems.erase(name);

        std::cout << "Item removed: " << name << std::endl;
    } else {
        std::cout << "Item not found: " << name << std::endl;
    }
}

// Print the entire inventory
void Inventory::printInventory() const {
    std::cout << "Inventory: " << std::endl;
    for (const auto& item : items) {
        std::cout << "Item: " << item.first << ", Quantity: " << item.second
                  << ", Price: $" << prices.at(item.first) << std::endl;
    }
}

// Print the popular items
void Inventory::printPopularItems() const {
    std::cout << "Popular Items: " << std::endl;
    for (const auto& item : popularItems) {
        std::cout << item << std::endl;
    }
}
