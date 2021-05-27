#include <iostream>

using namespace std;
int dp[21];
int fib(int n);
int main() {
	//dp[0] = 0; dp[1] = 1;
	//int n; cin >> n;
	//for (int i = 2; i <= n; i++) {
	//	dp[i] = dp[i - 1] + dp[i - 2];
	//}
	//cout << dp[n] << "\n";
	int n; cin >> n;
	cout << fib(n);
}
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}