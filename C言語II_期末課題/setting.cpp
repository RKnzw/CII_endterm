#include "maze.h"

void getCurrentDirectory(char* currentDirectory) {	//���݂̃f�B���N�g���擾
	GetCurrentDirectory(BUFFSIZE, currentDirectory);
}

int readInt(const char* section, const char* keyword, int defaultValue, const char* filePath) {	//�ݒ�t�@�C�����琮���ǂݍ���
	int num = GetPrivateProfileInt(section, keyword, defaultValue, filePath);
	return num;
}