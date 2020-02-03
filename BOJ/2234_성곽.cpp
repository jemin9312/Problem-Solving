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


int n, m;
int map[50][50];
int s_map[50][50];
bool check[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int d_num[] = { -1,-2,-4,-8 };
int r_num;
int r_area;
int m_area;
int d_m_area;

void copy_map() {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			s_map[i][j] = map[i][j];
		}
	}

}

void recover_map() {
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = s_map[i][j];
		}
	}

}

void dfs(int row, int col,int cnt) {


	for (int i = 0; i < 4; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
			if (!check[nx][ny]) {
				if (i == 0) {
					if (!(map[row][col] & 2)) {
						check[nx][ny] = true;
						r_area++;
						dfs(nx, ny, cnt + 1);
					}
				}
				else if (i == 1) {
					if (!(map[row][col] & 4)) {
						check[nx][ny] = true;
						r_area++;
						dfs(nx, ny, cnt + 1);
					}
				}
				else if (i == 2) {
					if (!(map[row][col] & 8)) {
						check[nx][ny] = true;
						r_area++;
						dfs(nx, ny, cnt + 1);
					}
				}
				else if (i == 3) {
					if (!(map[row][col] & 1)) {
						check[nx][ny] = true;
						r_area++;
						dfs(nx, ny, cnt + 1);
					}
				}
			}
		}
	}

	

}

void sol_1() {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				r_area = 1;
				r_num++;
				check[i][j] = true;
				dfs(i, j, 0);
				if (r_area > m_area) {
					m_area = r_area;
				}
			}
		}
	}

}


void sol_2() {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) continue;
			for (int k = 0; k < 4; k++) {
				printf("row : %d col : %d\n", i, j);
				memset(check, false, sizeof(check));
				if (k == 0 && (map[i][j] & 1)) {
					r_area = 1;
					copy_map();
					check[i][j] = true;
					map[i][j] += d_num[k];
					dfs(i, j, 0);
					printf("r_area : %d k : %d\n", r_area, k);
					if (r_area > d_m_area) {
						d_m_area = r_area;
					}
					recover_map();
				}
				else if (k == 1 && (map[i][j] & 2)) {
					r_area = 1;
					copy_map();
					check[i][j] = true;
					map[i][j] += d_num[k];
					dfs(i, j, 0);
					printf("r_area : %d k : %d\n", r_area, k);
					if (r_area > d_m_area) {
						d_m_area = r_area;
					}
					recover_map();
				}
				else if (k == 2 && (map[i][j] & 4)) {
					r_area = 1;
					copy_map();
					check[i][j] = true;
					map[i][j] += d_num[k];
					dfs(i, j, 0);
					printf("r_area : %d k : %d\n", r_area, k);
					if (r_area > d_m_area) {
						d_m_area = r_area;
					}
					recover_map();
				}
				else if (k == 3 && (map[i][j] & 8)) {
					r_area = 1;
					copy_map();
					check[i][j] = true;
					map[i][j] += d_num[k];
					dfs(i, j, 0);
					printf("r_area : %d k : %d\n", r_area, k);
					if (r_area > d_m_area) {
						d_m_area = r_area;
					}
					recover_map();
				}
			}
		}
	}


}

void go() {

	sol_1();

	memset(check, false, sizeof(check));

	sol_2();

	cout << r_num << '\n';
	cout << m_area << '\n';
	cout << d_m_area << '\n';

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	go();
	

	return 0;

}