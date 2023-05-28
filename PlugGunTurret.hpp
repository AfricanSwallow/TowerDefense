#ifndef PLUGGUNTURRET_HPP
#define PLUGGUNTURRET_HPP
#include "Turret.hpp"

class PlugGunTurret : public Turret {
public:
    static const int Price;
    static const int ID;
    PlugGunTurret(float x, float y);
    void CreateBullet() override;
};

class MachineGunTurret : public Turret {
public:
    static const int Price;
    static const int ID;
    MachineGunTurret(float x, float y);
    void CreateBullet() override;
};

class TwoGunTurret : public Turret {
public:
    static const int Price;
    static const int ID;
    TwoGunTurret(float x, float y);
    void CreateBullet() override;
};

class ElephantTurret : public Turret {
public:
    static const int Price;
    static const int ID;
    ElephantTurret(float x, float y);
    void CreateBullet() override;
    void Update(float deltaTime) override;
};

class ShovelTurret : public Turret {
public:
    static const int Price;
    static const int ID;
    ShovelTurret(float x, float y);
    void CreateBullet() override;
    void Draw() const override;
};

class ShifterTurret : public Turret {
public:
    static const int Price;
    static const int ID;
    ShifterTurret(float x, float y);
    void CreateBullet() override;
    void Draw() const override;
};

class SpellTurret : public Turret {
public:
    static const int Price;
    static const int ID;
    SpellTurret(float x, float y);
    void CreateBullet() override;
    void Draw() const override;
    void Update(float deltaTime) override;
};
#endif // PLUGGUNTURRET_HPP