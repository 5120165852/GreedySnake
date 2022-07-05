/*###################################################################
#FileName：foods.c
#Author：liuxun
#Date：2022/07/05
#Describe：Null
#####################################################################*/

#include <stdlib.h>
#include "foods.h"
#include "winApi.h"
#include "greedySnakeMap.h"


void initFood(void)
{
	genFood();

	return;
}

void genFood(void)
{
	/*生成食物位置，数值修改防止食物嵌入墙体. */
	g_snakeFood.posx = rand() % (g_wall.width - 2) + g_wall.startX + 2;
	g_snakeFood.posy = rand() % (g_wall.height - 1)+ g_wall.startY + 1;

	//画出食物
	setPos(g_snakeFood.posx, g_snakeFood.posy);
	printf("■");

	//把光标移出画面外
	setPos(g_map.width, g_map.height);

	return;
}