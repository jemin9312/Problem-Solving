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

int T;
char map[5][5];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ans;
set<string> v;
string s;



void dfs(int row, int col, int cnt) {

	if (cnt == 7) {
		v.insert(s);
		return;

	}

	for (int i = 0; i < 4; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			s.push_back(map[row][col]);
			dfs(nx, ny, cnt + 1);
			if (!s.empty())
				s.pop_back();
		}
	}
}

void go() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			s.clear();
			s.push_back(map[i][j]);
			dfs(i, j, 0);
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
		memset(map, NULL, sizeof(map));
		v.clear();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}

		go();




		cout << "#" << test_case << " " << v.size() << '\n';
	}


	return 0;

}