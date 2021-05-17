#include <iostream>
#include <vector>
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int n;
int ans = 0;

int input[501][501];
int dp[501][501];
void dfs(int sum, int idx, int depth);
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int tmp; cin >> tmp;
			input[i][j] = tmp;
		}
	}
	dp[1][1] = input[1][1];
	int depth = 2;
	while (depth <= n) {
		for (int idx = 1; idx <= depth; idx++) {
			//cout << "max:" << (MAX(dp[depth - 1][idx], dp[depth - 1][idx - 1])) << endl;
			//cout << "input[" << depth << "][" << idx << "]:" << input[depth][idx] << endl;
			dp[depth][idx] = (MAX(dp[depth - 1][idx], dp[depth - 1][idx - 1])) + input[depth][idx];
			//cout << "depth:" << depth << "idx:" << idx << "dp:" << dp[depth][idx] << endl;
		}
		depth++;
	}
	for (int i = 1; i <= n; i++) {
		if (ans < dp[n][i]) ans = dp[n][i];
	}
	cout << ans << endl;
}
