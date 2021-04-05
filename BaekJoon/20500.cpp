#include <iostream>

using namespace std;
int N;
long long dp[1516];

int main() {
	cin >> N;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 3;
	for (int i = 5; i <= N; i++) {
		if (i % 2 == 0) {
			dp[i] = (dp[i - 1] * 2 + 1) % 1000000007;
		}
		else {
			dp[i] = (dp[i - 1] * 2 - 1) % 1000000007;
		}
	}
	cout << dp[N] << endl;
	return 0;
}