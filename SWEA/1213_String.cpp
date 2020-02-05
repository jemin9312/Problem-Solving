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

int tc;
string s1, s2;
int ans;

void go() {

	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] == s1[0]) {
			bool is_right = true;
			int s_idx = i;
			int s_l = 0;
			for (int j = s_idx; j < s_idx + s1.size(); j++) {
				if (s2[j] != s1[s_l]) is_right = false;
				s_l++;
			}
			if (is_right) ans++;
		}
	}



}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> tc;
		cin >> s1;
		cin >> s2;
		ans = 0;

		go();

		cout << "#" << test_case << " " << ans << '\n';
	}




	return 0;

}