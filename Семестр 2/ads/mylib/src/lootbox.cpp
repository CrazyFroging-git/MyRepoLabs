#include "lootbox.hpp"
lootbox::lootbox(){
    caseName = "undefined box";
    caseItems;
}
lootbox::lootbox(const lootbox& other){
    caseName = other.caseName;
    caseItems = other.caseItems;
    // std::cout << "Copy Lootbox this=" << this << " from=" << &other << std::endl;
}
lootbox::lootbox(const std::string& caseName_, const std::vector<item>& caseItems_){
    caseName = caseName_;
    caseItems = caseItems_;
}
lootbox::~lootbox(){
    // std::cout << this->caseName << std::endl;
    std::cout << "lootbox deleted " << std::endl;
}
lootbox& lootbox::operator=(const lootbox& other){
    if (this == &other) {
        return *this;
    }
    caseName = other.caseName;
    caseItems = other.caseItems;
    return *this;
}  
item lootbox::returnRandItem() const{
      if (caseItems.empty()) {
        return item("Nothing", 0, "Case is empty");
    }
    int indx = std::rand() % caseItems.size();
    return caseItems[indx];
}
void lootbox::printLootbox() const{
    std::cout << "Case name: " << caseName << std::endl;
    std::cout << "Items in case: " << std::endl;
    if (caseItems.empty()) {
        std::cout << "Case is empty" << std::endl;;
    } 
    else {
        for (size_t i = 0; i < caseItems.size(); i++) {
            std::cout << "Item name: " << caseItems[i].name << std::endl;
            std::cout << "Item description: " <<caseItems[i].description << std::endl;
            std::cout << "Item rare: " << caseItems[i].rare << std::endl;
            if (i + 1 < caseItems.size())
                std::cout << " ----- " << std::endl;
        }
    }
    std::cout << std::endl;
}