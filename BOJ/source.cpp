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
//백준 1079 마피아

typedef struct {

	bool isalive;
	int guilty;

}Person;

int n;
int mafia;
int arr[16][16];
bool check[16];
vector<Person> v;
int mx;

bool is_end() {

	int civil_num = 0;

	for (int i = 0; i < n; i++) {
		if (!v[i].isalive && i != mafia && v[mafia].isalive) {
			civil_num++;
		}
	}

	if (civil_num == n - 1) return true;

	return false;

}

void kill(int who,int num,int arr_t[16],int cnt) {

	if (is_end()) {

		printf("cnt : %d\n", cnt);

		for (int i = 0; i < n; i++) {
			//printf("%d %d ", v[i].isalive, v[i].guilty);
		}
		//printf("\n");

		if (cnt > mx) {
			mx = cnt;
		}

		return;
	}



	int sub_arr[16] = { 0, };

	for (int i = 0; i < n; i++) {
		sub_arr[i] = arr_t[i];
		//printf("%d %d", v[i].isalive, sub_arr[i]);
	}
	//printf("\n");

	

	if (num % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (v[i].isalive && !check[i]) {
				check[i] = true;
				v[i].isalive = false;
				for (int j = 0; j < n; j++) {
					if (i != j) {
						sub_arr[j] += arr[i][j];
					}
				}
				kill(i, num - 1, sub_arr,cnt + 1);
				for (int j = 0; j < n; j++) {
					if (i != j) {
						sub_arr[j] -= arr[i][j];
					}
				}
				v[i].isalive = true;
				check[i] = false;
			}
		}
	}

	else {
		int mx_g = 0;
		int mx_idx = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].isalive) {
				if (v[i].guilty > mx_g) {
					mx_g = v[i].guilty;
					mx_idx = i;
				}
			}
		}
		kill(mx_idx, num - 1, sub_arr, cnt);
	}


}

void go() {



	int alive_num = 0;
		

	for (int i = 0; i < n; i++) {
		if (v[i].isalive) alive_num++;
	}

	int sub_arr[16] = { 0, };

	for (int i = 0; i < n; i++) {
		sub_arr[i] = v[i].guilty;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", sub_arr[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		if (v[i].isalive && i != mafia) {
			memset(check, false, sizeof(check));
			kill(i, alive_num, sub_arr,0);
		}
	}



}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		Person p;
		p.isalive = true;
		p.guilty = num;
		v.push_back(p);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> mafia;

	go();

	cout << mx << '\n';


	return 0;
}