#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;

int dp[1001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		A.push_back(input);
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		int j;
		int max_ = 1;
		for (j = i - 1; j >= 0; j--) {
			if (A[j] < A[i]) {
				if (max_ <= dp[j]) max_ = dp[j] + 1;
			}
			
		}
		dp[i] = max_;
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (dp[i] > ans) ans = dp[i];
	}
	cout << ans << endl;
}