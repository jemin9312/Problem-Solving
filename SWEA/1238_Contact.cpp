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

int start, len;
bool near_arr[101][101];
bool check[101];
int d;
int depth[101];
vector<int> v;

void bfs(int num) {

	queue<pair<int,int>> q;
	
	q.push(make_pair(num,0));
	check[num] = true;
	depth[num] = 0;
	
	while (!q.empty()) {
		int now = q.front().first;
		int dep = q.front().second;
		q.pop();
		
		for (int i = 1; i <= 100; i++) {
			if (!check[i] && near_arr[now][i]) {
				check[i] = true;
				depth[i] = dep + 1;
				q.push(make_pair(i, dep + 1));
			}
		}
	}


}

void go() {

	bfs(start);

	/*for (int i = 1; i <= 100; i++) {
		printf("%d ", depth[i]);
	}
	printf("\n");*/

	int mx_d = 0;

	for (int i = 1; i <= 100; i++) {
		if (check[i]) {
			if (depth[i] > mx_d) {
				mx_d = depth[i];
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (depth[i] == mx_d) {
			v.push_back(i);
		}
	}

	sort(v.begin(), v.end());

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		memset(check, false, sizeof(check));
		memset(depth, 0, sizeof(depth));
		memset(near_arr, false, sizeof(near_arr));
		v.clear();
		cin >> len >> start;

		for (int i = 0; i < len/2; i++) {
			int f, t;
			cin >> f >> t;
			near_arr[f][t] = true;
		}

		go();

		cout << "#" << test_case << " " << v[v.size()-1] << '\n';

	}




	return 0;

}