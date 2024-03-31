#include "rain.h"


rain::rain() {



}

rain::~rain() {

}

void rain::draw() {
	static Rain rains[50] = {};

	for (int i = 0; i < 50; i++) {
		rains[i].x = GetRandomValue(0, 1200);
		rains[i].y = GetRandomValue(0, 800);
	}
	for (int i = 0; i < 50; i++) {
		DrawPixel(rains[i].x, rains[i].y,BLACK);
	}
	
}