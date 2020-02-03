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
	bool can_crash;

}BLOCK;

int n, m;
int map[1000][1000];
bool check[2][1000][1000] = { false, };
int dist[2][1000][1000] = { 0, };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int row, int col, int can_crash) {

	queue<BLOCK> q;
	BLOCK block;
	block.row = row;
	block.col = col;
	block.can_crash = can_crash;
	q.push(block);

	
	check[can_crash][row][col] = true;
	dist[can_crash][row][col] = 1;

	//printf("row : %d col : %d\n", row, col);

	

	while (!q.empty()) {
		row = q.front().row;
		col = q.front().col;
		can_crash = q.front().can_crash;
		q.pop();

		//printf("row : %d col : %d crash: %d\n", row, col, can_crash);

		if (row == n - 1 && col == m - 1) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] == 0 && !check[can_crash][nx][ny]) {
					check[can_crash][nx][ny] = true;
					dist[can_crash][nx][ny] = dist[can_crash][row][col] + 1;
					block.row = nx;
					block.col = ny;
					block.can_crash = can_crash;
					q.push(block);
				}
				else if (map[nx][ny] == 1 && !can_crash && !check[1][nx][ny]) {
					check[1][nx][ny] = true;
					dist[1][nx][ny] = dist[0][row][col] + 1;
					block.row = nx;
					block.col = ny;
					block.can_crash = true;
					q.push(block);
				}
			}
		}


	}

	/*for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", dist[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}*/

	int mx = 999999;

	for (int i = 0; i < 2; i++) {
		if (dist[i][n - 1][m - 1] < mx && dist[i][n-1][m-1] != 0) {
			mx = dist[i][n - 1][m - 1];
		}
	}

	if (mx == 999999) {
		cout << -1;
	}
	else {
		cout << mx;
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = (int)(s[j] - '0');
		}
	}

	
	
	bfs(0, 0, 0);

	

	return 0;

}