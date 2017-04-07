/**
 *	Name		:	Vector2
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Vector2 to manipulate any mathematical calculus 
 *					applied to a vector.
 *	Reference	:	Game Physics Engine Development by Ian Millington
 */

#pragma once

namespace Zeno
{
	/**
	 * @class	Vector2
	 *
	 * @brief	The class holds the x and y coordinates of a point in 2D space.
	 */

	class Vector2
	{
	public:

		/**
		 * @fn	Vector2::Vector2();
		 *
		 * @brief	The default constructor sets the x and y coordinates of
		 * 			the vector to the middle of the carthesian axis.
		 */

		Vector2();

		/**
		 * @fn	Vector2::Vector2(float nX, float nY);
		 *
		 * @brief	The explicit constructor sets the x and y coordinates of
		 * 			vector to the one given by user.
		 *
		 * @param	nX	The x coordinate.
		 * @param	nY	The y coordinate.
		 */

		Vector2(float nX, float nY);

		/**
		 * @fn	Vector2::~Vector2();
		 *
		 * @brief	Destructor.
		 */

		~Vector2();

		/**
		 * @fn	void Vector2::inverse();
		 *
		 * @brief	Inverses the vector coordinates. From 2,4 to -2,-4
		 */

		void inverse();

		/**
		 * @fn	void Vector2::clear();
		 *
		 * @brief	Sets the vector coordinates to 0,0.
		 */

		void clear();

		/**
		 * @fn	void Vector2::operator+=(Vector2 cVector);
		 *
		 * @brief	Adds another vector coordinates to this vector.
		 *
		 * @param	cVector	The vector to add.
		 */

		void operator+=(Vector2 cVector);

		/**
		 * @fn	Vector2 Vector2::operator+(Vector2 cVector);
		 *
		 * @brief	Returns a vector which is the result of additioning between
		 * 			this vector and another vector.
		 *
		 * @param	cVector	The vector to add.
		 *
		 * @return	The result of the operation.
		 */

		Vector2 operator+(Vector2 cVector);

		/**
		 * @fn	void Vector2::operator-=(Vector2 cVector);
		 *
		 * @brief	Substracts another vector coordinates to this vector.
		 *
		 * @param	cVector	The vector.
		 */

		void operator-=(Vector2 cVector);

		/**
		 * @fn	Vector2 Vector2::operator-(Vector2 cVector);
		 *
		 * @brief	Returns a vector which is the result of substracting between
		 * 			this vector and another vector.
		 *
		 * @param	cVector	The vector.
		 *
		 * @return	The result of the operation.
		 */

		Vector2 operator-(Vector2 cVector);

		/**
		 * @fn	void Vector2::operator*=(float nValue);
		 *
		 * @brief	Multiplies this vector with a scalar number.
		 *
		 * @param	nValue	The value.
		 */

		void operator*=(float nValue);

		/**
		 * @fn	Vector2 Vector2::operator*(float nValue);
		 *
		 * @brief	Returns a vector which is the result of multipling between
		 * 			this vector and a scalar number.
		 *
		 * @param	nValue	The value.
		 *
		 * @return	The result of the operation.
		 */

		Vector2 operator*(float nValue);

		/**
		 * @fn	bool Vector2::operator==(Vector2 cVector);
		 *
		 * @brief	Checks if this vector is equal with the one passed through 
		 * 			parametre.
		 *
		 * @param	cVector	The vector.
		 *
		 * @return	true if the vectors are equivalent.
		 */

		bool operator==(Vector2 cVector);

        /**
         * @fn	bool Vector2::operator!=(Vector2 cVector);
         *
         * @brief	Checks if this vector is not equal with the one passed through 
		 * 			parametre.
         *
         * @param	cVector	The vector.
         *
         * @return	true if the vectors are not equivalent.
         */

        bool operator!=(Vector2 cVector);

		/**
		 * @fn	void Vector2::setX(float nY);
		 *
		 * @brief	Sets the x coordinate.
		 *
		 * @param	nY	The x coordinate.
		 */

		void setX(float nX);

		/**
		 * @fn	void Vector2::setY(float nY);
		 *
		 * @brief	Sets the y coordinate.
		 *
		 * @param	nY	The y coordinate.
		 */

		void setY(float nY);

		/**
		 * @fn	float Vector2::getX();
		 *
		 * @brief	Gets the x coordinate.
		 *
		 * @return	The x coordinate.
		 */

		float getX();

		/**
		 * @fn	float Vector2::getY();
		 *
		 * @brief	Gets the y coordinate.
		 *
		 * @return	The y coordinate.
		 */

		float getY();

	protected:


	private:

		/**
		 * @brief	Holds the x coordinate.
		 */

		float nX;
		
		/**
		 * @brief	Holds the y coordinate.
		 */

		float nY;

	};
}