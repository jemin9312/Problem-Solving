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

int T, n;
double ans;
double map[16][16];
bool check[16];

void dfs(int cnt, double sum) {

	if (sum * 100 <= ans) {
		return;
	}

	if (cnt == n) {

		if (sum * 100 > ans) {
			ans = sum * 100;
			//cout << "cnt : " << cnt << " sum : " << sum << '\n';
		}

		return;
	}


	//cout << "cnt : " << cnt << " sum : " << sum << '\n';

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			dfs(cnt + 1, sum * map[cnt][i]);
			check[i] = false;
		}
	}


}

void go() {

	dfs(0, 1.0);

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		memset(map, 0, sizeof(map));
		memset(check, false, sizeof(check));
		ans = 0;

		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				double a;
				cin >> a;
				a /= 100;
				map[i][j] = a;
			}
		}

		go();

		//cout << ans << '\n';



		cout << "#" << test_case << " ";
		cout << fixed;
		cout.precision(6);
		cout << ans << '\n';
	}

	return 0;
}