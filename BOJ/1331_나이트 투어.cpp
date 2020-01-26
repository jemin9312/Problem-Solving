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

vector<string> v;
int map[6][6];
bool check[6][6];
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,-2,-1,1,2 };
bool flag;
bool case2;

bool go() {

	int row = (6 - (int)(v[0][1] - '0'));
	int col = (int)(v[0][0] - 'A');
	check[row][col] = true;

	for (int i = 1; i < 36; i++) {

		int st_row = (6 - (int)(v[i][1] - '0'));
		int st_col = (int)(v[i][0] - 'A');

		bool case1 = false;

		for (int j = 0; j < 8; j++) {

			int nx = row + dx[j];
			int ny = col + dy[j];

			if (nx >= 0 && ny >= 0 && nx < 6 && ny < 6) {
				if (nx == st_row && ny == st_col) {
					if (!check[nx][ny]) {
						case1 = true;
						check[nx][ny] = true;
						row = nx;
						col = ny;
					}
					else {
						return false;
					}
				}
			}
		}

		if (!case1) return false;

	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (!check[i][j]) return false;
		}
	}

	int s_row = (6 - (int)(v[0][1] - '0'));
	int s_col = (int)(v[0][0] - 'A');

	bool case2 = false;

	for (int i = 0; i < 8; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (nx == s_row && ny == s_col) {
			case2 = true;
		}
	}

	if (!case2) return false;

	return true;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 36; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}



	bool end;

	end = go();

	if (!end) cout << "Invalid" << '\n';
	else cout << "Valid" << '\n';

	return 0;
}