#pragma once
#include "raylib.h"
#include "iostream"


class Character
{
protected:

	enum State
	{
		idle, left, run, jump
	};

	int movement_x = 0; // Indicating player movement about x
	int movement_y = 0; // Indicating player movement about y
	float gravity = 0.5f; // Need a value about gravity so gradually falling down 
	float jump_velocity; // 
	bool isGrounded = true; // 
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
	void Tick();


	void Animation(int frame, State currentstate);
};
