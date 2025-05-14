#include "Particle.h"

Particle::Particle(float r) {
	position = { 1.0f, 1.0f };
	velocity = { (float)GetRandomValue(25, 50), 0.0f };
	acceleration = { 0.0f, 50.0f };
	radius = r;
	mass = r*.1f;

}

Particle::~Particle() {
	acceleration = { 0 };
	velocity = { 0 };
	position = { 0 };
	radius = { 0 };
}