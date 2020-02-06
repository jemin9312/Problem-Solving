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

int T;
int n;
int score[100];
bool s_score[10001];
bool check[100];
int s_sum;

void go() {



	for (int i = 0; i < n; i++)
	{
		for (int j = s_sum; j >= 0; j--)
		{
			if (s_score[j])
			{

				s_score[j + score[i]] = true;
			}
		}
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		memset(score, 0, sizeof(score));
		memset(s_score, false, sizeof(s_score));
		s_sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> score[i];
			s_sum += score[i];
		}
		s_score[0] = true;
		go();

		int ans = 0;


		for (int i = 0; i <= 10000; i++) {
			if (s_score[i]) {
				ans++;
				//printf("i : %d\n", i);
			}
		}

		cout << "#" << test_case << " " << ans << '\n';
	}


	return 0;

}