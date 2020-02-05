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

string s;
int n;
int ans;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);


	for (int test_case = 1; test_case <= 10; test_case++) {
		s.clear();
		cin >> n;

		cin >> s;

		stack<char> st;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '{' || s[i] == '[' || s[i] == '(' || s[i] == '<') {
				st.push(s[i]);
			}
			else if (st.top() == '{' && s[i] == '}') st.pop();
			else if (st.top() == '[' && s[i] == ']') st.pop();
			else if (st.top() == '(' && s[i] == ')') st.pop();
			else if (st.top() == '<' && s[i] == '>') st.pop();
			else st.push(s[i]);
		}

		if (st.empty()) ans = 1;
		else ans = 0;


		cout << "#" << test_case << " " << ans << '\n';
	}




	return 0;

}