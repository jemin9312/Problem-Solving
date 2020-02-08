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

typedef struct {

	int p;
	char o;

}oper;

int T, n;
stack<int> num;
stack<oper> op;
string s;
int ans;

void calc() {

	int a, b, result;

	b = num.top();
	num.pop();
	a = num.top();
	num.pop();

	char ope = op.top().o;
	op.pop();

	if (ope == '+') {
		result = a + b;
	}
	else if (ope == '*') {
		result = a * b;
	}

	num.push(result);

}

void go() {

	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num.push((int)(s[i] - '0'));
		}
		else if (s[i] == '(') {
			oper ope;
			ope.o = s[i];
			ope.p = 0;
			op.push(ope);
		}
		else if (s[i] == '*' || s[i] == '+') {
			oper ope;
			if (s[i] == '*') {
				ope.o = '*';
				ope.p = 2;
			}
			else {
				ope.o = '+';
				ope.p = 1;
			}

			while (!op.empty() && ope.p <= op.top().p) {
				calc();
			}
			op.push(ope);

		}
		else if (s[i] == ')') {
			while (op.top().o != '(') {
				calc();
			}
			op.pop();
		}


	}

	while (!op.empty()) {
		calc();
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);

	//cin >> T;

	for (int test_case = 1; test_case <= 10; test_case++) {
		s.clear();
		cin >> n;

		cin >> s;

		go();
		

		cout << "#" << test_case << " " << num.top() << '\n';
		num.pop();
	}

	

	return 0;
}