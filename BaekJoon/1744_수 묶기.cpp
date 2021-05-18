#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
//int ans = -1000000000;
vector<int> input;
bool cmp(int a, int b) {
	if (a < 0 && b < 0) {
		return -a > -b;
	}
	return a > b;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	int zeros = 0;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		input.push_back(tmp);
		if (tmp == 0) zeros++;
	}
	int left = 0;
	int ans = 0;
	sort(input.begin(), input.end(),cmp);
	while (left <= N - 2) {
		//cout << "left:" << left << endl;
		if (input[left] == 0 && input[left + 1] < 0) {
			left++;
			continue;
		}
		if (input[left + 1] == 1 || input[left] == 1) {
			ans += input[left];
			left++;
			continue;
		}
		if (input[left] > input[left] * input[left + 1]) {
			ans += input[left];
			left++;
		}
		else {
			ans += (input[left] * input[left + 1]);
			left += 2;
		}
		//cout << "ans:" << ans << " after left:" << left << endl;
	}
	//cout << "final left:" << left << endl;
	if (left < N) {
		if (input[left] < 0 && zeros>0) {
			;
		}
		else ans += input[left];
	}
	cout << ans << endl;
}