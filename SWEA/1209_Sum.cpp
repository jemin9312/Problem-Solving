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

int tc, mx;
int map[100][100];

void go() {

	int sum = 0;


	for (int i = 0; i < 100; i++) {
		sum = 0;
		for (int j = 0; j < 100; j++) {
			sum += map[i][j];
		}
		if (sum > mx) mx = sum;
	}

	sum = 0;

	for (int i = 0; i < 100; i++) {
		sum = 0;
		for (int j = 0; j < 100; j++) {
			sum += map[j][i];
		}
		if (sum > mx) mx = sum;
	}

	sum = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == j) {
				sum += map[i][j];
			}
		}
	}

	if (sum > mx) mx = sum;

	//(0,4) (1,3) (2,2) (3,1) (4,0)

	sum = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 99; j >= 0; j--) {
			if (i + j == 99) {
				sum += map[i][j];
			}
		}
	}

	if (sum > mx) mx = sum;


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> tc;
		mx = 0;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
			}
		}

		go();

		cout << "#" << test_case << " " << mx << '\n';

	}




	return 0;

}#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int tc, mx;
int map[100][100];

void go() {

	int sum = 0;


	for (int i = 0; i < 100; i++) {
		sum = 0;
		for (int j = 0; j < 100; j++) {
			sum += map[i][j];
		}
		if (sum > mx) mx = sum;
	}

	sum = 0;

	for (int i = 0; i < 100; i++) {
		sum = 0;
		for (int j = 0; j < 100; j++) {
			sum += map[j][i];
		}
		if (sum > mx) mx = sum;
	}

	sum = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (i == j) {
				sum += map[i][j];
			}
		}
	}

	if (sum > mx) mx = sum;

	//(0,4) (1,3) (2,2) (3,1) (4,0)

	sum = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 99; j >= 0; j--) {
			if (i + j == 99) {
				sum += map[i][j];
			}
		}
	}

	if (sum > mx) mx = sum;


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> tc;
		mx = 0;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
			}
		}

		go();

		cout << "#" << test_case << " " << mx << '\n';

	}




	return 0;

}