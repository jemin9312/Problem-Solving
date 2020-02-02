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

char map[6][6];
bool check[5][5];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ans;

bool is_near() {

	vector<pair<int, int>> v;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[i][j]) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(v[0]);

	bool check2[5][5] = { false, };
	check2[v[0].first][v[0].second] = true;

	int cnt = 1;

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
				if (!check2[nx][ny] && check[nx][ny]) {
					//printf("nx : %d ny : %d\n", nx, ny);
					check2[nx][ny] = true;
					cnt++;
					q.push(make_pair(nx, ny));
				}
			}
		}
		



	}

	if (cnt == 7) return true;
	else return false;




}

bool is_many() {

	int sum_y = 0;
	int sum_s = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[i][j]) {
				if (map[i][j] == 'Y') {
					sum_y++;
				}
				else {
					sum_s++;
				}
			}
		}
	}

	if (sum_s >= 4) return true;
	else return false;



}


void dfs(int row,int col,int cnt) {

	if (cnt == 7) {

		/*for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				printf("%d ", check[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/

		if (is_near() && is_many()) {
			ans++;
		}

		return;
	}

	for (int i = row; i < 5; i++) {
		for (int j = col; j < 5; j++) {
			if (!check[i][j]) {
				check[i][j] = true;
				dfs(i,j + 1,cnt + 1);
				check[i][j] = false;
			}
		}
		col = 0;
	}


}

void go() {


	dfs(0,0,0);


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}

	go();

	cout << ans << '\n';

	return 0;
}