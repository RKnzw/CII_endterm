#include "maze.h"

void getCurrentDirectory(char* currentDirectory) {	//現在のディレクトリ取得
	GetCurrentDirectory(BUFFSIZE, currentDirectory);
}

int readInt(const char* section, const char* keyword, int defaultValue, const char* filePath) {	//設定ファイルから整数読み込み
	int num = GetPrivateProfileInt(section, keyword, defaultValue, filePath);
	return num;
}