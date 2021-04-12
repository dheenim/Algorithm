#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#include <cstdio>
#define INF 1000000001
using namespace std;

vector<pair<int, int>> edge[1001];
vector<pair<int, int>> to_edge[1001];
bool visit[1001];
int cityNum, busNum;
int startStation, destStation;
int ans = 1000000000;
int dist[1001];

int main() {

	cin >> cityNum >> busNum;

	for (int i = 0; i < busNum; i++) {
		int start, dest, cost_;
		cin >> start >> dest >> cost_;
		to_edge[start].push_back({ dest,cost_ });
		edge[dest].push_back({ start,cost_ });
		//edge[start].push_back({ dest,cost_ });
	}
	cin >> startStation >> destStation;
	for (int i = 0; i <= cityNum; i++) {
		dist[i] = INF;
	}
	visit[startStation] = true;
	dist[startStation] = 0;
	for (int i = 0; i < to_edge[startStation].size(); i++) {
		dist[to_edge[startStation][i].first] = min(dist[to_edge[startStation][i].first] ,to_edge[startStation][i].second);
	}
	/*for (int i = 1; i <= cityNum;i++) {
		printf("dist[%d] = %d\n", i, dist[i]);
	}
	printf("\n");*/
	for (int i = 1; i < cityNum; i++) {
		int min_idx = 0;
		int min_dist = INF;
		int v;
		for (v = 1; v <= cityNum; v++) {
			if (visit[v]) continue;
			if (dist[v] < min_dist) {
				min_dist = dist[v];
				min_idx = v;
			}
		}
		for (int k = 0; k < to_edge[min_idx].size(); k++) {
			if (visit[to_edge[min_idx][k].first]) continue;
			dist[to_edge[min_idx][k].first] = min(dist[to_edge[min_idx][k].first], dist[min_idx] + to_edge[min_idx][k].second);
		}
		visit[min_idx] = true;
		/*printf("minidx:%d\n", min_idx);
		for (int i = 1; i <= cityNum; i++) {
			printf("dist[%d] = %d\n", i, dist[i]);
		}
		printf("\n");*/
	}
	cout << dist[destStation] << endl;
}
