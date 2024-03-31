#include "raylib.h"
#include "raygui.h"
#include "character.h"
#include "background.h"
#include "string"
#include "iostream"
#include "rain.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_STATIC

void debug() {
	

}
int currentProcess = NULL;


typedef struct {
	float x,    //The stars coordinates
		y,    //on the screen
		z;    //The stars depth or distance from camera
}Star;


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
	camera.offset = { width/300.f , height / 230 };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	Rectangle Item = {600,515,20,30};

	Star stars[50] = { 0 };
	for (int i = 0; i < 50; i++) {
		stars[i].x = GetRandomValue(0, 800);
		stars[i].y = GetRandomValue(0, 1200);
		stars[i].z = randf();
	}


	while (!WindowShouldClose()) {
		ClearBackground(BLACK);
		Rectangle Player_boxs = { player.position_x,player.position.y ,64,64 };

		BeginMode2D(camera);
		DrawRectangleRec(Player_boxs, RED);
		player.Tick();
		BeginDrawing();

		for (int i = 0; i < 50; i++) {
			stars[i].y += 12;

			if (stars[i].y >= 1200) {   
				stars[i].x = GetRandomValue(0, 1200);
				stars[i].y = 0;
			}
		}

		for (int i = 0; i < 50; i++) {
			float x = stars[i].x;
			float y = stars[i].y;
			for (int j = 0; j < 6; j++) {
				DrawPixel(x, y + j, BLUE);
			}

		}
		DrawRectangleRec(Item,RED);

		if (CheckCollisionRecs({Player_boxs}, {Item})) {
			PlaySound(coin);
			std::cout << "Touched" << std::endl;
			std::cout << IsSoundPlaying(coin) << std::endl;

			Item.y = -100;
		}

		std::string position_x_value = std::to_string(player.position_x);
		const char* X_value = position_x_value.c_str();
		std::string position_y_value = std::to_string(Player_boxs.y);
		const char* Y_value = position_y_value.c_str();

		DrawText(X_value, 30, 50, 20, WHITE);
		EndDrawing();
	}

	UnloadSound(coin);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}