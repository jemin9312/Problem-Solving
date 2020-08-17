#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <ctime>
using namespace std;

typedef struct {

	int row, col, dir;
	bool isdie = false;

}FISH;

int map[4][4];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int mx;
FISH fish[17];

void move_fish(int s_row,int s_col) {

	for (int i = 1; i <= 16; i++) {
		int row = fish[i].row;
		int col = fish[i].col;
		int dir = fish[i].dir;
		int n_dir = dir;
		bool move = false;

		if (fish[i].isdie) continue;

		for (int j = 0; j < 8; j++) {

			int nx = row + dx[n_dir];
			int ny = col + dy[n_dir];
			
			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
				if (!(nx == s_row && ny == s_col)) {
					if (map[nx][ny] != 0) {
						int temp_num, temp_dir;
						//옮길 좌표 저장
						temp_num = map[nx][ny];
						temp_dir = fish[map[nx][ny]].dir;

						//옮길 물고기 -> 타겟 물고기
						map[nx][ny] = map[row][col];
						fish[i].row = nx;
						fish[i].col = ny;
						fish[i].dir = n_dir;

						//타겟물고기 -> 옮길 물고기
						map[row][col] = temp_num;
						fish[temp_num].row = row;
						fish[temp_num].col = col;
						fish[temp_num].dir = temp_dir;

						move = true;
						break;
					}
					else if (map[nx][ny] == 0) {

						int temp_num, temp_dir;
						//옮길 좌표 저장
						temp_num = map[nx][ny];
						temp_dir = fish[map[nx][ny]].dir;

						//옮길 물고기 -> 타겟 물고기
						map[nx][ny] = map[row][col];
						fish[i].row = nx;
						fish[i].col = ny;
						fish[i].dir = n_dir;

						//타겟물고기 -> 옮길 물고기
						map[row][col] = temp_num;
						fish[temp_num].row = row;
						fish[temp_num].col = col;
						fish[temp_num].dir = temp_dir;

						move = true;
						break;

					}
				}
			}

			if (move) break;

			n_dir++;
			if (n_dir > 7) n_dir = 0;

		}

	}


}

void go_shark(int row, int col, int dir, int ans,int depth) {


	if (ans > mx) {
		mx = ans;
	}

	FISH temp_fish[17];
	int temp_map[4][4];

	move_fish(row, col);
	memcpy(temp_fish, fish, sizeof(fish));
	memcpy(temp_map, map, sizeof(map));

	/*printf("row : %d col : %d dir : %d ans : %d depth : %d\n", row, col, dir, ans, depth);
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			if (fish[map[a][b]].isdie) printf("0 0 ");
			else printf("%d %d ", map[a][b], fish[map[a][b]].dir);
		}
		printf("\n");
	}
	printf("\n");*/

	for (int i = 1; i <= 3; i++) {
		int nx = row + dx[dir] * i;
		int ny = col + dy[dir] * i;
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			if (!fish[map[nx][ny]].isdie && map[nx][ny] != 0) {
				int temp = map[nx][ny];
				int dir = fish[temp].dir;
				fish[map[nx][ny]].isdie = true;
				map[nx][ny] = 0;
				go_shark(nx, ny, dir, ans + temp, depth + 1);
				map[nx][ny] = temp;
				fish[map[nx][ny]].isdie = false;
				memcpy(fish, temp_fish, sizeof(fish));
				memcpy(map, temp_map, sizeof(map));
			}
		}
	}

}

void go() {

	int start = map[0][0];
	fish[map[0][0]].isdie = true;
	fish[0].dir = fish[start].dir;
	map[0][0] = 0;
	go_shark(0, 0, fish[start].dir, start, 0);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			dir--;
			map[i][j] = num;
			FISH f;
			f.row = i;
			f.col = j;
			f.isdie = false;
			f.dir = dir;
			fish[num] = f;
		}
	}

	fish[0].row = 0;
	fish[0].col = 0;
	fish[0].isdie = true;

	go();

	cout << mx << '\n';

	return 0;
}
