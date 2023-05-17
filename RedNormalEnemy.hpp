#ifndef REDNORMALENEMY_HPP
#define REDNORMALENEMY_HPP
#include "Enemy.hpp"

class RedNormalEnemy : public Enemy {
public:
    RedNormalEnemy(int x, int y);
};

class Dice_2 : public Enemy {
public:
    Dice_2(int x, int y);
    void OnExplode() override;
};
#endif // REDNORMALENEMY_HPP
