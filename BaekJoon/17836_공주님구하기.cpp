#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
#define MIN(a,b) ((a)<(b))?(a):(b)
#define INF 1000000000
using namespace std;

int dir_row[4] = { 0,0,1,-1 };
int dir_col[4] = { 1,-1,0,0 };
int N, M, T;
int map[101][101];
bool visit[101][101];
bool visit_graem[101][101];
int time[101][101];
int ans = INF;

void bfs(int row, int col, int curTime, bool graem);
bool chkRange(int row, int col);
int main() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	visit[1][1] = true;
	bfs(1, 1, 0, false);
	if (ans < INF)
		cout << ans << endl;
	else cout << "Fail" << endl;
}
bool chkRange(int row, int col) {
	if (row > N || row < 1 || col > M || col < 1) return false;
	return true;
}

void bfs(int row, int col, int curTime, bool graem) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {row,col}, curTime });
	while (!q.empty()) {
		pair<pair<int, int>, int> cur = q.front();
		//printf("curR:%d,curC:%d\n", cur.first.first, cur.first.second);
		q.pop();
		if (cur.first.first == N && cur.first.second == M) {
			ans = MIN(ans, cur.second);
			return;
		}
		for (int i = 0; i < 4; i++) {
			
			int next_row = cur.first.first + dir_row[i];
			int next_col = cur.first.second + dir_col[i];
			//printf("nextR:%d, nextC:%d, time:%d\n", next_row, next_col,cur.second);
			if (!chkRange(next_row, next_col)) continue;

			if (map[next_row][next_col] == 1) continue;
			if (map[next_row][next_col] == 2) {
				//printf("%d %d %d//ans:%d\n", cur.second + 1, N - next_row, M - next_col,ans);
				if(T >= cur.second + 1 + N - next_row + M - next_col)
					ans = MIN(ans, cur.second + 1 + N - next_row + M - next_col);
				continue;
			}
			if (visit[next_row][next_col]) continue;
			if (cur.second + 1 > T || cur.second + 1 >= ans) continue;
			visit[next_row][next_col] = true;
			q.push({ {next_row, next_col},  cur.second + 1 });
		}
	}
}