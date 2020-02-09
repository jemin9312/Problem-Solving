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

int n;
int ans = 99999999;
int map[21][21];
bool check[21][21];
int sub_map[21][21];
int dx[] = { 1,1,1 };
int dy[] = { 0,-1,1 };


void fill_5(int row, int col) {


	for (int i = col + 1; i <= n; i++) {
		if (sub_map[row][i] == 5) break;
		else if (sub_map[row][i] == 0) {
			sub_map[row][i] = 5;
		}

	}




}

void make_map(int row, int col, int d1, int d2) {

	for (int i = 0; i <= d1; i++) {
		sub_map[row + i][col - i] = 5;
	}

	for (int i = 0; i <= d2; i++) {
		sub_map[row + i][col + i] = 5;
	}

	for (int i = 0; i <= d2; i++) {
		sub_map[row + d1 + i][col - d1 + i] = 5;
	}

	for (int i = 0; i <= d1; i++) {
		sub_map[row + d2 + i][col + d2 - i] = 5;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == row && j == col) continue;
			if (i == row + d1 + d2 && j == col + d2 - d1) continue;
			if (sub_map[i][j] == 5) {
				fill_5(i, j);
				break;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (sub_map[i][j] != 0) continue;
			if (i >= 1 && i < row + d1 && j >= 1 && j <= col) {
				sub_map[i][j] = 1;
			}
			else if (i >= 1 && i <= row + d2 && j > col && j <= n) {
				sub_map[i][j] = 2;
			}
			else if (i >= row + d1 && i <= n && j >= 1 && j < col - d1 + d2) {
				sub_map[i][j] = 3;
			}
			else if (i > row + d2 && i <= n && j >= col - d1 + d2 && j <= n) {
				sub_map[i][j] = 4;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (sub_map[i][j] == 0) sub_map[i][j] = 5;
		}
	}

	/*for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= n; j++) {
	printf("%d ", sub_map[i][j]);
	}
	printf("\n");
	}
	printf("\n");*/

	int sub_num[5] = { 0, };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (sub_map[i][j] == 1) sub_num[0] += map[i][j];
			else if (sub_map[i][j] == 2) sub_num[1] += map[i][j];
			else if (sub_map[i][j] == 3) sub_num[2] += map[i][j];
			else if (sub_map[i][j] == 4) sub_num[3] += map[i][j];
			else if (sub_map[i][j] == 5) sub_num[4] += map[i][j];
		}
	}

	int mx = 0;
	int mn = 99999999;

	for (int i = 0; i < 5; i++) {
		if (mn > sub_num[i]) mn = sub_num[i];
		if (sub_num[i] > mx)mx = sub_num[i];
	}

	if (ans > mx - mn) {
		ans = mx - mn;
	}


}

bool can_go(int row, int col, int d1, int d2) {

	if (row + d1 <= n && col - d1 >= 1 && row + d2 <= n && col + d2 <= n && row + d1 + d2 <= n && col - d1 + d2 <= n && row + d1 + d2 <= n && col + d2 - d1 >= 1)
		return true;

	return false;


}

void go() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (can_go(i, j, d1, d2)) {
						memset(sub_map, 0, sizeof(sub_map));
						//printf("row : %d col : %d d1 : %d d2 : %d\n", i, j, d1, d2);
						make_map(i, j, d1, d2);
					}
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

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	go();

	cout << ans << '\n';

	return 0;
}