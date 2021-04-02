#include <iostream>
using namespace std;

int N;
int input[1001];
int dp[1001];

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		dp[i] = 100000000;
	}
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		for (int j = input[i]; j > 0; j--) {
			if (dp[i+j] > dp[i] + 1) {
				dp[i+j] = dp[i] + 1;
			}
		}
	}
	if (dp[N - 1] >= 100000000) {
		cout << -1 << endl;
	}
	else cout << dp[N - 1] << endl;
}