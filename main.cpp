#include "raylib.h"
#include "character.h"
#include "background.h"
#include "string"
#include "iostream"

void debug() {


}


int main() {
	const int width = 1200;
	const int height = 600;

	InitWindow(width, height, "First Windows");
	SetTargetFPS(60);
	Texture2D layer01 = LoadTexture("resource/layer01.png");
	Character player;
	Background bg;

	Camera2D camera = { 0 };
	camera.target = { 0.0f, 0.0f };
	camera.offset = { width/300.f , height / 230 };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(GRAY);
		
		BeginMode2D(camera);
		bg.draw();
		player.Tick();
		//std::cout << player.time << std::endl;
		//std::string str_number = std::to_string(Frame);
		//const char* FPS = str_number.c_str();
		//DrawText(FPS, 100, 150, 10, WHITE);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}