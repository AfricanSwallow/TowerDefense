CXXFLAGS = -std=c++11 -O2 `pkg-config allegro-5 --cflags`

LDFLAGS = -lm -Wall -Wextra

LDLIBS = `pkg-config allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5 allegro_video-5 --libs`

exe = TowerDefense.out

obj = Allegro5Exception.o AudioHelper.o Bullet.o Collider.o DirtyEffect.o Enemy.o ExplosionEffect.o GameEngine.o GreenNormalEnemy.o Group.o IControl.o Image.o ImageButton.o IObject.o IScene.o Label.o LOG.o LoseScene.o Plane.o PlugGunTurret.o PlayScene.o Point.o RedNormalEnemy.o Resources.o SettingScene.o Slider.o Sprite.o StageSelectScene.o StartScene.o Turret.o TurretButton.o WinScene.o WoodBullet.o main.o 



.PHONY: all clean



all: $(obj)

	$(CXX) -o $(exe) $(obj) $(LDFLAGS) $(LDLIBS)



%.o: %.cpp

	$(CXX) -c $< -o $@ $(CXXFLAGS)



clean:

	rm $(exe) $(obj)