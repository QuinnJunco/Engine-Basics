#ifndef PARTICLE_H
#define PARTICLE_H
#include "raylib.h"
#include "raymath.h"

class Particle {
public:
	Vector2 position { 0 };
	Vector2 acceleration { 0 };
	Vector2 velocity { 0 };
	float radius { 0 };
	float mass { 0 };
	
	/**
	* Default constructor
	*/
	Particle(float r);

	~Particle();

	/**
	* Updates particle position and velocity every frame
	*/
	void update(float delta) {
		velocity = Vector2Clamp(velocity + acceleration * delta, {-100, -100}, {100, 100});
		position = position + velocity * delta;

		/* Discrete collision detection */
		if (position.x <= 5.0f || position.x >= 635.0f) {
			velocity.x = -velocity.x;
		}

		if (position.y <= 5.0f || position.y >= 475.0f) {
			velocity.y = -velocity.y;
		}
	}
};
#endif // !PARTICLE_H
