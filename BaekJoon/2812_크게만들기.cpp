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
		if (K == N - i) break;//�����ؾ� �� ���� �����ִ� ����
								//���ٸ� �� ������������
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