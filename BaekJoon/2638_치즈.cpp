#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int dir_row[4] = { -1,1,0,0 };
int dir_col[4] = { 0,0,1,-1 };

int row, col;
int chkTwo[101][101];
int cheese[101][101];
bool visit[101][101];
int ans = 0;

void calcCheese();

int main() {
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> cheese[i][j];
		}
	}
	calcCheese();
	cout << ans << endl;
}
bool chkAllGone() {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (cheese[i][j]) return false;
		}
	}
	return true;
}
bool chkRange(pair<int, int> pos) {
	if (pos.first < 1 || pos.second < 1 || pos.first > row || pos.second > col) {
		return false;
	}
	return true;
}
void calcCheese() {
	while (!chkAllGone()) {
		memset(visit, 0, sizeof(visit));
		memset(chkTwo, 0, sizeof(chkTwo));
		queue<pair<int,int>> q;
		q.push({ 1,1 });
		visit[1][1] = true;
		
		while (!q.empty()) {
			pair<int, int> curPos = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_row = curPos.first + dir_row[i];
				int next_col = curPos.second + dir_col[i];
				if (!chkRange(curPos)) {
					continue;
				}
				if (cheese[next_row][next_col] && !cheese[curPos.first][curPos.second]) {
					chkTwo[next_row][next_col]++;
					if (chkTwo[next_row][next_col] > 1) {
						cheese[next_row][next_col] = 0;
					}
					visit[next_row][next_col] = true;
				}
				if (visit[next_row][next_col]) continue;
				visit[next_row][next_col] = true;
				q.push({ next_row,next_col });
			}
		}
		ans++;
	}
}
