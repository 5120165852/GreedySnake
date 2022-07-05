/*###################################################################
#FileName��snake.h
#Author��liuxun
#Date��2022/07/05
#Describe��Null
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
	int moveForce; //0:�� 1:�� 2:�� 3:��
}SSnake;

SSnake g_snake;

void initSnake(void);
void moveSnake(void);
void drawSnake(void);
void runSnake(void);
void eatFood(void);
bool hitWall(void);

#endif
