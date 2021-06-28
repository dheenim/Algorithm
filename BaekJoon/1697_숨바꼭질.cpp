#include <iostream>
#include <queue>
#define MIN(a,b) (a)<(b)?(a):(b)
#define INF 2100000000
using namespace std;

int n, k;
int sec[100001];
bool visit[100001];
int main() {
	cin >> n >> k;
	for (int i = 0; i <= 100000; i++)
		sec[i] = INF;
	sec[n] = 0; visit[n] = true;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		//cout << "cur:" << cur << endl;
		if (cur == k) break;
		q.pop();
		if (cur == 0) {
			sec[cur + 1] = MIN(sec[cur] + 1, sec[cur + 1]);
			q.push(cur+1);
			visit[cur+1] = true;
			continue;
		}
		if (cur - 1 >= 0 && !visit[cur - 1]) {
			sec[cur - 1] = MIN(sec[cur] + 1, sec[cur - 1]);
			visit[cur - 1] = true;
			q.push(cur - 1);
		}
		if (cur + 1 <= 100000 && !visit[cur + 1]) {
			sec[cur + 1] = MIN(sec[cur] + 1, sec[cur + 1]);
			visit[cur + 1] = true;
			q.push(cur + 1);
		}
		if (cur * 2 <= 100000 && !visit[cur * 2]) {
			sec[cur * 2] = MIN(sec[cur] + 1, sec[cur * 2]);
			visit[cur * 2] = true;
			q.push(cur * 2);
		}
	}
	cout << sec[k] << endl;
	return 0;
}