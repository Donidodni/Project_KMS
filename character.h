#pragma once
#include "raylib.h"


class Character
{
protected:
	enum state
	{
		idle, right, left
	};
	int movement_x = 0;
	int movement_y = 0;

public:

	Character();
	~Character();

	Image player_picture;
	Image player_picture_left;
	Texture2D player_pic_idle;
	Texture2D player_pic_left;
	Texture2D player_pic_right;

	Rectangle sprite_normal;
	Rectangle sprite_flip;
	state characterState;

	Vector2 position;
	float time= {};
	int frame = 0;

	void Draw(int x, int y);
	void Tick( );
	void Animation(state, int frame);
};
