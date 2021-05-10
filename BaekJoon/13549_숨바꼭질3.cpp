#include<iostream>
#include <vector>
#include<queue>
#define INF 2100000000
using namespace std;
int dp[100001];
int N, K;

int main() {
	cin >> N >> K;
	for (int i = 0; i <= 100000; i++) dp[i] = INF;
	queue<int> q;
	q.push(N);
	dp[N] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == K) break;
		if (cur - 1 >= 0 && dp[cur-1] > dp[cur]+1) {
			dp[cur - 1] = dp[cur] + 1;
			q.push(cur - 1);
		}
		if (cur + 1 < 100001 && dp[cur+1] > dp[cur]+1) {
			dp[cur + 1] = dp[cur] + 1;
			q.push(cur + 1);
		}
		if (cur * 2 < 100001 && dp[cur * 2] > dp[cur]) {
			dp[cur * 2] = dp[cur];
			q.push(cur * 2);
		}
	}
	cout << dp[K];
}