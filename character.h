#pragma once
#include "raylib.h"
#include "iostream"


class Character
{
protected:

	int movement_x = 0;
	int movement_y = 0;
	float gravity = 0.5f;
	float jump_velocity;
	bool isGrounded = true;
	bool isJumping = false;

public:

	Character();
	~Character();
	float position_x = 0.f;
	float position_y = 0.f;

	Image player_idle;
	Image player_run;
	Image player_run_left;

	Texture2D player_idle_t;
	Texture2D player_run_t;
	Texture2D player_run_left_t;

	Rectangle sprite;
	Rectangle chracter_box;

	Vector2 position;
	float Runtime = {};
	int frame = 0;

public:
	void Tick( );
	void Animation_idle( int frame);
	void Animation_run(int frame);
	void Animation_run_left(int frame);
	void Animation_jump(int frame);
};
