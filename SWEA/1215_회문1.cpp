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

int len, ans;
char map[9][9];
bool check[8][8];
int dx[] = { 1,0 };
int dy[] = { 0,1 };
vector<char> v;

bool is_pal() {

	bool is_right = true;

	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	printf("\n");*/

	if (v.size() % 2 == 0) {

		vector<char> sub1, sub2;
		for (int i = 0; i < v.size(); i++) {
			if (i < v.size() / 2) {
				sub1.push_back(v[i]);
			}
			else {
				sub2.push_back(v[i]);
			}
		}

		for (int i = 0; i < sub1.size(); i++) {
			if (sub1[i] != sub2[sub1.size() - 1 - i]) {
				is_right = false;
			}
		}


	}
	else {
		vector<char> sub1, sub2;
		for (int i = 0; i < v.size(); i++) {
			if (i < v.size() / 2) {
				sub1.push_back(v[i]);
			}
			else if (i > v.size() / 2) {
				sub2.push_back(v[i]);
			}
		}

		for (int i = 0; i < sub1.size(); i++) {
			if (sub1[i] != sub2[sub1.size() - 1 - i]) {
				is_right = false;
			}
		}

	}


	//printf("%d\n", is_right);
	return is_right;


}

void dfs(int row, int col, int cnt, int dir) {

	if (cnt == len) {

		if (is_pal()) {
			ans++;
		}

		return;
	}



	v.push_back(map[row][col]);

	int nx = row + dx[dir];
	int ny = col + dy[dir];
	if (nx >= 0 && ny >= 0 && nx < 9 && ny < 9) {
		dfs(nx, ny, cnt + 1, dir);
		v.pop_back();
	}


}

void go() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 2; k++) {
				v.clear();
				dfs(i, j, 0, k);
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
		v.clear();
		memset(map, 0, sizeof(map));
		ans = 0;

		cin >> len;

		for (int i = 0; i < 8; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 8; j++) {
				map[i][j] = s[j];
			}
		}

		go();

		cout << "#" << test_case << " " << ans << '\n';
	}




	return 0;

}