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

int map[1000];
int sub_map[256][1000];
int T, tc;
int ans;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

bool can_see(int row, int col) {


	for (int i = 1; i <= 2; i++) {
		int nx = row + dx[1] * i;
		int ny = col + dy[1] * i;
		if (sub_map[nx][ny]) return false;
	}

	for (int i = 1; i <= 2; i++) {
		int nx = row + dx[3] * i;
		int ny = col + dy[3] * i;
		if (sub_map[nx][ny]) return false;
	}


	return true;


}

void go() {

	for (int i = 0; i < tc; i++) {
		if (map[i]) {
			for (int j = 0; j < map[i]; j++) {
				if (can_see(j, i)) {
					ans++;
				}
			}
		}
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> tc;
		ans = 0;
		memset(map, 0, sizeof(map));
		memset(sub_map, 0, sizeof(sub_map));

		for (int i = 0; i < tc; i++) {
			cin >> map[i];
		}

		for (int i = 0; i < tc; i++) {
			if (map[i]) {
				for (int j = 0; j < map[i]; j++) {
					sub_map[j][i]++;
				}
			}
		}

		go();

		cout << "#" << test_case << " " << ans << '\n';

	}




	return 0;

}