#include <iostream>
#include <stack>
using namespace std;

int N, K;
string input;

int main() {
	cin >> N >> K;
	cin >> input;
	stack<char> s;
	for (int i = 0; i < input.length(); i++) {
		while ((!s.empty() && input[i] > s.top()) && K) {
			s.pop();
			K--;
		}
		if (K == N - i) break;//제거해야 할 수랑 남아있는 수랑
								//같다면 다 지워버려야함
		s.push(input[i]);
	}
	stack<char> ans;
	while (!s.empty()) {
		ans.push(s.top());
		s.pop();
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	return 0;
}