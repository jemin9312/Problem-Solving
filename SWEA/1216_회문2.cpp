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

char map[101][101];
int len, ans;

void check_sero(int row, int col, int length) {
	int s_row = row;
	int e_row = row + length - 1;
	int s_col = col;
	int e_col = col;
	bool is_true = true;

	while (1) {

		if (s_row > e_row) {
			break;
		}
		if (map[s_row][s_col] != map[e_row][e_col]) {
			is_true = false;
			break;
		}
		else {

			s_row++;
			e_row--;
		}

	}

	if (is_true) {
		if (length > ans) {
			//printf("ans : %d\n", ans);
			ans = length;
		}
	}

}

void check_garo(int row, int col, int length) {

	int s_row = row;
	int e_row = row;
	int s_col = col;
	int e_col = col + length - 1;
	bool is_true = true;

	while (1) {

		if (s_col > e_col) {
			break;
		}
		if (map[s_row][s_col] != map[e_row][e_col]) {
			is_true = false;
			break;
		}
		else {

			s_col++;
			e_col--;
		}

	}

	if (is_true) {
		if (length > ans) {
			//printf("ans : %d\n", ans);
			ans = length;
		}
	}



}

void go() {

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 1; k <= 100; k++) {
				//printf("row : %d col : %d\n", i, j);
				if (j + k <= 100) check_garo(i, j, k);
				if (i + k <= 100) check_sero(i, j, k);
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
		memset(map, 0, sizeof(map));
		ans = 0;

		cin >> len;

		for (int i = 0; i < 100; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 100; j++) {
				map[i][j] = s[j];
			}
		}

		go();

		cout << "#" << test_case << " " << ans << '\n';
	}




	return 0;

}