#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <set>
#define INF 2100000000
using namespace std;
unordered_map<int,int> map[10001];
bool visit[10001];
set<int> edge[10001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int s, d, c;
		cin >> s >> d >> c;
		if (map[s].empty()) {
			map[s][d] = c;
		}
		if (map[d].empty()) {
			map[d][s] = c;
		}
		if (map[s][d] < c) map[s][d] = c;
		if (map[d][s] < c) map[d][s] = c;
		edge[s].insert(d);
		edge[d].insert(s);
	}
	int start, dest;
	cin >> start >> dest;
	int low = 0, high = 1000000000;
	while (low <= high) {
		int mid = (low + high) / 2;
		//cout << "@@@@@@@@@@@@@mid:" << mid << endl;
		//cout << "low:" << low << " high:" << high << endl;
		memset(visit, 0, sizeof(visit));
		queue<int> q;
		q.push(start);
		visit[start] = true;
		bool pos = false;
		while (!q.empty()) {
			int cur = q.front();
			//cout << "cur:" << cur << endl;
			q.pop();
			if (cur == dest) {
				pos = true;
				break;
			}
			for (auto it = edge[cur].begin(); it != edge[cur].end(); it++) {
				//cout << "*it:" << *it << endl;
				if (map[cur][*it] < mid) continue;
				if (visit[*it]) continue;
				q.push(*it);
				visit[*it] = true;
			}
		}
		if (pos) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << high << endl;
}