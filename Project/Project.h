#ifndef PROJECT_H
#define PROJECT_H

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
	private:
		Text* gameScore = NULL;
		Text* endScore = NULL;

		Sprite* titleSprite = NULL;
		Texture* titleTexture = NULL;

		Sprite* playButtonSprite = NULL;
		Texture* playButtonTexture = NULL;
		Sprite* exitButtonSprite = NULL;
		Texture* exitButtonTexture = NULL;

		Sprite* guiSprite = NULL;
		Texture* guiTexture = NULL;
		Sprite* endGuiSprite = NULL;
		Texture* endGuiTexture = NULL;

		Sprite* menuInfoSprite = NULL;
		Texture* menuInfoTexture = NULL;
		Sprite* gameInfoSprite = NULL;
		Texture* gameInfoTexture = NULL;
		Sprite* overInfoSprite = NULL;
		Texture* overInfoTexture = NULL;

		Sprite* restartButtonSprite = NULL;
		Texture* restartButtonTexture = NULL;
		Sprite* quitButtonSprite = NULL;
		Texture* quitButtonTexture = NULL;

		Sprite* backgroundSprite = NULL;
		Texture* backgroundTexture = NULL;

		Sprite* playerSprite = NULL;
		Texture* playerTexture = NULL;
		Sprite* player1Sprite = NULL;
		Texture* player1Texture = NULL;
		Sprite* player2Sprite = NULL;
		Texture* player2Texture = NULL;
		Sprite* player3Sprite = NULL;
		Texture* player3Texture = NULL;

		Sprite* enemySprite = NULL;
		Sprite* enemySprite1 = NULL;
		Sprite* enemySprite2 = NULL;
		Texture* enemyTexture = NULL;
		
		Music* music = NULL;
		bool Mentok = false, Mentok1 = false, Mentok2 = false;
		int count, count1, count2;

		bool menu = true;
		bool gameOn = false;
		bool gameOver = false;

		bool buttonPlaySelected = true;
		bool buttonExitSelected = false;
		bool buttonRestartSelected = true;
		bool buttonQuitSelected = false;

		bool up = false;
		bool down = false;
		int positionSpawnY;
		int score = 0;
		int overScore = 0;
		int targetPos = 0;
		int i = 2;
		int pos[5] = {40, 170, 310, 450, 580};
		float yspeed = 0;
		float velocity = 0.1f;
		float yK = 310;
	};
}
#endif