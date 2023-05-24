#ifndef TURRETBUTTON_HPP
#define TURRETBUTTON_HPP
#include <string>

#include "ImageButton.hpp"
#include "Sprite.hpp"

class PlayScene;

class TurretButton : public Engine::ImageButton {
protected:
    PlayScene* getPlayScene();
public:
	int money;
	bool want_base;
	Engine::Sprite Base;
	Engine::Sprite Turret;
	TurretButton(std::string img, std::string imgIn, Engine::Sprite Base, Engine::Sprite Turret, float x, float y, int money, bool want_base);
	void Update(float deltaTime) override;
	void Draw() const override;
};
#endif // TURRETBUTTON_HPP
