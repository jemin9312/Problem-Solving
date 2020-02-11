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

int n;
pair<int, int> num[15];
bool check[15];
vector<int> v;
int mx;

bool can_go(int day) {

	int t;
	int p;

	t = num[day].first;
	p = num[day].second;

	if (day + t > n) return false;

	for (int i = day; i < day + t; i++) {
		if (check[i]) return false;
	}

	return true;

}

void make_check(int day) {

	int t, p;

	t = num[day].first;
	p = num[day].second;
	for (int i = day; i < day + t; i++) {
		check[i] = true;
	}

}

void unmake_check(int day) {

	int t, p;
	t = num[day].first;
	p = num[day].second;

	for (int i = day; i < day + t; i++) {
		check[i] = false;
	}

}


void dfs(int day) {



	int sum = 0;

	/*for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");*/

	for (int i = 0; i < v.size(); i++) {
		sum += num[v[i]].second;
	}

	if (sum > mx) {
		mx = sum;
	}




	for (int i = day; i < n; i++) {
		if (can_go(i)) {
			make_check(i);
			v.push_back(i);
			dfs(i + 1);
			v.pop_back();
			unmake_check(i);
		}
	}


}

void go() {

	for (int i = 0; i < n; i++) {
		dfs(i);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		num[i].first = a;
		num[i].second = b;
	}

	go();

	cout << mx << '\n';


	return 0;

}