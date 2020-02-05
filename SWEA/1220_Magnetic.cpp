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

int r;
int map[100][100];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool check[100][100];
int ans;

void cal_state() {

	/*for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/

	bool group = false;
	int color;

	for (int i = 0; i < r; i++) {
		group = false;
		for (int j = 0; j < r; j++) {
			if (map[j][i] != 0) {
				if (map[j][i] == 1 && !group) {
					group = true;
				}
				else if (map[j][i] == 2 && group) {
					ans++;
					group = false;
				}
			}
		}
	}



}

void go() {


	while (1) {

		bool can_move = false;

		/*printf("\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/

		memset(check, false, sizeof(check));

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				if (map[i][j] == 1) {
					int nx = i + dx[2];
					int ny = j + dy[2];
					if (nx >= 0 && ny >= 0 && nx < r && ny < r) {
						if (map[nx][ny] == 0 && !check[i][j]) {
							map[i][j] = 0;
							map[nx][ny] = 1;
							check[nx][ny] = true;
							can_move = true;
						}
					}
					else if (nx < 0 || ny < 0 || nx >= r || ny >= r) {
						map[i][j] = 0;
						can_move = true;
					}
				}
				else if (map[i][j] == 2) {
					int nx = i + dx[0];
					int ny = j + dy[0];
					if (nx >= 0 && ny >= 0 && nx < r && ny < r) {
						if (map[nx][ny] == 0 && !check[i][j]) {
							map[i][j] = 0;
							map[nx][ny] = 2;
							check[nx][ny] = true;
							can_move = true;
						}
					}
					else if (nx < 0 || ny < 0 || nx >= r || ny >= r) {
						map[i][j] = 0;
						can_move = true;
					}
				}
			}
		}

		if (!can_move) break;

	}

	cal_state();

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> r;
		ans = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < r; j++) {
				cin >> map[i][j];
			}
		}

		go();

		//printf("ans : %d\n", ans);

		cout << "#" << test_case << " " << ans << '\n';

	}




	return 0;

}