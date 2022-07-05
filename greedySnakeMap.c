/*###################################################################
#FileName：greedySnakeMap.c
#Author：liuxun
#Date：2022/07/05
#Describe：Null
#####################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include "greedySnakeMap.h"
#include "errorCode.h"
#include "winApi.h"
#include "foods.h"

void showWall(void)
{
	//画上下边界
	for (int i = g_wall.startX; i < g_wall.startX + g_wall.width; i++) {
		setPos(i, g_wall.startY);
		printf("█");
		setPos(i, g_wall.startY + g_wall.height);
		printf("█");
	}

	//画左右边界
	for (int i = g_wall.startY; i < g_wall.startY + g_wall.height; i++) {
		setPos(g_wall.startX, i);
		printf("▋");
		setPos(g_wall.startX + g_wall.width, i);
		printf("▋");
	}
	setPos(g_map.width, g_map.height);

	return;
}

int initWall(int startx, int starty, int width, int height)
{
	g_wall.startX = startx;
	g_wall.startY = starty;
	g_wall.width = width;
	g_wall.height = height;

	showWall();

	return RET_OK;
}

void showTitle(void)
{
	setPos(g_title.startX, g_title.startY);
	printf("%s", g_title.title);

	return;
}

int initTitle(int startx, int starty, char* title)
{
	g_title.startX = startx;
	g_title.startY = starty;
	strcpy(g_title.title, title);
	showTitle();

	return RET_OK;
}

int initMap()
{
	//获取屏幕大小
	getScreenSiz(&g_map.width, &g_map.height);
	initTitle((int)(g_map.width * 0.5), (int)(g_map.height * 0.05), "贪吃蛇");
	initWall((int)(g_map.width * 0.1), (int)(g_map.height * 0.1), (int)(g_map.width * 0.8), (int)(g_map.height * 0.8));

	return RET_OK;
}

void showMap(void)
{
	showTitle();
	showWall();

	return;
}



