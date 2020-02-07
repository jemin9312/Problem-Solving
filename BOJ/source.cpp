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

int T, n;
int map[16][16];
bool check[16][16];
bool check2[16];
double ans;

void cal() {

	double sub = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) {
				sub *= map[i][j];
			}
		}
	}

	cout << sub << '\n';

	sub /= 10000;

	if (sub > ans) {
		ans = sub;
	}

}

void dfs(int row, int col, int cnt) {

	if (cnt == n) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", check[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		cal();

		return;
	}

	

	for (int i = row; i < n; i++) {
		for (int j = col; j < n; j++) {
			if (!check[i][j] && !check2[i]) {
				check[i][j] = true;
				check2[i] = true;
				dfs(i, j + 1, cnt + 1);
				check[i][j] = false;
				check2[i] = false;
			}
		}
		col = 0;
	}


}

void go() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				dfs(i, j, 0);
			}
		}
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		memset(map, 0, sizeof(map));
		memset(check, false, sizeof(check));
		ans = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		go();

		cout << "#" << test_case << " ";
		cout.precision(6);
		cout << ans;
		cout << '\n';
		

	}


	return 0;

}