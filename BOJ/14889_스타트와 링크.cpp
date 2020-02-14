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

int n;
int near_arr[20][20];
bool check[20];
int mn = 99999999;
vector<int> t1, t2;

void cal() {

	t1.clear();
	t2.clear();

	for (int i = 0; i < n; i++) {
		if (check[i]) t1.push_back(i);
		else t2.push_back(i);
	}

	int t1_sum = 0, t2_sum = 0;

	for (int i = 0; i < t1.size(); i++) {
		for (int j = i + 1; j < t1.size(); j++) {
			t1_sum += near_arr[t1[i]][t1[j]];
			t1_sum += near_arr[t1[j]][t1[i]];
		}
	}

	for (int i = 0; i < t2.size(); i++) {
		for (int j = i + 1; j < t2.size(); j++) {
			t2_sum += near_arr[t2[i]][t2[j]];
			t2_sum += near_arr[t2[j]][t2[i]];
		}
	}

	if (mn > abs(t1_sum - t2_sum)) {
		mn = abs(t1_sum - t2_sum);
	}

}

void dfs(int idx, int cnt) {

	if (cnt == n / 2) {

		cal();

		return;
	}

	for (int i = idx; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			dfs(i + 1, cnt + 1);
			check[i] = false;
		}
	}



}

void go() {


	dfs(0, 0);



}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> near_arr[i][j];
		}
	}


	go();

	cout << mn << '\n';

	return 0;
}