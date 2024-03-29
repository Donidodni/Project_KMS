#pragma once

class Background {
protected:
public:
	Background();
	~Background();

	Texture2D layer01;
	Texture2D layer02;
	Texture2D layer03;
	Texture2D layer04;
	Texture2D layer05;

	void draw();
};