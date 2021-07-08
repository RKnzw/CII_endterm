#include "maze.h"

void makeMaze(maze* maze) {	//�_�|���@�ɂ����H����

	for (int i = 0; i < maze->ySize; i++) {
		for (int j = 0; j < maze->xSize; j++) {
			if (i == 0 || j == 0 || i == maze->ySize - 1 || j == maze->xSize - 1) {	//�[��1�i�ǁj�ɐݒ�
				maze->map[i][j] = 1;
			}
			else {
				maze->map[i][j] = 0;
			}
		}
	}

	srand(time(NULL));	//�����̃V�[�h�����ݎ����ŏ�����

	for (int y = 2; y < maze->ySize - 1; y = y + 2) {	//�_�|���@�ɂ��ǂ̐���
		for (int x = 2; x < maze->xSize - 1; x = x + 2) {
			int r;	//����

			maze->map[y][x] = 1;	//�_�𗧂Ă�i�ǂɂ���j

			while (true) {	//�_���|����܂�
				if (y == 2) {	//1�Ԗڂ̍s������ɂ��|����
					r = rand() % 4;		//0����3�܂ł̗��������B0����A1���E�A2�����A3����
				}
				else {
					r = rand() % 3 + 1;	//1����3�܂ł̗��������B1���E�A2�����A3����
				}

				if (r == UP) {	//�_��|����������
					if (maze->map[y - 1][x] != 1) {	//�|���������ǂ���Ȃ���Γ|���i�ǂɂ���j
						maze->map[y - 1][x] = 1;
						break;
					}
				}
				else if (r == RIGHT) {	//�_��|���������E
					if (maze->map[y][x + 1] != 1) {	//�|���������ǂ���Ȃ���Γ|���i�ǂɂ���j
						maze->map[y][x + 1] = 1;
						break;
					}
				}
				else if (r == DOWN) {	//�_��|����������
					if (maze->map[y + 1][x] != 1) {	//�|���������ǂ���Ȃ���Γ|���i�ǂɂ���j
						maze->map[y + 1][x] = 1;
						break;
					}
				}
				else if (r == LEFT) {	//�_��|����������
					if (maze->map[y][x - 1] != 1) {	//�|���������ǂ���Ȃ���Γ|���i�ǂɂ���j
						maze->map[y][x - 1] = 1;
						break;
					}
				}
			}
		}
			
	}
}
