#pragma once
#include "raylib.h"


class Character
{
public:

	Character();
	~Character();

	Texture2D player_pic;
	Rectangle sprite;
	Vector2 position;
	float time= {};
	int frame = 0;

	void Draw(int x, int y);
	void Tick( );
};
