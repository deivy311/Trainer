#include <iostream>      // for input/output operations
#include <string> 
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>

class InventorySystem {

private:

std::map<std::string,int> items;
std::set<std::string> categories;
std::unordered_map<std::string,double> prices;
std::multiset<std::string> popularItems;


public:

void addItem(const std::string& name,int quantity,const std::string& category,double price);
void updateItem(const std::string& name,int quantity);
void removeItem(const std::string& name);
void printInventory();
void printPopularItems();

};

void InventorySystem::addItem(const std::string& name,int quantity,const std::string& category,double price)
{
  items[name] = quantity; // add in map
  categories.insert(category); // add in set
  prices[name] = price; // add in unordered map
  popularItems.insert(name);  // add in multiset
}

void InventorySystem::updateItem(const std::string& name,int quantity){
    if(items.find(name) != items.end()){
        items[name] = quantity; // update item quantity
        popularItems.insert(name); //insert item in popular items
    }else{
        std::cout << "Item not found. \n";
    }
}

void InventorySystem::removeItem(const std::string& name){
     if (items.find(name) != items.end()) {
        items.erase(name);
        prices.erase(name);
        popularItems.erase(name);  // removes all occurrences
    } else {
        std::cout << "Item not found.\n";
    }
}

void InventorySystem::printInventory() {
    for (const auto& item : items) {
        std::cout << "Item: " << item.first << ", Quantity: " << item.second
                  << ", Price: " << prices.at(item.first) << "\n";
    }
}

void InventorySystem::printPopularItems() {
    std::cout << "Popular Items:\n";
    for (const auto& item : popularItems) {
        std::cout << item << "\n";
    }
}

int main(){


    InventorySystem inventory;
    inventory.addItem("Laptop", 5, "Electronics", 1200.00);
    inventory.addItem("Shirt", 50, "Clothing",30.00);

    inventory.printInventory();

    inventory.updateItem("Laptop",10);
    inventory.printPopularItems();

    inventory.removeItem("Shirt");
}
