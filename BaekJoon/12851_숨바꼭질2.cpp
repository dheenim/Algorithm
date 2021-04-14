#include <iostream>
#include <queue>

using namespace std;
bool visit[100001];
int dp[100001];
int dpcnt[100001];
int n, k;
void bfs();

int main() {
	cin >> n >> k;
	bfs();
	cout << dp[k] << endl;
	cout << dpcnt[k] << endl;
}
void bfs() {
	queue<int> q;
	q.push(n);
	visit[n] = true;
	dpcnt[n] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : {cur - 1, cur + 1, cur * 2}) {
			if (next >= 0 && next <= 100000) {
				if (visit[next] == false) {
					visit[next] = true;
					dp[next] = dp[cur] + 1;
					dpcnt[next] = dpcnt[cur];
					q.push(next);
				}
				else if (dp[next] == dp[cur] + 1) {
					dpcnt[next] += dpcnt[cur];
				}
			}
		}
		//printf("cur:%d dp[cur]:%d dpcnt[cnt]:%d\n", cur, dp[cur], dpcnt[cur]);
	}
}