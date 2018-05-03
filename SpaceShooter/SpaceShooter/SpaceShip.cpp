#include "SpaceShip.h"

void SpaceShip::Destroy() {
	GameObject::Destroy();
}
void SpaceShip::Init(ALLEGRO_BITMAP *image) {
	GameObject::Init(20, 200, 6, 6, 0, 0, 10, 12);

	setID(PLAYER);
	SetAlive(true);
	lives = 3;
	score = 0;

	maxFrame = 3;
	currFrame = 0;
	frameWidth = 46;
	frameHeight = 41;
	animationColumns = 3;
	animationDirection = 1;
	animationRow = 1;

	if (image != NULL)
		SpaceShip::Image = Image;
}

void SpaceShip::Update() {
	GameObject::Update();

	if (x < 0)
		x = 0;
	else if (x > Height)
		x = Width;
	if (y < 0)
		y = 0;
	else if (y > Height)
		y = Height;
}