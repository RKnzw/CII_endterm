#include "maze.h"

void makeMaze(maze* maze) {	//棒倒し法による迷路生成

	for (int i = 0; i < maze->ySize; i++) {
		for (int j = 0; j < maze->xSize; j++) {
			if (i == 0 || j == 0 || i == maze->ySize - 1 || j == maze->xSize - 1) {	//端を1（壁）に設定
				maze->map[i][j] = 1;
			}
			else {
				maze->map[i][j] = 0;
			}
		}
	}

	srand(time(NULL));	//乱数のシードを現在時刻で初期化

	for (int y = 2; y < maze->ySize - 1; y = y + 2) {	//棒倒し法による壁の生成
		for (int x = 2; x < maze->xSize - 1; x = x + 2) {
			int r;	//乱数

			maze->map[y][x] = 1;	//棒を立てる（壁にする）

			while (true) {	//棒が倒せるまで
				if (y == 2) {	//1番目の行だけ上にも倒せる
					r = rand() % 4;		//0から3までの乱数生成。0が上、1が右、2が下、3が左
				}
				else {
					r = rand() % 3 + 1;	//1から3までの乱数生成。1が右、2が下、3が左
				}

				if (r == UP) {	//棒を倒す方向が上
					if (maze->map[y - 1][x] != 1) {	//倒す方向が壁じゃなければ倒す（壁にする）
						maze->map[y - 1][x] = 1;
						break;
					}
				}
				else if (r == RIGHT) {	//棒を倒す方向が右
					if (maze->map[y][x + 1] != 1) {	//倒す方向が壁じゃなければ倒す（壁にする）
						maze->map[y][x + 1] = 1;
						break;
					}
				}
				else if (r == DOWN) {	//棒を倒す方向が下
					if (maze->map[y + 1][x] != 1) {	//倒す方向が壁じゃなければ倒す（壁にする）
						maze->map[y + 1][x] = 1;
						break;
					}
				}
				else if (r == LEFT) {	//棒を倒す方向が左
					if (maze->map[y][x - 1] != 1) {	//倒す方向が壁じゃなければ倒す（壁にする）
						maze->map[y][x - 1] = 1;
						break;
					}
				}
			}
		}
			
	}
}
