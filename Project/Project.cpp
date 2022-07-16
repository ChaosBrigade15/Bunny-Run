#include "Project.h"

using namespace Engine;

Engine::Belajar01::Belajar01(Setting* setting) :Engine::Game(setting)
{
}

Engine::Belajar01::~Belajar01()
{
}

void Engine::Belajar01::Init()
{
	music = new Music("Game-BGM.ogg");
	music->SetVolume(30);
	music->Play(true);
	
	gameScore = new Text("Kaph-Regular.ttf", 64, defaultTextShader);
	gameScore->SetScale(0.3);
	gameScore->SetColor(255, 255, 255);
	gameScore->SetPosition(1010, 660);

	endScore = new Text("Kaph-Regular.ttf", 64, defaultTextShader);
	endScore->SetScale(0.45);
	endScore->SetColor(255, 255, 255);
	endScore->SetPosition(410, 410);

	backgroundTexture = new Texture("game background.png");
	backgroundSprite = new Sprite(backgroundTexture, defaultSpriteShader, defaultQuad);
	backgroundSprite->SetPosition(0, 0);
	backgroundSprite->SetScale(1.24);

	guiTexture = new Texture("gui board.png");
	guiSprite = new Sprite(guiTexture, defaultSpriteShader, defaultQuad);
	guiSprite->SetPosition(250, 125);
	guiSprite->SetScale(0.6);

	endGuiTexture = new Texture("gui board.png");
	endGuiSprite = new Sprite(endGuiTexture, defaultSpriteShader, defaultQuad);
	endGuiSprite->SetPosition(370, 225);
	endGuiSprite->SetScale(0.4);

	titleTexture = new Texture("Game Title.png");
	titleSprite = new Sprite(titleTexture, defaultSpriteShader, defaultQuad);
	titleSprite->SetPosition(330, 430);
	titleSprite->SetScale(0.7);

	playButtonTexture = new Texture("Play Button.png");
	playButtonSprite = new Sprite(playButtonTexture, defaultSpriteShader, defaultQuad);
	playButtonSprite->SetPosition(500, 300);
	playButtonSprite->SetNumXFrames(3);
	playButtonSprite->SetNumYFrames(1);
	playButtonSprite->AddAnimation("normal", 0, 0);
	playButtonSprite->AddAnimation("hover", 1, 2);
	playButtonSprite->SetScale(0.2);

	exitButtonTexture = new Texture("Exit Button.png");
	exitButtonSprite = new Sprite(exitButtonTexture, defaultSpriteShader, defaultQuad);
	exitButtonSprite->SetPosition(500, 200);
	exitButtonSprite->SetNumXFrames(3);
	exitButtonSprite->SetNumYFrames(1);
	exitButtonSprite->AddAnimation("normal", 0, 0);
	exitButtonSprite->AddAnimation("hover", 1, 2);
	exitButtonSprite->SetScale(0.2);

	restartButtonTexture = new Texture("Reload Button.png");
	restartButtonSprite = new Sprite(restartButtonTexture, defaultSpriteShader, defaultQuad);
	restartButtonSprite->SetPosition(620, 310);
	restartButtonSprite->SetNumXFrames(3);
	restartButtonSprite->SetNumYFrames(1);
	restartButtonSprite->AddAnimation("normal", 0, 0);
	restartButtonSprite->AddAnimation("hover", 1, 2);
	restartButtonSprite->SetScale(0.4);

	quitButtonTexture = new Texture("Quit Button.png");
	quitButtonSprite = new Sprite(quitButtonTexture, defaultSpriteShader, defaultQuad);
	quitButtonSprite->SetPosition(500, 310);
	quitButtonSprite->SetNumXFrames(3);
	quitButtonSprite->SetNumYFrames(1);
	quitButtonSprite->AddAnimation("normal", 0, 0);
	quitButtonSprite->AddAnimation("hover", 1, 2);
	quitButtonSprite->SetScale(0.4);

	menuInfoTexture = new Texture("Menu GUI.png");
	menuInfoSprite = new Sprite(menuInfoTexture, defaultSpriteShader, defaultQuad);
	menuInfoSprite->SetPosition(0, 600);
	menuInfoSprite->SetScale(0.7);

	gameInfoTexture = new Texture("InGame GUI.png");
	gameInfoSprite = new Sprite(gameInfoTexture, defaultSpriteShader, defaultQuad);
	gameInfoSprite->SetPosition(0, 625);
	gameInfoSprite->SetScale(0.9);

	overInfoTexture = new Texture("GameOver GUI.png");
	overInfoSprite = new Sprite(overInfoTexture, defaultSpriteShader, defaultQuad);
	overInfoSprite->SetPosition(7, 600);
	overInfoSprite->SetScale(0.7);

	playerTexture = new Texture("Ninja Frog Run.png");
	playerSprite = new Sprite(playerTexture, defaultSpriteShader, defaultQuad);
	playerSprite->SetPosition(60, yK);
	playerSprite->SetAnimationDuration(100);
	playerSprite->SetNumXFrames(12);
	playerSprite->SetNumYFrames(1);
	playerSprite->AddAnimation("walk", 0, 11);
	playerSprite->PlayAnim("walk");
	playerSprite->SetScale(2.2);

	enemyTexture = new Texture("Bunny Run.png");
	enemySprite = new Sprite(enemyTexture, defaultSpriteShader, defaultQuad);
	enemySprite->SetPosition(1200, 40);
	enemySprite->SetAnimationDuration(100);
	enemySprite->SetNumXFrames(12);
	enemySprite->SetNumYFrames(1);
	enemySprite->AddAnimation("walk", 0, 11);
	enemySprite->PlayAnim("walk");
	enemySprite->SetScale(2.2);
	enemySprite->SetFlipHorizontal(false);

	enemySprite1 = new Sprite(enemyTexture, defaultSpriteShader, defaultQuad);
	enemySprite1->SetPosition(1200, 310);
	enemySprite1->SetAnimationDuration(100);
	enemySprite1->SetNumXFrames(12);
	enemySprite1->SetNumYFrames(1);
	enemySprite1->AddAnimation("walk", 0, 11);
	enemySprite1->PlayAnim("walk");
	enemySprite1->SetScale(2.2);
	enemySprite1->SetFlipHorizontal(false);

	enemySprite2 = new Sprite(enemyTexture, defaultSpriteShader, defaultQuad);
	enemySprite2->SetPosition(1200, 580);
	enemySprite2->SetAnimationDuration(100);
	enemySprite2->SetNumXFrames(12);
	enemySprite2->SetNumYFrames(1);
	enemySprite2->AddAnimation("walk", 0, 11);
	enemySprite2->PlayAnim("walk");
	enemySprite2->SetScale(2.2);
	enemySprite2->SetFlipHorizontal(false);

	inputManager->AddInputMapping("Start", SDLK_SPACE);
	inputManager->AddInputMapping("Enter", SDLK_RETURN);
	inputManager->AddInputMapping("Walk Up", SDLK_w);
	inputManager->AddInputMapping("Walk Down", SDLK_s);
	inputManager->AddInputMapping("Select Up", SDLK_UP);
	inputManager->AddInputMapping("Select Down", SDLK_DOWN);
	inputManager->AddInputMapping("Select Right", SDLK_RIGHT);
	inputManager->AddInputMapping("Select Left", SDLK_LEFT);
	inputManager->AddInputMapping("Quit", SDLK_ESCAPE);
	inputManager->AddInputMapping("Left Mouse", SDL_BUTTON_LEFT);
	inputManager->AddInputMapping("Right Mouse", SDL_BUTTON_RIGHT);
}

