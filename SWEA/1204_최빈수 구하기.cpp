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

int score[101];
int T, tc;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> T;


	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> tc;
		int mx = 0;
		int mx_i = 0;
		memset(score, 0, sizeof(score));
		for (int i = 0; i < 1000; i++) {
			int num;
			cin >> num;
			score[num]++;
		}

		for (int i = 1; i < 101; i++) {

			if (score[i] >= mx) {
				mx = score[i];
				mx_i = i;
			}
		}

		cout << "#" << test_case << " " << mx_i << '\n';

	}




	return 0;

}