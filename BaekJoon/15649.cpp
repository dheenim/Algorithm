#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, M;

vector<vector<int>> answer;
bool visit[9];
void dfs(vector<int> order, int usingNum);

int main() {
	memset(visit, false, sizeof(visit));
	cin >> N >> M;
	vector<int> tmp;
	dfs(tmp,0);
	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}
}

void dfs(vector<int> order, int usingNum) {
	//printf("usingNum = %d\n", usingNum);
	//for (int i = 0; i < order.size(); i++) {
	//	printf("[%d]=%d\n",i, order[i]);
	//}
	if (usingNum == M) {
		answer.push_back(order);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		order.push_back(i);
		dfs(order, usingNum + 1);
		visit[i] = false;
		order.pop_back();
	}
}
