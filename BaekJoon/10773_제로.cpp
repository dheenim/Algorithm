#include <iostream>
#include <stack>

using namespace std;

int main() {
	int k;
	cin >> k;
	stack<int> s;
	for (int i = 0; i < k; i++) {
		int num; cin >> num;
		if (num != 0) {
			s.push(num);
		}
		else s.pop();
	}
	int ans = 0;
	while (!s.empty()) {
		ans += s.top(); s.pop();
	}
	cout << ans << endl;
}