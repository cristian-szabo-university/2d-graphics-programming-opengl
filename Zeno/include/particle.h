/**
 *	Name		:	Particle
 *	Author		:	B00233705
 *	Version		:	1.0
 *	Copyright	:	(c) 2013 http://videogamelab.co.uk/monkey-invasion
 *	Description	:	This file presents the variables and functions declarations 
 *					of class Particle to simulate the motion of an object.
 *	Reference	:	Game Physics Engine Development by Ian Millington
 */

#pragma once

#include <math.h>

#include <zeno\vector2.h>

namespace Zeno
{
	/**
	 * @class	Particle
	 *
	 * @brief	The class stores the mass, amortization, position, velocity 
	 * 			and acceleration of an object.
	 */

	class Particle
	{
	public:

		/**
		 * @fn	Particle::Particle();
		 *
		 * @brief	The default constructor calls the clear function to set
		 * 			the initial value for variables.
		 */

		Particle();

		/**
		 * @fn	Particle::~Particle();
		 *
		 * @brief	Destructor.
		 */

		~Particle();

		/**
		 * @fn	void Particle::integrate(float nDuration);
		 *
		 * @brief	When comes to physics in games, integration is used to 
		 * 			update the position and velocity of each object.
		 *
		 * @param	nDuration	The duration.
		 */

		void integrate(float nDuration);

		/**
		 * @fn	void Particle::clear();
		 *
		 * @brief	Clears this particle to it's initial state.
		 */

		void clear();

		/**
		 * @fn	void Particle::setMass(float nValue);
		 *
		 * @brief	Sets the mass.
		 *
		 * @param	nValue	The mass value.
		 */

		void setMass(float nValue);

		/**
		 * @fn	void Particle::setAmortization(float nValue);
		 *
		 * @brief	Sets the amortization.
		 *
		 * @param	nValue	The amortization value.
		 */

		void setAmortization(float nValue);

		/**
		 * @fn	void Particle::setPosition(Vector2 cVector);
		 *
		 * @brief	Sets the vector position.
		 *
		 * @param	cVector	The vector position.
		 */

		void setPosition(Vector2 cVector);

		/**
		 * @fn	void Particle::setVelocity(Vector2 cVector);
		 *
		 * @brief	Sets the vector velocity.
		 *
		 * @param	cVector	The vector velocity.
		 */

		void setVelocity(Vector2 cVector);

		/**
		 * @fn	void Particle::setAcceleration(Vector2 cVector);
		 *
		 * @brief	Sets the vector acceleration.
		 *
		 * @param	cVector	The vector acceleration.
		 */

		void setAcceleration(Vector2 cVector);

		/**
		 * @fn	void Particle::addForce(Vector2 cVector);
		 *
		 * @brief	Adds a vector force.
		 *
		 * @param	cVector	The vector force.
		 */

		void addForce(Vector2 cVector);

		/**
		 * @fn	float Particle::getMass();
		 *
		 * @brief	Gets the mass.
		 *
		 * @return	The mass value.
		 */

		float getMass();

		/**
		 * @fn	float Particle::getAmortization();
		 *
		 * @brief	Gets the amortization.
		 *
		 * @return	The amortization value.
		 */

		float getAmortization();

		/**
		 * @fn	Vector2* Particle::getPosition();
		 *
		 * @brief	Gets the position.
		 *
		 * @return	The vector position.
		 */

		Vector2* getPosition();

		/**
		 * @fn	Vector2* Particle::getVelocity();
		 *
		 * @brief	Gets the velocity.
		 *
		 * @return	The vector velocity.
		 */

		Vector2* getVelocity();

		/**
		 * @fn	Vector2* Particle::getAcceleration();
		 *
		 * @brief	Gets the acceleration.
		 *
		 * @return	The vector acceleration.
		 */

		Vector2* getAcceleration();

	protected:


	private:

		/**
		 * @brief	Holds the mass of object.
		 */

		float nMass;

		/**
		 * @brief	Holds the amount of force applied to object.
		 */

		float nAmortization;

		/**
		 * @brief	Holds the vector position of the particle.
		 */

		Vector2 cPosition;

		/**
		 * @brief	Holds the vector velocity of the particle.
		 */

		Vector2 cVelocity;

		/**
		 * @brief	Holds the vector acceleration of the particle.
		 */

		Vector2 cAcceleration;

		/**
		 * @brief	Holds the accumulated vector force to be applied at the next
         *			integration. It is cleared at every step.
		 */

		Vector2 cForceAccum;

	};
}