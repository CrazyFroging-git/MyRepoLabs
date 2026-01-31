#include <iostream>
#include <string>
#include "Player.hpp"

/*class Player{
private:
    std::string name_;
    int posx_;
    int posy_;
    int hp_;
    std::string actionstatus_;
public:
    Player(std::string name, int posx, int posy, int hp, std::string actionstatus){
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
    Player(const Player &other): name_(other.name_), posx_(other.posx_), posy_(other.posy_), hp_(other.hp_), actionstatus_(other.actionstatus_){
        std::cout << "Игрок копирован" << std::endl;
    }
    ~Player(){
        std::cout << "Деструктор" << std::endl;
    }
    void setPosX(int posx){
        posx_ = posx;
    }
    void setPosY(int posy){
        posy_ = posy;
    }
    void Setactionstatus(std::string actionstatus){
        actionstatus_ = actionstatus;
    }
    void DrinkFlask(int k){
        hp_ += k;
        if (hp_ >= 100){
            hp_ = 0;
        }
    }
    void TakeDamage(int k){
        hp_ -= k;
        if (hp_ <= 0){
            hp_ = 0;
        }
    }
    void ViewAll(){
        std::cout << "Игрок 1: " << name_
          << ",    HP: " << hp_ 
          << ",    Позиция: (" << posx_ 
          << ", " << posy_ << ")"
          << ",    " << "Действие:" << actionstatus_ << std::endl;
    }
    std::string GetName() const {return name_;}
    int GetPosX() const {return posx_;}
    int GetPosY() const {return posy_;}
    int GetHP() const {return hp_;}
};

*/
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    try {
        Player player1("Иван", 0, 0, 100, "Бегает");
        std::cout << player1.GetName() << std::endl;
        std::cout << player1.GetPosX() << std::endl;
        player1.setPosX(100);
        std::cout << player1.GetPosX() << std::endl;
        player1.ViewAll();
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Неизвестная ошибка: " << std::endl;
    }
}
