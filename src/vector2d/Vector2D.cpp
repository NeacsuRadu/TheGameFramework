#include "../vector2d/Vector2d.h"

Vector2D::Vector2D(float x, float y) :
	x_(x),
	y_(y)
{

}

float Vector2D::getX() const
{
	return x_;
}

float Vector2D::getY() const
{
	return y_;
}

void Vector2D::setX(float x)
{
	x_ = x;
}

void Vector2D::setY(float y)
{
	y_ = y;
}

float Vector2D::length()
{
	return sqrt(x_*x_ + y_*y_);
}