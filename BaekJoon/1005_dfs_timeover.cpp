#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

vector<int> edge[1001];
bool visit[1001];
int cost[1001];
int buildings, edges, fin;

int ans;

void dfs(int cur, int totCost);
void calc();

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(edge, 0, sizeof(edge));
		memset(cost, 0, sizeof(cost));
		cin >> buildings >> edges;
		for (int b = 1; b <= buildings; b++) {
			cin >> cost[b];
		}
		for (int e = 0; e < edges; e++) {
			int from, to;
			cin >> from >> to;
			edge[to].push_back(from);
		}
		cin >> fin;
		calc();
	}
}
void calc() {
	memset(visit, 0, sizeof(visit));
	ans = 0;
	visit[fin] = true;
	dfs(fin, cost[fin]);
	cout << ans << endl;
}
void dfs(int cur, int totCost) {
	if (edge[cur].size() == 0) {
		if (totCost > ans) ans = totCost;
		return;
	}

	for (int i = 0; i < edge[cur].size(); i++) {
		int next_v = edge[cur][i];
		if (visit[next_v]) continue;
		visit[next_v] = true;
		dfs(next_v, totCost + cost[next_v]);
		visit[next_v] = false;
	}
}