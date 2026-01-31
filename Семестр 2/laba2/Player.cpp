#include "Player.hpp"
#include <iostream>
#include <string>

Player::Player(std::string name, int posx, int posy, int hp, std::string actionstatus){
    name_ = name;
    posx_ = posx;
    posy_ = posy;
    hp_ = hp;
    actionstatus_ = actionstatus;
    if (name.empty()) {
        throw std::invalid_argument("Имя не может быть пустым!");
    }
    if (hp < 0) {
        throw std::invalid_argument("HP должен быть положительным числом!");
    }
}
Player::Player(const Player &other): name_(other.name_), posx_(other.posx_), posy_(other.posy_), hp_(other.hp_), actionstatus_(other.actionstatus_){
    std::cout << "Игрок копирован" << std::endl;
}
Player::~Player(){
    std::cout << "Деструктор" << std::endl;
}
void Player::setPosX(int posx){
    posx_ = posx;
}
void Player::setPosY(int posy){
    posy_ = posy;
}
void Player::Setactionstatus(std::string actionstatus){
    actionstatus_ = actionstatus;
}
void Player::DrinkFlask(int k){
    hp_ += k;
    if (hp_ >= 100){
        hp_ = 0;
    }
}
void Player::TakeDamage(int k){
    hp_ -= k;
    if (hp_ <= 0){
        hp_ = 0;
    }
}
void Player::ViewAll() const{
    std::cout << "Игрок 1: " << name_
      << ",    HP: " << hp_ 
      << ",    Позиция: (" << posx_ 
      << ", " << posy_ << ")"
      << ",    " << "Действие:" << actionstatus_ << std::endl;
}
std::string Player::GetName() const {return name_;}
int Player::GetPosX() const {return posx_;}
int Player::GetPosY() const {return posy_;}
int Player::GetHP() const {return hp_;}