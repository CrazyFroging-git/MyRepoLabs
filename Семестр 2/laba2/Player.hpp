#pragma once

class Player{
private:
    std::string name_;
    int posx_;
    int posy_;
    int hp_;
    std::string actionstatus_;
public:
    Player(std::string name, int posx, int posy, int hp, std::string actionstatus);
    Player(const Player &other);
    ~Player();
    void setPosX(int posx);
    void setPosY(int posy);
    void Setactionstatus(std::string actionstatus);
    void DrinkFlask(int k);
    void TakeDamage(int k);
    
    void ViewAll() const;
    std::string GetName() const;
    int GetPosX() const;
    int GetPosY() const;
    int GetHP() const;
};
