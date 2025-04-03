#include <Novice.h>
#include <Player.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include<time.h>

const char kWindowTitle[] = "時代を下る者 [beyond the time]";
#pragma region マップタイル
/*----------------
    GENDAIMAP
----------------*/
const float maptipTotalNumber = 17.0f;
int gendaiMap[12][40] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 12,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 0, 0, 12, 12, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 13, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 0, 0, 13, 1, 1, 1, 1, 11, 0, 0, 0, 0, 0, 0, 0, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10,
	10, 5, 10, 5, 10, 5, 10, 5, 10, 5, 4, 16, 16, 9, 10, 5, 10, 5, 4, 14, 14, 14, 14, 14, 14, 14, 9, 10, 5, 10, 5, 10, 5, 10, 5, 10, 5, 10, 5, 10,
	10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 4, 0, 0, 9, 10, 10, 10, 10, 4, 0, 0, 0, 0, 0, 0, 0, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
};

int gendaiMap2[12][40] = {
	12, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 12, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 15, 0, 0, 0,
	12, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 15, 0, 0, 0,
	12, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 15, 0, 0, 0,
	12, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 15, 0, 0, 0,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 12, 12, 6, 0, 0, 7, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 15, 0, 0, 0,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 12, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 15, 6, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 11, 0, 0, 7, 15, 0, 0, 0, 0, 0, 12,
	1, 11, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 12, 12, 0, 0, 0, 0, 16, 0, 0, 0, 0, 12, 0, 0, 9, 4, 0, 0, 0, 15, 0, 0, 0, 0, 12, 12,
	10, 10, 1, 1, 1, 1, 11, 0, 0, 0, 13, 1, 1, 1, 1, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 9, 4, 0, 0, 0, 0, 0, 0, 0, 13, 1, 1,
	5, 10, 5, 10, 5, 10, 4, 0, 0, 0, 9, 5, 10, 5, 10, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 9, 4, 0, 0, 0, 0, 0, 0, 0, 9, 10, 10,
	10, 10, 10, 10, 10, 10, 4, 0, 0, 0, 9, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 9, 4, 0, 0, 0, 0, 0, 0, 0, 9, 10, 10,
};

int gendaiMap3[12][40] = {
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 15, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 15, 14, 14, 14, 12, 0, 15, 0, 0, 0, 0, 0, 7, 15, 0, 0, 0, 7,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 12, 0, 15, 14, 0, 15, 15, 0, 7, 15, 6, 0, 0, 7,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 12, 0, 15, 0, 0, 0, 0, 0, 7, 15, 6, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 15, 0, 0, 0, 0, 0, 7, 15, 6, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 14, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 12, 0, 15, 0, 0, 0, 0, 0, 7, 15, 6, 0, 0, 12,
	12, 0, 0, 0, 0, 0, 14, 0, 0, 0, 14, 0, 0, 0, 7, 15, 6, 0, 0, 0, 0, 0, 15, 0, 0, 0, 12, 0, 0, 0, 0, 15, 15, 0, 0, 15, 15, 3, 12, 12,
	1, 1, 0, 0, 0, 0, 14, 0, 0, 0, 14, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 12, 12, 12,
	10, 10, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 15, 1, 1, 1,
	10, 10, 16, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 13, 10, 10, 10,
	10, 10, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 9, 10, 10, 10,
};
int gendaiBoss[12][20] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 
	10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
};
/*----------------
	SENGOKUMAP
----------------*/
const int sengokuMaptipTotalNumber = 24;
int sengokuMap[12][40] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 8, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 8, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 13, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0,
	0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 9, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 9, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 0, 0, 13, 0, 0, 0, 0, 15, 15, 15, 13, 13, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 13,
	2, 2, 2, 2, 2, 2, 5, 5, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 4, 2, 2,
	1, 1, 1, 1, 1, 1, 11, 11, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1,
	1, 1, 1, 1, 1, 1, 12, 12, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1,
};

int sengokuMap2[12][40] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 13, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
	13, 20, 20, 20, 20, 0, 20, 19, 20, 20, 0, 23, 20, 0, 0, 13, 20, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 13, 19, 0, 0, 6, 20, 0, 0, 21, 6, 21, 7,
	2, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 4, 2, 2, 4, 4, 2, 2, 2, 2, 2,
	1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 21, 1, 21, 21, 21, 21, 21, 21, 21, 21, 1, 1, 3, 1, 1, 3, 3, 1, 1, 1, 1, 1,
	1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 3, 1, 1, 1, 1, 1,
};

int sengokuMap3[12][40] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 9,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 13, 0, 0, 13,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 13, 0, 0, 13,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 13,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 13, 0, 0, 0, 13, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 13, 7, 0, 13,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0, 13, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 7,
	13, 0, 0, 0, 0, 0, 23, 0, 0, 13, 0, 13, 21, 21, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 22, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7,
	2, 0, 0, 4, 2, 2, 2, 2, 4, 2, 4, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 4, 2, 4, 4, 4, 2, 2, 2, 2, 0, 0, 0, 2, 2,
	1, 0, 0, 3, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 21, 21, 21, 21, 21, 21, 21, 21, 21, 1, 1, 3, 1, 3, 3, 3, 1, 1, 1, 1, 0, 0, 0, 1, 1,
	1, 0, 0, 3, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 3, 3, 1, 1, 1, 1, 0, 0, 0, 1, 1,
};

int sengokuBoss[12][20] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
/*----------------
	ZYOUMONMAP
----------------*/
const float zyoumonMaptipTotalNumber = 22.0f;
int zyoumonMap[12][40] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 20, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 3, 3, 3, 3, 0, 4, 0, 0, 0, 0, 0, 4, 0, 9, 0, 9, 0, 9, 17, 18, 2, 0, 16, 16, 16, 0, 0, 16, 16, 17, 18, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 21, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 12, 12, 12, 12, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 13, 13, 13, 13, 2, 2,
};
int zyoumonMap2[12][40] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 14, 1, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 14, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 14, 15, 0, 0, 0, 0, 0, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 0, 1, 0, 16, 16, 0, 0, 9, 1, 0, 0, 0, 0, 2, 2, 2, 1, 0, 0, 1, 14, 0, 0, 0, 16, 16, 0, 0, 17, 18, 0, 1, 0, 0, 0, 0, 1, 2,
	2, 2, 0, 2, 1, 1, 1, 21, 1, 1, 1, 16, 16, 16, 16, 2, 2, 2, 2, 1, 1, 2, 2, 1, 1, 21, 1, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 2, 2,
	2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2,
	2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2,
};
int zyoumonMap3[12][40] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 14, 15, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 8, 11, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 2, 1, 14, 15, 0, 0, 0, 0, 21, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 20, 0, 0, 2,
	2, 0, 0, 2, 2, 1, 14, 0, 0, 0, 1, 2, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 4, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 18, 3, 8, 2,
	2, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 21, 21, 21, 21, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 21, 21, 1, 1, 1, 1, 1,
	2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};

