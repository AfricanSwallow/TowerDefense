#ifndef WOODBULLET_HPP
#define WOODBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class WoodBullet : public Bullet {
public:
    explicit WoodBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};

class FireBullet : public Bullet {
public:
    explicit FireBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
	void Update(float deltaTime) override;
};

class VirusBullet : public Bullet {
public:
    explicit VirusBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
	void Update(float deltaTime) override;
};
#endif // WOODBULLET_HPP
