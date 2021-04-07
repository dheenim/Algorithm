#include <iostream>
#include <utility>
#include <cstdio>

using namespace std;

pair<int, int> dir[4] = { {-1,0},{0,1},{1,0},{0,-1} };

int R, C;
int startR, startC, startDir;
int map[51][51];
bool visit[51][51];
int ans = 0;

void clean(int curR, int curC, int curDir);

int main() {
	cin >> R >> C;
	cin >> startR >> startC >> startDir;
	//direction 0:north, 1:east, 2:south, 3:west
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	clean(startR, startC, startDir);
	cout << ans << endl;
}
void clean(int curR, int curC, int curDir) {
	if (!visit[curR][curC]) ans++;
	visit[curR][curC] = true;
	int newDir = (curDir + 3) % 4;
	while (newDir != curDir) {
		if (!map[curR + dir[newDir].first][curC + dir[newDir].second] && !visit[curR + dir[newDir].first][curC + dir[newDir].second]) {
			clean(curR + dir[newDir].first, curC + dir[newDir].second, newDir);
			return;
		}
		newDir = (newDir + 3) % 4;
	}
	if (!map[curR + dir[newDir].first][curC + dir[newDir].second] && !visit[curR + dir[newDir].first][curC + dir[newDir].second]) {
		clean(curR + dir[newDir].first, curC + dir[newDir].second, newDir);
		return;
	}
	if (map[curR + dir[(curDir + 2) % 4].first][curC + dir[(curDir + 2) % 4].second]) return;
	clean(curR + dir[(curDir + 2) % 4].first, curC + dir[(curDir + 2) % 4].second, curDir);
}