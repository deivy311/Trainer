#include "Inventory.hpp"
#include <iostream>

int main() {
    Inventory inventory;

    // Adding items to the inventory
    inventory.addItem("Laptop", 10, "Electronics", 999.99);
    inventory.addItem("Shirt", 20, "Clothing", 19.99);
    inventory.addItem("Apple", 50, "Groceries", 0.99);

    // Update items in the inventory
    inventory.updateItem("Laptop", 5);
    inventory.updateItem("Shirt", 10);

    // Remove an item from the inventory
    inventory.removeItem("Apple");

    // Print the entire inventory
    inventory.printInventory();

    // Print popular items
    inventory.printPopularItems();

    return 0;
}
