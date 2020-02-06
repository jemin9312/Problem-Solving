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

int T, n;
int map[20][20];
bool check[20][20];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
string s;


void move(int row, int col, int dir) {


	int nx = row + dx[dir];
	int ny = col + dy[dir];
	if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
		if (map[nx][ny] == 0) {
			map[nx][ny] = map[row][col];
			map[row][col] = 0;
			move(nx, ny, dir);
		}
		else if (map[nx][ny] > 0 && !check[nx][ny]) {
			check[nx][ny] = true;
			if (map[nx][ny] == map[row][col]) {
				map[nx][ny] += map[row][col];
				map[row][col] = 0;
				move(nx, ny, dir);
			}
		}
	}


}

void go() {

	if (s == "up") {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0)
					move(i, j, 0);
			}
		}
	}
	else if (s == "right") {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (map[j][i] != 0)
					move(j, i, 1);
			}
		}
	}
	else if (s == "down") {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0)
					move(i, j, 2);
			}
		}
	}
	else if (s == "left") {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[j][i] != 0)
					move(j, i, 3);
			}
		}
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		memset(map, 0, sizeof(map));
		memset(check, false, sizeof(check));
		cin >> n >> s;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		go();

		cout << "#" << test_case << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << '\n';
		}

	}


	return 0;

}