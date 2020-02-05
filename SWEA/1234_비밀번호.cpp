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
string ans;
string s;
bool check[100];

void go_del(int idx) {

	int s_idx = idx;
	int e_idx = idx + 1;

	check[s_idx] = true;
	check[e_idx] = true;

	while (1) {

		if (s[s_idx] != s[e_idx] || s_idx < 0 || e_idx >= n) {
			break;
		}

		else if (s[s_idx] == s[e_idx] && !check[s_idx] && !check[e_idx]) {
			check[s_idx] = true;
			check[e_idx] = true;
			s_idx--;
			e_idx++;
		}
		else
			break;


	}
	


}

bool is_end() {

	for (int i = 0; i < ans.size(); i++) {
		if (check[i]) return false;
	}

	return true;

}


void go() {

	ans = s;

	while (1) {

		memset(check, false, sizeof(check));
		s = ans;

		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == s[i + 1] && !check[i]) {
				go_del(i);
			}
		}

		ans.clear();

		for (int i = 0; i < s.size(); i++) {
			if (!check[i]) {
				ans += s[i];
			}
		}

		
		if (is_end()) {
			
			break;
		}

	}



}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		s.clear();
		ans.clear();
		memset(check, false, sizeof(check));
		cin >> n;
		cin >> s;

		go();


		cout << "#" <<test_case << " " << ans << '\n';
	}




	return 0;

}