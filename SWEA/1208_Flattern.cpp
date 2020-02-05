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

int d_num;
int map[100][100];
int arr[100];
int ans;

void go() {

	int t_row = 0;
	int t_col = 0;
	int b_row = 0;
	int b_col = 0;

	for (int i = 0; i < 100; i++) {
		bool can_break = false;
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1) {
				t_row = i;
				t_col = j;
				map[i][j] = 0;
				can_break = true;
				break;
			}
		}
		if (can_break) break;
	}

	for (int i = 99; i >= 0; i--) {
		bool can_break = false;
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 0) {
				b_row = i;
				b_col = j;
				map[i][j] = 1;
				can_break = true;
				break;
			}
		}
		if (can_break) break;
	}


}

void cal_h() {

	int t_h = 0;
	int b_h = 0;

	for (int i = 0; i < 100; i++) {
		bool can_break = false;
		for (int j = 0; j < 100; j++) {
			if (map[i][j]) {
				t_h = 100 - i;
				can_break = true;
				break;
			}
		}
		if (can_break) break;
	}

	for (int i = 99; i >= 0; i--) {
		bool can_break = false;
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 0) {
				b_h = 100 - i;
				can_break = true;
				break;
			}
		}
		if (can_break) break;
	}

	ans = t_h - b_h + 1;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> d_num;
		memset(map, 0, sizeof(map));

		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
			//printf("%d ", arr[i]);
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 99; j > 99 - arr[i]; j--) {
				map[j][i]++;
			}
		}

		/*for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}*/

		for (int i = 0; i < d_num; i++) {
			//printf("%d\n", i);
			go();
		}

		cal_h();

		//printf("%d\n", ans);

		cout << "#" << test_case << " " << ans << '\n';

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

int d_num;
int map[100][100];
int arr[100];
int ans;

void go() {

	int t_row = 0;
	int t_col = 0;
	int b_row = 0;
	int b_col = 0;

	for (int i = 0; i < 100; i++) {
		bool can_break = false;
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1) {
				t_row = i;
				t_col = j;
				map[i][j] = 0;
				can_break = true;
				break;
			}
		}
		if (can_break) break;
	}

	for (int i = 99; i >= 0; i--) {
		bool can_break = false;
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 0) {
				b_row = i;
				b_col = j;
				map[i][j] = 1;
				can_break = true;
				break;
			}
		}
		if (can_break) break;
	}


}

void cal_h() {

	int t_h = 0;
	int b_h = 0;

	for (int i = 0; i < 100; i++) {
		bool can_break = false;
		for (int j = 0; j < 100; j++) {
			if (map[i][j]) {
				t_h = 100 - i;
				can_break = true;
				break;
			}
		}
		if (can_break) break;
	}

	for (int i = 99; i >= 0; i--) {
		bool can_break = false;
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 0) {
				b_h = 100 - i;
				can_break = true;
				break;
			}
		}
		if (can_break) break;
	}

	ans = t_h - b_h + 1;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		cin >> d_num;
		memset(map, 0, sizeof(map));

		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
			//printf("%d ", arr[i]);
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 99; j > 99 - arr[i]; j--) {
				map[j][i]++;
			}
		}

		/*for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}*/

		for (int i = 0; i < d_num; i++) {
			//printf("%d\n", i);
			go();
		}

		cal_h();

		//printf("%d\n", ans);

		cout << "#" << test_case << " " << ans << '\n';

	}




	return 0;

}