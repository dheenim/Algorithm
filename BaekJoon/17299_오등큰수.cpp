#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
int input[1000001];
int ans[1000001];
int nums[1000001];
stack<pair<int, int>> s;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
		nums[input[i]]++;
	}
	for (int i = N; i >= 1; i--) {
		while (!s.empty() && s.top().first <= nums[input[i]]) {
			s.pop();
		}
		if (s.empty()) ans[i] = -1;
		else {
			ans[i] = s.top().second;
		}
		s.push({ nums[input[i]], input[i] });
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
}