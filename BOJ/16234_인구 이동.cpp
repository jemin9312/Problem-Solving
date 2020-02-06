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

int n, l, r;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int map[50][50];
bool check[50][50];
bool is_move;
int ans;

void bfs(int row, int col) {

	vector<pair<int, int>> v;
	queue<pair<int, int>> q;

	check[row][col] = true;
	v.push_back(make_pair(row, col));
	q.push(make_pair(row, col));

	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (!check[nx][ny]) {
					if (abs(map[nx][ny] - map[row][col]) >= l && abs(map[nx][ny] - map[row][col]) <= r) {
						check[nx][ny] = true;
						//printf("nx : %d ny : %d\n", nx, ny);
						q.push(make_pair(nx, ny));
						v.push_back(make_pair(nx, ny));
					}
				}
			}
		}


	}

	if (v.size() > 1) is_move = true;

	int sum = 0;

	for (int i = 0; i < v.size(); i++) {
		int r = v[i].first;
		int c = v[i].second;
		sum += map[r][c];
	}

	sum /= v.size();

	for (int i = 0; i < v.size(); i++) {
		int r = v[i].first;
		int c = v[i].second;
		map[r][c] = sum;
	}



}

void move() {

	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				bfs(i, j);
			}
		}
	}


}

void go() {

	int cnt = 0;

	while (1) {

		is_move = false;

		memset(check, false, sizeof(check));

		move();

		if (!is_move) {
			ans = cnt;
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		cnt++;

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

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	go();

	cout << ans << '\n';

	return 0;

}