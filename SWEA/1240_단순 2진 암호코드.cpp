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

int T, ans;
int n, m;
string s[2000];

void cal_pass(string sub) {

	vector<int> v;
	string s1;

	for (int i = 0; i < sub.size(); i++) {
		if ((i % 7 == 0 && i != 0) || i == sub.size() - 1) {

			if (i == sub.size() - 1) s1 += sub[i];

			int sum = 0;

			for (int j = 0; j < s1.size(); j++) {
				sum += pow(2, 6 - j) * (int)(s1[j] - '0');
			}
			cout << s1 << '\n';
			printf("sum : %d\n", sum);

			if (sum == 13) {
				v.push_back(0);
			}
			else if (sum == 25) {
				v.push_back(1);
			}
			else if (sum == 19) {
				v.push_back(2);
			}
			else if (sum == 61) {
				v.push_back(3);
			}
			else if (sum == 35) {
				v.push_back(4);
			}
			else if (sum == 49) {
				v.push_back(5);
			}
			else if (sum == 47) {
				v.push_back(6);
			}
			else if (sum == 59) {
				v.push_back(7);
			}
			else if (sum == 55) {
				v.push_back(8);
			}
			else if (sum == 11) {
				v.push_back(9);
			}

			s1.clear();
			s1 += sub[i];
		}
		else {
			s1 += sub[i];
		}

	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';

	int veri = 0;

	veri += (v[0] + v[2] + v[4] + v[6]) * 3 + v[1] + v[3] + v[5] + v[7];

	if (veri % 10 == 0) {
		ans = v[0] + v[1] + v[2] + v[3] + v[4] + v[5] + v[6] + v[7];
	}
	else {
		ans = 0;
	}

}

void go() {

	for (int i = 0; i < n; i++) {
		for (int j = s[i].size() - 1; j >= 0; j--) {
			if (s[i][j] != '0') {
				int cnt = 0;
				string sub;
				for (int k = j; k >= 0; k--) {
					if (cnt == 56) break;
					sub += s[i][k];
					cnt++;
				}
				reverse(sub.begin(), sub.end());
				cout << sub << '\n';
				cal_pass(sub);
				break;
			}
		}
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		ans = 0;
		
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			s[i].clear();
		}

		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}

		go();

		cout << "#" << test_case << " " << ans << '\n';
	}

	
	return 0;

}