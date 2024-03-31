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



void Character::Animation(int frame, State currentstate) {
	if (currentstate == idle) {
		sprite.x = SPRITE * (frame % 4);
		sprite.y = 0;
		DrawTextureRec(player_idle_t, sprite, { position.x + movement_x,position.y + movement_y }, WHITE);
	}
	else if (currentstate == run) {
		sprite.x = SPRITE * (frame % 5);
		sprite.y = 0;
		DrawTextureRec(player_run_t, sprite, { position.x + movement_x,position.y + movement_y }, WHITE);
	}
	else if (currentstate == left) {
		sprite.x = SPRITE * (frame % 5);
		sprite.y = 0;
		DrawTextureRec(player_run_left_t, sprite, { position.x + movement_x,position.y + movement_y }, WHITE);
	}
	else if (currentstate == jump) {
		position.y -= jump_velocity;
		jump_velocity -= gravity;

		if (position.y >= 510.f) {
			isGrounded = true;
			isJumping = false;
		}

		DrawTextureRec(player_idle_t, sprite, { position.x + movement_x,position.y + movement_y }, WHITE);
	}

}

void Character::Tick() {
	float deltatime = GetFrameTime();
	State currentstate = idle;
	Runtime += deltatime;
	position_x = position.x + movement_x;
	position_y = position.y + movement_y;

	if (Runtime >= 0.1f) {
		Runtime = 0;
		frame++;
	}


	if (IsKeyDown(KEY_LEFT)) {
		currentstate = left;
		movement_x -= 3.0f;
	}
	else if (IsKeyDown(KEY_RIGHT)) {
		currentstate = run;
		movement_x += 3.0f;
	}
	if (IsKeyPressed(KEY_SPACE)) {
		isJumping = true;
		jump_velocity = 10.f;
	}
	if (isJumping) {
		currentstate = jump;
	}


	Animation(frame, currentstate);


}
