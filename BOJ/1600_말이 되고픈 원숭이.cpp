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
using namespace std;

typedef struct {

	int row, col, num;


}MONKEY;

int k, w, h;
int mn = 99999999;
int map[200][200];
int dx[] = { -2,2,-2,2,-1,1,-1,1 ,-1,0,1,0 };
int dy[] = { 1,1,-1,-1,-2,-2,2,2 ,0,1,0,-1 };
bool check[30][200][200] = { false, };
int dist[31][200][200] = { 0, };

void bfs(int row, int col, int k_num) {

	queue<MONKEY> q;

	MONKEY monkey;

	monkey.row = row;
	monkey.col = col;
	monkey.num = k_num;

	q.push(monkey);


	check[k_num][row][col] = true;

	while (!q.empty()) {
		row = q.front().row;
		col = q.front().col;
		k_num = q.front().num;
		q.pop();

		//printf("row : %d col : %d k_num : %d dist : %d\n", row, col, k_num,dist[k_num][row][col]);

		for (int i = 0; i < 12; i++) {
			if (i >= 0 && i <= 7) {
				if (k_num <= 0) continue;
			}
			int nx = row + dx[i];
			int ny = col + dy[i];
			int n_num = k_num;
			if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
				if (i >= 0 && i <= 7) {
					n_num -= 1;
					if (!check[n_num][nx][ny] && map[nx][ny] != 1) {
						check[n_num][nx][ny] = true;
						monkey.row = nx;
						monkey.col = ny;
						monkey.num = n_num;
						dist[n_num][nx][ny] = dist[k_num][row][col] + 1;
						q.push(monkey);
					}
				}
				else {
					if (!check[n_num][nx][ny] && map[nx][ny] != 1) {
						check[n_num][nx][ny] = true;
						monkey.row = nx;
						monkey.col = ny;
						monkey.num = n_num;
						dist[n_num][nx][ny] = dist[k_num][row][col] + 1;
						q.push(monkey);
					}
				}
			}
		}


	}

	

	for (int i = 0; i <= k; i++) {
		if (check[i][h - 1][w - 1]) {
			if (mn > dist[i][h - 1][w - 1]) {
				mn = dist[i][h - 1][w - 1];
			}
		}
	}


}


void go() {

	bfs(0, 0, k);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> k;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	go();

	if (mn == 99999999) cout << -1 << '\n';
	else cout << mn << '\n';


	return 0;

}