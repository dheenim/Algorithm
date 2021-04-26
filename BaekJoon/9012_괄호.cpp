#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int chk = 0;
		int idx;
		for (idx = 0; idx < s.length(); idx++) {
			if (s[idx] == '(') {
				chk++;
			}
			else if (s[idx] == ')') {
				chk--;
			}
			if (chk < 0) {
				break;
			}
		}
		if (idx == s.length() && chk == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}