void Engine::Belajar01::Update()
{
	backgroundSprite->Update(GetGameTime());
	guiSprite->Update(GetGameTime());
	gameScore->SetText("Score : " + to_string(score));
	playButtonSprite->Update(GetGameTime());
	exitButtonSprite->Update(GetGameTime());
	restartButtonSprite->Update(GetGameTime());
	quitButtonSprite->Update(GetGameTime());
	playerSprite->Update(GetGameTime());
	enemySprite->Update(GetGameTime());
	enemySprite1->Update(GetGameTime());
	enemySprite2->Update(GetGameTime());

	if (gameOver == true) {
		overScore = score;
		endScore->SetText("Final Score : " + to_string(overScore));
	}

	if (inputManager->IsKeyReleased("Quit")) {
		state = State::EXIT;
		return;
	}

	if (inputManager->IsKeyReleased("Select Up")) {
		playButtonSprite->PlayAnim("hover");
		exitButtonSprite->PlayAnim("normal");
		buttonPlaySelected = true;
		buttonExitSelected = false;
	}

	if (inputManager->IsKeyReleased("Select Down")) {
		playButtonSprite->PlayAnim("normal");
		exitButtonSprite->PlayAnim("hover");
		buttonExitSelected = true;
		buttonPlaySelected = false;
		if (inputManager->IsKeyReleased("Start")) {
			state = State::EXIT;
			return;
		}
	}

	if (inputManager->IsKeyReleased("Select Right")) {
		restartButtonSprite->PlayAnim("hover");
		quitButtonSprite->PlayAnim("normal");
		buttonRestartSelected = true;
		buttonQuitSelected = false;
	}

	if (inputManager->IsKeyReleased("Select Left")) {
		restartButtonSprite->PlayAnim("normal");
		quitButtonSprite->PlayAnim("hover");
		buttonRestartSelected = false;
		buttonQuitSelected = true;
	}

	if (inputManager->IsKeyReleased("Start")) {
		if (buttonPlaySelected == true && buttonExitSelected == false) {
			menu = false;
			gameOn = true;
		}
		else {
			gameOn = false;
			state = State::EXIT;
			return;
		}
	}

	vec2 oldPlayerPos = playerSprite->GetPosition();
	float yPlayer = oldPlayerPos.y;
	float x = enemySprite->GetPosition().x;
	float y = enemySprite->GetPosition().y;
	float x1 = enemySprite1->GetPosition().x;
	float y1 = enemySprite1->GetPosition().y;
	float x2 = enemySprite2->GetPosition().x;
	float y2 = enemySprite2->GetPosition().y;

	enemySprite->PlayAnim("walk");
	enemySprite1->PlayAnim("walk");
	enemySprite2->PlayAnim("walk");
	playerSprite->PlayAnim("walk");

	if (gameOn == true) {

		// Bunny 1
		if (Mentok == false) {
			x -= velocity * GetGameTime();
			enemySprite->SetPosition(x, y);
			if (x <= -100) {
				Mentok = true;
			}
		}
		else {
			count++;
			if (count >= 100) {
				positionSpawnY = rand() % 100 + 1;
				if (positionSpawnY <= 20) {
					enemySprite->SetPosition(1200, 40);
				}
				else if (positionSpawnY >= 21 && positionSpawnY <= 40) {
					enemySprite->SetPosition(1200, 170);
				}
				else if (positionSpawnY >= 41 && positionSpawnY <= 60) {
					enemySprite->SetPosition(1200, 310);
				}
				else if (positionSpawnY >= 61 && positionSpawnY <= 80) {
					enemySprite->SetPosition(1200, 450);
				}
				else if (positionSpawnY >= 81 && positionSpawnY <= 100) {
					enemySprite->SetPosition(1200, 580);
				}
				velocity += 0.05f;
				score += 100;
				Mentok = false;
				count = 0;
			}
		}
		//Bunny 2
		if (Mentok1 == false) {
			x1 -= velocity * GetGameTime();
			enemySprite1->SetPosition(x1, y1);
			if (x1 <= -100) {
				Mentok1 = true;
			}
		}
		else {
			count1++;
			if (count1 >= 200) {
				positionSpawnY = rand() % 100 + 1;
				if (positionSpawnY <= 20) {
					enemySprite1->SetPosition(1200, 40);
				}
				else if (positionSpawnY >= 21 && positionSpawnY <= 40) {
					enemySprite1->SetPosition(1200, 170);
				}
				else if (positionSpawnY >= 41 && positionSpawnY <= 60) {
					enemySprite1->SetPosition(1200, 310);
				}
				else if (positionSpawnY >= 61 && positionSpawnY <= 80) {
					enemySprite1->SetPosition(1200, 450);
				}
				else if (positionSpawnY >= 81 && positionSpawnY <= 100) {
					enemySprite1->SetPosition(1200, 580);
				}
				velocity += 0.05f;
				score += 100;
				Mentok1 = false;
				count1 = 0;
			}
		}

		if (Mentok2 == false) {
			x2 -= velocity * GetGameTime();
			enemySprite2->SetPosition(x2, y2);
			if (x2 <= -100) {
				Mentok2 = true;
			}
		}
		else {
			count2++;
			if (count2 >= 300) {
				positionSpawnY = rand() % 100 + 1;
				if (positionSpawnY <= 20) {
					enemySprite2->SetPosition(1200, 40);
				}
				else if (positionSpawnY >= 21 && positionSpawnY <= 40) {
					enemySprite2->SetPosition(1200, 170);
				}
				else if (positionSpawnY >= 41 && positionSpawnY <= 60) {
					enemySprite2->SetPosition(1200, 310);
				}
				else if (positionSpawnY >= 61 && positionSpawnY <= 80) {
					enemySprite2->SetPosition(1200, 450);
				}
				else if (positionSpawnY >= 81 && positionSpawnY <= 100) {
					enemySprite2->SetPosition(1200, 580);
				}
				velocity += 0.05f;
				score += 100;
				Mentok2 = false;
				count2 = 0;
			}
		}
	}

	if (inputManager->IsKeyPressed("Walk Up") && up == false) {
		up = true;
		yspeed = 1.15f;
		if (i < 4) {
			i++;
			targetPos = pos[i];
		}
	}
	
	if (inputManager->IsKeyPressed("Walk Down") && !down) {
		down = true;
		yspeed = -1.15f;
		if (i > 0) {
			i--;
			targetPos = pos[i];
		}
	}

	if (yPlayer >= targetPos && up) {
		yspeed = 0;
		up = false;
		yPlayer = targetPos;
	}
	if (yPlayer <= targetPos && down) {
		yspeed = 0;
		down = false;
		yPlayer = targetPos;
	}
	yPlayer += yspeed * GetGameTime();
	playerSprite->SetPosition(oldPlayerPos.x, yPlayer);


	if (playerSprite->GetBoundingBox()->CollideWith(enemySprite->GetBoundingBox())
		|| playerSprite->GetBoundingBox()->CollideWith(enemySprite1->GetBoundingBox())
		|| playerSprite->GetBoundingBox()->CollideWith(enemySprite2->GetBoundingBox())) {
		gameOn = false;
		gameOver = true;
		enemySprite->SetPosition(1200, 40);
		enemySprite1->SetPosition(1200, 310);
		enemySprite2->SetPosition(1200, 580);
	}

	if (inputManager->IsKeyReleased("Enter")) {
		if (buttonRestartSelected == true && buttonQuitSelected == false) {
			score = 0;
			overScore = 0;
			velocity = 0.1f;
			gameOver = false;
			gameOn = true;
			menu = false;
		}
		else {
			score = 0;
			overScore = 0;
			velocity = 0.1f;
			gameOver = false;
			gameOn = false;
			menu = true;
		}
	}
}

void Engine::Belajar01::Render()
{
	if (gameOn == true) {
		backgroundSprite->Draw();
		enemySprite->Draw();
		enemySprite1->Draw();
		enemySprite2->Draw();
		playerSprite->Draw();
		gameScore->Draw();
		gameInfoSprite->Draw();
	}
	else if (gameOver == true) {
		backgroundSprite->Draw();
		endGuiSprite->Draw();
		endScore->Draw();
		restartButtonSprite->Draw();
		quitButtonSprite->Draw();
		overInfoSprite->Draw();
	}
	else if (menu == true) {
		backgroundSprite->Draw();
		guiSprite->Draw();
		titleSprite->Draw();
		playButtonSprite->Draw();
		exitButtonSprite->Draw();
		menuInfoSprite->Draw();
	}
}

int main(int argc, char** argv) {
	Setting* setting = new Setting();
	setting->windowTitle = "Project Example";
	setting->screenWidth = 1200;
	setting->screenHeight = 680;
	setting->targetFrameRate = 60;
	setting->windowFlag = WindowFlag::WINDOWED;
	Game* game = new Belajar01(setting);
	game->Run();
	delete setting;
	delete game;

	return 0;
}