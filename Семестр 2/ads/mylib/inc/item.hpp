#pragma once
#include "includes.hpp"
struct item{   
    std::string name;
    unsigned rare;
    std::string description;
    item(const std::string& name_, unsigned rare_, const std::string& description_);
    void printItem() const; 
};
extern const item bow;
extern const item dolg;
extern const item avtomat;
extern const item water;
extern const item grass;
extern const item woodSword;
extern const item diamondSword;