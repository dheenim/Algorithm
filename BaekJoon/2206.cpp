#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#define INF 100000000
using namespace std;

int N, M;
int map[1002][1002];
//bool visit[1002][1002];
//bool oneWallvisit[1002][1002];
pair<int,int> dp[1002][1002];
int ans;
//void dfs(int row, int col, int dist, int breakWall);
void bfs();
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j + 1] = str[j] - 48;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j].first = INF;
			dp[i][j].second = INF;
		}
	}
	//memset(oneWallvisit, 0, sizeof(oneWallvisit));
	//memset(visit, 0, sizeof(visit));
	dp[1][1].first = 1;
	bfs();
	ans = dp[N][M].first < dp[N][M].second ? dp[N][M].first : dp[N][M].second;
	if (ans >= INF) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}

}
void bfs() {
	queue<pair<int,pair<int, int>>> q;//row, col, wall
	q.push(make_pair(1, make_pair(1,0)));
	while (!q.empty()) {
		pair<int, pair<int, int>> tmp = q.front();
		q.pop();
		int row = tmp.first;
		int col = tmp.second.first;
		int wall = tmp.second.second;
		if (!wall) {//wall안부숨
			//위쪽
			if ((row - 1 >= 1 && col >= 1) && (row - 1 <= N && col <= M)) {
				int nextRow = row - 1;
				int nextCol = col;
				if (map[nextRow][nextCol]) {//이동할 곳 벽 있는 경우
					int nextVal = dp[row][col].first + 1;
					if (nextVal < dp[nextRow][nextCol].second) {
						dp[nextRow][nextCol].second = dp[row][col].first + 1;
						q.push(make_pair(nextRow, make_pair(nextCol, 1)));
					}
				}
				else {
					int nextVal = dp[row][col].first + 1;
					if (nextVal < dp[nextRow][nextCol].first) {
						dp[nextRow][nextCol].first = dp[row][col].first + 1;
						q.push(make_pair(nextRow, make_pair(nextCol, 0)));
					}
				}
			}

			//아래쪽
			if ((row + 1 >= 1 && col >= 1) && (row + 1 <= N && col <= M)) {
				int nextRow = row + 1;
				int nextCol = col;
				if (map[nextRow][nextCol]) {//이동할 곳 벽 있는 경우
					int nextVal = dp[row][col].first + 1;
					if (nextVal < dp[nextRow][nextCol].second) {
						dp[nextRow][nextCol].second = dp[row][col].first + 1;
						q.push(make_pair(nextRow, make_pair(nextCol, 1)));
					}
				}
				else {
					int nextVal = dp[row][col].first + 1;
					if (nextVal < dp[nextRow][nextCol].first) {
						dp[nextRow][nextCol].first = dp[row][col].first + 1;
						q.push(make_pair(nextRow, make_pair(nextCol, 0)));
					}
				}
			}
			//왼쪽
			if ((row >= 1 && col - 1 >= 1) && (row <= N && col - 1 <= M)) {
				int nextRow = row;
				int nextCol = col - 1;
				if (map[nextRow][nextCol]) {//이동할 곳 벽 있는 경우
					int nextVal = dp[row][col].first + 1;
					if (nextVal < dp[nextRow][nextCol].second) {
						dp[nextRow][nextCol].second = dp[row][col].first + 1;
						q.push(make_pair(nextRow, make_pair(nextCol, 1)));
					}
				}
				else {
					int nextVal = dp[row][col].first + 1;
					if (nextVal < dp[nextRow][nextCol].first) {
						dp[nextRow][nextCol].first = dp[row][col].first + 1;
						q.push(make_pair(nextRow, make_pair(nextCol, 0)));
					}
				}
			}
			//오른쪽
			if ((row >= 1 && col + 1 >= 1) && (row <= N && col + 1 <= M)) {
				int nextRow = row;
				int nextCol = col + 1;
				if (map[nextRow][nextCol]) {//이동할 곳 벽 있는 경우
					int nextVal = dp[row][col].first + 1;
					if (nextVal < dp[nextRow][nextCol].second) {
						dp[nextRow][nextCol].second = dp[row][col].first + 1;
						q.push(make_pair(nextRow, make_pair(nextCol, 1)));
					}
				}
				else {
					int nextVal = dp[row][col].first + 1;
					if (nextVal < dp[nextRow][nextCol].first) {
						dp[nextRow][nextCol].first = dp[row][col].first + 1;
						q.push(make_pair(nextRow, make_pair(nextCol, 0)));
					}
				}
			}
		}
		else {//이미 벽한번 부순 상태
			//위쪽
			if ((row - 1 >= 1 && col >= 1) && (row - 1 <= N && col <= M)) {
				int nextRow = row - 1;
				int nextCol = col;
				if (!map[nextRow][nextCol]) {//이동할 곳 벽 없는 경우
					int nextVal = dp[row][col].second + 1;
					if (nextVal < dp[nextRow][nextCol].second && nextVal < dp[nextRow][nextCol].first) {
						dp[nextRow][nextCol].second = nextVal;
						q.push(make_pair(nextRow, make_pair(nextCol, 1)));
					}
				}
			}

			//아래쪽
			if ((row + 1 >= 1 && col >= 1) && (row + 1 <= N && col <= M)) {
				int nextRow = row + 1;
				int nextCol = col;
				if (!map[nextRow][nextCol]) {//이동할 곳 벽 없는 경우
					int nextVal = dp[row][col].second + 1;
					if (nextVal < dp[nextRow][nextCol].second && nextVal < dp[nextRow][nextCol].first) {
						dp[nextRow][nextCol].second = nextVal;
						q.push(make_pair(nextRow, make_pair(nextCol, 1)));
					}
				}
			}
			//왼쪽
			if ((row >= 1 && col - 1 >= 1) && (row <= N && col - 1 <= M)) {
				int nextRow = row;
				int nextCol = col - 1;
				if (!map[nextRow][nextCol]) {//이동할 곳 벽 없는 경우
					int nextVal = dp[row][col].second + 1;
					if (nextVal < dp[nextRow][nextCol].second && nextVal < dp[nextRow][nextCol].first) {
						dp[nextRow][nextCol].second = nextVal;
						q.push(make_pair(nextRow, make_pair(nextCol, 1)));
					}
				}
			}
			//오른쪽
			if ((row >= 1 && col + 1 >= 1) && (row <= N && col + 1 <= M)) {
				int nextRow = row;
				int nextCol = col + 1;
				if (!map[nextRow][nextCol]) {//이동할 곳 벽 없는 경우
					int nextVal = dp[row][col].second + 1;
					if (nextVal < dp[nextRow][nextCol].second && nextVal < dp[nextRow][nextCol].first) {
						dp[nextRow][nextCol].second = nextVal;
						q.push(make_pair(nextRow, make_pair(nextCol, 1)));
					}
				}
			}
		}
		
	}
}

