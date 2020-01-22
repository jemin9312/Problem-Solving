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
//현재 시간초과 (완전탐색하며 배열을 넘기는 과정에서 났을거같음)
//시간초과 해결법 : num == 1 일때 즉 모든 시민이 죽고 마피아 혼자 남았을때가 최대값이므로
//최대값 갱신시 더 이상 진행되지 않아도 되므로 return하여 시간초과 방지
//=> return 하지 않으면 모든 케이스를 다 탐색하여 중복되므로 시간초과 발생 flag이용

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
bool flag;


void kill(int who,int num,int cnt) {

	if (flag) return;

	if ((num == 1 && v[mafia].isalive) || !v[mafia].isalive) {

		/*for (int i = 0; i < n; i++) {
			printf("%d %d ", v[i].isalive, v[i].guilty);
		}
		printf("cnt : %d num : %d\n", cnt, num);*/

		if (cnt > mx) {
			mx = cnt;
		}

		if (num == 1) flag = true;

		return;
	}

	/*for (int i = 0; i < n; i++) {
		printf("%d %d ", v[i].isalive, v[i].guilty);
	}
	printf("cnt : %d num : %d\n",cnt,num);*/

	int sub_arr[16] = { 0, };
	

	if (num % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (v[i].isalive && i != mafia) {
				v[i].isalive = false;

				for (int j = 0; j < n; j++) {
					sub_arr[j] = v[j].guilty;
				}

				for (int j = 0; j < n; j++) {
					if (i != j && v[j].isalive) {
						v[j].guilty += arr[i][j];
					}
				}
				kill(i, num - 1,cnt + 1);

				for (int j = 0; j < n; j++) {
					v[j].guilty = sub_arr[j];
				}

				v[i].isalive = true;
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
		v[mx_idx].isalive = false;
		kill(mx_idx, num - 1, cnt);
		v[mx_idx].isalive = true;
	}


}

void go() {



	int alive_num = 0;
		

	for (int i = 0; i < n; i++) {
		if (v[i].isalive) alive_num++;
	}

	for (int i = 0; i < n; i++) {
		if (v[i].isalive && i != mafia) {
			kill(i, alive_num, 0);
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