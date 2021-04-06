#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;


int degree[1001];
int cost[1001];
int costAns[1001];
int buildings, edges, fin;

int ans;

void calc(vector<int> *fromto);

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<int> fromto[1001];
		memset(degree, 0, sizeof(degree));
		memset(cost, 0, sizeof(cost));
		memset(costAns, 0, sizeof(costAns));
		cin >> buildings >> edges;
		for (int b = 1; b <= buildings; b++) {
			cin >> cost[b];
		}
		for (int e = 0; e < edges; e++) {
			int from, to;
			cin >> from >> to;
			fromto[from].push_back(to);
			degree[to]++;
		}
		cin >> fin;
		calc(fromto);
	}
}
void calc(vector<int> *fromto) {
	queue<int> q;
	for (int i = 1; i <= buildings; i++) {
		if (!degree[i]) {
			costAns[i] = cost[i];
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < fromto[cur].size(); i++) {
			int next = fromto[cur][i];
			degree[next]--;
			costAns[next] = costAns[next] > costAns[cur] + cost[next] ? costAns[next] : costAns[cur] + cost[next];
			if (!degree[next]) {
				q.push(next);
			}
		}
	}

	cout << costAns[fin] << endl;
}