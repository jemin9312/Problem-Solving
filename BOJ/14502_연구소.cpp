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

int n, m, ans;
int map[8][8];
int temp_map[8][8];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> virus;

void load_map() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = temp_map[i][j];
		}
	}


}

void save_map() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp_map[i][j] = map[i][j];
		}
	}


}

void spread_virus() {

	queue<pair<int, int>>q;

	bool check[8][8] = { false, };

	for (int i = 0; i < virus.size(); i++) {
		q.push(make_pair(virus[i].first, virus[i].second));
		check[virus[i].first][virus[i].second] = true;
	}


	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (!check[nx][ny] && map[nx][ny] == 0) {
					check[nx][ny] = true;
					map[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}

	if (cnt > ans) {
		ans = cnt;
	}

}

void make_wall(int cnt) {

	if (cnt == 3) {

		save_map();

		spread_virus();

		load_map();

		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				make_wall(cnt + 1);
				map[i][j] = 0;
			}
		}
	}


}

void go() {

	make_wall(0);



}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	/*for (int test_case = 1; test_case <= 10; test_case++) {


		cout << "#" << test_case << " " << '\n';
	}*/

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	go();

	cout << ans << '\n';

	return 0;

}