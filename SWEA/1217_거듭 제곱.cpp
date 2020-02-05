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

int len;
int ans;

void go(int a, int length, int cnt, int ret) {

	if (cnt == length) {

		ans = ret;

		return;
	}

	int s_ret = ret;

	s_ret *= a;

	go(a, length, cnt + 1, s_ret);


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		ans = 0;
		int a, b;

		cin >> len;
		cin >> a >> b;


		go(a, b, 0, 1);

		cout << "#" << test_case << " " << ans << '\n';
	}




	return 0;

}