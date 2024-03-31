#include "raylib.h"
#include "raygui.h"
#include "character.h"
#include "background.h"
#include "string"
#include "iostream"
#include "rain.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_STATIC
#define SNOWS 200

void debug() {


}

typedef struct {
	float x,    //The stars coordinates
		y,    //on the screen
		z;    //The stars depth or distance from camera
}Star;

float CurrentTime = {};
int score = {};

float randf() {
	return (rand() % 1000) / 1000.0f;
}

int main() {
	const int width = 1200;
	const int height = 600;

	InitWindow(width, height, "First Windows");
	InitAudioDevice();

	Sound coin = LoadSound("resource/coin.wav");

	SetTargetFPS(60);

	Texture2D layer01 = LoadTexture("resource/layer01.png");
	Character player;
	Background bg;
	rain rain;

	Camera2D camera = { 0 };
	camera.target = { 0.0f, 0.0f };
	camera.offset = { width / 300.f , height / 230 };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	Rectangle Item = { 600,515,20,30 };
	Rectangle Arrow = { 800,520 ,60, 15 };

	Star stars[SNOWS] = { 0 };
	for (int i = 0; i < SNOWS; i++) {
		stars[i].x = GetRandomValue(0, 800);
		stars[i].y = GetRandomValue(0, 1200);
		stars[i].z = randf();
	}


	while (!WindowShouldClose()) {
		ClearBackground(BLACK);
		Rectangle Player_boxs = { player.position_x,player.position.y ,64,64 };
		float deltatime = GetFrameTime();
		CurrentTime += deltatime;


		BeginMode2D(camera);
		player.Tick();
		BeginDrawing();

		if (CurrentTime >= 0.1f) {
			CurrentTime = 0.f;
		}

		if (Arrow.x < -30 || CheckCollisionRecs({ Player_boxs }, { Arrow })) {
			Arrow.x = 1200;

		}
		else {
			Arrow.x -= 6.f;
		}

		for (int i = 0; i < SNOWS; i++) {

			stars[i].y += GetRandomValue(0, 2);
			stars[i].x -= GetRandomValue(0, 1);
			if (stars[i].y >= 1200 || stars[i].x >= 1200) {
				stars[i].x = GetRandomValue(400, 1200);
				stars[i].y = 0;
			}
		}


		for (int i = 0; i < SNOWS; i++) {
			float x = stars[i].x;
			float y = stars[i].y;
			for (int j = 0; j < 2; j++) {
				DrawPixel(x, y + j, WHITE);
				DrawPixel(x + 1, y + j, WHITE);
				DrawPixel(x, y + j, WHITE);
				DrawPixel(x - 1, y + j, WHITE);
			}
		}




		DrawRectangleRec(Item, RED);
		DrawRectangleRec(Arrow, GREEN);

		if (CheckCollisionRecs({ Player_boxs }, { Item })) {
			PlaySound(coin);
			std::cout << "Touched" << std::endl;
			std::cout << IsSoundPlaying(coin) << std::endl;
			Item.x = GetRandomValue(20, 600);
			score += 1;
			WaitTime(0.1);
		}
		if (CheckCollisionRecs({ Player_boxs }, { Arrow })) {
			std::cout << "Touched : Arrow" << std::endl;
		}

		std::string position_x_value = std::to_string(player.position_x);
		const char* X_value = position_x_value.c_str();
		DrawText(X_value, 30, 50, 20, WHITE);

		std::string Time_str = "CurrentTime" + std::to_string(CurrentTime);
		const char* RunningTime = Time_str.c_str();
		DrawText(RunningTime, 30, 70, 20, WHITE);

		std::string Score_value = "Score : " + std::to_string(score);
		const char* Scores = Score_value.c_str();
		DrawText(Scores, 30, 90, 20, WHITE);
		EndDrawing();
	}



	UnloadSound(coin);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}