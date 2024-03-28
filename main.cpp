#include "raylib.h"
#include "character.h"
#include "string"
#include "iostream"

int main() {
	const int width = 1200;
	const int height = 600;

	InitWindow(width, height, "First Windows");
	SetTargetFPS(60);

	Character player;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(GRAY);
		
	
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