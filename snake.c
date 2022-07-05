/*###################################################################
#FileName：snake.c
#Author：liuxun
#Date：2022/07/05
#Describe：Null
#####################################################################*/

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "snake.h"
#include "greedySnakeMap.h"
#include "winApi.h"
#include "foods.h"

//"▲"
void initSnake()
{
	srand((unsigned int)time(NULL));
	g_snake.x = rand() % (g_wall.width - g_snake.lenth * 2) + g_wall.startX ; //因为方块宽度为2，所以*2
	g_snake.y = rand() % (g_wall.height - g_snake.lenth) + g_wall.startY;

	g_snake.lenth = 3;
	g_snake.isAlive = 1;
	g_snake.moveForce = rand() % 4;

	//按随机方向展示蛇位置
	if (g_snake.moveForce == 0) {
		//横向
		g_snake.body[0].x = g_snake.x + 2;
		g_snake.body[0].y = g_snake.y;

		for (int i = 1; i < g_snake.lenth; i++) {
			g_snake.body[i].x = g_snake.body[i - 1].x + 2;
			g_snake.body[i].y = g_snake.body[i - 1].y;
		}
	}
	else {
		//纵向
		g_snake.body[0].x = g_snake.x;
		g_snake.body[0].y = g_snake.y + 1;

		for (int i = 1; i < g_snake.lenth; i++) {
			g_snake.body[i].x = g_snake.body[i - 1].x;
			g_snake.body[i].y = g_snake.body[i - 1].y + 1;
		}
	}

	drawSnake();
}

void moveSnake()
{
	//清理蛇尾巴
	setPos(g_snake.body[g_snake.lenth - 1].x, g_snake.body[g_snake.lenth - 1].y);
	printf("  ");
	setPos(g_map.width, g_map.height);

	for (int i = g_snake.lenth - 1; i >= 0; i--)
	{
		g_snake.body[i].x = g_snake.body[i - 1].x;
		g_snake.body[i].y = g_snake.body[i - 1].y;
	}

	g_snake.body[0].x = g_snake.x;
	g_snake.body[0].y = g_snake.y;

	if (g_snake.moveForce == 0) {
		g_snake.y--;
	}
	else if (g_snake.moveForce == 1){
		g_snake.y++;
	}
	else if(g_snake.moveForce == 2) {
		g_snake.x = g_snake.x - 2; //左右移动时，因为方块宽度为2，所以移动两格
	}
	else {
		g_snake.x = g_snake.x + 2;//左右移动时，因为方块宽度为2，所以移动两格
	}

	//吃食物
	eatFood();

	//蛇成长
	drawSnake();

	return;
}

void drawSnake()
{
	setPos(g_snake.x, g_snake.y);
	printf("●");

	for (int i = 0; i < g_snake.lenth; i++) {
		setPos(g_snake.body[i].x, g_snake.body[i].y);
		printf("■");
	}

	setPos(g_map.width, g_map.height);
	return;
}

void runSnake() 
{
	int flag;
	bool changeDir = false;
	while (1) {
		if (kbhit()) {
			flag = getch();
			changeDir = true;
			if (flag == 224) flag = getch();
			if (flag == 72 && g_snake.moveForce != 1) {
				g_snake.moveForce = 0;
			}
			if (flag == 80 && g_snake.moveForce != 0) {
				g_snake.moveForce = 1;
			}
			if (flag == 75 && g_snake.moveForce != 3) {
				g_snake.moveForce = 2;
			}
			if (flag == 77 && g_snake.moveForce != 2) {
				g_snake.moveForce = 3;
			}
		}

		if (changeDir == false) {
			sleep(SNAKE_RUN_SPEED);
		}
		else {
			changeDir = false;
		}
		moveSnake();

		if (hitWall() == true) {
			break;
		}
	}
}

void eatFood(void)
{
	if ( abs(g_snake.x - g_snakeFood.posx) <= 1 && g_snake.y == g_snakeFood.posy) {
		setPos(g_snakeFood.posx, g_snakeFood.posy);
		printf("  ");
		beep(800, 800);
		//蛇长大一个单位
		for (int i = g_snake.lenth; i > 0; i--) {
			g_snake.body[i].x = g_snake.body[i - 1].x;
			g_snake.body[i].y = g_snake.body[i - 1].y;
		}
		g_snake.body[0].x = g_snake.x;
		g_snake.body[0].y = g_snake.y;
		g_snake.x = g_snakeFood.posx;
		g_snake.y = g_snakeFood.posy;
		g_snake.lenth++;

		genFood();
	}

	setPos(g_map.width, g_map.height);
}

bool hitWall(void)
{
	bool ret = false;

	if (g_snake.x >= (g_wall.startX + g_wall.width)
		|| g_snake.x <= g_wall.startX
		|| g_snake.y >= (g_wall.startY + g_wall.height)
		|| g_snake.y <= g_wall.startY
		)
	{
		ret = true;


		g_snake.isAlive = 0;
		g_snake.lenth = 0;
		clearMap();
		showMap();
		beep(900, 1000);

		setPos(g_wall.startX + g_wall.width / 2 - sizeof(HIT_WALL_MSG), g_wall.startY + g_wall.height / 2);
		printf("%s", HIT_WALL_MSG);
		setPos(0, g_wall.startY + g_wall.height + 1);
	}

	return ret;
}