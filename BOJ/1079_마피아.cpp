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
bool check[16][16];
vector<Person> v;
int mx;

void kill(int who,int cnt) {

	int sub_num[16] = { 0, };

	for (int i = 0; i < n; i++) {
		sub_num[i] = v[i].guilty;
	}




}

void mafia_kill() {


	for (int i = 0; i < n; i++) {
		if (v[i].isalive && i != mafia) {
			memset(check, false, sizeof(check));
			kill(i,1);
		}
	}



}

void go() {



	int alive_num = 0;
		

	for (int i = 0; i < n; i++) {
		if (v[i].isalive) alive_num++;
	}

	if (alive_num % 2 == 0) {
		mafia_kill();
	}
	else {
		int mxidx;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].guilty > mx) {
				mxidx = i;
				mx = v[i].guilty;
			}
		}
		v[mxidx].isalive = false;
		if (mxidx != mafia) mafia_kill();
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