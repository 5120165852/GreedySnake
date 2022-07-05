/*###################################################################
#FileName£ºsnake.h
#Author£ºliuxun
#Date£º2022/07/05
#Describe£ºNull
#####################################################################*/

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdbool.h>

#define SNAKE_RUN_SPEED 400 //400ms
#define HIT_WALL_MSG "Game Over!"

typedef struct SGreedySnakeBody {
	int x;
	int y;
}SSnakeBody;

typedef struct SGreedySnake {
	int x;
	int y;
	int lenth;
	SSnakeBody body[1000];
	int isAlive; //0:not alive, 1:alive
	int moveForce; //0:ÉÏ 1:ÏÂ 2:×ó 3:ÓÒ
}SSnake;

SSnake g_snake;

void initSnake(void);
void moveSnake(void);
void drawSnake(void);
void runSnake(void);
void eatFood(void);
bool hitWall(void);

#endif
