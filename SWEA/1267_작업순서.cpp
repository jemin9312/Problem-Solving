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

int v, e;
bool near_arr1[1000][1000];
bool near_arr2[1000][1000];
bool check[1000];
vector<int> route;

bool can_go(int num) {

	for (int i = 1; i <= v; i++) {
		if (near_arr2[i][num]) return false;
	}
	return true;

}

bool can_go2(int from,int to) {

	for (int i = 1; i <= v; i++) {
		if (near_arr2[i][to]) {
			if (!check[i]) return false;
		}
	}
	
	return true;
}

void bfs(int num) {

	queue<int> q;
	q.push(num);

	int i_cnt = 1;

	check[num] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		//printf("now : %d\n", now);

		for (int i = 1; i <= v; i++) {
			if (near_arr2[now][i] && !check[i]) {
				if (can_go2(now, i)) {
					check[i] = true;
					i_cnt++;
					route.push_back(i);
					q.push(i);
				}
			}
		}
	}

	
	

}

void go() {

	for (int i = 1; i <= v; i++) {
		if (can_go(i)) {
			//printf("i : %d\n", i);
			memset(check, false, sizeof(check));
			route.push_back(i);
			bfs(i);
		}
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		memset(near_arr2, false, sizeof(near_arr2));
		route.clear();
		cin >> v >> e;

		for (int i = 0; i < e; i++) {
			int f, t;
			cin >> f >> t;
			near_arr2[f][t] = true;
			
		}
		
		go();


		cout << "#" << test_case << " ";
		for (int i = 0; i < route.size(); i++) {
			cout << route[i] << " ";
		}
		cout << '\n';
	}




	return 0;

}