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
int ans = 99999999;
int map[50][50];
int temp_map[50][50];
bool check[10];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<pair<int, int>> virus;

void save_map() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp_map[i][j] = map[i][j];
		}
	}


}

void load_map() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = temp_map[i][j];
		}
	}

}

void spread_virus() {

	queue<pair<int, int>> q;
	bool check2[50][50] = { false, };
	for (int i = 0; i < virus.size(); i++) {
		if (check[i]) {
			q.push(make_pair(virus[i].first, virus[i].second));
			check2[virus[i].first][virus[i].second] = true;
		}
	}


	int dist[50][50] = { 0, };

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (map[nx][ny] == 0 || map[nx][ny] == 2 && !check2[nx][ny]) {
					if (dist[nx][ny] == 0 || dist[nx][ny] > dist[row][col] + 1) {
						dist[nx][ny] = dist[row][col] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

	int s_mx = 0;
	bool can_spread = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				if (dist[i][j] == 0) can_spread = false;
			}
		}
	}

	if (can_spread) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//printf("%d ", dist[i][j]);
				if (dist[i][j] > s_mx) {
					s_mx = dist[i][j];
				}
			}
			//printf("\n");
		}
		//printf("\n");

		//printf("s_mx : %d\n", s_mx);

		if (ans > s_mx) {
			ans = s_mx;
		}

	}


}


void dfs(int idx, int cnt) {

	if (cnt == m) {

		save_map();

		for (int i = 0; i < virus.size(); i++) {
			//printf("%d ", check[i]);
		}
		//printf("\n");

		spread_virus();


		load_map();

		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			dfs(i + 1, cnt + 1);
			check[i] = false;
		}
	}



}

void go() {

	dfs(0, 0);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	go();

	if (ans == 99999999) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;

}