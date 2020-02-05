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

int tc;
int map[16][16];
bool check[16][16];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int s_row, s_col, e_row, e_col;

void go(int row,int col) {

	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	check[row][col] = true;

	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 16 && ny < 16) {
				if (!check[nx][ny] && map[nx][ny] == 0 || map[nx][ny] == 3) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}

	}
	


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		memset(check, false, sizeof(check));
		memset(map, false, sizeof(map));
		cin >> tc;

		

		for (int i = 0; i < 16; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 16; j++) {
				map[i][j] = (int)(s[j] - '0');
				if (map[i][j] == 2) {
					s_row = i;
					s_col = j;
				}
				else if (map[i][j] == 3) {
					e_row = i;
					e_col = j;
				}
			}
		}

		go(s_row, s_col);

		cout << "#" << test_case << " " << check[e_row][e_col] << '\n';

	}




	return 0;

}