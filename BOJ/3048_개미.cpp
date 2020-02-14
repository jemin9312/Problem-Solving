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

vector<pair<char, int>> t1, t2, ans;
int n1, n2, t;

void go() {

	int tim = 0;

	reverse(t1.begin(), t1.end());

	for (int i = 0; i < t1.size(); i++) {
		ans.push_back(t1[i]);
	}
	for (int i = 0; i < t2.size(); i++) {
		ans.push_back(t2[i]);
	}

	while (1) {

		if (tim == t) {

			for (int i = 0; i < ans.size(); i++) {
				printf("%c", ans[i].first);
			}

			break;
		}

		vector<pair<char, int>> sub;

		for (int i = 0; i < ans.size() - 1; i++) {
			if (ans[i].second != ans[i + 1].second) {
				if (ans[i].second == 0 && ans[i + 1].second == 1) {
					pair<char, int> temp;
					temp = ans[i];
					ans[i] = ans[i + 1];
					ans[i + 1] = temp;
					i++;
				}
			}
		}



		tim++;
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n1 >> n2;

	for (int i = 0; i < n1; i++) {
		char c;
		cin >> c;
		t1.push_back(make_pair(c, 0));
	}
	for (int i = 0; i < n2; i++) {
		char c;
		cin >> c;
		t2.push_back(make_pair(c, 1));
	}

	cin >> t;

	go();

	return 0;

}