#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

typedef struct {

	int row, col;
	char type;

}Puyo;

int r, c, n;
int cnt = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<int> v;
char map[13][7];
bool is_end = false;
bool bomb = false;
bool check[13][7];

void bfs(int row, int col) {

	queue<Puyo> q;
	vector<Puyo> pu;
	check[row][col] = true;

	Puyo puyo;

	puyo.row = row;
	puyo.col = col;
	puyo.type = map[row][col];

	q.push(puyo);
	pu.push_back(puyo);

	while (!q.empty()) {
		row = q.front().row;
		col = q.front().col;
		char type = q.front().type;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 12 && ny < 6) {
				if (!check[nx][ny] && type == map[nx][ny]) {
					check[nx][ny] = true;
					puyo.row = nx;
					puyo.col = ny;
					puyo.type = map[nx][ny];
					//printf("row : %d col : %d type : %c\n", puyo.row, puyo.col, puyo.type);
					pu.push_back(puyo);
					q.push(puyo);
				}
			}
		}
	}

	//printf("size : %d\n", pu.size());

	if (pu.size() >= 4) {

		is_end = false;
		bomb = true;

		for (int i = 0; i < pu.size(); i++) {
			map[pu[i].row][pu[i].col] = '.';
		}

	}


}

void down(int row, int col) {

	int c_row = row;
	int c_col = col;

	while (1) {


		int nx = c_row + dx[2];
		int ny = c_col + dy[2];

		if (map[nx][ny] != '.' || nx < 0) {
			break;
		}
		else {

			map[nx][ny] = map[c_row][c_col];
			map[c_row][c_col] = '.';
		}

		c_row = nx;
		c_col = ny;


	}


}

void go() {

	while (1) {

		if (is_end) {

			break;
		}

		memset(check, false, sizeof(check));
		is_end = true;
		bomb = false;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					bfs(i, j);
				}
			}
		}

		if (bomb) {
			cnt++;
		}

		//printf("cnt : %d\n", cnt);

		for (int i = 11; i >= 0; i--) {
			for (int j = 6; j >= 0; j--) {
				if (map[i][j] != '.') {
					down(i, j);
				}
			}
		}

		/*printf("\n");

		for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
		printf("%c", map[i][j]);
		}
		printf("\n");
		}*/


	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}

	go();

	cout << cnt << '\n';

	return 0;

}