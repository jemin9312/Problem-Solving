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
int map[1000][1000];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int a_room = 999999999;
int ans;


void dfs(int s_row,int s_col,int row, int col, int cnt) {

	if (cnt >= ans) {
		if (ans == cnt) {
			if (a_room > map[s_row][s_col]) {
				a_room = map[s_row][s_col];
			}
		}
		else if (cnt > ans) {
			a_room = map[s_row][s_col];
		}
		ans = cnt;
	}

	for (int i = 0; i < 4; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (map[nx][ny] == map[row][col] + 1) {
				dfs(s_row,s_col,nx, ny, cnt + 1);
			}
		}
	}


}

void go() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dfs(i,j,i, j, 1);
		}
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		memset(map, 0, sizeof(map));
		ans = 0;

		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		go();

		cout << "#" << test_case << " " <<a_room << " " <<ans<< '\n';
		
		
	}


	return 0;

}