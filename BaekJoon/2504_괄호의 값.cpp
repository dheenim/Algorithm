#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string input;
	cin >> input;
	int ans = 0;
	stack<int> s;
	int tmp = 0;
	// '(' -> -1, '[' -> -2
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') s.push(-1);
		else if (input[i] == '[') s.push(-2);
		else if (input[i] == ')') {
			if (s.empty() || s.top() == -2) {
				cout << 0 << "\n";
				return 0;
			}
			if (s.top() == -1) {
				tmp = 2;
				s.pop();
			}
			else {
				while (s.top() != -1) {
					int topChar = s.top();
					s.pop();
					if (s.empty() || topChar == -2) {
						cout << 0 << "\n";
						return 0;
					}
					tmp += topChar;
				}
				s.pop();
				tmp *= 2;
			}
		}
		else if (input[i] == ']') {
			if (s.empty() || s.top() == -1) {
				cout << 0 << "\n";
				return 0;
			}
			if (s.top() == -2) {
				tmp = 3;
				s.pop();
			}
			else {
				while (s.top() != -2) {
					int topChar = s.top();
					s.pop();
					if (s.empty() || topChar == -1) {
						cout << 0 << "\n";
						return 0;
					}
					tmp += topChar;
				}
				s.pop();
				tmp *= 3;
			}
		}
		if (tmp != 0) {
			s.push(tmp);
			tmp = 0;
		}
	}
	while (!s.empty()) {
		if (s.top() == -1 || s.top() == -2) {
			cout << 0 << "\n";
			return 0;
		}
		ans += s.top();
		s.pop();
	}
	cout << ans << "\n";
}