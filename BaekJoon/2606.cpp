#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int edgeNum;
vector<int> edge[101];
int cnt = 0;
bool visit[101];
void dfs(int cur);

int main() {
	cin >> N;
	cin >> edgeNum;
	for (int i = 1; i <= edgeNum; i++) {
		int s, d;
		cin >> s >> d;
		edge[s].push_back(d);
		edge[d].push_back(s);
	}
	memset(visit, 0, sizeof(visit));
	dfs(1);
	cout << cnt-1 << endl;
}

void dfs(int cur) {
	
	visit[cur] = true;
	cnt++;
	for (int i = 0; i < edge[cur].size(); i++) {
		//printf("cur:%d, next:%d, cur_cnt : %d\n", cur, edge[cur][i],cnt);
		if (visit[edge[cur][i]]) continue;
		dfs(edge[cur][i]);
	}
}