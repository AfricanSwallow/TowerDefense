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
#endif // PLUGGUNTURRET_HPP
