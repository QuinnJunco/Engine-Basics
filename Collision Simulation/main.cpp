#include "raylib.h"
#include "raymath.h"
#include "Particle.h"
#include <list>
#include <iostream>

const int screen_width = 640;
const int screen_height = 480;
const int num_particles = 4;

void sort_particles(Particle* particles[]) { // NOT WORKING
	int i = 0;
	while (i < num_particles) {
		int j = i;
		while (j > 0 && particles[j - 1]->position.x > particles[j]->position.x) {
			std::swap(particles[j], particles[j - 1]);
			j--;
		}
		i++;
	}
}

void particle_collision(Particle* p1, Particle* p2) {
	Vector2 c1 = p1->position; Vector2 c2 = p2->position; // stores centers
	// this kinda works but it is wrong
	float m1 = p1->mass;
	Vector2 v1 = p1->velocity;

	float m2 = p2->mass;
	Vector2 v2 = p2->velocity;
	p1->velocity = (Vector2Scale(v1,(m1 - m2)) + Vector2Scale(Vector2Scale(v2, m2), 2));
	p2->velocity = (Vector2Scale(v2, (m2 - m1)) + Vector2Scale(Vector2Scale(v1, m1), 2));
}

bool intersect(Particle p1, Particle p2) {
	int p1_min = p1.position.x - p1.radius;
	int p1_max = p1.position.x + p1.radius;

	int p2_min = p2.position.x - p2.radius;
	int p2_max = p2.position.x + p2.radius;

	return (p2_max > p1_min && p2_max < p1_max) || (p2_min > p1_min && p2_min < p1_max);
}

int main() {

	InitWindow(screen_width, screen_height, "hello");
	SetTargetFPS(60);
	Particle p1 = Particle(30.0f);
	p1.position = { screen_width / 2, screen_height / 2 };

	Particle p2 = Particle(25.0f);
	p2.position = { screen_height / 2, screen_width / 2 };

	Particle p3 = Particle(30.0f);
	p3.position = { 50 , screen_height / 2 };

	Particle p4 = Particle(25.0f);
	p4.position = { screen_width - 100, screen_height / 2 };
	
	Particle* P[] = { &p1, &p2 , &p3, &p4};

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawCircle(p1.position.x, p1.position.y, p1.radius, BLUE);
		p1.update(GetFrameTime());

		DrawCircle(p2.position.x, p2.position.y, p2.radius, RED);
		p2.update(GetFrameTime());

		DrawCircle(p3.position.x, p3.position.y, p3.radius, PURPLE);
		p3.update(GetFrameTime());

		DrawCircle(p4.position.x, p4.position.y, p4.radius, GREEN);
		p4.update(GetFrameTime());

		sort_particles(P);

		/* SWEEP AND PRUNE */
		for (int i = 0; i < num_particles; i++) {
			Particle* a = P[i];

			for (int j = i + 1; j < num_particles; j++) {
				Particle* b = P[j];

				if (!intersect(*a, *b)) {
					break;
				}

				if (Vector2Distance(a->position, b->position) <= a->radius + b->radius) {
					particle_collision(a, b);
				}

			}
		}

		EndDrawing();
	}


}