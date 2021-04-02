#include <iostream>
#include <utility>
using namespace std;

pair<int,int> dp[41];

int main() {
	int T;
	cin >> T;
	dp[0].first = 1;
	dp[0].second = 0;
	dp[1].first = 0;
	dp[1].second = 1;
	int max_ = 1;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		for (int j = max_+1; j <= N; j++) {
			dp[j].first = dp[j - 1].first + dp[j-2].first;
			dp[j].second = dp[j - 1].second + dp[j - 2].second;
		}
		if (N > max_) max_ = N;
		cout << dp[N].first << ' ' << dp[N].second << endl;
	}
	return 0;
}