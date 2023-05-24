#include <allegro5/base.h>
#include <allegro5/color.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <utility>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "PlugGunTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect.hpp"
#include "Enemy.hpp"
#include "Sprite.hpp"
#include "Image.hpp"

const int PlugGunTurret::Price = 40;
const int PlugGunTurret::ID = 0;
PlugGunTurret::PlugGunTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-6.png", x, y, 200, Price, 1.5, ID) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet(Position + normalized * 36, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}

const int MachineGunTurret::Price = 50;
const int MachineGunTurret::ID = 1;
MachineGunTurret::MachineGunTurret(float x, float y) :
    Turret("play/tower-base.png", "play/turret-1.png", x, y, 400, Price, 1.5, ID) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void MachineGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized * 36, diff, rotation, this));
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}

const int TwoGunTurret::Price = 60;
const int TwoGunTurret::ID = 2;
TwoGunTurret::TwoGunTurret(float x, float y) :
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 400, Price, 1.5, ID) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void TwoGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    Engine::Point perpendicular = Engine::Point(-normalized.y, normalized.x);
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized * 36 + perpendicular * 5, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized * 36 - perpendicular * 5, diff, rotation, this));
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}

const int ElephantTurret::Price = 30;
const int ElephantTurret::ID = 3;
ElephantTurret::ElephantTurret(float x, float y) :
    Turret("play/tower-base.png", "play/elephant.png", x, y, 150, Price, 1.5, ID) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void ElephantTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point up = Engine::Point(0, -1);
    Engine::Point down = Engine::Point(0, 1);
    Engine::Point right = Engine::Point(1, 0);
    Engine::Point left = Engine::Point(-1, 0);
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new VirusBullet(Position + up * CollisionRadius, left, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new VirusBullet(Position + down * CollisionRadius, right, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new VirusBullet(Position + right * CollisionRadius, up, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new VirusBullet(Position + left * CollisionRadius, down, rotation, this));
}

void ElephantTurret::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	imgBase.Position = Position;
	imgBase.Tint = Tint;
	if (!Enabled)
		return;
	
    if (bullet_num == 0) {
        ElephantTurret::CreateBullet();
        bullet_num = 4;
    }
}

const int ShovelTurret::Price = 0;
const int ShovelTurret::ID = 4;
ShovelTurret::ShovelTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/shovel.png", x, y, 200, Price, 1.5, ID) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}

void ShovelTurret::CreateBullet() {

}

void ShovelTurret::Draw() const{
    if (Preview) {
		al_draw_filled_circle(Position.x, Position.y, CollisionRadius, al_map_rgba(0, 255, 0, 50));
	}
	Sprite::Draw();
	if (PlayScene::DebugMode) {
		// Draw target radius.
		al_draw_circle(Position.x, Position.y, CollisionRadius, al_map_rgb(0, 0, 255), 2);
	}
}

const int ShifterTurret::Price = 0;
const int ShifterTurret::ID = 5;
ShifterTurret::ShifterTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/shifter.png", x, y, 200, Price, 1.5, ID) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}

void ShifterTurret::CreateBullet() {

}

void ShifterTurret::Draw() const{
    if (Preview) {
		al_draw_filled_circle(Position.x, Position.y, CollisionRadius, al_map_rgba(0, 255, 0, 50));
	}
	Sprite::Draw();
	if (PlayScene::DebugMode) {
		// Draw target radius.
		al_draw_circle(Position.x, Position.y, CollisionRadius, al_map_rgb(0, 0, 255), 2);
	}
}