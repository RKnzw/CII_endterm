// chuukan2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "maze.h"

int main()
{
	int xSize;	//迷路の横の大きさ
	int ySize;	//迷路の縦の大きさ
	int cnt = 0;	//何個目の迷路か
	int key;	//キー入力

	char directory[BUFFSIZE];	//現在のディレクトリ
	char setting[BUFFSIZE];	//設定ファイル名

	getCurrentDirectory(directory);	//現在のディレクトリ取得
	sprintf_s(setting, "%s\\setting.ini", directory);	//設定ファイルの絶対パスを生成
	xSize = readInt("section1", "xSize", -1, setting);	//設定ファイルから迷路の大きさ取得
	ySize = readInt("section1", "ySize", -1, setting);

	if (xSize < 5 || ySize < 5 || xSize >= xMax || ySize >= yMax) {	//迷路の大きさが5×5未満か、30×30以上
		fprintf_s(stderr, "迷路の大きさは5×5以上、30×30未満でければなりません。\n現在のサイズ：%d×%d\n", ySize, xSize);
	}
	else if (xSize % 2 != 1 || ySize % 2 != 1) {	//迷路の1辺の大きさが奇数
		fprintf_s(stderr, "迷路の1辺の大きさは奇数でなければなりません。\n現在のサイズ：%d×%d\n", ySize, xSize);
	}
	else {							//迷路の大きさが5×5以上かつ30×30未満で、かつ奇数
		if (initscr() == NULL) {
			return 1;
		}
		noecho();
		cbreak();
		keypad(stdscr, TRUE);
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);	// 色1 は黒地に赤文字
		init_pair(2, COLOR_WHITE, COLOR_BLACK);	// 色2 は黒地に白文字
		init_pair(3, COLOR_GREEN, COLOR_BLACK);	// 色2 は黒地に緑文字

		mvaddstr(15, 40, "Press S to start!!");
		while (true) {
			key = getch();
			if (key == 'S' || key == 's') {
				break;
			}
		}
		

		while (true) {
			erase();	//迷路をクリアするごとに内側のwhile文を抜けてここに戻ってくる

			maze* myMaze = new maze();
			sprintf_s(myMaze->name, "maze%d", cnt);
			myMaze->ySize = ySize;
			myMaze->xSize = xSize;

			attrset(COLOR_PAIR(2));
			mvaddstr(29, 0, "making maze...");
			refresh();
			makeMaze(myMaze);	//迷路の生成
			maze2Txt(myMaze);	//迷路のファイル出力
			erase();

			attrset(COLOR_PAIR(2));
			for (int i = 0; i < myMaze->ySize; i++) {	//迷路の描画。
				for (int j = 0; j < myMaze->xSize; j++) {	//壁は白字で*
					if (myMaze->map[i][j] == 1) {
						attrset(COLOR_PAIR(2));
						mvaddch(i, j, '*');
					}
					if (i == myMaze->ySize - 2 && j == myMaze->xSize - 2) {	//ゴール位置に緑文字でG
						attrset(COLOR_PAIR(3));
						mvaddch(i, j, 'G');
					}
				}
			}
			attrset(COLOR_PAIR(2));
			mvprintw(29, 40, "maze%d", cnt);

			player myPlayer{ XSTART, YSTART };	//プレイヤーの座標を初期化

			while (true) {	//迷路をプレイ中の処理
				attrset(COLOR_PAIR(1));
				mvaddch(myPlayer.y, myPlayer.x, '*');	//プレイヤーを描画
				refresh();

				key = getch();
				if (key == KEY_UP) {			//入力方向に壁がなければその方向に進む。
					if (myMaze->map[myPlayer.y - 1][myPlayer.x] == 0) {	//xとyがxSize-2とySize-2の間のみで変動するように、
						mvaddch(myPlayer.y, myPlayer.x, ' ');			//迷路を設定している（一番外側はすべて壁）
						myPlayer.y--;
					}
				}
				else if (key == KEY_DOWN) {
					if (myMaze->map[myPlayer.y + 1][myPlayer.x] == 0) {
						mvaddch(myPlayer.y, myPlayer.x, ' ');
						myPlayer.y++;
					}
				}
				else if (key == KEY_RIGHT) {
					if (myMaze->map[myPlayer.y][myPlayer.x + 1] == 0) {
						mvaddch(myPlayer.y, myPlayer.x, ' ');
						myPlayer.x++;
					}
				}
				else if (key == KEY_LEFT) {
					if (myMaze->map[myPlayer.y][myPlayer.x - 1] == 0) {
						mvaddch(myPlayer.y, myPlayer.x, ' ');
						myPlayer.x--;
					}
				}

				if (myPlayer.x == myMaze->xSize - 2 && myPlayer.y == myMaze->ySize - 2) {	//右下のゴールに来たら迷路クリア。
					cnt++;	//迷路の数を更新
					break;	//迷路の情報を更新するためにbreakで内側のwhile文を抜ける
				}
			}
		}
	}
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
