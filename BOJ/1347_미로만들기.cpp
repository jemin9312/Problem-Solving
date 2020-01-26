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

typedef struct {

	int row;
	int col;
	int dir;

}User;

int n, f_cnt;
vector<char> v;
char map[101][101];
bool check[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
User user;
int s_row, s_col, e_row, e_col;

void go() {

	map[user.row][user.col] = '.';
	check[user.row][user.col] = true;
	int s_r = 101;
	int s_c = 101;
	int e_r = 0;
	int e_c = 0;

	for (int i = 0; i < n; i++) {
		char go = v[i];

		int dir = user.dir;

		if (go == 'R') {
			dir = (dir + 1) % 4;
			user.dir = dir;
		}
		else if (go == 'F') {
			int nx = user.row + dx[user.dir];
			int ny = user.col + dy[user.dir];
			user.row = nx;
			user.col = ny;
			e_row = nx;
			e_col = ny;
			check[nx][ny] = true;
		}
		else if (go == 'L') {
			dir = dir - 1;
			if (dir < 0) {
				dir = 3;
			}
			user.dir = dir;
		}


	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (check[i][j]) {
				if (s_r > i) s_r = i;
				if (s_c > j) s_c = j;
				if (e_r < i) e_r = i;
				if (e_c < j) e_c = j;
			}
		}
	}
	

	for (int i = s_r; i <= e_r; i++) {
		for (int j = s_c; j <= e_c; j++) {
			if (check[i][j]) printf(".");
			else printf("#");
		}
		printf("\n");
	}
	


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	string s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		char c;
		c = s[i];
		if (c == 'F')
			f_cnt++;
		v.push_back(c);
	}

	user.row = 51;
	user.col = 51;
	user.dir = 2;

	s_row = 51;
	s_col = 51;

	memset(map, 'c', sizeof(map));

	go();

	return 0;
}