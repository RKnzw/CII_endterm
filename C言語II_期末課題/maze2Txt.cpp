#include "maze.h"

void maze2Txt(maze* maze) {	//���H���e�L�X�g�t�@�C���ɏo��
	FILE* fp;
	errno_t error;
	char s[BUFFSIZE];
	char fileName[BUFFSIZE];	//�t�@�C����
	sprintf_s(fileName, "%s.txt", maze->name);	//���H�̖��O.txt

	error = fopen_s(&fp, fileName, "w");
	if (error != 0) {
		printf("could not open the file");
	}
	else {
		for (int i = 0; i < maze->ySize; i++) {
			for (int j = 0; j < maze->xSize; j++) {
				if (j != maze->xSize - 1) {
					sprintf_s(s, "%d,", maze->map[i][j]);
					fputs(s, fp);
				}
				else {
					sprintf_s(s, "%d\n", maze->map[i][j]);
					fputs(s, fp);
				}
			}
		}
		sprintf_s(s, "���H�̃T�C�Y�F%d�~%d\n", maze->ySize, maze->xSize);
		fputs(s, fp);
	}

}
