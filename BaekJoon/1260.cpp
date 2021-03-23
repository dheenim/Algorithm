#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, V;
vector<int> edge[1001];
bool visit[1001];

void dfs(int startNum);
void bfs(int startNum);
bool chk();

int main() {
	memset(visit, false, sizeof(visit));

	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {
		int s, d;
		cin >> s >> d;
		edge[s].push_back(d);
		edge[d].push_back(s);
	}
	for (int i = 1; i <= N; i++) {
		if (edge[i].size() < 1) continue;
		sort(edge[i].begin(), edge[i].end());
	}
	dfs(V);
	memset(visit, false, sizeof(visit));
	bfs(V);
}
bool chk() {
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) return false;
	}
	return true;
}
void bfs(int startNum) {
	vector<int> ans;
	queue<int> q;

	//ans.push_back(startNum);
	q.push(startNum);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visit[cur]) continue;
		visit[cur] = true;
		ans.push_back(cur);
		for (int j = 0; j < edge[cur].size(); j++) {

			int next = edge[cur][j];
			//printf("cur:%d next:%d\n", cur, next);
			if (visit[next]) continue;
			q.push(next);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	//printf("\n");
}
void dfs(int startNum) {
	vector<int> ans;
	stack<int> s;

	s.push(startNum);
	visit[startNum] = true;
	ans.push_back(startNum);
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		for (int j = 0; j < edge[cur].size(); j++) {
			
			int next = edge[cur][j];
			//printf("cur:%d next:%d\n", cur, next);
			if (visit[next]) continue;
			visit[next] = true;
			ans.push_back(next);
			s.push(cur);
			s.push(next);
			break;
		}
	}
	
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}