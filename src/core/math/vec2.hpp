#include <iostream>
#include <cmath>


struct Vec2 {

	float x = 0.0f;
	float y = 0.0f;

	Vec2() {
		x = 0.0f;
		y = 0.0f;
	}

	Vec2 operator+(Vec2 otro) {
		return Vec2(x + otro.x, y + otro.y);
	}
	Vec2 operator-(Vec2 otro) {
		return Vec2(x - otro.x, y - otro.y);
	}
	Vec2 operator*(Vec2 otro) {
		return Vec2(x * otro.x, y * otro.y)
	}
	
	float magnitud() {
		return std::sqrt(x * x + y * y);
	}

	Vec2 normalizar() {
		float mag = magnitud();
		if (mag > 0.0f) {
			return Vec2(x / mag, y / mag);
		}
		return Vec2(0.0f, 0.0f);
	}

};