#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;
int dp[1001];
int N;
int ans = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	ans = (dp[0] = input[0]);
	for (int i = 1; i < input.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (input[i] < input[j]) {
				dp[i] = max(dp[i], dp[j] + input[i]);
				
			}
			else {
				dp[i] = max(dp[i],input[i]);
			}
		}
		if (dp[i] > ans) ans = dp[i];
	}
	cout << ans << endl;
}