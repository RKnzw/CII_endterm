#include "maze.h"

void makeMaze(maze* maze) {	//ñ_ì|Çµñ@Ç…ÇÊÇÈñ¿òHê∂ê¨

	for (int i = 0; i < maze->ySize; i++) {
		for (int j = 0; j < maze->xSize; j++) {
			if (i == 0 || j == 0 || i == maze->ySize - 1 || j == maze->xSize - 1) {	//í[Ç1Åiï«ÅjÇ…ê›íË
				maze->map[i][j] = 1;
			}
			else {
				maze->map[i][j] = 0;
			}
		}
	}

	for (int y = 2; y < maze->ySize - 1; y = y + 2) {	//ñ_ì|Çµñ@Ç…ÇÊÇÈï«ÇÃê∂ê¨
		for (int x = 2; x < maze->xSize - 1; x = x + 2) {
			int r;	//óêêî

			maze->map[y][x] = 1;	//ñ_ÇóßÇƒÇÈÅiï«Ç…Ç∑ÇÈÅj

			while (true) {	//ñ_Ç™ì|ÇπÇÈÇ‹Ç≈
				if (y == 2) {	//1î‘ñ⁄ÇÃçsÇæÇØè„Ç…Ç‡ì|ÇπÇÈ
					r = rand() % 4;		//0Ç©ÇÁ3Ç‹Ç≈ÇÃóêêîê∂ê¨ÅB0Ç™è„ÅA1Ç™âEÅA2Ç™â∫ÅA3Ç™ç∂
				}
				else {
					r = rand() % 3 + 1;	//1Ç©ÇÁ3Ç‹Ç≈ÇÃóêêîê∂ê¨ÅB1Ç™âEÅA2Ç™â∫ÅA3Ç™ç∂
				}

				if (r == UP) {	//ñ_Çì|Ç∑ï˚å¸Ç™è„
					if (maze->map[y - 1][x] != 1) {	//ì|Ç∑ï˚å¸Ç™ï«Ç∂Ç·Ç»ÇØÇÍÇŒì|Ç∑Åiï«Ç…Ç∑ÇÈÅj
						maze->map[y - 1][x] = 1;
						break;
					}
				}
				else if (r == RIGHT) {	//ñ_Çì|Ç∑ï˚å¸Ç™âE
					if (maze->map[2][x + 1] != 1) {	//ì|Ç∑ï˚å¸Ç™ï«Ç∂Ç·Ç»ÇØÇÍÇŒì|Ç∑Åiï«Ç…Ç∑ÇÈÅj
						maze->map[2][x + 1] = 1;
						break;
					}
				}
				else if (r == DOWN) {	//ñ_Çì|Ç∑ï˚å¸Ç™â∫
					if (maze->map[2 + 1][x] != 1) {	//ì|Ç∑ï˚å¸Ç™ï«Ç∂Ç·Ç»ÇØÇÍÇŒì|Ç∑Åiï«Ç…Ç∑ÇÈÅj
						maze->map[2 + 1][x] = 1;
						break;
					}
				}
				else if (r == LEFT) {	//ñ_Çì|Ç∑ï˚å¸Ç™ç∂
					if (maze->map[2][x - 1] != 1) {	//ì|Ç∑ï˚å¸Ç™ï«Ç∂Ç·Ç»ÇØÇÍÇŒì|Ç∑Åiï«Ç…Ç∑ÇÈÅj
						maze->map[2][x - 1] = 1;
						break;
					}
				}
			}
		}
			
	}
}
