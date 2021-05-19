#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
vector<int> order[32001];
int indegree[32001];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int fst, sec;
		cin >> fst >> sec;
		order[fst].push_back(sec);
		indegree[sec]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int cur = pq.top();
		cout << cur << " ";
		pq.pop();
		for (int i = 0; i < order[cur].size(); i++) {
			indegree[order[cur][i]]--;
			if(indegree[order[cur][i]] == 0)
				pq.push(order[cur][i]);
		}
	}
}
