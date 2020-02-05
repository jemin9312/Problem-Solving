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

int tc;
int map[100][100];
bool check[100][100];
int s_row, s_col;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int e_row, e_col;

void go() {

	int row = s_row;
	int col = s_col;
	check[row][col] = true;
	//printf("s_row : %d s_col : %d\n", s_row, s_col);

	while (1) {

		//printf("row : %d col : %d\n", row, col);

		if (row == 0 && map[row][col] == 1) {
			e_row = row;
			e_col = col;
			break;
		}



		for (int i = 3; i >= 0; i--) {
			if (i != 2) {
				int nx = row + dx[i];
				int ny = col + dy[i];
				if (nx >= 0 && ny >= 0 && nx < 100 && ny < 100) {
					if (map[nx][ny] == 1 && !check[nx][ny]) {
						check[nx][ny] = true;
						row = nx;
						col = ny;
						break;
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


	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> tc;
		memset(check, false, sizeof(check));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					s_row = i;
					s_col = j;
				}
			}
		}

		go();

		cout << "#" << test_case << " " << e_col << '\n';

	}




	return 0;

}