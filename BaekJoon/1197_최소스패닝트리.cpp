#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> selected;
vector<pair<int,int>> edge[10001];
int V, E;
int ans = 0;
void mst();
//priority 정렬 방식
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};
int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int s, d, c;
		cin >> s >> d >> c;
		edge[s].push_back({ d,c });
		edge[d].push_back({ s,c });
	}
	mst();
	cout << ans << endl;
}
void mst() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 0; i < edge[1].size(); i++) {
		pq.push({ edge[1][i].first, edge[1][i].second });
	}
	selected.push_back(1);
	while (selected.size() < V) {
		pair<int, int> vtx = pq.top();
		pq.pop();
		if (find(selected.begin(), selected.end(), vtx.first) == selected.end()) {
			//선택된 집합에 없는 vertex일때
			selected.push_back(vtx.first);
			ans += vtx.second;
			for (int i = 0; i < edge[vtx.first].size(); i++) {
				pq.push({ edge[vtx.first][i].first, edge[vtx.first][i].second });
			}
		}
	}
}