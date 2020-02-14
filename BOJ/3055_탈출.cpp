#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <stack>
#include <deque>
using namespace std;

typedef struct {

	int row, col, depth;

}Q;

int r, c, s_row, s_col, ans;
char map[51][51];
bool check[50][50];
int dist_go[50][50];
int dist_water[50][50];
queue<Q> water, go_sem;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool is_end, can_move;

void move_go(int depth) {

	while (!go_sem.empty()) {

		int row = go_sem.front().row;
		int col = go_sem.front().col;
		int dep = go_sem.front().depth;

		if (dep >= depth) return;
		else {
			go_sem.pop();

			dist_go[row][col] = dep;

			if (map[row][col] == 'D') {
				is_end = true;
				can_move = true;
				ans = dist_go[row][col];
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nx = row + dx[i];
				int ny = col + dy[i];
				if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
					if (!check[nx][ny] && (map[nx][ny] == '.' || map[nx][ny] == 'D')) {
						check[nx][ny] = true;
						dist_go[nx][ny] = dist_go[row][col] + 1;
						Q qu;
						qu.row = nx;
						qu.col = ny;
						qu.depth = dep + 1;
						can_move = true;
						go_sem.push(qu);
					}
				}
			}


		}


	}
}

void spread_water(int depth) {

	while (!water.empty()) {
		int row = water.front().row;
		int col = water.front().col;
		int dep = water.front().depth;

		if (dep >= depth) return;
		else {
			water.pop();

			dist_water[row][col] = dep;

			for (int i = 0; i < 4; i++) {
				int nx = row + dx[i];
				int ny = col + dy[i];
				if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
					if (!check[nx][ny] && map[nx][ny] == '.') {
						check[nx][ny] = true;
						dist_water[nx][ny] = dist_water[row][col] + 1;
						Q qu;
						qu.row = nx;
						qu.col = ny;
						qu.depth = dep + 1;
						water.push(qu);
					}
				}
			}


		}

	}

}

void go() {

	int tim = 1;

	Q qu;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'S') {
				qu.row = i;
				qu.col = j;
				qu.depth = 0;
				go_sem.push(qu);
			}
			else if (map[i][j] == '*') {
				qu.row = i;
				qu.col = j;
				qu.depth = 0;
				water.push(qu);
			}
		}
	}

	while (1) {


		can_move = false;

		spread_water(tim);

		move_go(tim);

		/*printf("water\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%d ", dist_water[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		printf("go\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%d ", dist_go[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/


		if (is_end) {
			break;
		}

		if (!can_move) {
			break;
		}


		tim++;
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				s_row = i;
				s_col = j;
			}
		}
	}

	go();

	if (can_move) {
		cout << ans << '\n';
	}
	else {
		cout << "KAKTUS" << '\n';
	}
	return 0;

}