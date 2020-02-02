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

int n, m;
int q_n, k_n, p_n;
int map[1000][1000];
bool check[1000][1000];
bool sub_check[1000][1000];
int dx[] = { -1,0,1,0,1,-1,1,-1 };
int dy[] = { 0,1,0,-1,1,1,-1,-1 };
int dx_n[] = { -2,2,-2,2,-1,1,-1,1 };
int dy_n[] = { 1,-1,-1,1,2,2,-2,-2 };
int ans;

void go_knight(int row, int col) {


	for (int i = 0; i < 8; i++) {
		int nx = row + dx_n[i];
		int ny = col + dy_n[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			check[nx][ny] = true;
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}
	printf("\n");


}

void go_queen(int row, int col,int dir) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	check[row][col] = true;
	sub_check[row][col] = true;

	int nx = row + dx[dir];
	int ny = col + dy[dir];
	if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
		if (!sub_check[nx][ny] && map[nx][ny] == 0) {
			sub_check[nx][ny] = true;
			check[nx][ny] = true;
			go_queen(nx, ny, dir);
		}
	}


}

void go() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				memset(sub_check, false, sizeof(sub_check));
				check[i][j] = true;
				for (int k = 0; k < 8; k++) {
					go_queen(i, j, k);
				}
			}
			else if (map[i][j] == 2) {
				check[i][j] = true;
				go_knight(i, j);
			}
			else if (map[i][j] == 3) {
				check[i][j] = true;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) ans++;
		}
	}

}

int main() {

	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;*/

	scanf("%d %d", &n, &m);

	scanf("%d", &q_n);
	for (int i = 0; i < q_n; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		map[r - 1][c - 1] = 1;
	}
	scanf("%d", &k_n);
	for (int i = 0; i < k_n; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		map[r - 1][c - 1] = 2;
	}
	scanf("%d", &p_n);
	for (int i = 0; i < p_n; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		map[r - 1][c - 1] = 3;
	}

	go();

	printf("%d\n", ans);

	return 0;
}