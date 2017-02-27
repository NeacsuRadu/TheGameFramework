#pragma once

#ifndef BLEAH_VECTOR2D_VECTOR2D_H_
#define BLEAH_VECTOR2D_VECTOR2D_H_

class Vector2D
{
public:

	Vector2D(float x = 0, float y = 0);

	float getX() const;
	float getY() const;

	void setX(float x);
	void setY(float y);

private:

	float x_;
	float y_;

};

#endif // !BLEAH_VECTOR2D_VECTOR2D_H_

