/*###################################################################
#FileName£ºgreedySnakeMap.h
#Author£ºliuxun
#Date£º2022/07/05
#Describe£ºNull
#####################################################################*/

#ifndef __GREEDYSNAKEMAP_H_
#define __GREEDYSNAKEMAP_H_

typedef struct SGreedySnakeMap{
	int height;
	int width;
}SMap;

typedef struct SGreedySnakeWall {
	int startX;
	int startY;
	int width;
	int height;
}SWall;

typedef struct SGreedySnakeTitle {
	int startX;
	int startY;
	char title[20];
}STitle;

typedef struct SGreedySnakeMsgBox {
	int startX;
	int startY;
	int width;
	int height;
}SMsgBox;

SMap g_map;
SWall g_wall;
STitle g_title;
SMsgBox g_msgBox; 


extern int initMap(void);
extern void showMap(void);
extern void showTitle(void);
extern void showWall(void);

#endif
