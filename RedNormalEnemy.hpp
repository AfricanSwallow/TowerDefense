#ifndef REDNORMALENEMY_HPP
#define REDNORMALENEMY_HPP
#include "Enemy.hpp"

class RedNormalEnemy : public Enemy {
public:
    RedNormalEnemy(int x, int y);
};

class GreenNormalEnemy : public Enemy {
public:
    GreenNormalEnemy(int x, int y);
    void OnExplode() override;
};
#endif // REDNORMALENEMY_HPP
