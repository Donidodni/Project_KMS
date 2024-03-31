#include "character.h"


#define SPRITE 64

Character::Character() {
	player_idle = LoadImage("resource/hoody_sheet_idle.png");
	player_idle_t = LoadTextureFromImage(player_idle);

	player_run = LoadImage("resource/hoody_sheet_run.png");
	player_run_t = LoadTextureFromImage(player_run);

	player_run_left = ImageCopy(player_run);
	ImageFlipHorizontal(&player_run_left);
	player_run_left_t = LoadTextureFromImage(player_run_left);

	Character::sprite = { 10.f,10.f,64.f,64.f };
	Character::position = { 400.f, 510.f };
	Vector2 position{ 200.f, 100.f };
	Rectangle chracter_box = { position.x + movement_x, position.y + movement_y, 64, 64 };
}
Character::~Character() {
	UnloadTexture(player_idle_t);
	UnloadTexture(player_run_t);
	UnloadTexture(player_run_left_t);
}


void Character::Animation_idle(int frame) {
	sprite.x = SPRITE * (frame % 4);
	sprite.y = 0;
	DrawTextureRec(player_idle_t, sprite, { position.x + movement_x,position.y + movement_y }, WHITE);
}
void Character::Animation_run(int frame) {
	sprite.x = SPRITE * (frame % 5);
	sprite.y = 0;
	DrawTextureRec(player_run_t, sprite, { position.x + movement_x,position.y + movement_y }, WHITE);
}
void Character::Animation_run_left(int frame) {
	sprite.x = SPRITE * (frame % 5);
	sprite.y = 0;
	DrawTextureRec(player_run_left_t, sprite, { position.x + movement_x,position.y + movement_y }, WHITE);
}
void Character::Animation_jump(int frame) {

	if (isJumping) {
		position.y -= jump_velocity; 
		jump_velocity -= gravity; 

		if (position.y >= 500.f) { 
			isGrounded = true; 
			isJumping = false; 
			jump_velocity = 30.0f; 
		}
	}
	DrawTextureRec(player_idle_t, sprite, { position.x + movement_x,position.y + movement_y }, WHITE);
}

void Character::Tick() {
	float deltatime = GetFrameTime();
	Runtime += deltatime;
	position_x = position.x + movement_x;
	position_y = position.y + movement_y;


	if (Runtime >= 0.1f) {
		Runtime = 0;
		frame++;
	}

	if (IsKeyDown(KEY_LEFT)) {
		movement_x -= 3.0f;
		Animation_run_left(frame);
	}
	else if (IsKeyDown(KEY_RIGHT)) {
		movement_x += 3.0f;
		Animation_run(frame);
	}
	else if (IsKeyPressed(KEY_SPACE)) {
		isJumping = true;
		isGrounded = false;
		jump_velocity = 30.f;
		Animation_jump(frame);
	}
	else {
		Animation_idle(frame);
	}

}