//void dfs(int row, int col, int dist, int breakWall) {
//	cout << row << ' ' << col << ' ' << dist << ' ' << breakWall << endl;
	//if ((row < 1 || col < 1) || (row > N || col > M)) return;
	//if (map[row][col]) breakWall++;
	//if (breakWall >= 2) return;
	//if (row == N && col == M) {
	//	//cout << dist << ' ' << breakWall << endl;
	//	if (ans == -1 || ans > dist) ans = dist;
	//	return;
	//}
	//dist++;
	//if (ans != -1 && dist >= ans) return;
	////위쪽
	//if ((row - 1 >= 1 && col >= 1) && (row - 1 <= N && col <= M)) {
	//	if (!visit[row - 1][col]) {
	//		visit[row - 1][col] = true;
	//		dfs(row-1,col,dist,breakWall);
	//		visit[row - 1][col] = false;
	//	}
	//}
	//
	////아래쪽
	//if ((row + 1 >= 1 && col >= 1) && (row + 1 <= N && col <= M)) {
	//	if (!visit[row + 1][col]) {
	//		visit[row + 1][col] = true;
	//		dfs(row + 1, col, dist, breakWall);
	//		visit[row + 1][col] = false;
	//	}
	//}
	////왼쪽
	//if ((row >= 1 && col - 1 >= 1) && (row <= N && col - 1<= M)) {
	//	if (!visit[row][col - 1]) {
	//		visit[row][col - 1] = true;
	//		dfs(row, col - 1, dist, breakWall);
	//		visit[row][col - 1] = false;
	//	}
	//}
	////오른쪽
	//if ((row >= 1 && col + 1 >= 1) && (row <= N && col + 1 <= M)) {
	//	if (!visit[row][col + 1]) {
	//		visit[row][col + 1] = true;
	//		dfs(row, col + 1, dist, breakWall);
	//		visit[row][col + 1] = false;
	//	}
	//}
//}