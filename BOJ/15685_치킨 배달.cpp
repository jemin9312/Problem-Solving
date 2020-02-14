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

int n, m;
int map[50][50];
int mn = 999999;
bool check[13];
vector<pair<int, int>> chic;

void cal_chic() {

	int chic_dist = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				int mn_dist = 999999;
				for (int k = 0; k < chic.size(); k++) {
					if (check[k]) {
						int sub_dist = abs(i - chic[k].first) + abs(j - chic[k].second);
						if (mn_dist > sub_dist) {
							mn_dist = sub_dist;
						}
					}
				}
				chic_dist += mn_dist;
			}
		}
	}

	if (mn > chic_dist) {
		mn = chic_dist;
	}


}

void sel_chic(int idx, int cnt) {

	if (cnt == m) {

		cal_chic();

		return;
	}

	for (int i = idx; i < chic.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			sel_chic(i + 1, cnt + 1);
			check[i] = false;
		}
	}

}

void go() {

	sel_chic(0, 0);


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chic.push_back(make_pair(i, j));
			}
		}
	}

	go();


	cout << mn << '\n';


	return 0;

}