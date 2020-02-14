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

int n, ans;
int map[16][16];
bool check[16][16];
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };

void dfs(int row, int col, int dir) {

	if (row == n - 1 && col == n - 1) {
		ans++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (!check[nx][ny] && map[nx][ny] == 0) {
				if (dir == 0) {
					if (i == 1) continue;
					if (i == 2) {
						if (map[row + 1][col] == 0 && map[row][col + 1] == 0) {
							check[nx][ny] = true;
							dfs(nx, ny, 2);
							check[nx][ny] = false;
						}
					}
					else if (i == 0) {
						check[nx][ny] = true;
						dfs(nx, ny, 0);
						check[nx][ny] = false;
					}
				}
				else if (dir == 1) {
					if (i == 0) continue;
					if (i == 1) {
						check[nx][ny] = true;
						dfs(nx, ny, 1);
						check[nx][ny] = false;
					}
					else if (i == 2) {
						if (map[row + 1][col] == 0 && map[row][col + 1] == 0) {
							check[nx][ny] = true;
							dfs(nx, ny, 2);
							check[nx][ny] = false;
						}
					}
				}
				else if (dir == 2) {
					if (i == 0) {
						check[nx][ny] = true;
						dfs(nx, ny, 0);
						check[nx][ny] = false;
					}
					else if (i == 1) {
						check[nx][ny] = true;
						dfs(nx, ny, 1);
						check[nx][ny] = false;
					}
					else if (i == 2) {
						if (map[row + 1][col] == 0 && map[row][col + 1] == 0) {
							check[nx][ny] = true;
							dfs(nx, ny, 2);
							check[nx][ny] = false;
						}
					}
				}
			}
		}
	}


}


void go() {

	dfs(0, 1, 0);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	go();

	cout << ans << '\n';


	return 0;
}