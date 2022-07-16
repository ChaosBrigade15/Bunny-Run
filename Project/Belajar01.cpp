#include "Belajar01.h"

using namespace Engine;

Engine::Belajar01::Belajar01(Setting* setting):Engine::Game(setting)
{
}

Engine::Belajar01::~Belajar01()
{
}

void Engine::Belajar01::Init()
{

	backgroundTexture = new Texture("background game.png");
	backgroundSprite = new Sprite(backgroundTexture, defaultSpriteShader, defaultQuad);
	backgroundSprite->SetPosition(100, 384);
	backgroundSprite->SetAnimationDuration(100);
	backgroundSprite->SetNumXFrames(1);
	backgroundSprite->SetNumYFrames(1);
	monsterSprite->SetScale(2);

	monsterTexture = new Texture("Ninja Frog Run.png");
	monsterSprite = new Sprite(monsterTexture, defaultSpriteShader, defaultQuad);
	monsterSprite->SetPosition(600, 340);
	monsterSprite->SetAnimationDuration(100);
	monsterSprite->SetNumXFrames(12);
	monsterSprite->SetNumYFrames(1);
	//monsterSprite->AddAnimation("idle", 0, 10);
	monsterSprite->AddAnimation("walk", 0, 11);
	monsterSprite->PlayAnim("walk");
	monsterSprite->SetScale(3);

	enemyTexture = new Texture("Enemy Run.png");
	enemySprite = new Sprite(enemyTexture, defaultSpriteShader, defaultQuad);
	enemySprite->SetPosition(1200, 300);
	enemySprite->SetAnimationDuration(100);
	enemySprite->SetNumXFrames(12);
	enemySprite->SetNumYFrames(1);
	enemySprite->AddAnimation("walk", 0, 11);
	enemySprite->PlayAnim("walk");
	enemySprite->SetScale(3);
	enemySprite->SetFlipHorizontal(true);

	inputManager->AddInputMapping("Rotate Right", SDLK_e);
	inputManager->AddInputMapping("Rotate Left", SDLK_q);
	inputManager->AddInputMapping("Move Up", SDLK_w);
	inputManager->AddInputMapping("Move Down", SDLK_s);
	inputManager->AddInputMapping("Move Right", SDLK_d);
	inputManager->AddInputMapping("Move Left", SDLK_a);
	inputManager->AddInputMapping("Walk Right", SDLK_RIGHT);
	inputManager->AddInputMapping("Walk Left", SDLK_LEFT);
	inputManager->AddInputMapping("Quit", SDLK_ESCAPE);
}

void Engine::Belajar01::Update()
{
	monsterSprite->Update(GetGameTime());
	enemySprite->Update(GetGameTime());
	float xspeed = 0;
	
	/*vec2 oldMonsterPos = monsterSprite->GetPosition();
	vec2 oldMonsterPosE = enemySprite->GetPosition();*/
	float x = enemySprite->GetPosition().x;
	float y = enemySprite->GetPosition().y;

	monsterSprite->PlayAnim("walk");
	enemySprite->PlayAnim("walk");

	if (Mentok == false) {
		x -= velocity * GetGameTime();
		enemySprite->SetPosition(x, y);
		if (x <= -100) {
			Mentok = true;
		}
	}
	else {
		count++;
		if (count >= 2000) {
			positionSpawnY = rand();
			if (positionSpawnY % 2 == 0) {
				enemySprite->SetPosition(1200, 500);
			}
			else if (positionSpawnY % 2 == 1) {
				enemySprite->SetPosition(1200, 100);
			}
			else {
				enemySprite->SetPosition(1200, 300);
			}
			velocity += 0.05f;
			Mentok = false;
			count = 0;
		}
	}
	/*if (Mentok == true) {
		enemySprite->SetPosition(oldMonsterPosE.x + 0.2 * GetGameTime(), oldMonsterPosE.y);
		if (oldMonsterPosE.x >= 939) {
			Mentok = false;
			enemySprite->SetFlipHorizontal(true);
		}
	}
	else if (Mentok == false) {
		enemySprite->SetPosition(oldMonsterPosE.x - 0.2 * GetGameTime(), oldMonsterPosE.y);
		if (oldMonsterPosE.x <= 0) {
			Mentok = true;
			enemySprite->SetFlipHorizontal(false);
		}
	}*/

	/*if (inputManager->IsKeyPressed("Move Up")) {
		xspeed = 0.1f;
		monsterSprite->PlayAnim("walk");
		monsterSprite->SetPosition(oldMonsterPos.x, oldMonsterPos.y + 42);
		//monsterSprite->SetPosition(oldMonsterPos.x + xspeed * GetGameTime(), oldMonsterPos.y);
		//monsterSprite->SetFlipHorizontal(false);
	}

	if (inputManager->IsKeyPressed("Move Down")) {
		xspeed = -0.1f;
		monsterSprite->PlayAnim("walk");
		monsterSprite->SetPosition(oldMonsterPos.x, oldMonsterPos.y - 42);
		//monsterSprite->SetPosition(oldMonsterPos.x + xspeed * GetGameTime(), oldMonsterPos.y);
		//monsterSprite->SetFlipHorizontal(true);
	}*/
	monsterSprite->Update(GetGameTime());
	enemySprite->Update(GetGameTime());
}

void Engine::Belajar01::Render()
{
	backgroundSprite->Draw();
	enemySprite->Draw();
	//monsterSprite->Draw();
}

int main(int argc, char** argv) {
	Setting* setting = new Setting();
	setting->windowTitle = "Project Example";
	setting->screenWidth = 1200;
	setting->screenHeight = 680;
	setting->windowFlag = WindowFlag::WINDOWED;
	Game* game = new Belajar01(setting);
	game->Run();
	delete setting;
	delete game;

	return 0;
}