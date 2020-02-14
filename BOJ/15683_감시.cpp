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

	int row, col;
	int type, num;

}CCTV;

int n, m;
int ans = 99999999;
int map[8][8];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<CCTV> cctv;


void load_map() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//map[i][j] = temp_map[i][j];
		}
	}

}

void save_map() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//temp_map[i][j] = map[i][j];
		}
	}

}

void light_on(int row, int col, int dir) {

	int nx = row;
	int ny = col;
	//printf("row : %d col : %d dir : %d new\n", row, col, dir);
	while (1) {

		nx += dx[dir];
		ny += dy[dir];
		//printf("nx : %d ny : %d\n", nx, ny);
		if (map[nx][ny] == 6 || nx < 0 || ny < 0 || nx >= n || ny >= m) break;
		else {
			if (map[nx][ny] == 0)
				map[nx][ny] = 7;
		}


	}


}

void go(int idx) {


	if (idx == cctv.size()) {

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//printf("%d ", map[i][j]);
				if (map[i][j] == 0) {
					cnt++;
				}
			}
			//printf("\n");
		}
		//printf("\n");


		if (ans > cnt) {
			ans = cnt;
		}

		return;
	}

	int row = cctv[idx].row;
	int col = cctv[idx].col;
	int type = cctv[idx].type;
	int temp_map[8][8];

	for (int i = 0; i < cctv[idx].num; i++) {

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				temp_map[j][k] = map[j][k];
			}
		}


		if (type == 1) {
			light_on(row, col, i % 4);
		}
		else if (type == 2) {
			light_on(row, col, i % 4);
			light_on(row, col, (i + 2) % 4);
		}
		else if (type == 3) {
			light_on(row, col, i % 4);
			light_on(row, col, (i + 1) % 4);
		}
		else if (type == 4) {
			light_on(row, col, i % 4);
			light_on(row, col, (i + 1) % 4);
			light_on(row, col, (i + 2) % 4);
		}
		else if (type == 5) {
			light_on(row, col, i % 4);
			light_on(row, col, (i + 1) % 4);
			light_on(row, col, (i + 2) % 4);
			light_on(row, col, (i + 3) % 4);
		}

		go(idx + 1);

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				map[j][k] = temp_map[j][k];
			}
		}

	}







}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				CCTV cc;
				cc.row = i;
				cc.col = j;
				cc.type = map[i][j];
				if (map[i][j] == 1 || map[i][j] == 3 || map[i][j] == 4) {
					cc.num = 4;
				}
				else if (map[i][j] == 2) cc.num = 2;
				else if (map[i][j] == 5) cc.num = 1;
				cctv.push_back(cc);
			}
		}
	}

	go(0);

	cout << ans << '\n';

	return 0;
}