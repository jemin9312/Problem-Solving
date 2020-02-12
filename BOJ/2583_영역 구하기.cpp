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

typedef struct{

	int s_row,s_col,e_row,e_col;

}SQ;

int m, n, k;
int map[101][101];
bool check[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<SQ> sq;
vector<int> ans;

int bfs(int row, int col, int cnt) {

	queue<pair<int, int>> q;

	q.push(make_pair(row, col));
	
	int s_cnt = cnt;

	check[row][col] = true;
	

	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
				if (!check[nx][ny] && map[nx][ny] == 0) {
					check[nx][ny] = true;
					s_cnt++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return s_cnt;
}

void go() {

	for (int i = 0; i < k; i++) {
		int s_row = sq[i].s_row;
		int s_col = sq[i].s_col;
		int e_row = sq[i].e_row;
		int e_col = sq[i].e_col;

		if (s_row < e_row) {
			if (s_col < e_col) {
				for (int j = s_row; j <= e_row; j++) {
					for (int k = s_col; k <= e_col; k++) {
						map[j][k] = 1;
					}
				}
			}
			else {
				for (int j = s_row; j <= e_row; j++) {
					for (int k = e_col; k <= s_col; k++) {
						map[j][k] = 1;
					}
				}
			}
		}
		else {
			if (s_col < e_col) {
				for (int j = e_row; j <=s_row; j++) {
					for (int k = s_col; k <= e_col; k++) {
						map[j][k] = 1;
					}
				}
			}
			else {
				for (int j = e_row; j <= s_row; j++) {
					for (int k = e_col; k <= s_col; k++) {
						map[j][k] = 1;
					}
				}
			}
		}

	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && !check[i][j]) {
				int cnt;
				cnt = bfs(i, j, 1);
				ans.push_back(cnt);
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


		cout << "#" << test_case << " " << '\n';
	}*/

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		SQ squ;
		squ.s_row = m - 1 - b;
		squ.s_col = a;
		squ.e_row = m - d;
		squ.e_col = c - 1;
		sq.push_back(squ);
	}

	go();

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";


	return 0;

}