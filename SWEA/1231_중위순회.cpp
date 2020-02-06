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
#include <deque>
using namespace std;

int n, l, r, num;
char c;
bool near_arr[101][101];
char node[102];
bool check[101];
vector<char> s;

void dfs(int num) {


	if (num > n)
		return;

	check[num] = true;

	if (!check[num * 2]) {
		check[num * 2] = true;
		dfs(num * 2);
	}
	//printf("%d ", num);
	s.push_back(node[num]);
	if (!check[num * 2 + 1]) {
		check[num * 2 + 1] = true;
		dfs(num * 2 + 1);
	}



}

void go() {


	dfs(1);

}

int main() {

	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		memset(check, false, sizeof(check));
		memset(near_arr, false, sizeof(check));
		memset(node, NULL, sizeof(node));
		s.clear();
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> num >> c;

			if (n % 2 == 0 && n / 2 > i || n % 2 == 1 && n / 2 >= i) {
				scanf("%d %d", &l, &r);
			}
			else if (n % 2 == 0 && n / 2 == i) {
				scanf("%*d", &l);
			}

			node[num] = c;

		}


		go();

		cout << "#" << test_case << " ";
		for (int i = 0; i < s.size(); i++) {
			cout << s[i];
		}
		cout << '\n';

	}


	return 0;

}