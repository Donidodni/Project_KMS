#include "character.h"
#include "raylib.h"
#include "iostream"


Character::Character() {
	player_pic = LoadTexture("resource/hoody_sheet.png");
	Character::sprite = { 0.f, 0.f ,256 / 8.f,288 / 9.f };
	Character::position = { 400.f, 300.f };
	Vector2 position{ 200.f, 100.f };

}
Character::~Character() {

}

void Character::Tick() {
    float deltatime = GetFrameTime();
    time += deltatime;
    if (time >= 0.1f) {
        time = 0;
        sprite.x = 32 * (frame % 2);
        sprite.y = 0;

        if (IsKeyDown(KEY_LEFT)) {
            sprite.x = 32 * (frame % 5);
            sprite.y = 32 * 3;
            position.x -= 3;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            sprite.x = 32 * (frame % 5);
            sprite.y = 32 * 3;
            position.x += 4.6;
        }
        if (IsKeyDown(KEY_UP)) {
            sprite.x = 32 * (frame % 5);
            sprite.y = 32 * 3;
            position.y -= 3;
        }
        if (IsKeyDown(KEY_DOWN)) {
            sprite.x = 32 * (frame % 5);
            sprite.y = 32 * 3;
            position.y += 3;
        }
        frame++;
    }
    // 스프라이트 그리기
    DrawTextureRec(player_pic, sprite, position, WHITE);
}