int zyoumonBoss[12][20] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};
#pragma endregion
#pragma region 自作関数
void DrawTileSetGendai1(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(gendaiMap[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / maptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetGendai2(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(gendaiMap2[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / maptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetGendai3(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(gendaiMap3[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / maptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetGendaiBoss(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(gendaiBoss[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / maptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetSengoku1(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(sengokuMap[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / sengokuMaptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetSengoku2(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(sengokuMap2[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / sengokuMaptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetSengoku3(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(sengokuMap3[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / sengokuMaptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetSengokuBoss(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(sengokuBoss[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / sengokuMaptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetZyoumon1(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(zyoumonMap[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / zyoumonMaptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetZyoumon2(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(zyoumonMap2[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / zyoumonMaptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetZyoumon3(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(zyoumonMap3[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / zyoumonMaptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

void DrawTileSetZyoumonBoss(int sprite, Vector2 pos, float tileSize, int tileCountX, int tileCountY) {
	for (int i = 0; i < tileCountY; i++) {
		for (int j = 0; j < tileCountX; j++) {
			Novice::DrawSpriteRect(static_cast<int>(pos.x + (j * tileSize)), static_cast<int>(pos.y + (i * tileSize)),
				static_cast<int>(zyoumonBoss[i][j] * tileSize), 0, static_cast<int>(tileSize), static_cast<int>(tileSize),
				sprite, 1.0f / zyoumonMaptipTotalNumber, 1.0f, 0.0f, WHITE);
		}
	}
}

float Clamp(float value, float min, float max) {
	if (value < min) {
		return min;
	} else if (value > max) {
		return max;
	} else {
		return value;
	}
}
#pragma endregion
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
#pragma region 画像読み込み
	int gendaiMapGraph = Novice::LoadTexture("./Resources/images/maptip.png");
	int sengokuMapGraph = Novice::LoadTexture("./Resources/images/sengokuMaptip.png");
	int zyoumonMapGraph = Novice::LoadTexture("./Resources/images/zyoumonMaptip.png");
	int gendaiBackGroundGraphs[] = {
		Novice::LoadTexture("./Resources/images/gendaiBackGlound.png"),
		Novice::LoadTexture("./Resources/images/gendaiBackGlound.png"),
	};
	int sengokuBackGroundGraphs[] = {
		Novice::LoadTexture("./Resources/images/sengokuBackGlound.png"),
		Novice::LoadTexture("./Resources/images/sengokuBackGlound.png"),
	};
	int cannonBulletGraphHandle = Novice::LoadTexture("./Resources/images/cannonBullet.png");
	int zyoumonBackGroundGraphs[] = {
		Novice::LoadTexture("./Resources/images/zyoumonBackGlound.png"),
		Novice::LoadTexture("./Resources/images/zyoumonBackGlound.png"),
	};
	int stageClearGraphHandle = Novice::LoadTexture("./Resources/images/stageClear.png");
	float clearPosY = -720.0f;
	float clearSpeed = 10.0f;
	/*--------
	 実機の画像
	--------*/
	//現代
	int gendaiPlayerRightGraphHandle = Novice::LoadTexture("./Resources/images/gendaiPlayerRight.png");
	int gendaiPlayerLeftGraphHandle = Novice::LoadTexture("./Resources/images/gendaiPlayerLeft.png");
	int gendaiPlayerMoveLeftGraphHandle = Novice::LoadTexture("./Resources/images/gendaiPlayerMoveLeft.png");
	int gendaiPlayerMoveRightGraphHandle = Novice::LoadTexture("./Resources/images/gendaiPlayerMoveRight.png");
	int gendaiPlayerRightIsHitGraphHandle = Novice::LoadTexture("./Resources/images/gendaiPlayerRightIsHit.png");
	int gendaiPlayerLeftIsHitGraphHandle = Novice::LoadTexture("./Resources/images/gendaiPlayerLeftIsHit.png");
	int gendaiPlayerMoveLeftIsHitGraphHandle = Novice::LoadTexture("./Resources/images/gendaiPlayerMoveLeftIsHit.png");
	int gendaiPlayerMoveRightIsHitGraphHandle = Novice::LoadTexture("./Resources/images/gendaiPlayerMoveRightIsHit.png");
	//戦国
	int sengokuPlayerRightGraphHandle = Novice::LoadTexture("./Resources/images/sengokuPlayerRight.png");
	int sengokuPlayerLeftGraphHandle = Novice::LoadTexture("./Resources/images/sengokuPlayerLeft.png");
	int sengokuPlayerMoveLeftGraphHandle = Novice::LoadTexture("./Resources/images/sengokuPlayerMoveLeft.png");
	int sengokuPlayerMoveRightGraphHandle = Novice::LoadTexture("./Resources/images/sengokuPlayerMoveRight.png");
	int sengokuPlayerRightIsHitGraphHandle = Novice::LoadTexture("./Resources/images/sengokuPlayerRightIsHit.png");
	int sengokuPlayerLeftIsHitGraphHandle = Novice::LoadTexture("./Resources/images/sengokuPlayerLeftIsHit.png");
	int sengokuPlayerMoveLeftIsHitGraphHandle = Novice::LoadTexture("./Resources/images/sengokuPlayerMoveLeftIsHit.png");
	int sengokuPlayerMoveRightIsHitGraphHandle = Novice::LoadTexture("./Resources/images/sengokuPlayerMoveRightIsHit.png");
	int sengokuBossMoveFrontGraph = Novice::LoadTexture("./Resources/images/sengokuBossMoveFront.png");
	int sengokuBossMoveBackGraph = Novice::LoadTexture("./Resources/images/sengokuBossMoveBack .png");
	int sengokuBossZangekiFrontGraph = Novice::LoadTexture("./Resources/images/sengokuBossActionFront.png");
	int sengokuBossZangekiBackGraph = Novice::LoadTexture("./Resources/images/sengokuBossActionBack.png");
	int sengokuBossRightDieGraphHandle = Novice::LoadTexture("./Resources/images/sengokuBossRightDie.png");
	int sengokuBossLeftDieGraphHandle = Novice::LoadTexture("./Resources/images/sengokuBossLeftDie.png");
	//縄文
	int zyoumonPlayerRightGraphHandle = Novice::LoadTexture("./Resources/images/zyoumonPlayerRight.png");
	int zyoumonPlayerLeftGraphHandle = Novice::LoadTexture("./Resources/images/zyoumonPlayerLeft.png");
	int zyoumonPlayerMoveLeftGraphHandle = Novice::LoadTexture("./Resources/images/zyoumonPlayerMoveLeft.png");
	int zyoumonPlayerMoveRightGraphHandle = Novice::LoadTexture("./Resources/images/zyoumonPlayerMoveRight.png");
	int zyoumonPlayerRightIsHitGraphHandle = Novice::LoadTexture("./Resources/images/zyoumonPlayerRightIsHit.png");
	int zyoumonPlayerLeftIsHitGraphHandle = Novice::LoadTexture("./Resources/images/zyoumonPlayerLeftIsHit.png");
	int zyoumonPlayerMoveLeftIsHitGraphHandle = Novice::LoadTexture("./Resources/images/zyoumonPlayerMoveLeftIsHit.png");
	int zyoumonPlayerMoveRightIsHitGraphHandle = Novice::LoadTexture("./Resources/images/zyoumonPlayerMoveRightIsHit.png");
	int rakusekiGraphHandle = Novice::LoadTexture("./Resources/images/rakuseki.png");
	int tousekiGraphHandle = Novice::LoadTexture("./Resources/images/touseki.png");
	int yariLeftGraphHandle = Novice::LoadTexture("./Resources/images/yariLeft.png");
	int yariRightGraphHandle = Novice::LoadTexture("./Resources/images/yariRight.png");
	//boss
	int zyoumonShockWaveFrontGraph = Novice::LoadTexture("./Resources/images/shockWaveFront.png");
	int zyoumonShockWaveBackGraph = Novice::LoadTexture("./Resources/images/shockWaveBack.png");
	int zyoumonBossMoveBackGraph = Novice::LoadTexture("./Resources/images/zyoumonBossMoveBack.png");
	int zyoumonBossMoveFrontGraph = Novice::LoadTexture("./Resources/images/zyoumonBossMoveFront.png");
	int zyoumonBossRockGraph = Novice::LoadTexture("./Resources/images/zyoumonBossRock.png");
	int zyoumonBossRockThrowFrontGraph = Novice::LoadTexture("./Resources/images/zyoumonThrowFrontRock.png");
	int zyoumonBossRockThrowBackGraph = Novice::LoadTexture("./Resources/images/zyoumonThrowBackRock.png");
	int zyomonBulletGraph = Novice::LoadTexture("./Resources/images/zyomonBullet.png");
	//実機用の画像
	int playerGostBarGraphHandle = Novice::LoadTexture("./Resources/images/playerGhostBar.png");
	int playerLifeGraphHandle[4];
	playerLifeGraphHandle[0] = Novice::LoadTexture("./Resources/images/playerLife0.png");
	playerLifeGraphHandle[1] = Novice::LoadTexture("./Resources/images/playerLife1.png");
	playerLifeGraphHandle[2] = Novice::LoadTexture("./Resources/images/playerLife2.png");
	playerLifeGraphHandle[3] = Novice::LoadTexture("./Resources/images/playerLife3.png");

	int gendaiBossRightGraphHandle = Novice::LoadTexture("./Resources/images/gendaiBossRight.png");
	int gendaiBossLeftGraphHandle = Novice::LoadTexture("./Resources/images/gendaiBossLeft.png");
	int gendaiBossRightDieGraphHandle = Novice::LoadTexture("./Resources/images/gendaiBossRightDie.png");
	int gendaiBossLeftDieGraphHandle = Novice::LoadTexture("./Resources/images/gendaiBossLeftDie.png");
	int gendaiBossBulletGraphHandle = Novice::LoadTexture("./Resources/images/gendaiBossBullet.png");


	int playerBulletGraphHandle = Novice::LoadTexture("./Resources/images/playerBullet.png");
	int playerSlashRightGraphHandle = Novice::LoadTexture("./Resources/images/playerSlashRight.png");
	int playerSlashLeftGraphHandle = Novice::LoadTexture("./Resources/images/playerSlashLeft.png");

	int taitlleGraphHandle = Novice::LoadTexture("./Resources/images/taitll.png");
	int gameOverSceneGraphHandle = Novice::LoadTexture("./Resources/images/gameOver.png");
	int stageSelectHandle = Novice::LoadTexture("./Resources/test/stageSelect.png");
#pragma endregion
    #pragma region 変数宣言
	float scrollX = 0.0f;
	float greenLinePosX = 540.0f;
	float redLinePosX = 740.0f;
	float playerScreenPosX = 0.0f;
	float windowRight = 1280.0f;
	float windowLeft = 0.0f;
	const int kGraphNums = static_cast<int>(sizeof(gendaiBackGroundGraphs) / sizeof(gendaiBackGroundGraphs[0]));
	Vector2 graphSize{ 1280.0f,720.0f };
	//実機用変数
	int playerJumpCount = 2;
	int playerDirection = true;
	PBullet playerBullet[16];
	for (int i = 0; i < 16; i++)
	{
		playerBullet[i].pos.x = 0.0f;
		playerBullet[i].pos.y = 0.0f;
		playerBullet[i].size.x = 32.0f;
		playerBullet[i].size.y = 32.0f;
		playerBullet[i].radius = 16.0f;
		playerBullet[i].speedX = 0.0f;
		playerBullet[i].isAlive = false;
	}
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	enum SceneChange {
		TITLLE,
		STAGESELECT,
		GENDAI,
		GENDAI2,
		GENDAI3,
		GENDAIBOSS,
		SENGOKU,
		SENGOKU2,
		SENGOKU3,
		SENGOKUBOSS,
		ZYOUMON,
		ZYOUMON2,
		ZYOUMON3,
		ZYOMONBOSS,
	};
	SceneChange currentScene = TITLLE;
	int stageNumber = 1;
	int isGameOver = false;
	//アニメーション用変数
	int playerFlameCount = 0;
	int playerFlameNumber = 0;
	int playerMoveFlameCount = 0;
	int playerMoveFlameNumber = 0;
#pragma endregion
    #pragma region 現代ボス変数
	struct Boss
	{
		Vector2 pos;
		Vector2 velocity;
		float speed;
		float jump;
		bool isAlive;
		bool isAction;
		bool isGround;
		int actionCoolTime;
		int action;
		float gravity;
		int shotCoolTime;
		int dashCount;
		int hp;
	};

	struct Bullet
	{
		Vector2 pos;
		float speed;
		float isShot;
		bool isHit;
		float radius;
	};
	Boss gendaiboss;
	gendaiboss.pos.x = 800.0f;
	gendaiboss.pos.y = 300.0f;
	gendaiboss.velocity.x = 0.0f;
	gendaiboss.velocity.y = 0.0f;
	gendaiboss.jump = -20.0f;
	gendaiboss.speed = 1.0f;
	gendaiboss.isAction = false;
	gendaiboss.isAlive = true;
	gendaiboss.isGround = false;
	gendaiboss.actionCoolTime = 0;
	gendaiboss.action = 0;
	gendaiboss.gravity = 0.8f;
	gendaiboss.shotCoolTime = 30;

	Bullet gendaiBossBullet[3];
	for (int i = 0; i < 3; i++)
	{
		gendaiBossBullet[i].pos.x = gendaiboss.pos.x;
		gendaiBossBullet[i].pos.y = gendaiboss.pos.y;
		gendaiBossBullet[i].isShot = false;
		gendaiBossBullet[i].speed = 4.0f;
		gendaiBossBullet[i].isHit = false;
		gendaiBossBullet[i].radius = 16.0f;
	}

	int gendaiBossLife = 120;
	int gendaiBossIsAlive = true;
	int gendaiBossFlameCount = 0;
	int gendaiBossFlameNumber = 0;

	enum GENDAIBOSSATTACK
	{
		NONE,
		MOVE,
		FIRINGBULLET,
		JUMP,
	};

	GENDAIBOSSATTACK gendaiBossAction = NONE;

	unsigned int currentTime = static_cast<int>(time(nullptr));
	srand(currentTime);
#pragma endregion
    #pragma region 戦国ボス変数
	/*戦国ボス*/

	Boss sengokuboss;
	sengokuboss.pos.x = 800.0f;
	sengokuboss.pos.y = 500.0f;
	sengokuboss.velocity.x = 0.0f;
	sengokuboss.velocity.y = 0.0f;
	sengokuboss.jump = -20.0f;
	sengokuboss.isAction = false;
	sengokuboss.isAlive = true;
	sengokuboss.isGround = false;
	sengokuboss.actionCoolTime = 0;
	sengokuboss.action = 0;
	sengokuboss.gravity = 0.8f;
	sengokuboss.speed = 1.0f;
	sengokuboss.dashCount = 0;
	float sengokuBossRadius = 32.0f;
	float sengokuBossZangekiFrontRadius = 32.0f;
	float sengokuBossZangekiBackRadius = 32.0f;

	Vector2 sengokuBossZangekiBackPlayer;
	sengokuBossZangekiBackPlayer.x = sengokuboss.pos.x - 96.0f;
	sengokuBossZangekiBackPlayer.y = sengokuboss.pos.y;

	Vector2 sengokuBossZangekiFrontPlayer;
	sengokuBossZangekiFrontPlayer.x = sengokuboss.pos.x + 64.0f;
	sengokuBossZangekiFrontPlayer.y = sengokuboss.pos.y;

	// アニメーションカウント
	int sengokuActionDoTime = 0;
	int sengokuBossGraphCount = 0;
	int sengokuBossMoveCount = 0;
	int sengokuBossActionFlameCount = 0;
	int sengokuBossActionGraphCount = 0;
	bool sengokuZangekiAction = false;

	//bossToPlayer Hit
	float sengokuBossToPlayerX = 0.0f;
	float sengokuBossToPlayerY = 0.0f;

	//bossActionToPlayer Hit
	float bossZangekiFrontToPlayerX = 0.0f;
	float bossZangekiFrontToPlayerY = 0.0f;

	float bossZangekiBackToPlayerX = 0.0f;
	float bossZangekiBackToPlayerY = 0.0f;

	//HitJudge
	float hitJudgeSengokuBossToPlayer = 0.0f;
	float hitJudgeBossZangekiFrontToPlayer = 0.0f;
	float hitJudgeBossZangekiBackToPlayer = 0.0f;


	enum SENGOKUBOSSDIRECTION
	{
		FRONT,
		BACK,
	};

	SENGOKUBOSSDIRECTION  sengokubossDirection = BACK;

#pragma endregion
    #pragma region 縄文ボス変数
	//----------------------------------------------------------------------
	Boss zyoumonboss;
	zyoumonboss.pos.x = 800.0f;
	zyoumonboss.pos.y = 100.0f;
	zyoumonboss.velocity.x = 0.0f;
	zyoumonboss.velocity.y = 0.0f;
	zyoumonboss.jump = -80.0f;
	zyoumonboss.isAction = false;
	zyoumonboss.isAlive = true;
	zyoumonboss.isGround = false;
	zyoumonboss.actionCoolTime = 0;
	zyoumonboss.action = 0;
	zyoumonboss.gravity = 0.7f;
	zyoumonboss.speed = 1.0f;
	zyoumonboss.dashCount = 0;
	zyoumonboss.hp = 80;

	int zyoumonBossMoveCount = 0;
	int zyoumonBossMoveGraphCount = 0;
	int zyoumonBossMoveActionCount = 0;
	float zyoumonbossRadius = 64.0f;

	Boss zyoumonbossRock;
	zyoumonbossRock.pos.x = zyoumonboss.pos.x - 96.0f;
	zyoumonbossRock.pos.y = 512.0f;
	zyoumonbossRock.speed = 0.0f;
	zyoumonbossRock.isAction = false;

	bool zyoumonIsDirectionRock = false;
	int zyoumonbossRockMoveCount = 0;
	int zyoumonbossRockGraphCount = 0;
	float zyoumonBossRockRadius = 32.0f;

	Boss zyoumonBossShockWave;
	zyoumonBossShockWave.pos.x = zyoumonboss.pos.x;
	zyoumonBossShockWave.pos.y = 512.0f;
	zyoumonBossShockWave.speed = 0.0f;
	zyoumonBossShockWave.isAction = false;

	float zyoumonBossShockWaveRadius = 32.0f;

	//bossPlayerDistance 
	float zyoumonBossToPlayerX = 0.0f;
	float zyoumonBossToPlayerY = 0.0f;

	//bossRockToPlayer
	float zyoumonBossRockToPlayerX = 0.0f;
	float zyoumonBossRockToPlayerY = 0.0f;

	//bossShockWaveToPlayer
	float zyoumonBossShockWaveToPlayerX = 0.0f;
	float zyoumonBossShockWaveToPlayerY = 0.0f;

	//HitJudge
	float hitJudgezyoumonBossToPlayer = 0.0f;
	float hitJudgeZyoumonBossRockToPlayer = 0.0f;
	float hitJudgeZyoumonBossShockWaveToPlayer = 0.0f;
	//----------------------------------------------------------------------

#pragma endregion 
    #pragma region 現代当たり判定
	float gendaiPlayerToBossX = 0.0f;
	float gendaiPlayerToBossY = 0.0f;
	float gendaiPlayerToBossXY = 0.0f;
	float gendaiPlayerBulletToBossX = 0.0f;
	float gendaiPlayerBulletToBossY = 0.0f;
	float gendaiPlayerBulletToBossXY = 0.0f;
	float gendaiPlayerToBossBulletX = 0.0f;
	float gendaiPlayerToBossBulletY = 0.0f;
	float gendaiPlayerToBossBulletXY = 0.0f;
#pragma endregion
    #pragma region 砲丸の変数
	//戦国1
	float cannonPosX[10] = { 192.0f,448.0f,576.0f,1216.0f,1728.0f,1792.0f,1728.0f,1792.0f,2240.0f,2368.0f };
	float cannonPosY[10] = { 320.0f,256.0f,256.0f,320.0f,192.0f,192.0f,448.0f,448.0f,320.0f,320.0 };
	float cannonGravityY = 0.1f;
	float cannonUpPower = -10.0;
	float cannonSpeedX[10] = { 8.0f,10.0f,17.0f,-15.0f,-17.0f,10.0f,-12.0f,10.0f,-10.0f,-10.0f };
	int cannonIsShot[10] = { false, false, false, false, false, false, false, false, false, false };
	int cannonIsShotTimer = 0;
	float playerTocannonBulletX = 0.0f;
	float playerTocannonBulletY = 0.0f;
	float playerTocannonBulletXY = 0.0f;
	//戦国2
	float cannon2PosX[2] = { 704.0f,960.0f };
	float cannon2PosY[2] = { 512.0f,384.0f };
	float cannon2SpeedX = -15.0f;
	int cannon2IsShot[2] = { false,false };
	int cannon2IsShotTimer = 0;
	float playerTocannon2BulletX = 0.0f;
	float playerTocannon2BulletY = 0.0f;
	float playerTocannon2BulletXY = 0.0f;
	//戦国3
	float blackCannonPosX[5] = {};
	float blackCannonPosY[5] = {};
	float blackCannonSpeedX[5] = { -10.0f,-10.0f, -10.0f, 14.0f, 12.0f };
	int blackCannonIsShot[5] = { false,false, false, false, false };
	int blackCannonIsShotTimer = 0;
	float blackCannonToPlayerX = 0.0f;
	float blackCannonToPlayerY = 0.0f;
	float blackCannonToPlayerXY = 0.0f;

	float redCannonPosX[5] = {};
	float redCannonPosY[5] = {};
	float redCannonSpeedX[5] = { -8.5f,6.3f, -9.0f, -8.7f, 10.0f };
	int redCannonIsShot[5] = { false,false, false, false, false };
	int redCannonIsShotTimer = 0;
	float redCannonGravityY = 0.1f;
	float redCannonUpPower = -10.0;
	float redCannonToPlayerX = 0.0f;
	float redCannonToPlayerY = 0.0f;
	float redCannonToPlayerXY = 0.0f;
#pragma endregion
    #pragma region 戦国プレイヤーの攻撃
	float playerSlashPosX = 0.0f;
	float playerSlashPosY = 0.0f;
	float playerSlashSpeedX = 2.0f;
	int platerSlashIsAlive = false;
	int playerSlashIsAliveTimer = 0;
	int playerSlashDirection = true;
	float playerSlashToBossX = 0.0f;
	float playerSlashToBossY = 0.0f;
	float playerSlashToBossXY = 0.0f;
	int sengokuBossLife = 20;
	int sengokuBossIsAlive = true;
	int sengokuBossDieFlameCount = 0;
	int sengokuBossDieFlameNumber = 0;
#pragma endregion
    #pragma region 縄文落石変数
	//1
	float rakuseki1PosX[10] = { 512.0f,576.0f,640.0f,704.0f,768.0f,1792.0f,2176.0f,2240.0f,2304.0f,2368.0f };
	float rakuseki1PosY[10] = {};
	float rakuseki1SpeedY[10] = {};
	float rakuseki1ToPlayerX = 0.0f;
	float rakuseki1ToPlayerY = 0.0f;
	float rakuseki1ToPlayerXY = 0.0f;
	//2
	float rakuseki2PosX[9] = { 128.0f,448.0f,768.0f,832.0f,1600.0f ,2176.0f,2240.0f,2304.0f,2368.0f };
	float rakuseki2PosY[9] = {};
	float rakuseki2SpeedY[9] = {};
	float rakuseki2ToPlayerX = 0.0f;
	float rakuseki2ToPlayerY = 0.0f;
	float rakuseki2ToPlayerXY = 0.0f;
	//3
	float rakuseki3PosX[10] = { 704.0f,832.0f,896.0f,960.0f,1024.0f,1088.0f,1152.0f,1856.0f,2112.0f,2176.0f };
	float rakuseki3PosY[10] = {};
	float rakuseki3SpeedY[10] = {};
	float rakuseki3ToPlayerX = 0.0f;
	float rakuseki3ToPlayerY = 0.0f;
	float rakuseki3ToPlayerXY = 0.0f;
#pragma endregion
    #pragma region 縄文投石変数
	//1
	float touseki1PosX[2] = {};
	float touseki1PosY[2] = {};
	float tousekiSpeedX[2] = {};
	float tousekiGravity = 0.1f;
	float tousekiUp = 0.0f;
	int tousekiIsAlive[2] = { false,false };
	int tousekiIsAliveTimer = 0;
	float touseki1ToPlayerX = 0.0f;
	float touseki1ToPlayerY = 0.0f;
	float touseki1ToPlayerXY = 0.0f;
	//2
	float touseki2PosX = {};
	float touseki2PosY = {};
	float touseki2SpeedX = {};
	float touseki2Gravity = 0.2f;
	float touseki2Up = 0.0f;
	int touseki2IsAlive = false;
	int touseki2IsAliveTimer = 0;
	float touseki2ToPlayerX = 0.0f;
	float touseki2ToPlayerY = 0.0f;
	float touseki2ToPlayerXY = 0.0f;
	//3
	float touseki3PosX = {};
	float touseki3PosY = {};
	float touseki3SpeedX = {};
	float touseki3Gravity = 0.2f;
	float touseki3Up = 0.0f;
	int touseki3IsAlive = false;
	int touseki3IsAliveTimer = 0;
	float touseki3ToPlayerX = 0.0f;
	float touseki3ToPlayerY = 0.0f;
	float touseki3ToPlayerXY = 0.0f;
#pragma endregion
    #pragma region 縄文槍変数
	//1
	float yari1PosX = 0.0f;
	float yari1PosY = 0.0f;
	float yari1SpeedX = -20.0f;
	int yari1IsAlive = false;
	int yari1IsAliveTimer = 0;
	float yari1ToPlayerX = 0.0f;
	float yari1ToPlayerY = 0.0f;
	float yari1ToPlayerXY = 0.0f;
	//2
	float yari2RightPosX[2] = {};
	float yari2RightPosY[2] = {};
	float yari2RightSpeedX = 20.0f;
	int yari2RightIsAlive[2] = {false,false};
	int yari2RightIsAliveTimer[2] = {};
	float yari2RightToPlayerX = 0.0f;
	float yari2RightToPlayerY = 0.0f;
	float yari2RightToPlayerXY = 0.0f;

	float yari2LeftPosX[2] = {};
	float yari2LeftPosY[2] = {};
	float yari2LeftSpeedX = -20.0f;
	int yari2LeftIsAlive[2] = { false,false };
	int yari2LeftIsAliveTimer[2] = {};
	float yari2LeftToPlayerX = 0.0f;
	float yari2LeftToPlayerY = 0.0f;
	float yari2LeftToPlayerXY = 0.0f;
	//3
	float yari3PosX[4] = {};
	float yari3PosY[4] = {};
	float yari3SpeedX = 20.0f;
	int yari3IsAlive[4] = {false, false ,false ,false };
	int yari3IsAliveTimer[4] = {};
	float yari3ToPlayerX = 0.0f;
	float yari3ToPlayerY = 0.0f;
	float yari3ToPlayerXY = 0.0f;
#pragma endregion
    #pragma region 縄文実機攻撃
	float zyomonBulletPosX = 0.0f;
	float zyomonBulletPosY = 0.0f;
	float zyomonBulletSpeedX = 0.0f;
	int zyomonBulletIsAlive = false;
	int zyomonBulletIsAliveTimer = 0;
	/*int PBulletToZyomonBossX = 0.0f;
	int PBulletToZyomonBossY = 0.0f;
	int PBulletToZyomonBossXY = 0.0f;*/
#pragma endregion

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/*Novice::SetWindowMode(kFullscreen);*/

		switch (currentScene)
		{
		case TITLLE:
        #pragma region タイトル
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				player.pos.x = 32.0f;
				player.pos.y = 592.0f;
				currentScene = STAGESELECT;
			}
			break;
#pragma endregion
		case STAGESELECT:
        #pragma region ステージセレクト
			playerLife = 3;
			isGameOver = false;
			playerIsAlive = true;
			clearPosY = -720.0f;
			gendaiBossIsAlive = true;
			gendaiBossLife = 120;
			gendaiBossFlameCount = 0;
			sengokuBossIsAlive = true;
			sengokuBossLife = 20;
			sengokuBossDieFlameCount = 0;
			for (int i = 0; i < 16; i++)
			{
				playerBullet[i].isAlive = false;
			}
			if (stageNumber == 1)
			{
				if (preKeys[DIK_D] == 0 && keys[DIK_D] != 0)
				{
					stageNumber = 2;
				}

				if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0)
				{
					currentScene = GENDAI;
					player.pos.x = 32.0f;
					player.pos.y = 500.0f;
				}
			} else if (stageNumber == 2)
			{
				if (preKeys[DIK_D] == 0 && keys[DIK_D] != 0)
				{
					stageNumber = 3;
				} else if (preKeys[DIK_A] == 0 && keys[DIK_A] != 0)
				{
					stageNumber = 1;
				}

				if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0)
				{
					currentScene = SENGOKU;
					player.pos.x = 32.0f;
					player.pos.y = 500.0f;
				}
			} else if (stageNumber == 3)
			{
				if (preKeys[DIK_A] == 0 && keys[DIK_A] != 0)
				{
					stageNumber = 2;
				}
				if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0)
				{
					currentScene = ZYOUMON;
					player.pos.x = 32.0f;
					player.pos.y = 500.0f;
				}
			}

			break;
#pragma endregion
		case GENDAI:
        #pragma region 現代
			if (isGameOver == false)
			{
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D]|| keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;

				//当たり判定
				if ((gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}

				if (
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}



				if (
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}

				if (
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}
				if (
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 12) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(gendaiMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15)
					) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//ダメージ判定
				if (playerIsAlive)
				{
					if (
						(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8) ||
						(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8) ||
						(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
				}


				if ((gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(gendaiMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 768.0f;
					player.pos.y = 600.0f;
				}

				if ((gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(gendaiMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 768.0f;
					player.pos.y = 600.0f;
				}



				if ((gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 768.0f;
					player.pos.y = 600.0f;
				}

				if ((gendaiMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14) ||
					(gendaiMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 768.0f;
					player.pos.y = 600.0f;
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
				playerScreenPosX = player.pos.x - scrollX;
				if (playerScreenPosX + 32.0f >= redLinePosX) {
					scrollX = player.pos.x + 32.0f - redLinePosX;
				}

				if (playerScreenPosX <= greenLinePosX) {
					scrollX = player.pos.x - greenLinePosX;
				}

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 2560.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 750.0f) {
					isGameOver = true;
				}
				//画面右端に到達で次のステージに移動
				if (player.pos.x > 2550.0f)
				{
					currentScene = GENDAI2;
					player.pos.x = 32.0f;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerLife < 0)
				{
					playerLife = 0;
				}
				if (playerIsAlive==false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
				if (keys[DIK_SPACE])
				{
					playerBulletRespawnTimer++;
					if (playerBulletRespawnTimer == 20)
					{
						playerBulletRespawnTimer = 0;
						for (int i = 0; i < 16; i++)
						{
							if (playerBullet[i].isAlive == false)
							{
								playerBullet[i].isAlive = true;
								playerBullet[i].pos.x = player.pos.x;
								playerBullet[i].pos.y = player.pos.y;
								if (playerDirection)
								{
									playerBullet[i].speedX = 10.0f;
								} 
								else
								{
									playerBullet[i].speedX = -10.0f;
								}
								break;
							}
						}
					}
				}
				else
				{
					playerBulletRespawnTimer = 0;
				}for (int i = 0; i < 16; i++)
				{
					if (playerBullet[i].isAlive)
					{
						playerBullet[i].pos.x += playerBullet[i].speedX;
						if (playerBullet[i].pos.x > 2560.0f)
						{
							playerBullet[i].isAlive = false;
						}
						if (playerBullet[i].pos.x < 0.0f)
						{
							playerBullet[i].isAlive = false;
						}
					}
				}
			}
			else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 32.0f;
					player.pos.y = 500.0f;
					playerLife = 3;
					for (int i = 0; i < 16; i++)
					{
						playerBullet[i].isAlive = false;
					}
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		case GENDAI2:
        #pragma region 現代2
			if (isGameOver == false)
			{
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;

				//当たり判定
				if (player.velocity.y > 0.0f) {
							if ((gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 12) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
								(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15)
								) {
								player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
								player.velocity.y = 0.0f;
								playerJumpCount = 2;
							}
						} else if (player.velocity.y < 0.0f) {
							if (
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
								(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15)
								) {
								player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
								player.velocity.y = 0.0f;
								playerJumpCount = 2;
							}
						}

						if (player.velocity.x > 0.0f) {
							if (
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 12) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 12) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15)
								) {
								player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
								player.velocity.x = 0.0f;
							}
						} else if (player.velocity.x < 0.0f) {
							if (
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 12) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 12) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13) ||
								(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15) ||
								(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15)
								) {
								player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
								player.velocity.x = 0.0f;
							}
						}
				
				if (
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 12) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(gendaiMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15)
					) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//ダメージ判定
				if (playerIsAlive)
				{
					if (
						(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
					else if (
						(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) 
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
					else if (
						(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8) ||
						(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
					else if (
						(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8) ||
						(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
				}
				if ((gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(gendaiMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 1312.0f;
					player.pos.y = 600.0f;
				}

				if ((gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(gendaiMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 1312.0f;
					player.pos.y = 600.0f;
				}



				if ((gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14) ||
					(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 1312.0f;
					player.pos.y = 600.0f;
				}

				if ((gendaiMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14) ||
					(gendaiMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 1312.0f;
					player.pos.y = 600.0f;
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
				playerScreenPosX = player.pos.x - scrollX;
				if (playerScreenPosX + 32.0f >= redLinePosX) {
					scrollX = player.pos.x + 32.0f - redLinePosX;
				}

				if (playerScreenPosX <= greenLinePosX) {
					scrollX = player.pos.x - greenLinePosX;
				}

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 2560.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 800.0f) {
					isGameOver = true;
				}
				//画面左端に到達で前のステージに移動
				if (player.pos.x < 10.0f)
				{
					currentScene = GENDAI;
					player.pos.x = 2528.0f;
				}
				//画面右端に到達で次のステージに移動
				if (player.pos.x > 2550.0f)
				{
					currentScene = GENDAI3;
					player.pos.x = 32.0f;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerLife < 0)
				{
					playerLife = 0;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
				if (keys[DIK_SPACE])
				{
					playerBulletRespawnTimer++;
					if (playerBulletRespawnTimer == 20)
					{
						playerBulletRespawnTimer = 0;
						for (int i = 0; i < 16; i++)
						{
							if (playerBullet[i].isAlive == false)
							{
								playerBullet[i].isAlive = true;
								playerBullet[i].pos.x = player.pos.x;
								playerBullet[i].pos.y = player.pos.y;
								if (playerDirection)
								{
									playerBullet[i].speedX = 10.0f;
								} else
								{
									playerBullet[i].speedX = -10.0f;
								}
								break;
							}
						}
					}
				} else
				{
					playerBulletRespawnTimer = 0;
				}for (int i = 0; i < 16; i++)
				{
					if (playerBullet[i].isAlive)
					{
						playerBullet[i].pos.x += playerBullet[i].speedX;
						if (playerBullet[i].pos.x > 2560.0f)
						{
							playerBullet[i].isAlive = false;
						}
						if (playerBullet[i].pos.x < 0.0f)
						{
							playerBullet[i].isAlive = false;
						}
					}
				}
			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 96.0f;
					player.pos.y = 400.0f;
					playerLife = 3;
					for (int i = 0; i < 16; i++)
					{
						playerBullet[i].isAlive = false;
					}
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		case GENDAI3:
        #pragma region 現代3
			if (isGameOver == false)
			{
				
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;

				//当たり判定
					if ((gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 12) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15)
						) {
						player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
						player.velocity.y = 0.0f;
						playerJumpCount = 2;
					}
				
					if (
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15)
						) {
						player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
						player.velocity.y = 0.0f;
						playerJumpCount = 2;
					}
				

				
					if (
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 12) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 12) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15)
						) {
						player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
						player.velocity.x = 0.0f;
					}
				
					if (
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 12) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 12) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15)
						) {
						player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
						player.velocity.x = 0.0f;
					}
				

				if (
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 12) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 12) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(gendaiMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15)
					) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//ダメージ判定
				if (playerIsAlive)
				{
					if (
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8) ||
						(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
				}
				if ((gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(gendaiMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 160.0f;
					player.pos.y = 664.0f;
				}

				if ((gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(gendaiMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 160.0f;
					player.pos.y = 664.0f;
				}



				if ((gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14) ||
					(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 160.0f;
					player.pos.y = 664.0f;
				}

				if ((gendaiMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14) ||
					(gendaiMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14)
					) {
					player.pos.x = 160.0f;
					player.pos.y = 664.0f;
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
				playerScreenPosX = player.pos.x - scrollX;
				if (playerScreenPosX + 32.0f >= redLinePosX) {
					scrollX = player.pos.x + 32.0f - redLinePosX;
				}

				if (playerScreenPosX <= greenLinePosX) {
					scrollX = player.pos.x - greenLinePosX;
				}

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 2560.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 800.0f) {
					isGameOver = true;
				}
				//画面左端に到達で前のステージに移動
				if (player.pos.x < 10.0f)
				{
					currentScene = GENDAI2;
					player.pos.x = 2528.0f;
				}
				//画面右端に到達で次のステージに移動
				if (player.pos.x > 2550.0f)
				{
					currentScene = GENDAIBOSS;
					player.pos.x = 32.0f;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerLife < 0)
				{
					playerLife = 0;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
				if (keys[DIK_SPACE])
				{
					playerBulletRespawnTimer++;
					if (playerBulletRespawnTimer == 20)
					{
						playerBulletRespawnTimer = 0;
						for (int i = 0; i < 16; i++)
						{
							if (playerBullet[i].isAlive == false)
							{
								playerBullet[i].isAlive = true;
								playerBullet[i].pos.x = player.pos.x;
								playerBullet[i].pos.y = player.pos.y;
								if (playerDirection)
								{
									playerBullet[i].speedX = 10.0f;
								} else
								{
									playerBullet[i].speedX = -10.0f;
								}
								break;
							}
						}
					}
				} else
				{
					playerBulletRespawnTimer = 0;
				}for (int i = 0; i < 16; i++)
				{
					if (playerBullet[i].isAlive)
					{
						playerBullet[i].pos.x += playerBullet[i].speedX;
						if (playerBullet[i].pos.x > 2560.0f)
						{
							playerBullet[i].isAlive = false;
						}
						if (playerBullet[i].pos.x < 0.0f)
						{
							playerBullet[i].isAlive = false;
						}
					}
				}
			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 96.0f;
					player.pos.y = 400.0f;
					playerLife = 3;
					for (int i = 0; i < 16; i++)
					{
						playerBullet[i].isAlive = false;
					}
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		case GENDAIBOSS:
        #pragma region 現代ボス
			if (isGameOver==false)
			{
				if (preKeys[DIK_P] == 0 && keys[DIK_P] != 0)
				{
					isGameOver = true;
				}
				
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;
                #pragma region しょうた現代ボス
				//ボスの攻撃
				gendaiboss.velocity.y += gendaiboss.gravity;
				gendaiboss.pos.y += gendaiboss.velocity.y;

				if (!gendaiboss.isAction && gendaiboss.actionCoolTime <= 80)
				{
					gendaiboss.actionCoolTime++;
				}
				if (gendaiBossIsAlive)
				{
					if (gendaiboss.actionCoolTime >= 80)
					{
						gendaiboss.action = static_cast<int>(rand() % 10);
						gendaiboss.actionCoolTime = 0;
					}
					gendaiboss.speed = 1.0f;
				}
				else
				{
					gendaiBossFlameCount++;
					gendaiBossFlameNumber = (gendaiBossFlameCount / 10) % 11;
					if (gendaiBossFlameCount > 100)
					{
						gendaiBossFlameCount = 100;
					}
					gendaiboss.speed = 0.0f;
				}
				if (gendaiBossFlameCount == 100)
				{
					clearPosY += clearSpeed;
					if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
					{
						currentScene = STAGESELECT;
					}
				}
				if (clearPosY > 0.0f)
				{
					clearPosY = 0.0f;
				}
				if (gendaiBossLife < 0)
				{
					gendaiBossIsAlive = false;
				}
				if (gendaiboss.action <= 5)
				{
					gendaiBossAction = MOVE;
				} else if (gendaiboss.action >= 6 && gendaiboss.action <= 8)
				{
					gendaiBossAction = JUMP;
				} else
				{
					gendaiBossAction = FIRINGBULLET;
				}

				for (int i = 0; i < 3; i++)
				{
					if (gendaiBossBullet[i].isShot)
					{
						gendaiBossBullet[i].pos.x += gendaiBossBullet[i].speed;
					}
					else
					{
						gendaiBossBullet[i].pos.x = 0.0f;
						gendaiBossBullet[i].pos.y = 0.0f;
					}

					if (gendaiBossBullet[i].pos.x <= 0 || gendaiBossBullet[i].isHit)
					{
						gendaiBossBullet[i].isShot = false;
					} else if (gendaiBossBullet[i].pos.x >= 1280 || gendaiBossBullet[i].isHit)
					{
						gendaiBossBullet[i].isShot = false;
					}
				}
				switch (gendaiBossAction)
				{
				case MOVE:
					gendaiboss.speed = 1.0f;

					if (gendaiboss.pos.x < player.pos.x)
					{
						gendaiboss.pos.x += gendaiboss.speed;
					} else
					{
						gendaiboss.pos.x -= gendaiboss.speed;
					}
					break;
				case FIRINGBULLET:
					if (gendaiboss.shotCoolTime > 0)
					{
						gendaiboss.shotCoolTime--;
					}
					if (gendaiboss.shotCoolTime <= 0)
					{
						for (int i = 0; i < 3; i++)
						{
							if (!gendaiBossBullet[i].isShot)
							{
								gendaiBossBullet[i].isShot = true;
								gendaiBossBullet[i].pos.x = gendaiboss.pos.x;
								gendaiBossBullet[i].pos.y = gendaiboss.pos.y;
								if (gendaiboss.pos.x > player.pos.x)
								{
									gendaiBossBullet[i].speed = -4.0f;
								} else
								{
									gendaiBossBullet[i].speed = 4.0f;
								}
								gendaiboss.shotCoolTime = 30;
								break;
							}
						}
					}
					for (int i = 0; i < 3; i++)
					{
						if (gendaiBossBullet[i].isShot)
						{
							gendaiBossBullet[i].pos.x += gendaiBossBullet[i].speed;
						}
					}
					break;
				case JUMP:
				{
					gendaiboss.pos.y += gendaiboss.jump;

					break;
				}
				}
				gendaiboss.speed = 0.0f;
				//ボスのマップチップとの当たり判定
				if (gendaiboss.velocity.y > 0.0f) {
					if ((gendaiBoss[int((gendaiboss.pos.y + 32.0f) / 64.0f)][int((gendaiboss.pos.x - 20.0f) / 64.0f)] != 0) ||
						(gendaiBoss[int((gendaiboss.pos.y + 32.0f) / 64.0f)][int((gendaiboss.pos.x + 20.0f) / 64.0f)] != 0)) {
						gendaiboss.pos.y = (int(gendaiboss.pos.y / 64.0f) * 64.0f) + 32.0f;
						gendaiboss.velocity.y = 0.0f;
					}
				} else if (gendaiboss.velocity.y < 0.0f) {
					if ((gendaiBoss[int((gendaiboss.pos.y - 30.0f) / 64.0f)][int((gendaiboss.pos.x - 20.0f) / 64.0f)] != 0) ||
						(gendaiBoss[int((gendaiboss.pos.y - 30.0f) / 64.0f)][int((gendaiboss.pos.x + 20.0f) / 64.0f)] != 0)) {
						gendaiboss.pos.y = (int(gendaiboss.pos.y / 64.0f) * 64.0f) + 32.0f;
						gendaiboss.velocity.y = 0.0f;
					}
				}

				if (gendaiboss.velocity.x > 0.0f) {
					if ((gendaiBoss[int((gendaiboss.pos.y - 32.0f) / 64.0f)][int((gendaiboss.pos.x + 33.0f) / 64.0f)] != 0) ||
						(gendaiBoss[int((gendaiboss.pos.y + 31.0f) / 64.0f)][int((gendaiboss.pos.x + 33.0f) / 64.0f)] != 0)) {
						gendaiboss.pos.x = (int(gendaiboss.pos.x / 64.0f) * 64.0f) + 32.0f;
						gendaiboss.velocity.x = 0.0f;
					}
				} else if (gendaiboss.velocity.x < 0.0f) 
				{
					if ((gendaiBoss[int((gendaiboss.pos.y - 32.0f) / 64.0f)][int((gendaiboss.pos.x - 33.0f) / 64.0f)] != 0) ||
						(gendaiBoss[int((gendaiboss.pos.y + 31.0f) / 64.0f)][int((gendaiboss.pos.x - 33.0f) / 64.0f)] != 0))
					{
						gendaiboss.pos.x = (int(gendaiboss.pos.x / 64.0f) * 64.0f) + 32.0f;
						gendaiboss.velocity.x = 0.0f;
					}
				}
					
#pragma endregion
				//当たり判定
				for (int i = 0; i < 12; i++) {
					for (int j = 0; j < 40; j++) {
						if (player.velocity.y > 0.0f) {
							if ((gendaiBoss[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] != 0) ||
								(gendaiBoss[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] != 0)) {
								player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
								player.velocity.y = 0.0f;
								playerJumpCount = 2;
							}
						} else if (player.velocity.y < 0.0f) {
							if ((gendaiBoss[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] != 0) ||
								(gendaiBoss[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] != 0)) {
								player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
								player.velocity.y = 0.0f;
								playerJumpCount = 2;
							}
						}

						if (player.velocity.x > 0.0f) {
							if ((gendaiBoss[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] != 0) ||
								(gendaiBoss[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] != 0)) {
								player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
								player.velocity.x = 0.0f;
							}
						} else if (player.velocity.x < 0.0f) {
							if ((gendaiBoss[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] != 0) ||
								(gendaiBoss[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] != 0)) {
								player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
								player.velocity.x = 0.0f;
							}
						}
					}
				}
				if ((gendaiBoss[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] != 0) ||
					(gendaiBoss[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] != 0)) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 1280.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 720.0f) {
					player.pos.x = 10.0f;
					player.pos.y = 100;
					break;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
				if (keys[DIK_SPACE])
				{
					playerBulletRespawnTimer++;
					if (playerBulletRespawnTimer == 20)
					{
						playerBulletRespawnTimer = 0;
						for (int i = 0; i < 16; i++)
						{
							if (playerBullet[i].isAlive == false)
							{
								playerBullet[i].isAlive = true;
								playerBullet[i].pos.x = player.pos.x;
								playerBullet[i].pos.y = player.pos.y;
								if (playerDirection)
								{
									playerBullet[i].speedX = 10.0f;
								} else
								{
									playerBullet[i].speedX = -10.0f;
								}
								break;
							}
						}
					}
				} else
				{
					playerBulletRespawnTimer = 0;
				}for (int i = 0; i < 16; i++)
				{
					if (playerBullet[i].isAlive)
					{
						playerBullet[i].pos.x += playerBullet[i].speedX;
						if (playerBullet[i].pos.x > 1280.0f)
						{
							playerBullet[i].isAlive = false;
						}
						if (playerBullet[i].pos.x < 0.0f)
						{
							playerBullet[i].isAlive = false;
						}
					}
					else
					{
						playerBullet[i].pos.x = 0.0f;
						playerBullet[i].pos.y = 0.0f;
					}
				}
				//当たり判定
				for (int i = 0; i < 16; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						gendaiPlayerBulletToBossX = playerBullet[i].pos.x - gendaiboss.pos.x;
						gendaiPlayerBulletToBossY = playerBullet[i].pos.y - gendaiboss.pos.y;
						gendaiPlayerBulletToBossXY = sqrtf(gendaiPlayerBulletToBossX * gendaiPlayerBulletToBossX + gendaiPlayerBulletToBossY * gendaiPlayerBulletToBossY);
						gendaiPlayerToBossBulletX = player.pos.x - gendaiBossBullet[j].pos.x;
						gendaiPlayerToBossBulletY = player.pos.y - gendaiBossBullet[j].pos.y;
						gendaiPlayerToBossBulletXY = sqrtf(gendaiPlayerToBossBulletX * gendaiPlayerToBossBulletX + gendaiPlayerToBossBulletY * gendaiPlayerToBossBulletY);
						gendaiPlayerToBossX = player.pos.x - gendaiboss.pos.x;
						gendaiPlayerToBossY = player.pos.y - gendaiboss.pos.y;
						gendaiPlayerToBossXY = sqrtf(gendaiPlayerToBossX * gendaiPlayerToBossX + gendaiPlayerToBossY * gendaiPlayerToBossY);
						if (playerIsAlive && gendaiBossIsAlive)
						{
							if (gendaiPlayerToBossBulletXY < player.radius + gendaiBossBullet[j].radius)
							{
								gendaiBossBullet[j].isShot = false;
								playerIsAlive = false;
								playerLife--;
							}
							if (gendaiPlayerToBossXY < player.radius + 32.0f)
							{
								playerIsAlive = false;
								playerLife--;
							}
							if (gendaiPlayerBulletToBossXY < playerBullet[i].radius + 32.0f)
							{
								playerBullet[i].isAlive = false;
								gendaiBossLife--;
							}
						}
					}
				}
			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					currentScene = GENDAI3;
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 2500.0 - 32.0f;
					player.pos.y = 400.0f;
					playerLife = 3;
					for (int i = 0; i < 16; i++)
					{
						playerBullet[i].isAlive = false;
					}
					for (int i = 0; i < 3; i++)
					{
						gendaiBossBullet[i].isShot = false;
					}
					gendaiBossLife = 120;
					gendaiboss.pos.x = 800.0f;
					gendaiboss.pos.y = 300.0f;
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
					for (int i = 0; i < 3; i++)
					{
						gendaiBossBullet[i].isShot = false;
					}
					gendaiBossLife = 120;
					gendaiboss.pos.x = 800.0f;
					gendaiboss.pos.y = 300.0f;
				}
			}
#pragma endregion
			break;
		case SENGOKU:
        #pragma region 戦国時代
			if (isGameOver == false)
			{
				
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;

				//当たり判定
				if ((sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}

				if (
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
					(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}



				if (
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}

				if (
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13) ||
					(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}


				if (
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(sengokuMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13)
					) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//ダメージ判定
				if (playerIsAlive)
				{
					if (
						(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
						(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
						(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
						(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16) ||
						(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(sengokuMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
						(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
						(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
						(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16) ||
						(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(sengokuMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 15) ||
						(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 15) ||
						(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 16) ||
						(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 16) ||
						(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 15) ||
						(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 15) ||
						(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 16) ||
						(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 16) ||
						(sengokuMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(sengokuMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
				}
               
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
				playerScreenPosX = player.pos.x - scrollX;
				if (playerScreenPosX + 32.0f >= redLinePosX) {
					scrollX = player.pos.x + 32.0f - redLinePosX;
				}

				if (playerScreenPosX <= greenLinePosX) {
					scrollX = player.pos.x - greenLinePosX;
				}

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 2560.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 800.0f) {
					isGameOver = true;
				}
				//画面右端に到達で次のステージに移動
				if (player.pos.x > 2550.0f)
				{
					currentScene = SENGOKU2;
					player.pos.x = 32.0f;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
                #pragma region 大砲の処理
				cannonIsShotTimer++;
				if (cannonIsShotTimer == 180)
				{
					for (int i = 0; i < 10; i++)
					{
						if (cannonIsShot[i] == false)
						{
							cannonIsShotTimer = 0;
							cannonIsShot[i] = true;
							cannonGravityY = 0.1f;
							cannonUpPower = -10.0f;
						}
					}
				}
				for (int i = 0; i < 10; i++)
				{
					if (cannonIsShot[i])
					{
						cannonUpPower += cannonGravityY;
						cannonPosY[i] += cannonUpPower;
						cannonPosX[i] += cannonSpeedX[i];
						if (cannonPosY[i] > 1000.0f)
						{
							cannonIsShot[i] = false;
						}
					} else
					{
						cannonGravityY = 0.0f;
						cannonPosX[0] = 192.0f;
						cannonPosX[1] = 448.0f;
						cannonPosX[2] = 576.0f;
						cannonPosX[3] = 1216.0f;
						cannonPosX[4] = 1728.0f;
						cannonPosX[5] = 1792.0f;
						cannonPosX[6] = 1728.0f;
						cannonPosX[7] = 1792.0f;
						cannonPosX[8] = 2240.0f;
						cannonPosX[9] = 2368.0f;
						cannonPosY[0] = 320.0f;
						cannonPosY[1] = 256.0f;
						cannonPosY[2] = 256.0f;
						cannonPosY[3] = 320.0f;
						cannonPosY[4] = 192.0f;
						cannonPosY[5] = 192.0f;
						cannonPosY[6] = 448.0f;
						cannonPosY[7] = 448.0f;
						cannonPosY[8] = 280.0f;
						cannonPosY[9] = 280.0f;
					}
					playerTocannonBulletX = player.pos.x - (cannonPosX[i] + 32.0f);
					playerTocannonBulletY = player.pos.y - (cannonPosY[i] + 32.0f);
					playerTocannonBulletXY = sqrtf(playerTocannonBulletX * playerTocannonBulletX + playerTocannonBulletY * playerTocannonBulletY);
					if (playerIsAlive && cannonIsShot)
					{
						if (playerTocannonBulletXY < playerRadiusX + 16.0f)
						{
							playerLife--;
							playerIsAlive = false;
						}
					}
				}
				//戦国プレイヤーの攻撃
				if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
				{
					if (platerSlashIsAlive == false)
					{
						platerSlashIsAlive = true;
						playerSlashPosX = player.pos.x;
						playerSlashPosY = player.pos.y;
						if (playerDirection)
						{
							playerSlashSpeedX = 7.0f;
							playerSlashDirection = true;
						}
						else
						{
							playerSlashSpeedX = -7.0f;
							playerSlashDirection = false;
						}
					}
				}
				if (platerSlashIsAlive)
				{
					playerSlashIsAliveTimer++;
					playerSlashPosX += playerSlashSpeedX;
					if (playerSlashIsAliveTimer == 120)
					{
						playerSlashIsAliveTimer = 0;
						platerSlashIsAlive = false;
					}
				}
				else
				{
					playerSlashPosX = 0.0f;
					playerSlashPosY = 0.0f;
				}
#pragma endregion
			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 32.0f;
					player.pos.y = 500.0f;
					playerLife = 3;
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		case SENGOKU2:
        #pragma region 戦国時代2
			if (isGameOver == false)
			{
				
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;

				//当たり判定
				if ((sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}

				if (
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
					(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}



				if (
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}

				if (
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13) ||
					(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}


				if (
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 22) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 23) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(sengokuMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13)
					) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//ダメージ判定
				if (playerIsAlive)
				{
					if (
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21) ||
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(sengokuMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21) ||
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(sengokuMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 15) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 15) ||
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 21) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 21) ||
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14) ||
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 15) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 15) ||
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 21) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 21) ||
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14) ||
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(sengokuMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(sengokuMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
				playerScreenPosX = player.pos.x - scrollX;
				if (playerScreenPosX + 32.0f >= redLinePosX) {
					scrollX = player.pos.x + 32.0f - redLinePosX;
				}

				if (playerScreenPosX <= greenLinePosX) {
					scrollX = player.pos.x - greenLinePosX;
				}

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 2560.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 800.0f) {
					isGameOver = true;
				}
				//画面左端に到達で前のステージに移動
				if (player.pos.x < 10.0f)
				{
					currentScene = SENGOKU;
					player.pos.x = 2528.0f;
					player.pos.y = 500.0f;
				}
				//画面右端に到達で次のステージに移動
				if (player.pos.x > 2550.0f)
				{
					currentScene = SENGOKU3;
					player.pos.x = 32.0f;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
            #pragma region 大砲の処理
				cannon2IsShotTimer++;
				if (cannon2IsShotTimer==120)
				{
					for (int i = 0; i < 2; i++)
					{
						if (cannon2IsShot[i] == false)
						{
							cannon2IsShotTimer = 0;
							cannon2IsShot[i] = true;
						}
					}
				}
				for (int i = 0; i < 2; i++)
				{
					if (cannon2IsShot[0])
					{
						cannon2PosX[0] += cannon2SpeedX;
						if (cannon2PosX[0] < -50.0f)
						{
							cannon2IsShot[0] = false;
						}
					}
					else
					{
						cannon2PosX[0] = 704.0f;
						cannon2PosY[0] = 512.0f;
					}
					if (cannon2IsShot[1])
					{
						cannon2PosX[1] += cannon2SpeedX;
						if (cannon2PosX[1] < -50.0f)
						{
							cannon2IsShot[1] = false;
						}
					} else
					{
						cannon2PosX[1] = 960.0f;
						cannon2PosY[1] = 384.0f;
					}

					playerTocannon2BulletX = player.pos.x - (cannon2PosX[i] + 32.0f);
					playerTocannon2BulletY = player.pos.y - (cannon2PosY[i] + 32.0f);
					playerTocannon2BulletXY = sqrtf(playerTocannon2BulletX * playerTocannon2BulletX + playerTocannon2BulletY * playerTocannon2BulletY);
					if (playerIsAlive && cannon2IsShot[i])
					{
						if (playerTocannon2BulletXY < playerRadiusX + 16.0f)
						{
							playerLife--;
							playerIsAlive = false;
						}
					}
				}
				//戦国プレイヤーの攻撃
				if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
				{
					if (platerSlashIsAlive == false)
					{
						platerSlashIsAlive = true;
						playerSlashPosX = player.pos.x;
						playerSlashPosY = player.pos.y;
						if (playerDirection)
						{
							playerSlashSpeedX = 7.0f;
							playerSlashDirection = true;
						} else
						{
							playerSlashSpeedX = -7.0f;
							playerSlashDirection = false;
						}
					}
				}
				if (platerSlashIsAlive)
				{
					playerSlashIsAliveTimer++;
					playerSlashPosX += playerSlashSpeedX;
					if (playerSlashIsAliveTimer == 120)
					{
						playerSlashIsAliveTimer = 0;
						platerSlashIsAlive = false;
					}
				} else
				{
					playerSlashPosX = 0.0f;
					playerSlashPosY = 0.0f;
				}
#pragma endregion

			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 32.0f;
					player.pos.y = 450.0f;
					playerLife = 3;
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		case SENGOKU3:
        #pragma region 戦国時代3
			if (isGameOver == false)
			{
				
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;

				//当たり判定
				if ((sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}

				if (
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13) ||
					(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}



				if (
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 13)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}

				if (
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13) ||
					(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 13)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}


				if (
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 5) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 22) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 23) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 13) ||
					(sengokuMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 13)
					) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//ダメージ判定
				if (playerIsAlive)
				{
					if (
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21) ||
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(sengokuMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21) ||
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(sengokuMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 15) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 15) ||
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 21) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 21) ||
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 14) ||
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 15) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 15) ||
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 21) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 21) ||
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 14) ||
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(sengokuMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(sengokuMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
				playerScreenPosX = player.pos.x - scrollX;
				if (playerScreenPosX + 32.0f >= redLinePosX) {
					scrollX = player.pos.x + 32.0f - redLinePosX;
				}

				if (playerScreenPosX <= greenLinePosX) {
					scrollX = player.pos.x - greenLinePosX;
				}

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 2560.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 800.0f) {
					isGameOver = true;
				}
				//画面左端に到達で前のステージに移動
				if (player.pos.x < 10.0f)
				{
					currentScene = SENGOKU2;
					player.pos.x = 2528.0f;
				}
				//画面右端に到達で次のステージに移動
				if (player.pos.x > 2550.0f)
				{
					currentScene = SENGOKUBOSS;
					player.pos.x = 32.0f;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
#pragma region 大砲の処理
				blackCannonIsShotTimer++;
				if (blackCannonIsShotTimer == 120)
				{
					for (int i = 0; i < 5; i++)
					{
						if (blackCannonIsShot[i] == false)
						{
							blackCannonIsShotTimer = 0;
							blackCannonIsShot[i] = true;
						}
					}
				}
				if (blackCannonIsShot[0])
				{
					blackCannonPosX[0] += blackCannonSpeedX[0];
					if (blackCannonPosX[0] < 0.0f)
					{
						blackCannonIsShot[0] = false;
					}
				}
				else
				{
					blackCannonPosX[0] = 384.0f;
					blackCannonPosY[0] = 512.0f;
				}
				if (blackCannonIsShot[1])
				{
					blackCannonPosX[1] += blackCannonSpeedX[1];
					if (blackCannonPosX[1] < 0.0f)
					{
						blackCannonIsShot[1] = false;
					}
				} else
				{
					blackCannonPosX[1] = 576.0f;
					blackCannonPosY[1] = 448.0f;
				}
				if (blackCannonIsShot[2])
				{
					blackCannonPosX[2] += blackCannonSpeedX[2];
					if (blackCannonPosX[2] < 0.0f)
					{
						blackCannonIsShot[2] = false;
					}
				}
				else
				{
					blackCannonPosX[2] = 704.0f;
					blackCannonPosY[2] = 320.0f;
				}
				if (blackCannonIsShot[3])
				{
					blackCannonPosX[3] += blackCannonSpeedX[3];
					if (blackCannonPosX[3] > 2560.0f)
					{
						blackCannonIsShot[3] = false;
					}
				} 
				else
				{
					blackCannonPosX[3] = 1600.0f;
					blackCannonPosY[3] = 512.0f;
				}
				if (blackCannonIsShot[4])
				{
					blackCannonPosX[4] += blackCannonSpeedX[4];
					if (blackCannonPosX[4] > 2560.0f)
					{
						blackCannonIsShot[4] = false;
					}
				} 
				else
				{
					blackCannonPosX[4] = 2048.0f;
					blackCannonPosY[4] = 384.0f;
				}
				
				for (int i = 0; i < 5; i++)
				{
					blackCannonToPlayerX = player.pos.x - (blackCannonPosX[i] + 32.0f);
					blackCannonToPlayerY = player.pos.y - (blackCannonPosY[i] + 32.0f);
					blackCannonToPlayerXY = sqrtf(blackCannonToPlayerX * blackCannonToPlayerX + blackCannonToPlayerY * blackCannonToPlayerY);
					if (playerIsAlive && blackCannonIsShot[i])
					{
						if (blackCannonToPlayerXY < playerRadiusX + 16.0f)
						{
							playerLife--;
							playerIsAlive = false;
						}
					}
				}

#pragma region 大砲の処理
				redCannonIsShotTimer++;
				if (redCannonIsShotTimer == 180)
				{
					for (int i = 0; i < 5; i++)
					{
						if (redCannonIsShot[i] == false)
						{
							redCannonIsShotTimer = 0;
							redCannonIsShot[i] = true;
							redCannonGravityY = 0.1f;
							redCannonUpPower = -10.0f;
						}
					}
				}
				for (int i = 0; i < 5; i++)
				{
					if (redCannonIsShot[i])
					{
						redCannonUpPower += redCannonGravityY;
						redCannonPosY[i] += redCannonUpPower;
						redCannonPosX[i] += redCannonSpeedX[i];
						if (redCannonPosY[i] > 1000.0f)
						{
							redCannonIsShot[i] = false;
						}
					} else
					{
						redCannonGravityY = 0.0f;
						redCannonPosX[0] = 704.0f;
						redCannonPosX[1] = 768.0f;
						redCannonPosX[2] = 1408.0f;
						redCannonPosX[3] = 1856.0f;
						redCannonPosX[4] = 2496.0f;
						redCannonPosY[0] = 0.0f;
						redCannonPosY[1] = 0.0f;
						redCannonPosY[2] = 0.0f;
						redCannonPosY[3] = 64.0f;
						redCannonPosY[4] = 0.0f;
					}
					redCannonToPlayerX = player.pos.x - (redCannonPosX[i] + 32.0f);
					redCannonToPlayerY = player.pos.y - (redCannonPosY[i] + 32.0f);
					redCannonToPlayerXY = sqrtf(redCannonToPlayerX * redCannonToPlayerX + redCannonToPlayerY * redCannonToPlayerY);
					if (playerIsAlive && redCannonIsShot[i])
					{
						if (redCannonToPlayerXY < playerRadiusX + 16.0f)
						{
							playerLife--;
							playerIsAlive = false;
						}
					}
				}
				//戦国プレイヤーの攻撃
				if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
				{
					if (platerSlashIsAlive == false)
					{
						platerSlashIsAlive = true;
						playerSlashPosX = player.pos.x;
						playerSlashPosY = player.pos.y;
						if (playerDirection)
						{
							playerSlashSpeedX = 7.0f;
							playerSlashDirection = true;
						} else
						{
							playerSlashSpeedX = -7.0f;
							playerSlashDirection = false;
						}
					}
				}
				if (platerSlashIsAlive)
				{
					playerSlashIsAliveTimer++;
					playerSlashPosX += playerSlashSpeedX;
					if (playerSlashIsAliveTimer == 120)
					{
						playerSlashIsAliveTimer = 0;
						platerSlashIsAlive = false;
					}
				} else
				{
					playerSlashPosX = 0.0f;
					playerSlashPosY = 0.0f;
				}
#pragma endregion
#pragma endregion
			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 32.0f;
					player.pos.y = 450.0f;
					playerLife = 3;
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		case SENGOKUBOSS:
        #pragma region 戦国ボス
				if (isGameOver == false)
				{
					if (playerJumpCount != 0)
					{
						if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
							player.velocity.y = playerJumpPower;
						}
					}
					if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
						player.velocity.y /= 2.0f;
					}
					if (keys[DIK_A] || keys[DIK_LEFT]) {
						player.velocity.x -= playerSpeed;
						playerDirection = false;
					} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
						playerDirection = true;
						player.velocity.x += playerSpeed;
					} else {
						player.velocity.x = 0.0f;
					}
					player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
					player.pos.x += player.velocity.x;

					if (!player.isOnGround) {
						player.velocity.y += playerGravity;
					}
					player.pos.y += player.velocity.y;
                    #pragma region 戦国ボス処理
					if (sengokuBossIsAlive)
					{
						sengokuboss.speed = 0;

						sengokuboss.velocity.y += sengokuboss.gravity;
						sengokuboss.pos.y += sengokuboss.velocity.y;

						if (player.pos.x < sengokuboss.pos.x)
						{
							sengokubossDirection = BACK;
						} else
						{
							sengokubossDirection = FRONT;
						}

						if (!sengokuboss.isAction && sengokuboss.actionCoolTime <= 80)
						{
							sengokuboss.actionCoolTime++;
						}

						if (sengokuboss.actionCoolTime >= 50)
						{
							sengokuboss.action = static_cast<int>(rand() % 10);
							sengokuboss.actionCoolTime = 0;
							sengokuboss.isAction = true;
						}

						if (sengokuboss.isAction)
						{
							if (sengokuboss.action <= 1)
							{
								sengokuActionDoTime++;
								sengokuboss.speed = 5.0f;
								if (sengokuboss.pos.x < player.pos.x)
								{
									sengokuboss.pos.x += sengokuboss.speed;
								} else
								{
									sengokuboss.pos.x -= sengokuboss.speed;
								}

								if (sengokuActionDoTime >= 20)
								{
									sengokuActionDoTime = 0;
									sengokuboss.isAction = false;
								}
							} else if (sengokuboss.action >= 2 && sengokuboss.action <= 9)
							{
								sengokuZangekiAction = true;

								if (sengokuboss.pos.x < player.pos.x)
								{
									sengokuBossZangekiFrontPlayer.x = sengokuboss.pos.x + 64.0f;
									sengokuBossZangekiFrontPlayer.y = sengokuboss.pos.y;
								} else
								{
									sengokuBossZangekiBackPlayer.x = sengokuboss.pos.x - 96.0f;
									sengokuBossZangekiBackPlayer.y = sengokuboss.pos.y;
								}

								if (sengokuZangekiAction)
								{
									sengokuBossActionFlameCount++;
									sengokuBossActionGraphCount = (sengokuBossActionFlameCount / 10) % 8;
								}

								if (sengokuBossActionFlameCount >= 80)
								{
									sengokuBossActionGraphCount = 0;
									sengokuBossActionFlameCount = 0;
									sengokuZangekiAction = false;
									sengokuboss.action = false;
								}
							} else
							{
								sengokuboss.speed = 1.5f;

								sengokuActionDoTime++;

								if (player.pos.x < sengokuboss.pos.x)
								{
									sengokuboss.pos.x -= sengokuboss.speed;
								} else
								{
									sengokuboss.pos.x += sengokuboss.speed;
								}

								if (sengokuActionDoTime >= 100)
								{
									sengokuboss.isAction = false;
									sengokuActionDoTime = 0;
								}
							}
						}

						//プレイヤー同士の当たり判定
						sengokuBossToPlayerX = sengokuboss.pos.x - player.pos.x;
						sengokuBossToPlayerY = sengokuboss.pos.y - player.pos.y;

						hitJudgeSengokuBossToPlayer = sqrtf(sengokuBossToPlayerX * sengokuBossToPlayerX + sengokuBossToPlayerY * sengokuBossToPlayerY);

						if (playerIsAlive)
						{
							if (hitJudgeSengokuBossToPlayer <= sengokuBossRadius + player.radius && playerIsAlive)
							{
								playerIsAlive = false;
								playerLife--;
							}
						}

						//playerToBossAction HItJudge
						if (sengokuZangekiAction)
						{
							if (sengokuboss.pos.x < player.pos.x && playerIsAlive)
							{
								bossZangekiFrontToPlayerX = sengokuBossZangekiFrontPlayer.x - player.pos.x;
								bossZangekiFrontToPlayerY = sengokuBossZangekiFrontPlayer.y - player.pos.y;
								hitJudgeBossZangekiFrontToPlayer = sqrtf(bossZangekiFrontToPlayerX * bossZangekiFrontToPlayerX + bossZangekiFrontToPlayerY * bossZangekiFrontToPlayerY);
								if (playerIsAlive)
								{
									if (hitJudgeBossZangekiFrontToPlayer <= player.radius + sengokuBossZangekiFrontRadius)
									{
										playerIsAlive = false;
										playerLife--;
									}
								}
							} else
							{
								bossZangekiBackToPlayerX = sengokuBossZangekiBackPlayer.x - player.pos.x;
								bossZangekiBackToPlayerY = sengokuBossZangekiBackPlayer.y - player.pos.y;
								hitJudgeBossZangekiBackToPlayer = sqrtf(bossZangekiBackToPlayerX * bossZangekiBackToPlayerX + bossZangekiBackToPlayerY * bossZangekiBackToPlayerY);
								if (playerIsAlive)
								{
									if (hitJudgeBossZangekiBackToPlayer <= player.radius + sengokuBossZangekiBackRadius)
									{
										playerIsAlive = false;
										playerLife--;
									}
								}
							}
						}
					}
					//ボスのアニメーション処理
					sengokuBossGraphCount++;
					sengokuBossMoveCount = (sengokuBossGraphCount / 10) % 4;

					if (sengokuBossGraphCount > 40)
					{
						sengokuBossGraphCount = 0;
					}
					//ボスのマップチップとの当たり判定
							if (sengokuboss.velocity.y > 0.0f) {
								if ((sengokuBoss[int((sengokuboss.pos.y + 32.0f) / 64.0f)][int((sengokuboss.pos.x - 20.0f) / 64.0f)] != 0) ||
									(sengokuBoss[int((sengokuboss.pos.y + 32.0f) / 64.0f)][int((sengokuboss.pos.x + 20.0f) / 64.0f)] != 0)) {
									sengokuboss.pos.y = (int(sengokuboss.pos.y / 64.0f) * 64.0f) + 32.0f;
									sengokuboss.velocity.y = 0.0f;
									playerJumpCount = 2;
								}
							} else if (sengokuboss.velocity.y < 0.0f) {
								if ((sengokuBoss[int((sengokuboss.pos.y - 30.0f) / 64.0f)][int((sengokuboss.pos.x - 20.0f) / 64.0f)] != 0) ||
									(sengokuBoss[int((sengokuboss.pos.y - 30.0f) / 64.0f)][int((sengokuboss.pos.x + 20.0f) / 64.0f)] != 0)) {
									sengokuboss.pos.y = (int(sengokuboss.pos.y / 64.0f) * 64.0f) + 32.0f;
									sengokuboss.velocity.y = 0.0f;
									playerJumpCount = 2;
								}
							}

							if (sengokuboss.velocity.x > 0.0f) {
								if ((sengokuBoss[int((sengokuboss.pos.y - 32.0f) / 64.0f)][int((sengokuboss.pos.x + 33.0f) / 64.0f)] != 0) ||
									(sengokuBoss[int((sengokuboss.pos.y + 31.0f) / 64.0f)][int((sengokuboss.pos.x + 33.0f) / 64.0f)] != 0)) {
									sengokuboss.pos.x = (int(sengokuboss.pos.x / 64.0f) * 64.0f) + 32.0f;
									sengokuboss.velocity.x = 0.0f;
								}
							} else if (sengokuboss.velocity.x < 0.0f) {
								if ((sengokuBoss[int((sengokuboss.pos.y - 32.0f) / 64.0f)][int((sengokuboss.pos.x - 33.0f) / 64.0f)] != 0) ||
									(sengokuBoss[int((sengokuboss.pos.y + 31.0f) / 64.0f)][int((sengokuboss.pos.x - 33.0f) / 64.0f)] != 0)) {
									sengokuboss.pos.x = (int(sengokuboss.pos.x / 64.0f) * 64.0f) + 32.0f;
									sengokuboss.velocity.x = 0.0f;
								}
							}
#pragma endregion
				
							if (player.velocity.y > 0.0f) {
								if ((sengokuBoss[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] != 0) ||
									(sengokuBoss[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] != 0)) {
									player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
									player.velocity.y = 0.0f;
									playerJumpCount = 2;
								}
							} else if (player.velocity.y < 0.0f) {
								if ((sengokuBoss[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] != 0) ||
									(sengokuBoss[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] != 0)) {
									player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
									player.velocity.y = 0.0f;
									playerJumpCount = 2;
								}
							}

							if (player.velocity.x > 0.0f) {
								if ((sengokuBoss[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] != 0) ||
									(sengokuBoss[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] != 0)) {
									player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
									player.velocity.x = 0.0f;
								}
							} else if (player.velocity.x < 0.0f) {
								if ((sengokuBoss[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] != 0) ||
									(sengokuBoss[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] != 0)) {
									player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
									player.velocity.x = 0.0f;
								}
						
					}
					if ((sengokuBoss[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] != 0) ||
						(sengokuBoss[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] != 0)) {
						player.isOnGround = true;
					} else {
						player.isOnGround = false;
					}
					//::::::::::::::::::::::::::::::::::::::::::::
					//          プレイヤーが赤い線で止まる
					//::::::::::::::::::::::::::::::::::::::::::::

					scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
					player.pos.x = Clamp(player.pos.x, 0.0f, 1280.0f);
					player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
					//::::::::::::::::::::::::::::::::::::::::::::::::
					//                  ラインの固定
					//::::::::::::::::::::::::::::::::::::::::::::::::
					if (redLinePosX >= windowRight) {
						redLinePosX = windowRight;
					}
					if (greenLinePosX <= windowLeft) {
						greenLinePosX = windowLeft;
					}
					//ゲームオーバー
					if (player.pos.y >= 720.0f) {
						player.pos.x = 10.0f;
						player.pos.y = 100;
						break;
					}
					//実機の向きを保存
					if (keys[DIK_D])
					{
						playerDirection = true;
					}
					if (keys[DIK_A])
					{
						playerDirection = false;
					}
					//実機のジャンプをカウント
					if (preKeys[DIK_W] == 0 && keys[DIK_W])
					{
						playerJumpCount--;
					}
					if (playerJumpCount < 0)
					{
						playerJumpCount = 0;
					}
					//実機のアニメーション処理
					playerFlameCount++;
					playerFlameNumber = (playerFlameCount / 10) % 4;
					if (playerFlameCount > 40)
					{
						playerFlameCount = 0;
					}
					playerMoveFlameCount++;
					playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
					if (playerMoveFlameCount > 30)
					{
						playerMoveFlameCount = 0;
					}
					//実機のHP生死の管理
					if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
					{
						playerLife--;
						playerIsAlive = false;
					}
					if (playerLife == 0)
					{
						isGameOver = true;
					}
					if (playerIsAlive == false)
					{
						playerIsAliveCount--;
						if (playerIsAliveCount == 0)
						{
							playerIsAlive = true;
							playerIsAliveCount = 60;
						}
					}
					//戦国プレイヤーの攻撃
					if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
					{
						if (platerSlashIsAlive == false)
						{
							platerSlashIsAlive = true;
							playerSlashPosX = player.pos.x;
							playerSlashPosY = player.pos.y;
							if (playerDirection)
							{
								playerSlashSpeedX = 7.0f;
								playerSlashDirection = true;
							} else
							{
								playerSlashSpeedX = -7.0f;
								playerSlashDirection = false;
							}
						}
					}
					if (platerSlashIsAlive)
					{
						playerSlashIsAliveTimer++;
						playerSlashPosX += playerSlashSpeedX;
						if (playerSlashIsAliveTimer == 120)
						{
							playerSlashIsAliveTimer = 0;
							platerSlashIsAlive = false;
						}
					} else
					{
						playerSlashIsAliveTimer = 0;
						playerSlashPosX = 0.0f;
						playerSlashPosY = 0.0f;
					}
					playerSlashToBossX = playerSlashPosX - sengokuboss.pos.x;
					playerSlashToBossY = playerSlashPosY - sengokuboss.pos.y;
					playerSlashToBossXY = sqrtf(playerSlashToBossX * playerSlashToBossX + playerSlashToBossY * playerSlashToBossY);
					if (playerSlashToBossXY < 48.0f)
					{
						platerSlashIsAlive = false;
						sengokuBossLife--;
					}
					if (sengokuBossLife < 0)
					{
						sengokuBossIsAlive = false;
					}
					if (sengokuBossIsAlive == false)
					{
						sengokuBossDieFlameCount++;
						sengokuBossDieFlameNumber = (sengokuBossDieFlameCount / 10) % 8;
						if (sengokuBossDieFlameCount > 70)
						{
							sengokuBossDieFlameCount = 70;
						}
						if (sengokuBossDieFlameCount == 70)
						{
							clearPosY += clearSpeed;
							if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
							{
								currentScene = STAGESELECT;
							}
						}
						if (clearPosY > 0.0f)
						{
							clearPosY = 0.0f;
						}
					}
				} else
				{
					if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
					{
						currentScene = SENGOKU3;
						isGameOver = false;
						playerIsAlive = true;
						player.pos.x = 2528.0f;
						player.pos.y = 300.0f;
						playerLife = 3;
						sengokuboss.pos.x = 800.0f;
						sengokuboss.pos.y = 500.0f;
						sengokuBossLife = 20;
					}
					if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
					{
						currentScene = STAGESELECT;
					}
				}
#pragma endregion
			break;
		case ZYOUMON:
        #pragma region 縄文時代
			if (isGameOver == false)
			{
				
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;

				//当たり判定
				if ((zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
					(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}

				if (
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21) ||
					(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}



				if (
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 21) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 21)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}

				if (
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 21) ||
					(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 21)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}


				if (
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
					(zyoumonMap[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21)
					) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//ダメージ判定
				if (playerIsAlive)
				{
					if (
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
						(zyoumonMap[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
						(zyoumonMap[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 16) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 16) ||
						(zyoumonMap[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
				playerScreenPosX = player.pos.x - scrollX;
				if (playerScreenPosX + 32.0f >= redLinePosX) {
					scrollX = player.pos.x + 32.0f - redLinePosX;
				}

				if (playerScreenPosX <= greenLinePosX) {
					scrollX = player.pos.x - greenLinePosX;
				}

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 2560.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 800.0f) {
					isGameOver = true;
				}
				//画面右端に到達で次のステージに移動
				if (player.pos.x > 2550.0f)
				{
					currentScene = ZYOUMON2;
					player.pos.x = 32.0f;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
				//落石 投石 弓 処理
				for (int i = 0; i < 10; i++)
				{
					if (rakuseki1PosY[i] < 0.0f)
					{
						rakuseki1SpeedY[i] = 5.0f;
					} else
					{
						rakuseki1SpeedY[i] = 15.0f;
					}
					rakuseki1PosY[i] += rakuseki1SpeedY[i];
					if (rakuseki1PosY[i] > 720.0f)
					{
						rakuseki1PosY[i] = -100.0f;
					}
					rakuseki1ToPlayerX = player.pos.x - (rakuseki1PosX[i] + 32.0f);
					rakuseki1ToPlayerY = player.pos.y - (rakuseki1PosY[i] + 32.0f);
					rakuseki1ToPlayerXY = sqrtf(rakuseki1ToPlayerX * rakuseki1ToPlayerX + rakuseki1ToPlayerY * rakuseki1ToPlayerY);
					if (playerIsAlive)
					{
						if (rakuseki1ToPlayerXY < playerRadiusX + 32.0f)
						{
							playerIsAlive = false;
							playerLife--;
						}
					}
				}

				tousekiIsAliveTimer++;
				for (int i = 0; i < 2; i++)
				{
					tousekiSpeedX[0] = -9.0f;
					tousekiSpeedX[1] = -10.0f;
					if (tousekiIsAliveTimer == 150)
					{
						tousekiIsAliveTimer = 0;
						tousekiIsAlive[0] = true;
						tousekiIsAlive[1] = true;
						tousekiUp = -10.0f;
					}
					if (tousekiIsAlive[0])
					{
						touseki1PosX[0] += tousekiSpeedX[0];
						tousekiUp += tousekiGravity;
						touseki1PosY[0] += tousekiUp;
						if (touseki1PosY[0] > 720.0f)
						{
							tousekiIsAlive[0] = false;
						}
					}
					else
					{
						touseki1PosX[0] = 1280.0f;
						touseki1PosY[0] = 512.0f;
					}
					if (tousekiIsAlive[1])
					{
						touseki1PosX[1] += tousekiSpeedX[1];
						tousekiUp += tousekiGravity;
						touseki1PosY[1] += tousekiUp;
						if (touseki1PosY[1] > 720.0f)
						{
							tousekiIsAlive[1] = false;
						}
					} else
					{
						touseki1PosX[1] = 1984.0f;
						touseki1PosY[1] = 512.0f;
					}
					touseki1ToPlayerX = player.pos.x - (touseki1PosX[i] + 32.0f);
					touseki1ToPlayerY = player.pos.y - (touseki1PosY[i] + 32.0f);
					touseki1ToPlayerXY = sqrtf(touseki1ToPlayerX * touseki1ToPlayerX + touseki1ToPlayerY * touseki1ToPlayerY);
					if (playerIsAlive)
					{
						if (touseki1ToPlayerXY < playerRadiusX + 32.0f)
						{
							playerIsAlive = false;
							playerLife--;
						}
					}
				}
				if (yari1IsAlive)
				{
					yari1PosX += yari1SpeedX;
					if (yari1PosX < 0.0f)
					{
						yari1IsAlive = false;
					}
				}
				else
				{
					yari1IsAliveTimer++;
					yari1PosX = 1408.0f;
					yari1PosY = 320.0f;
					if (yari1IsAliveTimer == 120)
					{
						yari1IsAliveTimer = 0;
						yari1IsAlive = true;
					}
				}
				if (playerIsAlive)
				{
					yari1ToPlayerX = player.pos.x - (yari1PosX + 32.0f);
					yari1ToPlayerY = player.pos.y - (yari1PosY + 32.0f);
					yari1ToPlayerXY = sqrtf(yari1ToPlayerX * yari1ToPlayerX + yari1ToPlayerY * yari1ToPlayerY);
					if (yari1ToPlayerXY < playerRadiusX + 32.0f)
					{
						playerIsAlive = false;
						playerLife--;
					}
				}
				if (zyomonBulletIsAlive)
				{
					zyomonBulletPosX += zyomonBulletSpeedX;
					zyomonBulletIsAliveTimer++;
					if (zyomonBulletIsAliveTimer == 120)
					{
						zyomonBulletIsAliveTimer = 0;
						zyomonBulletIsAlive = false;
					}
				}
				else
				{
					zyomonBulletPosX = player.pos.x;
					zyomonBulletPosY = player.pos.y;
					if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
					{
						zyomonBulletIsAlive = true;
						if (playerDirection)
						{
							zyomonBulletSpeedX = 20.0f;
						}
						else
						{
							zyomonBulletSpeedX = -20.0f;
						}
					}
				}
			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 32.0f;
					player.pos.y = 500.0f;
					playerLife = 3;
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		case ZYOUMON2:
        #pragma region 縄文時代2
			if (isGameOver == false)
			{
				
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;

				//当たり判定
				if ((zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
					(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}

				if (
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21) ||
					(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}



				if (
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 21) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 21)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}

				if (
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 21) ||
					(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 21)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}


				if (
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
					(zyoumonMap2[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21)
					) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//ダメージ判定
				if (playerIsAlive)
				{
					if (
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
						(zyoumonMap2[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
						(zyoumonMap2[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 16) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap2[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 16) ||
						(zyoumonMap2[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
				playerScreenPosX = player.pos.x - scrollX;
				if (playerScreenPosX + 32.0f >= redLinePosX) {
					scrollX = player.pos.x + 32.0f - redLinePosX;
				}

				if (playerScreenPosX <= greenLinePosX) {
					scrollX = player.pos.x - greenLinePosX;
				}

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 2560.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 800.0f) {
					isGameOver = true;
				}
				//画面左端に到達で前のステージに移動
				if (player.pos.x < 10.0f)
				{
					currentScene = ZYOUMON;
					player.pos.x = 2528.0f;
				}
				//画面右端に到達で次のステージに移動
				if (player.pos.x > 2550.0f)
				{
					currentScene = ZYOUMON3;
					player.pos.x = 32.0f;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
				//落石 投石 弓 処理
				for (int i = 0; i < 9; i++)
				{
					if (rakuseki2PosY[i] < 0.0f)
					{
						rakuseki2SpeedY[i] = 5.0f;
					} 
					else
					{
						rakuseki2SpeedY[i] = 15.0f;
					}

				rakuseki2PosY[i] += rakuseki2SpeedY[i];
				if (rakuseki2PosY[i] > 720.0f)
					{
						rakuseki2PosY[i] = -100.0f;
					}
				rakuseki2ToPlayerX = player.pos.x - (rakuseki2PosX[i] + 32.0f);
				rakuseki2ToPlayerY = player.pos.y - (rakuseki2PosY[i] + 32.0f);
				rakuseki2ToPlayerXY = sqrtf(rakuseki2ToPlayerX * rakuseki2ToPlayerX + rakuseki2ToPlayerY * rakuseki2ToPlayerY);
				if (playerIsAlive)
				{
					if (rakuseki2ToPlayerXY < playerRadiusX + 32.0f)
					{
						playerIsAlive = false;
						playerLife--;
					}
				}
				}
				
				touseki2SpeedX = -12.0f;
				if (touseki2IsAliveTimer == 150)
				{
					touseki2IsAliveTimer = 0;
					touseki2IsAlive = true;
					touseki2Up = -9.0f;
				}
				if (touseki2IsAlive)
				{
					touseki2PosX += touseki2SpeedX;
					touseki2Up += touseki2Gravity;
					touseki2PosY += touseki2Up;
					if (touseki2PosY > 720.0f)
					{
						touseki2IsAlive = false;
					}
				} 
				else
				{
					touseki2IsAliveTimer++;
					touseki2PosX = 1920.0f;
					touseki2PosY = 512.0f;
				}
				touseki2ToPlayerX = player.pos.x - (touseki2PosX + 32.0f);
				touseki2ToPlayerY = player.pos.y - (touseki2PosY + 32.0f);
				touseki2ToPlayerXY = sqrtf(touseki2ToPlayerX * touseki2ToPlayerX + touseki2ToPlayerY * touseki2ToPlayerY);
				if (playerIsAlive)
				{
					if (touseki2ToPlayerXY < playerRadiusX + 32.0f)
					{
						playerIsAlive = false;
						playerLife--;
					}
				}
				if(yari2LeftIsAlive[0])
				{
					yari2LeftPosX[0] += yari2LeftSpeedX;
					if (yari2LeftPosX[0] < 0.0f)
					{
						yari2LeftIsAlive[0] = false;
					}
				}
				else
				{
					yari2LeftPosX[0] = 640.0f;
					yari2LeftPosY[0] = 384.0f;
					yari2LeftIsAliveTimer[0]++;
					if (yari2LeftIsAliveTimer[0] == 120)
					{
						yari2LeftIsAliveTimer[0] = 0;
						yari2LeftIsAlive[0] = true;
					}
				}
				if (yari2LeftIsAlive[1])
				{
					yari2LeftPosX[1] += yari2LeftSpeedX;
					if (yari2LeftPosX[1] < 0.0f)
					{
						yari2LeftIsAlive[1] = false;
					}
				} 
				else
				{
					yari2LeftPosX[1] = 960.0f;
					yari2LeftPosY[1] = 320.0f;
					yari2LeftIsAliveTimer[1]++;
					if (yari2LeftIsAliveTimer[1] == 120)
					{
						yari2LeftIsAliveTimer[1] = 0;
						yari2LeftIsAlive[1] = true;
					}
				}
				if (yari2RightIsAlive[0])
				{
					yari2RightPosX[0] += yari2RightSpeedX;
					if (yari2RightPosX[0] > 2560.0f)
					{
						yari2RightIsAlive[0] = false;
					}
				}
				else
				{
					yari2RightPosX[0] = 1344.0f;
					yari2RightPosY[0] = 384.0f;
					yari2RightIsAliveTimer[0]++;
					if (yari2RightIsAliveTimer[0] == 120)
					{
						yari2RightIsAliveTimer[0] = 0;
						yari2RightIsAlive[0] = true;
					}
				}
				if (yari2RightIsAlive[1])
				{
					yari2RightPosX[1] += yari2RightSpeedX;
					if (yari2RightPosX[1] > 2560.0f)
					{
						yari2RightIsAlive[1] = false;
					}
				} else
				{
					yari2RightPosX[1] = 1408.0f;
					yari2RightPosY[1] = 448.0f;
					yari2RightIsAliveTimer[1]++;
					if (yari2RightIsAliveTimer[1] == 120)
					{
						yari2RightIsAliveTimer[1] = 0;
						yari2RightIsAlive[1] = true;
					}
				}
				for (int i = 0; i < 2; i++)
				{
					yari2RightToPlayerX = player.pos.x - (yari2RightPosX[i] + 32.0f);
					yari2RightToPlayerY = player.pos.y - (yari2RightPosY[i] + 32.0f);
					yari2RightToPlayerXY = sqrtf(yari2RightToPlayerX * yari2RightToPlayerX + yari2RightToPlayerY * yari2RightToPlayerY);
					yari2LeftToPlayerX = player.pos.x - (yari2LeftPosX[i] + 32.0f);
					yari2LeftToPlayerY = player.pos.y - (yari2LeftPosY[i] + 32.0f);
					yari2LeftToPlayerXY = sqrtf(yari2LeftToPlayerX * yari2LeftToPlayerX + yari2LeftToPlayerY * yari2LeftToPlayerY);
					if(playerIsAlive)
					{
						if (yari2RightToPlayerXY < playerRadiusX + 32.0f || yari2LeftToPlayerXY < playerRadiusX + 32.0f)
						{
							playerIsAlive = false;
							playerLife--;
						}
					}
				}
				if (zyomonBulletIsAlive)
				{
					zyomonBulletPosX += zyomonBulletSpeedX;
					zyomonBulletIsAliveTimer++;
					if (zyomonBulletIsAliveTimer == 120)
					{
						zyomonBulletIsAliveTimer = 0;
						zyomonBulletIsAlive = false;
					}
				} else
				{
					zyomonBulletPosX = player.pos.x;
					zyomonBulletPosY = player.pos.y;
					if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
					{
						zyomonBulletIsAlive = true;
						if (playerDirection)
						{
							zyomonBulletSpeedX = 20.0f;
						} else
						{
							zyomonBulletSpeedX = -20.0f;
						}
					}
				}
			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 32.0f;
					player.pos.y = 400.0f;
					playerLife = 3;
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		case ZYOUMON3:
        #pragma region 縄文時代3
			if (isGameOver == false)
			{
				
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;

				//当たり判定
				if ((zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
					(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}

				if (
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21) ||
					(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21)
					) {
					player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
					player.velocity.y = 0.0f;
					playerJumpCount = 2;
				}



				if (
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 21) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] == 21)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}

				if (
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 11) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 21) ||
					(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] == 21)
					) {
					player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
					player.velocity.x = 0.0f;
				}


				if (
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 1) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 2) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 4) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 10) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 11) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 14) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 15) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 17) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 18) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 19) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 20) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 21) ||
					(zyoumonMap3[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 21)
					) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//ダメージ判定
				if (playerIsAlive)
				{
					if (
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
						(zyoumonMap3[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 3) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 6) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 7) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 8) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 9) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] == 16) ||
						(zyoumonMap3[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 16) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 5.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					} else if (
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 3) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 6) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 7) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 8) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 9) ||
						(zyoumonMap3[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 16) ||
						(zyoumonMap3[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 5.0f) / 64.0f)] == 16)
						) {
						playerIsAlive = false;
						playerLife = playerLife - 1;
					}
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
				playerScreenPosX = player.pos.x - scrollX;
				if (playerScreenPosX + 32.0f >= redLinePosX) {
					scrollX = player.pos.x + 32.0f - redLinePosX;
				}

				if (playerScreenPosX <= greenLinePosX) {
					scrollX = player.pos.x - greenLinePosX;
				}

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 2560.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 800.0f) {
					isGameOver = true;
				}
				//画面左端に到達で前のステージに移動
				if (player.pos.x < 10.0f)
				{
					currentScene = ZYOUMON2;
					player.pos.x = 2528.0f;
				}
				//画面右端に到達で次のステージに移動
				if (player.pos.x > 2550.0f)
				{
					currentScene = ZYOMONBOSS;
					player.pos.x = 32.0f;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
				if (yari3IsAlive[0])
				{
					yari3PosX[0] += yari3SpeedX;
					if (yari3PosX[0] > 1052.0f)
					{
						yari3IsAlive[0] = false;
					}
				} else
				{
					yari3PosX[0] = 192.0f;
					yari3PosY[0] = 256.0f;
					yari3IsAliveTimer[0]++;
					if (yari3IsAliveTimer[0] == 120)
					{
						yari3IsAliveTimer[0] = 0;
						yari3IsAlive[0] = true;
					}
				}
				if (yari3IsAlive[1])
				{
					yari3PosX[1] += yari3SpeedX;
					if (yari3PosX[1] > 1052.0f)
					{
						yari3IsAlive[1] = false;
					}
				} else
				{
					yari3PosX[1] = 256.0f;
					yari3PosY[1] = 320.0f;
					yari3IsAliveTimer[1]++;
					if (yari3IsAliveTimer[1] == 120)
					{
						yari3IsAliveTimer[1] = 0;
						yari3IsAlive[1] = true;
					}
				}
				if (yari3IsAlive[2])
				{
					yari3PosX[2] += yari3SpeedX;
					if (yari3PosX[2] > 1052.0f)
					{
						yari3IsAlive[2] = false;
					}
				} else
				{
					yari3PosX[2] = 320.0f;
					yari3PosY[2] = 384.0f;
					yari3IsAliveTimer[2]++;
					if (yari3IsAliveTimer[2] == 120)
					{
						yari3IsAliveTimer[2] = 0;
						yari3IsAlive[2] = true;
					}
				}
				if (yari3IsAlive[3])
				{
					yari3PosX[3] += yari3SpeedX;
					if (yari3PosX[3] > 1052.0f)
					{
						yari3IsAlive[3] = false;
					}
				} else
				{
					yari3PosX[3] = 384.0f;
					yari3PosY[3] = 448.0f;
					yari3IsAliveTimer[3]++;
					if (yari3IsAliveTimer[3] == 120)
					{
						yari3IsAliveTimer[3] = 0;
						yari3IsAlive[3] = true;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					yari3ToPlayerX = player.pos.x - (yari3PosX[i] + 32.0f);
					yari3ToPlayerY = player.pos.y - (yari3PosY[i] + 32.0f);
					yari3ToPlayerXY = sqrtf(yari3ToPlayerX * yari3ToPlayerX + yari3ToPlayerY * yari3ToPlayerY);
					if (playerIsAlive)
					{
						if (yari3ToPlayerXY < playerRadiusX + 32.0f)
						{
							playerIsAlive = false;
							playerLife--;
						}
					}
				}
				for (int i = 0; i < 10; i++)
				{
					if (rakuseki3PosY[i] < 0.0f)
					{
						rakuseki3SpeedY[i] = 5.0f;
					} else
					{
						rakuseki3SpeedY[i] = 15.0f;
					}
					rakuseki3PosY[i] += rakuseki3SpeedY[i];
					if (rakuseki3PosY[i] > 720.0f)
					{
						rakuseki3PosY[i] = -200.0f;
					}
					rakuseki3ToPlayerX = player.pos.x - (rakuseki3PosX[i] + 32.0f);
					rakuseki3ToPlayerY = player.pos.y - (rakuseki3PosY[i] + 32.0f);
					rakuseki3ToPlayerXY = sqrtf(rakuseki3ToPlayerX * rakuseki3ToPlayerX + rakuseki3ToPlayerY * rakuseki3ToPlayerY);
					if (playerIsAlive)
					{
						if (rakuseki3ToPlayerXY < playerRadiusX + 32.0f)
						{
							playerIsAlive = false;
							playerLife--;
						}
					}
				}
				touseki3SpeedX = -14.0f;
				if (touseki3IsAliveTimer == 150)
				{
					touseki3IsAliveTimer = 0;
					touseki3IsAlive = true;
					touseki3Up = -9.0f;
				}
				if (touseki3IsAlive)
				{
					touseki3PosX += touseki3SpeedX;
					touseki3Up += touseki3Gravity;
					touseki3PosY += touseki3Up;
					if (touseki3PosY > 720.0f)
					{
						touseki3IsAlive = false;
					}
				} else
				{
					touseki3IsAliveTimer++;
					touseki3PosX = 2240.0f;
					touseki3PosY = 512.0f;
				}
				touseki3ToPlayerX = player.pos.x - (touseki3PosX + 32.0f);
				touseki3ToPlayerY = player.pos.y - (touseki3PosY + 32.0f);
				touseki3ToPlayerXY = sqrtf(touseki3ToPlayerX * touseki3ToPlayerX + touseki3ToPlayerY * touseki3ToPlayerY);
				if (playerIsAlive)
				{
					if (touseki3ToPlayerXY < playerRadiusX + 32.0f)
					{
						playerIsAlive = false;
						playerLife--;
					}
				}
				if (zyomonBulletIsAlive)
				{
					zyomonBulletPosX += zyomonBulletSpeedX;
					zyomonBulletIsAliveTimer++;
					if (zyomonBulletIsAliveTimer == 120)
					{
						zyomonBulletIsAliveTimer = 0;
						zyomonBulletIsAlive = false;
					}
				} else
				{
					zyomonBulletPosX = player.pos.x;
					zyomonBulletPosY = player.pos.y;
					if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
					{
						zyomonBulletIsAlive = true;
						if (playerDirection)
						{
							zyomonBulletSpeedX = 20.0f;
						} else
						{
							zyomonBulletSpeedX = -20.0f;
						}
					}
				}
			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 32.0f;
					player.pos.y = 400.0f;
					playerLife = 3;
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		case ZYOMONBOSS:
        #pragma region 縄文ボス
			if (isGameOver == false)
			{
			
				if (playerJumpCount != 0)
				{
					if (keys[DIK_W] != 0 && preKeys[DIK_W] == 0 || keys[DIK_UP] != 0 && preKeys[DIK_UP] == 0) {
						player.velocity.y = playerJumpPower;
					}
				}
				if (!player.isOnGround && (!keys[DIK_W] && preKeys[DIK_W]) && player.velocity.y < 0.0f || !player.isOnGround && (!keys[DIK_UP] && preKeys[DIK_UP]) && player.velocity.y < 0.0f) {
					player.velocity.y /= 2.0f;
				}
				if (keys[DIK_A] || keys[DIK_LEFT]) {
					player.velocity.x -= playerSpeed;
					playerDirection = false;
				} else if (keys[DIK_D] || keys[DIK_RIGHT]) {
					playerDirection = true;
					player.velocity.x += playerSpeed;
				} else {
					player.velocity.x = 0.0f;
				}
				player.velocity.x = Clamp(player.velocity.x, -playerSpeed, playerSpeed);
				player.pos.x += player.velocity.x;

				if (!player.isOnGround) {
					player.velocity.y += playerGravity;
				}
				player.pos.y += player.velocity.y;
                #pragma region 縄文ボス挙動
				//ボス 挙動------------------------------------------------------------------------------------

				zyoumonboss.speed = 0;

				zyoumonboss.velocity.y += zyoumonboss.gravity;
				zyoumonboss.pos.y += zyoumonboss.velocity.y;


				//ボス行動制限

				if (zyoumonboss.pos.y >= 512.0f)
				{

					zyoumonboss.pos.y = 512.0f;

					zyoumonboss.isGround = true;
				} else
				{
					zyoumonboss.isGround = false;
				}

				if (zyoumonboss.hp >= 40)
				{
					if (!zyoumonboss.isAction && zyoumonboss.actionCoolTime <= 70)
					{
						zyoumonboss.actionCoolTime++;
					}
				} else
				{
					if (!zyoumonboss.isAction && zyoumonboss.actionCoolTime <= 50)
					{
						zyoumonboss.actionCoolTime++;
					}
				}


				if (zyoumonboss.hp >= 40)
				{
					if (zyoumonboss.actionCoolTime >= 70)
					{
						zyoumonboss.actionCoolTime = 0;
						zyoumonboss.action = 6; //static_cast<int>(rand() % 10);
						zyoumonboss.isAction = true;
					}
				} else
				{
					if (zyoumonboss.actionCoolTime >= 50)
					{
						zyoumonboss.actionCoolTime = 0;
						zyoumonboss.action = static_cast<int>(rand() % 10);
						zyoumonboss.isAction = true;
					}
				}

				if (zyoumonboss.isAction)
				{
					if (zyoumonboss.hp >= 40)
					{
						//ダッシュ
						if (zyoumonboss.action <= 4)
						{
							zyoumonboss.speed = 3.0f;

							zyoumonBossMoveActionCount++;

							if (zyoumonboss.pos.x > player.pos.x)
							{
								zyoumonboss.pos.x -= zyoumonboss.speed;
							} else
							{
								zyoumonboss.pos.x += zyoumonboss.speed;
							}

							if (zyoumonBossMoveActionCount >= 100)
							{
								zyoumonBossMoveActionCount = 0;
								zyoumonboss.isAction = false;
							}
						} else if (zyoumonboss.action <= 6 && !zyoumonBossShockWave.isAction)
						{
							zyoumonBossShockWave.isAction = true;

							if (zyoumonBossShockWave.isAction)
							{
								zyoumonBossShockWave.pos.x = zyoumonboss.pos.x;
								zyoumonBossShockWave.pos.y = 545.0f;

								if (zyoumonboss.pos.x > player.pos.x)
								{
									zyoumonBossShockWave.speed = -6.0f;
								} else
								{
									zyoumonBossShockWave.speed = 6.0f;
								}
							}

							zyoumonboss.isAction = false;
						}
						// 鼻で岩を飛ばす
						else if (zyoumonboss.action <= 8 && !zyoumonbossRock.isAction)
						{
							zyoumonbossRock.speed = 0.0f;
							zyoumonIsDirectionRock = true;
							zyoumonbossRockMoveCount++;
							zyoumonbossRockGraphCount = (zyoumonbossRockMoveCount / 10) % 2;

							if (zyoumonbossRockMoveCount >= 20)
							{
								zyoumonbossRock.isAction = true;
								zyoumonbossRock.pos.x = zyoumonboss.pos.x;
								zyoumonbossRock.pos.y = zyoumonboss.pos.y + 20.0f;

								if (zyoumonboss.pos.x > player.pos.x)
								{
									zyoumonbossRock.speed = -12.0f;
								} else
								{
									zyoumonbossRock.speed = 12.0f;
								}

								zyoumonbossRockMoveCount = 0;
								zyoumonIsDirectionRock = false;
								zyoumonboss.isAction = false;
							}
						}
						//歩く
						else
						{
							zyoumonboss.speed = 0.5f;

							zyoumonBossMoveActionCount++;

							if (zyoumonboss.pos.x > player.pos.x)
							{
								zyoumonboss.pos.x -= zyoumonboss.speed;
							} else
							{
								zyoumonboss.pos.x += zyoumonboss.speed;
							}

							if (zyoumonBossMoveActionCount > 80)
							{
								zyoumonBossMoveActionCount = 0;
								zyoumonboss.isAction = false;
							}
						}
					} else
					{
						//ダッシュ
						if (zyoumonboss.action <= 3)
						{
							zyoumonboss.speed = 5.0f;

							zyoumonBossMoveActionCount++;

							if (zyoumonboss.pos.x > player.pos.x)
							{
								zyoumonboss.pos.x -= zyoumonboss.speed;
							} else
							{
								zyoumonboss.pos.x += zyoumonboss.speed;
							}

							if (zyoumonBossMoveActionCount >= 100)
							{
								zyoumonBossMoveActionCount = 0;
								zyoumonboss.isAction = false;
							}
						} else if (zyoumonboss.action <= 6 && !zyoumonBossShockWave.isAction)
						{
							zyoumonBossShockWave.isAction = true;

							if (zyoumonBossShockWave.isAction)
							{
								zyoumonBossShockWave.pos.x = zyoumonboss.pos.x;
								zyoumonBossShockWave.pos.y = 545.0f;

								if (zyoumonboss.pos.x > player.pos.x)
								{
									zyoumonBossShockWave.speed = -6.0f;
								} else
								{
									zyoumonBossShockWave.speed = 6.0f;
								}
							}

							zyoumonboss.isAction = false;
						}
						// 鼻で岩を飛ばす
						else if (zyoumonboss.action <= 9 && !zyoumonbossRock.isAction)
						{
							zyoumonbossRock.speed = 0.0f;
							zyoumonIsDirectionRock = true;
							zyoumonbossRockMoveCount++;
							zyoumonbossRockGraphCount = (zyoumonbossRockMoveCount / 10) % 2;

							if (zyoumonbossRockMoveCount >= 20)
							{
								zyoumonbossRock.isAction = true;
								zyoumonbossRock.pos.x = zyoumonboss.pos.x;
								zyoumonbossRock.pos.y = zyoumonboss.pos.y + 20.0f;

								if (zyoumonboss.pos.x > player.pos.x)
								{
									zyoumonbossRock.speed = -17.0f;
								} else
								{
									zyoumonbossRock.speed = 17.0f;
								}

								zyoumonbossRockMoveCount = 0;
								zyoumonIsDirectionRock = false;
								zyoumonboss.isAction = false;
							}
						}
					}

				}

				if (zyoumonbossRock.isAction)
				{
					zyoumonbossRock.pos.x += zyoumonbossRock.speed;
				}

				if (zyoumonBossShockWave.isAction)
				{
					zyoumonBossShockWave.pos.x += zyoumonBossShockWave.speed;
				}

				if (zyoumonbossRock.pos.x <= 0 || zyoumonbossRock.pos.x >= 1280)
				{
					zyoumonbossRock.isAction = false;
				}

				if (zyoumonBossShockWave.pos.x <= 0 || zyoumonBossShockWave.pos.x >= 1280)
				{
					zyoumonBossShockWave.isAction = false;
				}

				if (zyoumonboss.speed != 0)
				{
					zyoumonBossMoveCount++;

					zyoumonBossMoveGraphCount = (zyoumonBossMoveCount / 25) % 3;

					if (zyoumonBossMoveCount >= 75)
					{
						zyoumonBossMoveCount = 0;
					}
				} else if (zyoumonboss.speed == 3.0f)
				{
					zyoumonBossMoveCount++;

					zyoumonBossMoveGraphCount = (zyoumonBossMoveCount / 15) % 3;

					if (zyoumonBossMoveCount >= 45)
					{
						zyoumonBossMoveCount = 0;
					}
				}



				zyoumonBossToPlayerX = zyoumonboss.pos.x - player.pos.x;
				zyoumonBossToPlayerY = zyoumonboss.pos.y - player.pos.y;
				hitJudgezyoumonBossToPlayer = sqrtf(zyoumonBossToPlayerX * zyoumonBossToPlayerX + zyoumonBossToPlayerY * zyoumonBossToPlayerY);
				if (hitJudgezyoumonBossToPlayer <= zyoumonbossRadius + player.radius && playerIsAlive)
				{
					playerIsAlive = false;
					playerLife--;
				}

				zyoumonBossRockToPlayerX = zyoumonbossRock.pos.x - player.pos.x;
				zyoumonBossRockToPlayerY = zyoumonbossRock.pos.y - player.pos.y;
				hitJudgeZyoumonBossRockToPlayer = sqrtf(zyoumonBossRockToPlayerX * zyoumonBossRockToPlayerX + zyoumonBossRockToPlayerY * zyoumonBossRockToPlayerY);
				if (hitJudgeZyoumonBossRockToPlayer <= zyoumonBossRockRadius + playerRadiusX && playerIsAlive)
				{
					playerIsAlive = false;
					playerLife--;
				}

				zyoumonBossShockWaveToPlayerX = zyoumonBossShockWave.pos.x - player.pos.x;
				zyoumonBossShockWaveToPlayerY = zyoumonBossShockWave.pos.y - player.pos.y;
				hitJudgeZyoumonBossShockWaveToPlayer = sqrtf(zyoumonBossShockWaveToPlayerX * zyoumonBossShockWaveToPlayerX + zyoumonBossShockWaveToPlayerY * zyoumonBossShockWaveToPlayerY);
				if (hitJudgeZyoumonBossShockWaveToPlayer <= zyoumonBossShockWaveRadius + playerRadiusX && playerIsAlive)
				{
					playerIsAlive = false;
					playerLife--;
				}
				//-------------------------------------------------------------------------------------------------------------------------------------
#pragma endregion
				//当たり判定
				
						if (player.velocity.y > 0.0f) {
							if ((zyoumonBoss[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] != 0) ||
								(zyoumonBoss[int((player.pos.y + 32.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] != 0)) {
								player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
								player.velocity.y = 0.0f;
								playerJumpCount = 2;
							}
						} else if (player.velocity.y < 0.0f) {
							if ((zyoumonBoss[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] != 0) ||
								(zyoumonBoss[int((player.pos.y - 30.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] != 0)) {
								player.pos.y = (int(player.pos.y / 64.0f) * 64.0f) + 32.0f;
								player.velocity.y = 0.0f;
								playerJumpCount = 2;
							}
						}

						if (player.velocity.x > 0.0f) {
							if ((zyoumonBoss[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] != 0) ||
								(zyoumonBoss[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x + 33.0f) / 64.0f)] != 0)) {
								player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
								player.velocity.x = 0.0f;
							}
						} else if (player.velocity.x < 0.0f) {
							if ((zyoumonBoss[int((player.pos.y - 32.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] != 0) ||
								(zyoumonBoss[int((player.pos.y + 31.0f) / 64.0f)][int((player.pos.x - 33.0f) / 64.0f)] != 0)) {
								player.pos.x = (int(player.pos.x / 64.0f) * 64.0f) + 32.0f;
								player.velocity.x = 0.0f;
							}
						}
				
				if ((zyoumonBoss[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x - 20.0f) / 64.0f)] != 0) ||
					(zyoumonBoss[int((player.pos.y + 33.0f) / 64.0f)][int((player.pos.x + 20.0f) / 64.0f)] != 0)) {
					player.isOnGround = true;
				} else {
					player.isOnGround = false;
				}
				//::::::::::::::::::::::::::::::::::::::::::::
				//          プレイヤーが赤い線で止まる
				//::::::::::::::::::::::::::::::::::::::::::::
			

				scrollX = Clamp(scrollX, 0.0f, 3840.0f - 2560.0f);       //上限の設定
				player.pos.x = Clamp(player.pos.x, 0.0f, 1280.0f);
				player.pos.y = Clamp(player.pos.y, 0.0f, 820.0f);
				//::::::::::::::::::::::::::::::::::::::::::::::::
				//                  ラインの固定
				//::::::::::::::::::::::::::::::::::::::::::::::::
				if (redLinePosX >= windowRight) {
					redLinePosX = windowRight;
				}
				if (greenLinePosX <= windowLeft) {
					greenLinePosX = windowLeft;
				}
				//ゲームオーバー
				if (player.pos.y >= 720.0f) {
					player.pos.x = 10.0f;
					player.pos.y = 100;
					break;
				}
				//実機の向きを保存
				if (keys[DIK_D])
				{
					playerDirection = true;
				}
				if (keys[DIK_A])
				{
					playerDirection = false;
				}
				//実機のジャンプをカウント
				if (preKeys[DIK_W] == 0 && keys[DIK_W])
				{
					playerJumpCount--;
				}
				if (playerJumpCount < 0)
				{
					playerJumpCount = 0;
				}
				//実機のアニメーション処理
				playerFlameCount++;
				playerFlameNumber = (playerFlameCount / 10) % 4;
				if (playerFlameCount > 40)
				{
					playerFlameCount = 0;
				}
				playerMoveFlameCount++;
				playerMoveFlameNumber = (playerMoveFlameCount / 10) % 3;
				if (playerMoveFlameCount > 30)
				{
					playerMoveFlameCount = 0;
				}
				//実機のHP生死の管理
				if (preKeys[DIK_I] == 0 && keys[DIK_I] != 0)
				{
					playerLife--;
					playerIsAlive = false;
				}
				if (playerLife == 0)
				{
					isGameOver = true;
				}
				if (playerIsAlive == false)
				{
					playerIsAliveCount--;
					if (playerIsAliveCount == 0)
					{
						playerIsAlive = true;
						playerIsAliveCount = 60;
					}
				}
				if (zyomonBulletIsAlive)
				{
					zyomonBulletPosX += zyomonBulletSpeedX;
					zyomonBulletIsAliveTimer++;
					if (zyomonBulletIsAliveTimer == 120)
					{
						zyomonBulletIsAliveTimer = 0;
						zyomonBulletIsAlive = false;
					}
				} else
				{
					zyomonBulletPosX = player.pos.x;
					zyomonBulletPosY = player.pos.y;
					if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0)
					{
						zyomonBulletIsAlive = true;
						if (playerDirection)
						{
							zyomonBulletSpeedX = 20.0f;
						} else
						{
							zyomonBulletSpeedX = -20.0f;
						}
					}
				}
			} else
			{
				if (preKeys[DIK_Q] == 0 && keys[DIK_Q] != 0)
				{
					currentScene = ZYOUMON3;
					isGameOver = false;
					playerIsAlive = true;
					player.pos.x = 2500.0f;
					player.pos.y = 500.0f;
					playerLife = 3;
				}
				if (preKeys[DIK_E] == 0 && keys[DIK_E] != 0)
				{
					currentScene = STAGESELECT;
				}
			}
#pragma endregion
			break;
		}
		/*----
		 描画
		----*/
		switch (currentScene)
		{
		case TITLLE:
			Novice::DrawSprite(0, 0, taitlleGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			break;
		case STAGESELECT:

			Novice::DrawSprite(0, 0, stageSelectHandle, 1.0f, 1.0f, 0.0f, WHITE);
			Novice::ScreenPrintf(10, 10, "STAGE.Number.%d", stageNumber);
			break;
        #pragma region 現代の描画
		case GENDAI:
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, gendaiBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			DrawTileSetGendai1(gendaiMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f }, 64.0f, 40, 12);
	
			for (int i = 0; i < 16; i++)
			{
				if (playerBullet[i].isAlive)
				{
					Novice::DrawSprite(static_cast<int>(playerBullet[i].pos.x - 16) - static_cast<int>(scrollX), static_cast<int>(playerBullet[i].pos.y - 16), playerBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
		case GENDAI2:
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, gendaiBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			DrawTileSetGendai2(gendaiMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f }, 64.0f, 40, 12);
			for (int i = 0; i < 16; i++)
			{
				if (playerBullet[i].isAlive)
				{
					Novice::DrawSprite(static_cast<int>(playerBullet[i].pos.x - 16) - static_cast<int>(scrollX), static_cast<int>(playerBullet[i].pos.y - 16), playerBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
		case GENDAI3:
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, gendaiBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			DrawTileSetGendai3(gendaiMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f }, 64.0f, 40, 12);
			for (int i = 0; i < 16; i++)
			{
				if (playerBullet[i].isAlive)
				{
					Novice::DrawSprite(static_cast<int>(playerBullet[i].pos.x - 16) - static_cast<int>(scrollX), static_cast<int>(playerBullet[i].pos.y - 16), playerBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
		case GENDAIBOSS:
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x);
				Novice::DrawSprite(drawPosX, 0, gendaiBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			DrawTileSetGendaiBoss(gendaiMapGraph, { 0.0f,0.0f }, 64.0f, 40, 12);
			for (int i = 0; i < 16; i++)
			{
				if (playerBullet[i].isAlive)
				{
					Novice::DrawSprite(static_cast<int>(playerBullet[i].pos.x - 16), static_cast<int>(playerBullet[i].pos.y - 16), playerBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}
			for (int i = 0; i < 3; i++)
			{
				if (gendaiBossBullet[i].isShot)
				{
					Novice::DrawSprite(static_cast<int>(gendaiBossBullet[i].pos.x - 16), static_cast<int>(gendaiBossBullet[i].pos.y - 16), gendaiBossBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}
			if (gendaiBossIsAlive)
			{
				if (gendaiboss.pos.x > player.pos.x)
				{
					Novice::DrawSpriteRect(static_cast<int>(gendaiboss.pos.x - 48), static_cast<int>(gendaiboss.pos.y - 64), playerMoveFlameNumber * 96, 0, 96, 96, gendaiBossLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					Novice::DrawSpriteRect(static_cast<int>(gendaiboss.pos.x - 48), static_cast<int>(gendaiboss.pos.y - 64), playerMoveFlameNumber * 96, 0, 96, 96, gendaiBossRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				}
			}
			else
			{
				if (gendaiboss.pos.x > player.pos.x)
				{
					Novice::DrawSpriteRect(static_cast<int>(gendaiboss.pos.x - 48), static_cast<int>(gendaiboss.pos.y - 64), gendaiBossFlameNumber * 96, 0, 96, 96, gendaiBossLeftDieGraphHandle, 1.0f / 11.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					Novice::DrawSpriteRect(static_cast<int>(gendaiboss.pos.x - 48), static_cast<int>(gendaiboss.pos.y - 64), gendaiBossFlameNumber * 96, 0, 96, 96, gendaiBossRightDieGraphHandle, 1.0f / 11.0f, 1.0f, 0.0f, WHITE);
				}
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} 
				else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			}
			else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, gendaiPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, gendaiPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			Novice::DrawSprite(0, static_cast<int>(clearPosY), stageClearGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			break;
#pragma endregion
        #pragma region 戦国の描画
		case SENGOKU:
			Novice::ScreenPrintf(100, 150, "SENGOKU1");
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, sengokuBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}

			for (int i = 0; i < 10; i++)
			{
				if (cannonIsShot[i])
				{
					Novice::DrawSprite(static_cast<int>(cannonPosX[i] + 16) - static_cast<int>(scrollX), static_cast<int>(cannonPosY[i] + 16), cannonBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}

			DrawTileSetSengoku1(sengokuMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f }, 64.0f, 40, 12);
			if (platerSlashIsAlive)
			{
				if(playerSlashDirection)
				{
					Novice::DrawSprite(static_cast<int>(playerSlashPosX - 16) - static_cast<int>(scrollX), static_cast<int>(playerSlashPosY - 32), playerSlashRightGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
				else
				{
					Novice::DrawSprite(static_cast<int>(playerSlashPosX - 16) - static_cast<int>(scrollX), static_cast<int>(playerSlashPosY - 32), playerSlashLeftGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
		    //実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
		case SENGOKU2:
			Novice::ScreenPrintf(100, 150, "SENGOKU2");
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, sengokuBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			
				
			Novice::DrawSprite(static_cast<int>(cannon2PosX[0] + 16) - static_cast<int>(scrollX), static_cast<int>(cannon2PosY[0] + 16), cannonBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			Novice::DrawSprite(static_cast<int>(cannon2PosX[1] + 16) - static_cast<int>(scrollX), static_cast<int>(cannon2PosY[1] + 16), cannonBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			
			
			DrawTileSetSengoku2(sengokuMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f }, 64.0f, 40, 12);
			if (platerSlashIsAlive)
			{
				if (playerSlashDirection)
				{
					Novice::DrawSprite(static_cast<int>(playerSlashPosX - 16) - static_cast<int>(scrollX), static_cast<int>(playerSlashPosY - 32), playerSlashRightGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					Novice::DrawSprite(static_cast<int>(playerSlashPosX - 16) - static_cast<int>(scrollX), static_cast<int>(playerSlashPosY - 32), playerSlashLeftGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
		case SENGOKU3:
			Novice::ScreenPrintf(100, 150, "SENGOKU3");
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, sengokuBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			for (int i = 0; i < 5; i++)
			{
				Novice::DrawSprite(static_cast<int>(blackCannonPosX[i] + 16) - static_cast<int>(scrollX), static_cast<int>(blackCannonPosY[i] + 16), cannonBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			for (int i = 0; i < 5; i++)
			{
				Novice::DrawSprite(static_cast<int>(redCannonPosX[i] + 16) - static_cast<int>(scrollX), static_cast<int>(redCannonPosY[i] + 16), cannonBulletGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
		
			DrawTileSetSengoku3(sengokuMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f }, 64.0f, 40, 12);
			if (platerSlashIsAlive)
			{
				if (playerSlashDirection)
				{
					Novice::DrawSprite(static_cast<int>(playerSlashPosX - 16) - static_cast<int>(scrollX), static_cast<int>(playerSlashPosY - 32), playerSlashRightGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					Novice::DrawSprite(static_cast<int>(playerSlashPosX - 16) - static_cast<int>(scrollX), static_cast<int>(playerSlashPosY - 32), playerSlashLeftGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
		case SENGOKUBOSS:
			Novice::ScreenPrintf(100, 150, "SENGOKUBOSS");
			Novice::ScreenPrintf(100, 170, "SENGOKUBOSSLIFE%d",sengokuBossLife);
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x);
				Novice::DrawSprite(drawPosX, 0, sengokuBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			DrawTileSetSengokuBoss(sengokuMapGraph, { 0.0f,0.0f }, 64.0f, 40, 12);
			if (sengokuBossIsAlive)
			{
				switch (sengokubossDirection)
				{
				case FRONT:
					//drawBoss
					if (sengokuboss.isAlive && !sengokuboss.isAction)
					{
						Novice::DrawSpriteRect(static_cast<int>(sengokuboss.pos.x - 32), static_cast<int>(sengokuboss.pos.y - 32), 0, 0, 64, 64, sengokuBossMoveFrontGraph, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else if (sengokuboss.pos.x += sengokuboss.speed)
					{
						Novice::DrawSpriteRect(static_cast<int>(sengokuboss.pos.x - 32), static_cast<int>(sengokuboss.pos.y - 32), sengokuBossMoveCount * 64, 0, 64, 64, sengokuBossMoveFrontGraph, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
					break;

				case BACK:
					if (sengokuboss.isAlive && !sengokuboss.isAction)
					{
						Novice::DrawSpriteRect(static_cast<int>(sengokuboss.pos.x - 32), static_cast<int>(sengokuboss.pos.y - 32), 0, 0, 64, 64, sengokuBossMoveBackGraph, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else if (sengokuboss.pos.x -= sengokuboss.speed)
					{
						Novice::DrawSpriteRect(static_cast<int>(sengokuboss.pos.x - 32), static_cast<int>(sengokuboss.pos.y - 32), sengokuBossMoveCount * 64, 0, 64, 64, sengokuBossMoveBackGraph, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
					break;
				}

				if (sengokuZangekiAction)
				{
					if (sengokuboss.pos.x < player.pos.x)
					{
						Novice::DrawSpriteRect(static_cast<int>(sengokuBossZangekiFrontPlayer.x - 32), static_cast<int>(sengokuBossZangekiFrontPlayer.y - 32), sengokuBossActionGraphCount * 64, 0, 64, 64, sengokuBossZangekiFrontGraph, 1.0f / 8.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(sengokuBossZangekiBackPlayer.x - 32), static_cast<int>(sengokuBossZangekiBackPlayer.y - 32), sengokuBossActionGraphCount * 64, 0, 64, 64, sengokuBossZangekiBackGraph, 1.0f / 8.0f, 1.0f, 0.0f, WHITE);
					}
				}
			}
			else
			{
				if (gendaiboss.pos.x<player.pos.x)
				{
					Novice::DrawSpriteRect(static_cast<int>(sengokuboss.pos.x - 32), static_cast<int>(sengokuboss.pos.y - 32), 64 * sengokuBossDieFlameNumber, 0, 64, 64, sengokuBossRightDieGraphHandle, 1.0f / 8.0f, 1.0f, 0.0f, WHITE);
				}
				else
				{
					Novice::DrawSpriteRect(static_cast<int>(sengokuboss.pos.x - 32), static_cast<int>(sengokuboss.pos.y - 32), 64 * sengokuBossDieFlameNumber, 0, 64, 64, sengokuBossLeftDieGraphHandle, 1.0f / 8.0f, 1.0f, 0.0f, WHITE);

				}
			}
			//-----------------------------------------------------------------------------//
			if (platerSlashIsAlive)
			{
				if (playerSlashDirection)
				{
					Novice::DrawSprite(static_cast<int>(playerSlashPosX - 16), static_cast<int>(playerSlashPosY - 32), playerSlashRightGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					Novice::DrawSprite(static_cast<int>(playerSlashPosX - 16), static_cast<int>(playerSlashPosY - 32), playerSlashLeftGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} 
				else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} 
				else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} 
			else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, sengokuPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, sengokuPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			Novice::DrawSprite(0, static_cast<int>(clearPosY), stageClearGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			break;
#pragma endregion
        #pragma region 縄文の描画
		case ZYOUMON:
			Novice::ScreenPrintf(100, 150, "ZYOUMON1");
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, zyoumonBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			for (int i = 0; i < 10; i++)
			{
				Novice::DrawSprite(static_cast<int>(rakuseki1PosX[i]) - static_cast<int>(scrollX), static_cast<int>(rakuseki1PosY[i]), rakusekiGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			Novice::DrawSprite(static_cast<int>(yari1PosX) - static_cast<int>(scrollX), static_cast<int>(yari1PosY), yariLeftGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			DrawTileSetZyoumon1(zyoumonMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f }, 64.0f, 40, 12);

			for (int i = 0; i < 2; i++)
			{
				Novice::DrawSprite(static_cast<int>(touseki1PosX[i]) - static_cast<int>(scrollX), static_cast<int>(touseki1PosY[i]), tousekiGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			if (zyomonBulletIsAlive)
			{
				Novice::DrawSprite(static_cast<int>(zyomonBulletPosX-16.0f) - static_cast<int>(scrollX), static_cast<int>(zyomonBulletPosY - 16.0f), zyomonBulletGraph, 1.0f, 1.0f, 0.0f, WHITE);
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D]|| keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A]|| keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
		case ZYOUMON2:
			Novice::ScreenPrintf(100, 150, "ZYOUMON2");
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, zyoumonBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			for (int i = 0; i < 9; i++)
			{
				Novice::DrawSprite(static_cast<int>(rakuseki2PosX[i]) - static_cast<int>(scrollX), static_cast<int>(rakuseki2PosY[i]), rakusekiGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			for (int i = 0; i < 2; i++)
			{
				Novice::DrawSprite(static_cast<int>(yari2LeftPosX[i]) - static_cast<int>(scrollX), static_cast<int>(yari2LeftPosY[i]), yariLeftGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawSprite(static_cast<int>(yari2RightPosX[i]) - static_cast<int>(scrollX), static_cast<int>(yari2RightPosY[i]), yariRightGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			DrawTileSetZyoumon2(zyoumonMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f }, 64.0f, 40, 12);
			Novice::DrawSprite(static_cast<int>(touseki2PosX) - static_cast<int>(scrollX), static_cast<int>(touseki2PosY), tousekiGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			if (zyomonBulletIsAlive)
			{
				Novice::DrawSprite(static_cast<int>(zyomonBulletPosX - 16.0f) - static_cast<int>(scrollX), static_cast<int>(zyomonBulletPosY - 16.0f), zyomonBulletGraph, 1.0f, 1.0f, 0.0f, WHITE);
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
		case ZYOUMON3:
			Novice::ScreenPrintf(100, 150, "ZYOUMON3");
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, zyoumonBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			for (int i = 0; i < 4; i++)
			{
				Novice::DrawSprite(static_cast<int>(yari3PosX[i]) - static_cast<int>(scrollX), static_cast<int>(yari3PosY[i]), yariRightGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			for (int i = 0; i < 10; i++)
			{
				Novice::DrawSprite(static_cast<int>(rakuseki3PosX[i]) - static_cast<int>(scrollX), static_cast<int>(rakuseki3PosY[i]), rakusekiGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			DrawTileSetZyoumon3(zyoumonMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f }, 64.0f, 40, 12);
			Novice::DrawSprite(static_cast<int>(touseki3PosX) - static_cast<int>(scrollX), static_cast<int>(touseki3PosY), tousekiGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			if (zyomonBulletIsAlive)
			{
				Novice::DrawSprite(static_cast<int>(zyomonBulletPosX - 16.0f) - static_cast<int>(scrollX), static_cast<int>(zyomonBulletPosY - 16.0f), zyomonBulletGraph, 1.0f, 1.0f, 0.0f, WHITE);
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
		case ZYOMONBOSS:
			Novice::ScreenPrintf(100, 150, "ZYOUMONBOSS");
			for (int i = 0; i < kGraphNums; i++) {
				int drawPosX = 0 + i * static_cast<int>(graphSize.x) - static_cast<int>(scrollX);
				Novice::DrawSprite(drawPosX, 0, zyoumonBackGroundGraphs[i], 1.0f, 1.0f, 0.0f, WHITE);
			}
			DrawTileSetZyoumonBoss(zyoumonMapGraph, { 0.0f - static_cast<int>(scrollX),0.0f+64.0f }, 64.0f, 40, 12);
			//--------------------------------------------------------------
			if (zyoumonIsDirectionRock)
			{
				if (zyoumonboss.pos.x > player.pos.x)
				{
					Novice::DrawSpriteRect(static_cast<int>(zyoumonboss.pos.x - 64), static_cast<int>(zyoumonboss.pos.y - 64), zyoumonbossRockGraphCount * 128, 0, 128, 128, zyoumonBossRockThrowBackGraph, 1.0f / 2.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					Novice::DrawSpriteRect(static_cast<int>(zyoumonboss.pos.x - 64), static_cast<int>(zyoumonboss.pos.y - 64), zyoumonbossRockGraphCount * 128, 0, 128, 128, zyoumonBossRockThrowFrontGraph, 1.0f / 2.0f, 1.0f, 0.0f, WHITE);
				}
			}

			if (zyoumonboss.isAlive && !zyoumonIsDirectionRock)
			{
				if (zyoumonboss.pos.x > player.pos.x)
				{
					Novice::DrawSpriteRect(static_cast<int>(zyoumonboss.pos.x - 64), static_cast<int>(zyoumonboss.pos.y - 64), 0, 0, 128, 128, zyoumonBossMoveBackGraph, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					Novice::DrawSpriteRect(static_cast<int>(zyoumonboss.pos.x - 64), static_cast<int>(zyoumonboss.pos.y - 64), 0, 0, 128, 128, zyoumonBossMoveFrontGraph, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				}
			}

			if (zyoumonboss.speed != 0 && !zyoumonIsDirectionRock)
			{
				if (zyoumonboss.pos.x > player.pos.x)
				{
					Novice::DrawSpriteRect(static_cast<int>(zyoumonboss.pos.x - 64), static_cast<int>(zyoumonboss.pos.y - 64), zyoumonBossMoveGraphCount * 128, 0, 128, 128, zyoumonBossMoveBackGraph, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					Novice::DrawSpriteRect(static_cast<int>(zyoumonboss.pos.x - 64), static_cast<int>(zyoumonboss.pos.y - 64), zyoumonBossMoveGraphCount * 128, 0, 128, 128, zyoumonBossMoveFrontGraph, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				}
			}

			if (zyoumonBossShockWave.isAction)
			{
				if (zyoumonboss.pos.x > player.pos.x)
				{
					Novice::DrawSprite(static_cast<int>(zyoumonBossShockWave.pos.x - 32), static_cast<int>(zyoumonBossShockWave.pos.y - 32), zyoumonShockWaveBackGraph, 1.0f, 1.0f, 0.0f, WHITE);
				} else
				{
					Novice::DrawSprite(static_cast<int>(zyoumonBossShockWave.pos.x - 32), static_cast<int>(zyoumonBossShockWave.pos.y - 32), zyoumonShockWaveFrontGraph, 1.0f, 1.0f, 0.0f, WHITE);
				}
			}

			if (zyoumonbossRock.isAction)
			{
				Novice::DrawSprite(static_cast<int>(zyoumonbossRock.pos.x - 32.0f), static_cast<int>(zyoumonbossRock.pos.y - 32.0f), zyoumonBossRockGraph, 1.0f, 1.0f, 0.0f, WHITE);
			}

			//----------------------------------------------------------------------------------------
			if (zyomonBulletIsAlive)
			{
				Novice::DrawSprite(static_cast<int>(zyomonBulletPosX - 16.0f), static_cast<int>(zyomonBulletPosY - 16.0f), zyomonBulletGraph, 1.0f, 1.0f, 0.0f, WHITE);
			}
			if (playerIsAlive)
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveRightGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} 
				else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveLeftGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} 
				else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerRightGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerLeftGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
			} else
			{
				if (keys[DIK_D] || keys[DIK_RIGHT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveRightIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} 
				else if (keys[DIK_A] || keys[DIK_LEFT])
				{
					Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerMoveFlameNumber * 64, 0, 64, 64, zyoumonPlayerMoveLeftIsHitGraphHandle, 1.0f / 3.0f, 1.0f, 0.0f, WHITE);
				} 
				else
				{
					if (playerDirection)
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32) , static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerRightIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					} else
					{
						Novice::DrawSpriteRect(static_cast<int>(player.pos.x - 32), static_cast<int>(player.pos.y - 32), playerFlameNumber * 64, 0, 64, 64, zyoumonPlayerLeftIsHitGraphHandle, 1.0f / 4.0f, 1.0f, 0.0f, WHITE);
					}
				}
				Novice::DrawSprite(static_cast<int>(player.pos.x - 32) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 64), playerGostBarGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
				Novice::DrawBox(static_cast<int>(player.pos.x - 29) - static_cast<int>(scrollX), static_cast<int>(player.pos.y - 61), playerIsAliveCount, 10, 0.0f, WHITE, kFillModeSolid);
			}
			//実機の体力
			Novice::DrawSprite(0, 0, playerLifeGraphHandle[playerLife], 1.0f, 1.0f, 0.0f, WHITE);
			if (isGameOver)
			{
				Novice::DrawSprite(0, 0, gameOverSceneGraphHandle, 1.0f, 1.0f, 0.0f, WHITE);
			}
			break;
#pragma endregion
		}



		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
