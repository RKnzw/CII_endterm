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

struct maze {				//���H
	char name[BUFFSIZE];	//���H�̖��O�B�t�@�C���������ݎ��̃t�@�C�����Ɏg�p
	int xSize;				//���H�̉��̑傫��
	int ySize;				//���H�̏c�̑傫��
	int map[yMax][xMax];	//���H�̃}�b�v���B0���ʘH��1����
};

struct player {				//�v���C���[
	int x;					//�v���C���[��x���W
	int y;					//�v���C���[��y���W
};

void makeMaze(maze* maze);
void maze2Txt(maze* maze);
void getCurrentDirectory(char* currentDirectory);
int readInt(const char* section, const char* keyword, int defaultValue, const char* filePath);