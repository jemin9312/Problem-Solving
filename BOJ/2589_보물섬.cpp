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

int n, m;
char map[51][51];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int s_row, s_col, e_row, e_col;
int ans;

void bfs(int row, int col) {

	queue<pair<int, int>> q;
	q.push(make_pair(row, col));

	bool check[50][50] = { false, };
	int dist[50][50] = { 0, };

	check[row][col] = true;

	while (!q.empty()) {
		int t_row = q.front().first;
		int t_col = q.front().second;
		q.pop();

		if (dist[t_row][t_col] > ans) {
			ans = dist[t_row][t_col];
			s_row = row;
			s_col = col;
			e_row = t_row;
			e_col = t_col;
		}

		for (int i = 0; i < 4; i++) {
			int nx = t_row + dx[i];
			int ny = t_col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (!check[nx][ny] && map[nx][ny] == 'L') {
					check[nx][ny] = true;
					dist[nx][ny] = dist[t_row][t_col] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}



	}





}

void go() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}

	

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	/*for (int test_case = 1; test_case <= 10; test_case++) {
		
		cout << "#" << test_case << " " << s << '\n';

	}*/

	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
		}
	}

	go();

	printf("s_row : %d s_col : %d e_row : %d e_col : %d\n", s_row, s_col, e_row, e_col);

	cout << ans << '\n';



	return 0;

}