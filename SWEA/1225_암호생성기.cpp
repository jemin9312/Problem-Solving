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

int tc;
bool is_end;
deque<int> d;

void go() {

	int minu = 1;

	while (1) {

		if (is_end) {

			break;
		}

		int num = d.front();
		d.pop_front();
		num -= minu;
		if (num <= 0) {
			num = 0;
			is_end = true;
		}
		d.push_back(num);
		

		minu++;
		if (minu > 5) minu = 1;
	}



}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		d.clear();
		is_end = false;
		cin >> tc;

		for (int i = 0; i < 8; i++) {
			int a;
			cin >> a;
			d.push_back(a);
		}

		go();

		cout << "#" << test_case << " ";
		for (int i = 0; i < d.size(); i++) {
			cout << d[i] << ' ';
		}
		cout << '\n';
	}




	return 0;

}