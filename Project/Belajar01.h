#ifndef BELAJAR01_H
#define BELAJAR01_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"

namespace Engine {
	class Belajar01 :
		public Engine::Game
	{
	public:
		Belajar01(Setting* setting);
		~Belajar01();
		virtual void Init();
		virtual void Update();
		virtual void Render();
		Texture* playButtonTexture = NULL;
	private:
		Text* text = NULL;
		Sprite* backgroundSprite = NULL;
		Texture* backgroundTexture = NULL;
		Sprite* monsterSprite = NULL;
		Texture* monsterTexture = NULL;
		Sprite* enemySprite = NULL;
		Texture* enemyTexture = NULL;
		bool Mentok = false;
		int positionSpawnY;
		int count;
		float velocity = 0.1f;
	};
}
#endif

