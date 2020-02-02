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

	int row, col, dir;

}TREE;

int n;
char map[51][51];
int s_t_r, s_t_c, e_t_r, e_t_c;
int s_r, s_c, s_d;
int e_r, e_c, e_d;
int dx[] = { -1,0,1,0,0 };
int dy[] = { 0,1,0,-1,0 };
int dist[2][50][50];

bool can_go(int row, int col, int dir) {

	if (dir == 0) {
		if (row - 1 >= 0 && row + 1 < n) {
			if (map[row - 1][col] != '1' && map[row + 1][col] != '1' && map[row][col] != '1') return true;
		}
	}
	else {
		if (col - 1 >= 0 && col + 1 < n) {
			if (map[row][col - 1] != '1' && map[row][col + 1] != '1' && map[row][col] != '1') return true;
		}
	}

	return false;

}

bool can_turn(int row,int col,int dir) {

	//0 |
	//1 ---

	if (dir == 0) {
		if (row - 1 >= 0 && row + 1 < n && col - 1>=0 && col + 1 < n) {
			if (map[row - 1][col] != '1' && map[row + 1][col] != '1' && map[row - 1][col + 1] != '1' && map[row - 1][col - 1] != '1' && map[row + 1][col - 1] != '1' && map[row + 1][col + 1] != '1')
				return true;
		}
	}
	else {
		if (col - 1 >= 0 && col + 1 < n && row - 1 >= 0 && row + 1 < n) {
			if (map[row][col + 1] != '1' && map[row][col - 1] != '1' && map[row - 1][col + 1] != '1' && map[row - 1][col - 1] != '1' && map[row + 1][col - 1] != '1' && map[row + 1][col + 1] != '1')
				return true;
		}
	}

	return false;

}

void go(int row,int col) {

	queue<TREE> q;
	TREE tree;
	tree.row = row;
	tree.col = col;
	tree.dir = s_d;
	q.push(tree);

	bool check[2][50][50] = { false, };
	check[tree.dir][tree.row][tree.col] = true;
	

	while (!q.empty()) {
		row = q.front().row;
		col = q.front().col;
		int dir = q.front().dir;
		q.pop();

		for (int i = 0; i < 5; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			int n_dir = dir;
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (i == 4) {
					if (dir == 0) n_dir = 1;
					else n_dir = 0;
					if (can_turn(nx, ny, n_dir) && !check[n_dir][nx][ny]) {
						check[n_dir][nx][ny] = true;
						tree.row = nx;
						tree.col = ny;
						tree.dir = n_dir;
						dist[n_dir][nx][ny] = dist[dir][row][col] + 1;
						q.push(tree);
					}
				}
				else {
					if (can_go(nx, ny, dir) && !check[dir][nx][ny]) {
						check[dir][nx][ny] = true;
						tree.row = nx;
						tree.col = ny;
						tree.dir = dir;
						dist[dir][nx][ny] = dist[dir][row][col] + 1;
						q.push(tree);
					}
				}
			}
		}


	}

	for (int i = 0; i < 2; i++) {
		printf("i : %d\n", i);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				printf("%d ", dist[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");

	printf("%d\n", dist[e_d][e_r][e_c]);


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	bool s_t = false;
	bool s_m = false;
	bool e_t = false;
	bool e_m = false;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'B') {
				if (!s_t) {
					s_t = true;
					s_t_r = i;
					s_t_c = j;
				}
				else if (!s_m) {
					s_m = true;
					s_r = i;
					s_c = j;
				}
			}
			else if (map[i][j] == 'E') {
				if (!e_t) {
					e_t = true;
					e_t_r = i;
					e_t_c = j;
				}
				else if (!e_m) {
					e_m = true;
					e_r = i;
					e_c = j;
				}
			}
		}
	}

	//0 |
	//1 ---

	if (s_r - 1 == s_t_r) {
		s_d = 0;
	}
	else if (s_c - 1 == s_t_c) {
		s_d = 1;
	}

	if (e_r - 1 == e_t_r) {
		e_d = 0;
	}
	else if (e_c - 1 == e_t_c) {
		e_d = 1;
	}

	go(s_r, s_c);

	printf("e_t_r : %d e_t_c : %d\n", e_t_r, e_t_c);
	printf("e_r : %d e_c : %d e_d : %d\n", e_r, e_c, e_d);

	cout << dist[e_d][e_r][e_c] << '\n';


	return 0;
}