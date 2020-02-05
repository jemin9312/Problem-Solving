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


int tc, n;
int ans;
bool near_arr[100][100];

void bfs(int num) {

	queue<int> q;
	q.push(num);

	bool check[100] = { false, };
	check[num] = true;


	while (!q.empty()) {
		num = q.front();
		q.pop();

		for (int i = num; i < 100; i++) {
			if (!check[i] && near_arr[num][i]) {
				check[i] = true;
				q.push(i);
			}
		}
	}

	if (check[99]) ans = 1;
	else ans = 0;


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		memset(near_arr, false, sizeof(near_arr));
		cin >> tc >> n;

		for (int i = 0; i < n; i++) {
			int f, t;
			cin >> f >> t;
			near_arr[f][t] = true;
			near_arr[t][f] = true;
		}

		bfs(0);

		cout << "#" << test_case << " " << ans << '\n';
	}




	return 0;

}