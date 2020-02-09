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
int num[10];
bool check[10];
bool near[10][10];
vector<int> t1, t2;
int ans = 99999999;

bool can_connect(int t_num, vector<int> v) {

	queue<int> q;

	q.push(v[0]);

	bool check2[10] = { false, };

	check2[v[0]] = true;

	int a_num = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v.size(); i++) {
			if (!check2[v[i]] && near[now][v[i]]) {
				check2[v[i]] = true;
				a_num++;
				q.push(v[i]);
			}
		}


	}

	if (a_num == v.size()) {
		return true;
	}
	return false;


}

bool check_team() {

	t1.clear(); t2.clear();

	for (int i = 0; i < n; i++) {
		if (check[i]) t1.push_back(i);
		else t2.push_back(i);
	}


	if (t1.size() > 0 && t2.size()) {

		bool t1_connect = can_connect(1, t1);
		if (!t1_connect) return false;
		bool t2_connect = can_connect(2, t2);
		if (!t2_connect) return false;

		if (t1_connect && t2_connect) return true;


	}
	else return false;


}

void dfs(int idx, int cnt) {

	if (cnt > 0) {

		if (check_team()) {

			int num1 = 0, num2 = 0;

			for (int i = 0; i < t1.size(); i++) {
				num1 += num[t1[i]];
			}

			for (int i = 0; i < t2.size(); i++) {
				num2 += num[t2[i]];
			}

			if (ans > abs(num1 - num2)) {
				ans = abs(num1 - num2);
			}


		}


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
		cin >> num[i];
	}

	for (int i = 0; i < n; i++) {
		int s_n;
		cin >> s_n;
		for (int j = 0; j < s_n; j++) {
			int a;
			cin >> a;
			a -= 1;
			near[i][a] = true;
			near[a][i] = true;
		}
	}

	go();

	if (ans == 99999999) ans = -1;

	cout << ans << '\n';

	return 0;
}