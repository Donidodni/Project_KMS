#include "character.h"
#include "raylib.h"
#include "iostream"

#define SPRITE 64

Character::Character() {
    player_picture = LoadImage("resource/hoody_sheet2.png");

    player_pic_idle = LoadTextureFromImage(player_picture);
    player_picture_left = ImageCopy(player_picture);
    ImageFlipHorizontal(&player_picture_left);
    player_pic_left = LoadTextureFromImage(player_picture_left);

	Character::sprite_normal = { 10.f, 10.f ,516 / 8.f,576 / 9.f };
    Character::sprite_flip = { 10.f, 10.f ,516 / 8.f,576 / 9.f };
	Character::position = { 400.f, 510.f };
	Vector2 position{ 200.f, 100.f };
}
Character::~Character() {
    UnloadTexture(player_pic_idle);
    UnloadTexture(player_pic_left);
}


void Character::Animation(state currentState, int frame) {

    switch(currentState){
    case idle:
        sprite_normal.x = SPRITE * (frame % 2);
        sprite_normal.y = 0;
        DrawTextureRec(player_pic_idle, sprite_normal, { position.x + movement_x,position.y + movement_y }, WHITE);
        break;
    case right:
        sprite_normal.x = SPRITE * (frame % 5);
        sprite_normal.y = SPRITE * 3;
        DrawTextureRec(player_pic_left, sprite_normal, { position.x + movement_x,position.y + movement_y }, WHITE);
        break;
    case left:
        sprite_normal.x = SPRITE * (frame % 5);
        sprite_normal.y = SPRITE * 3;
        DrawTextureRec(player_pic_idle, sprite_normal, { position.x + movement_x,position.y + movement_y }, WHITE);
        break;
    }

}

void Character::Tick() {
    state currentstate = idle;
    float deltatime = GetFrameTime();
    time += deltatime;

    if (time >= 0.06f) {
        time = 0;

        if (IsKeyDown(KEY_LEFT)) {
            currentstate = left;
            movement_x -= 7;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            currentstate = right;
            movement_x += 7;
        }
        frame++;
    }
    Animation(currentstate, frame);
}


