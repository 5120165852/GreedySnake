/*###################################################################
#FileName£ºwinApi.h
#Author£ºliuxun
#Date£º2022/07/05
#Describe£ºNull
#####################################################################*/

#ifndef _WINAPI_H_
#define _WINAPI_H_

void clearMap(void);
int setPos(int posx, int posy);
int getScreenSiz(int* width, int* height);
void setColor(int color);
void fullScreen(void);
void sleep(int time);
void beep(int a, int b);
#endif
