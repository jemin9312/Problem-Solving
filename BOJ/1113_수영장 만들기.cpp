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

//BFS�� �̿��ϴ� �� ������ ���������� height�� �̿��ϴ� ���� ����� ������ ���� ����
//height�� 1~9���̸� ����Ǵ� ���� �������� Ž���ϰ� ä��� �ݺ��ϸ� ������ ���鼭 �ذ�
//can_cluster��� ���� bool ������ �̿��Ͽ� ������ üũ


int n, m;
int map[50][50];
int sub_map[50][50];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ans;
int height;
bool check[50][50];
bool can_cluster;


void fill_water() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] && map[i][j] == height) {
				map[i][j]++;
				ans++;
			}
		}
	}

	//printf("height : %d ans : %d\n",height ,ans);

}


void bfs(int row, int col) {

	queue<pair<int, int>> q;

	q.push(make_pair(row, col));
	can_cluster = true;

	check[row][col] = true;

	while (!q.empty()) {

		row = q.front().first;
		col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = row + dx[i];
			int ny = col + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (!check[nx][ny]) {
					if (map[nx][ny] < map[row][col]) {
						can_cluster = false;
					}
					else if (map[nx][ny] == map[row][col]) {
						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
			else can_cluster = false;
		}
	}



}

void go() {

	while (1) {

		height++;

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/

		if (height > 9) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == height && !check[i][j]) {
					bfs(i, j);
					if (can_cluster) {
						fill_water();
					}
					memset(check, false, sizeof(check));
				}
			}
		}
	}





}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = (int)(s[j] - '0');
		}
	}

	go();

	cout << ans << '\n';


	return 0;
}