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

Vector2D Vector2D::operator+(Vector2D v)
{
	return Vector2D(x_ + v.x_, y_ + v.y_);
}

Vector2D Vector2D::operator+=(Vector2D v)
{
	x_ += v.x_;
	y_ += v.y_;

	return *this;
}

Vector2D operator*(float scalar, Vector2D vect)
{
	return Vector2D(scalar*vect.x_, scalar*vect.y_);
}

Vector2D Vector2D::operator*=(float scalar)
{
	x_ *= scalar;
	y_ *= scalar;

	return *this;
}

Vector2D Vector2D::operator-(Vector2D v)
{
	return Vector2D(x_ - v.x_, y_ - v.y_ );
}

Vector2D Vector2D::operator-=(Vector2D v)
{
	x_ -= v.x_;
	y_ -= v.y_;

	return *this;
}

Vector2D Vector2D::operator/(float scalar)
{
	return Vector2D(x_/scalar, y_/scalar);
}

Vector2D Vector2D::operator/=(float scalar)
{
	x_ /= scalar;
	y_ /= scalar;

	return *this;
}

void Vector2D::normalize()
{
	float len = length();
	if (len > 0)
	{
		(*this) += 1 / len;
	}
}