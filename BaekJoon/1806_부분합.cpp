#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	vector<int> input;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		input.push_back(num);
	}
	int ans = 1000000;
	int left = 0, right = 0;
	int sum = input[0];
	while (right >= left) {
		if (sum >= s) {
			ans = (ans < right - left + 1) ? ans : (right - left + 1);
			sum -= input[left];
			left++;
		}
		else {
			if (right + 1 == input.size()) break;
			sum += input[++right];
		}
	}
	if (ans == 1000000) cout << 0 << endl;
	else cout << ans << endl;
}