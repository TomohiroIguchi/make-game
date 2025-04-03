#pragma once

struct Vector2 {
	float x;
	float y;
};

struct Player {
	Vector2 pos;
	Vector2 velocity;
	Vector2 size;
	bool isOnGround;
	float radius;
};

struct  PBullet
{
	Vector2 pos;
	Vector2 size;
	float speedX;
	float radius;
	int isAlive;
};



Player player{
	{32.0f, 500.0f},
	{0.0f, 0.0f},
	{64.0f,64.0f},
	false,
    {32.0f},
};
float playerRadiusX = 16.0f;
float playerGravity = 0.8f;
float playerSpeed = 6.0f;
float playerJumpPower = -15.0f;
int playerLife = 3;
int playerIsAlive = true;
int playerIsAliveCount = 60;
int playerBulletRespawnTimer = 0;