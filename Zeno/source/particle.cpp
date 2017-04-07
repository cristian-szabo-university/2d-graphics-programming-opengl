#include "zeno\particle.h"

namespace Zeno
{
	Particle::Particle()
	{
		clear();
	}

	Particle::~Particle()
	{

	}

	void Particle::integrate(float nDuration)
	{
		// Update position
		cPosition += cVelocity * nDuration;

		// Update acceleration from force
		Vector2 cSaveAcceleration;
		
		cSaveAcceleration = cAcceleration;

		cSaveAcceleration += cForceAccum * (1.0f / nMass);

		// Update velocity from acceleration
		cVelocity += cSaveAcceleration * nDuration;

		// Apply drag force
		cVelocity *= pow(nAmortization, nDuration);

		// Clear force
		cForceAccum.clear();
	}

	void Particle::clear()
	{
		nMass = 1.0f;

		nAmortization = 1.0f;

		cPosition.clear();

		cVelocity.clear();

		cAcceleration.clear();

		cForceAccum.clear();
	}

	void Particle::setMass(float nValue)
	{
		nMass = nValue;
	}

	void Particle::setAmortization(float nValue)
	{
		nAmortization = nValue;
	}

	void Particle::setPosition(Vector2 cVector)
	{
		cPosition = cVector;
	}

	void Particle::setVelocity(Vector2 cVector)
	{
		cVelocity = cVector;
	}

	void Particle::setAcceleration(Vector2 cVector)
	{
		cAcceleration = cVector;
	}

	float Particle::getMass()
	{
		return nMass;
	}

	float Particle::getAmortization()
	{
		return nAmortization;
	}

	Vector2* Particle::getPosition()
	{
		return &cPosition;
	}

	Vector2* Particle::getVelocity()
	{
		return &cVelocity;
	}

	Vector2* Particle::getAcceleration()
	{
		return &cAcceleration;
	}

	void Particle::addForce(Vector2 cVector)
	{
		cForceAccum += cVector;
	}
}