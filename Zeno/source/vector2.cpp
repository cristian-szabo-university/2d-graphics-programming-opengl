#include "zeno\vector2.h"

namespace Zeno
{
	Vector2::Vector2()
	{
		nX = 0.0f;
		nY = 0.0f;
	}

	Vector2::Vector2(float nX, float nY)
	{
		this->nX = nX;
		this->nY = nY;
	}

	Vector2::~Vector2()
	{		
		
	}

	void Vector2::inverse()
	{
		nX *= -1.0f;
		nY *= -1.0f;
	}

	void Vector2::clear()
	{
		nX = 0.0f;
		nY = 0.0f;
	}

	void Vector2::operator*=(float nValue)
	{
		nX *= nValue;
		nY *= nValue;
	}

	Vector2 Vector2::operator*(float nValue)
	{
		return Vector2(nX * nValue, nY * nValue);
	}

	void Vector2::operator+=(Vector2 cVector)
	{
		nX += cVector.getX();
		nY += cVector.getY();
	}

	Vector2 Vector2::operator+(Vector2 cVector)
	{
		return Vector2(nX + cVector.getX(), nY + cVector.getY());
	}

	void Vector2::operator-=(Vector2 cVector)
	{
		nX -= cVector.getX();
		nY -= cVector.getY();
	}

	Vector2 Vector2::operator-(Vector2 cVector)
	{
		return Vector2(nX - cVector.getX(), nY - cVector.getY());
	}

	bool Vector2::operator==(Vector2 cVector)
	{
		if (nX == cVector.getX() && nY == cVector.getY())
		{
			return true;
		}

		return false;
	}

    bool Vector2::operator!=(Vector2 cVector)
	{
		if (*this == cVector)
		{
			return true;
		}

		return false;
	}

	void Vector2::setX(float nValue)
	{
		nX = nValue;
	}

	void Vector2::setY(float nValue)
	{
		nY = nValue;
	}

	float Vector2::getX()
	{
		return nX;
	}

	float Vector2::getY()
	{
		return nY;
	}
}