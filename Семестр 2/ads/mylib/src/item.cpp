#include "item.hpp"
item::item(const std::string& name_, unsigned rare_, const std::string& description_){
    name = name_;
    rare = rare_;
    description = description_;
};
void item::printItem() const{
    std::cout << "Item name: " << name << std::endl;
    std::cout << "Item rare: "<< rare << std::endl;
    std::cout << "Description: " << description << std::endl;
}
extern const item bow("Bow", 3, "Just a bow");
extern const item dolg("Dolg", 1, "Dolg for the worst students");
extern const item avtomat("Avtomat", 10, "Avtomat for the most good students");
extern const item water("Water", 1, "Just a water");
extern const item grass("Grass", 1, "Just a grass");
extern const item woodSword("Wood sword", 2, "Wood sword, almost full useless");
extern const item diamondSword("Diamond sword", 5, "Diamond sword for cool players only");