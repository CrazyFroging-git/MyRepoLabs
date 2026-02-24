#include "player.hpp"
Player::Player() {
    std::cout << "afk player created" << std::endl;
    name = this->randomName();
    doing = "afk";
    hp = 100;
    x = 0.0;
    y = 0.0;
}
Player::Player(const Player& p) {
    std::cout << "player copied" << std::endl;
    name = p.name;
    doing = p.doing;
    inv = p.inv;
    hp = p.hp;
    x = p.x;
    y = p.y;
}
Player::Player(const std::string& name_, const std::string& doing_, const std::vector<item>& inv_, unsigned hp_, float x_, float y_) {
		std::cout << "norm player created" << std::endl;
		name = name_;
        doing = doing_;
		inv = inv_;
		hp = hp_;
		x = x_;
		y = y_;
	}
Player::~Player(){
    std::cout << "player " << this->name << " cleared" << std::endl;
    if (!inv.empty()){
        inv.clear();
        std::cout << "vector cleared" << std::endl;
    }
    else{
        std::cout << "vector was empty" << std::endl;
    }
}	
void Player::printinfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Doing: " << doing << std::endl;
    std::cout << "X coord: " << x << std::endl;
    std::cout << "Y coord: " << y << std::endl;
    std::cout << "Hp: " << hp << std::endl;
    std::cout << "Inventory: " << std::endl;
    std::cout << " ----- " << std::endl;
    if (inv.empty()) {
        std::cout << "Inventory is empty";
    } 
    else {
        for (size_t i = 0; i < inv.size(); i++) {
            std::cout << "Item name: " << inv[i].name << std::endl;
            std::cout << "Item description: " <<inv[i].description << std::endl;
            std::cout << "Item rare: " << inv[i].rare << std::endl;
            if (i + 1 < inv.size())
                std::cout << " ----- " << std::endl;
        }
    }
    std::cout << " ----- " << std::endl;
}
const std::string& Player::getName() const {
    return name;
}
const std::string& Player::getDoing() const {
    return doing;
}
const std::vector<item>& Player::getItems() const {
    return inv;
}
float Player::getX() const {
    return x;
}
float Player::getY() const {
    return y;
}
unsigned Player::getHp() const {
    return hp;
}
void Player::setX(float newX) {
    x = newX;
}
void Player::setY(float newY) {
    y = newY;
}
void Player::setDoing(const std::string& newDoing) {
    doing = newDoing;
}
void Player::setPos(float newX, float newY) {
    x = newX;
    y = newY;
}
void Player::addItem(const item& newItem){
    inv.push_back(newItem);
}
void Player::damage(int dmg) {
    if (dmg < 0 ) {
        return;
    }
    if (dmg >= hp) {
        hp = 0;
    }
    else {
        hp -= dmg;
    }
}
void Player::heal(int heal) {
    if (heal < 0) {
        return;
    }
    if ( (heal + hp) > 100) {
        hp = 100;
    }
    if (hp == 100) {
        std::cout << "hp already 100";
    }
    else{
        hp += heal;
    }
    
}
std::string Player::randomName() {
    return "Player_" + std::to_string(rand() % 100000);
}
void Player::removeDuplicates(std::vector<item>& v) {		
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = i + 1; j < v.size(); ) {
            if (v[j].name == v[i].name) {
                v.erase(v.begin() + j);
            } else {
                j++;
            }
        }
    }
}
Player Player::operator+(const Player& other){
    Player res;
    res.name = res.randomName();
    res.doing = this->doing;
    res.x = (this->x + other.x) / 2.0f;
    res.y = (this->y + other.y) / 2.0f;
    res.hp = this->hp;
    res.inv = this->inv;
    for (size_t i = 0; i < other.inv.size(); i++) {
        res.inv.push_back(other.inv[i]);
    }
    res.removeDuplicates(res.inv);
    return res;
}
Player Player::operator-(const Player& other){
    Player res = *this;
    res.name = res.randomName();
    if (rand() % 2 == 0) {
        res.x = this->x;
        res.y = this->y;
    } 
    else {
        res.x = other.x;
        res.y = other.y;
    }
    res.hp = this->hp;
    res.doing = this->doing;
    for (size_t i = 0; i < res.inv.size(); ) {
        bool inOther = false;
        for (size_t j = 0; j < other.inv.size(); j++) {
            if (res.inv[i].name == other.inv[j].name) {
                inOther = true;
                break;
            }
        }
        if (inOther and (rand() % 2 == 0)) { 
            res.inv.erase(res.inv.begin() + i);
        } 
        else {
            i++;
        }
    }
    return res;
}
Player Player::operator/(const Player& other){
    Player res;
    res.name = res.randomName();
    res.x = this->x * other.x;
    res.y = this->y * other.y;
    res.hp = this->hp;
    res.doing = this->doing;
    res.inv.clear();
    size_t halfThis = this->inv.size() / 2;       
    size_t halfOther = other.inv.size() / 2; 
    for (size_t i = 0; i < halfThis; i++) {
        res.inv.push_back(this->inv[i]);
    }
    for (size_t i = halfOther; i < other.inv.size(); i++) {
        res.inv.push_back(other.inv[i]);
    }
    res.removeDuplicates(res.inv);
    return res;
}
Player& Player::operator=(const Player& other){
    if (this == &other) {
        return *this;
    }
    name = other.name;
    inv = other.inv;
    doing = other.doing;
    hp = other.hp;
    x = other.x;
    y = other.y;
    return *this;
}
void Player::openBox(const lootbox& box){
    item itemFromBox = box.returnRandItem();
    std::cout << "Your item from case: " << itemFromBox.name << std::endl;
    std::cout << "Do you want to add this item to inventory? 1 - yes / 2 - no" << std::endl;
    unsigned choose;
    do{
        std::cin >> choose;
        if (choose == 1){
            addItem(itemFromBox);
            break;
        }
        else if(choose == 2){
            std::cout << "Item dropped" << std::endl;
            break;
        }
    }while ((choose != 1) and (choose != 2));
}