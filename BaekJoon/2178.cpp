#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dir_row[4] = {-1,1,0,0};
int dir_col[4] = {0,0,-1,1};

int N, M;
bool maze[101][101];
int val[101][101];
int ans = 100000000;


void bfs();

int main() {
	memset(maze, 0, sizeof(maze));
	memset(visit, 0, sizeof(visit));
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '0') maze[i][j + 1] = false;
			else maze[i][j + 1] = true;
		}
	}
	bfs();
}

void bfs() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			val[i][j] = 100000000;
		}
	}
	queue<pair<int,int>> q;
	q.push({ 1, 1 });
	val[1][1] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int cur_val = val[cur.first][cur.second];
		for (int i = 0; i < 4; i++) {
			int next_row = cur.first + dir_row[i];
			int next_col = cur.second + dir_col[i];
			if (!maze[next_row][next_col]) continue;
			if (next_row < 1 || next_row > N || next_col < 1 || next_col > M) continue;
			int next_val = val[next_row][next_col];
			if (cur_val + 1 < next_val) {
				val[next_row][next_col] = cur_val + 1;
				q.push({ next_row,next_col });
			}
		}
	}
	cout << val[N][M] << endl;
}