#include "raylib.h"
#include "background.h"

Background::Background() {
	layer01 = LoadTexture("resource/layer01.png");
	layer02 = LoadTexture("resource/layer02.png");
	layer03 = LoadTexture("resource/layer03.png");
	layer04 = LoadTexture("resource/layer04.png");
	layer05 = LoadTexture("resource/layer05.png");

}
	
Background::~Background() {

}
void Background::draw() {
	float scale = 2.4f;
	//All Background size is 512 X 256
	DrawTextureEx(layer01, { 0, 0 }, 0.0f, scale, WHITE);
	DrawTextureEx(layer02, { 0, 0 }, 0.0f, scale, WHITE);
	DrawTextureEx(layer03, { 0, 0 }, 0.0f, scale, WHITE);
	DrawTextureEx(layer04, { 0, 0 }, 0.0f, scale, WHITE);
	DrawTextureEx(layer05, { 0, 0 }, 0.0f, scale, WHITE);

}