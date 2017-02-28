#pragma once

#ifndef BLEAH_VECTOR2D_VECTOR2D_H_
#define BLEAH_VECTOR2D_VECTOR2D_H_

#include <cmath>

class Vector2D
{
public:
	Vector2D(float x = 0, float y = 0);

	float getX() const;
	float getY() const;

	void setX(float x);
	void setY(float y);

	float length();
	void normalize();

	Vector2D operator+(Vector2D v);
	Vector2D operator+=(Vector2D v);
	friend Vector2D operator*(float scalar, Vector2D vect);
	Vector2D operator*=(float scalar);
	Vector2D operator-(Vector2D v);
	Vector2D operator-=(Vector2D v);
	Vector2D operator/(float scalar);
	Vector2D operator/=(float scalar);

private:
	float x_;
	float y_;
};

#endif // !BLEAH_VECTOR2D_VECTOR2D_H_

