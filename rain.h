#pragma once
#include "raylib.h"
#include "stdlib.h"


class rain {

protected:
	typedef struct Rains
	{
		float y;
		float x;
	}Rain;

public: 


	rain();
	~rain();
	void draw();

};