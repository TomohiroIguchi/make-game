#pragma once

struct Vector2 {
	float x;
	float y;
};

struct enemy {
	Vector2 pos;
	Vector2 velocity;
	bool isOnGround;
	bool isAlive;
	bool isBulletShoot;
};


Player player{
	{20.0f, 0.0f},
	{0.0f, 0.0f},
	false
};


float enemyGravity = 0.8f;
float enemySpeed = 6.0f;
float enemyJumpPower = -15.0f;