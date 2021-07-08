#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <curses.h>
#include <time.h>

#define BUFFSIZE 1024
#define XSTART 1
#define YSTART 1
#define xMax 30
#define yMax 30
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct maze {				//迷路
	char name[BUFFSIZE];	//迷路の名前。ファイル書き込み時のファイル名に使用
	int xSize;				//迷路の横の大きさ
	int ySize;				//迷路の縦の大きさ
	int map[yMax][xMax];	//迷路のマップ情報。0が通路で1が壁
};

struct player {				//プレイヤー
	int x;					//プレイヤーのx座標
	int y;					//プレイヤーのy座標
};

void makeMaze(maze* maze);
void maze2Txt(maze* maze);
void getCurrentDirectory(char* currentDirectory);
int readInt(const char* section, const char* keyword, int defaultValue, const char* filePath);