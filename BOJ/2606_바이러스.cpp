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
using namespace std;

int n, k;
bool adj_mat[101][101];

void bfs(int num) {

	queue<int> q;
	q.push(num);

	bool check[101] = { false, };
	check[num] = true;

	int cnt = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (!check[i] && adj_mat[now][i]) {
				cnt++;
				check[i] = true;
				q.push(i);
			}
		}

	}

	cout << cnt << '\n';
}

void go() {


	bfs(1);


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	/*for (int test_case = 1; test_case <= 10; test_case++) {


		cout << "#" << test_case << " " << '\n';
	}*/

	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int f, t;
		cin >> f >> t;

		adj_mat[f][t] = true;
		adj_mat[t][f] = true;
	}

	go();

	return 0;

}