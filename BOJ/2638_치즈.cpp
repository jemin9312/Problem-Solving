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

	int near = 0;
	int num;

}CHEESE;

CHEESE map[100][100];
int n, m;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool check2[100][100];

void bfs(int row, int col) {

	queue<pair<int, int>>q;

	q.push(make_pair(row, col));
	bool check[100][100] = { false, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].num == 1) {
				map[i][j].near = 0;
			}
		}
	}

	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (!check[nx][ny] && map[nx][ny].num == 0) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				else if (map[nx][ny].num == 1) {
					map[nx][ny].near += 1;
				}
			}
		}



	}


}

bool is_over() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j].num == 1) return false;
		}
	}
	return true;

}

void go() {

	int tim = 0;

	while (1) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check2[i][j]) {
					map[i][j].num = 0;
				}
			}
		}

		if (is_over()) {

			break;
		}

		memset(check2, false, sizeof(check2));


		bfs(0, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j].near >= 2 && map[i][j].num == 1) {
					check2[i][j] = true;
				}
			}
		}

		/*printf("time : %d\n", tim);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", check2[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/

		tim++;

	}

	cout << tim << '\n';

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j].num;
		}
	}

	go();

	return 0;
}