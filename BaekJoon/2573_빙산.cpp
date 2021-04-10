#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int dir_row[4] = { -1,1,0,0 };
int dir_col[4] = { 0,0,1,-1 };

int row, col;
bool chkZero[301][301];
bool visit[301][301];
int ice[301][301];
int ans = 0;

void calc_ice();
int check_visit_and_ice();
bool chkRange(int r, int c);

int main() {
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> ice[i][j];
		}
	}
	calc_ice();
}
int check_visit_and_ice() {
	memset(visit, 0, sizeof(visit));
	int cnt = 0;
	int state = 0;//0이면 얼음 다 녹음
	//1이면 두덩이 이상
	//2이면 구멍
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (ice[i][j] > 0 && !visit[i][j]) {
				state = 2;
				queue<pair<int, int>> q;
				q.push({ i,j });
				while (!q.empty()) {
					pair<int, int> pos = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int next_row = pos.first + dir_row[dir];
						int next_col = pos.second + dir_col[dir];
						if (!chkRange(next_row, next_col)) continue;
						if (visit[next_row][next_col]) continue;
						if (ice[next_row][next_col] == 0)continue;
						visit[next_row][next_col] = true;
						q.push({ next_row,next_col });
					}
				}
				cnt++;
			}
		}
	}

	if (cnt >= 2) {
		return 1;
	}
	return state;
}
bool chkRange(int r, int c) {
	if (r > row || c > col || c < 1 || r < 1) return false;
	return true;
}
void calc_ice() {
	int state;
	while ((state = check_visit_and_ice()) == 2) {
		memset(chkZero, 0, sizeof(chkZero));
		for (int r = 1; r <= row; r++) {
			for (int c = 1; c <= col; c++) {
				if (chkZero[r][c] || ice[r][c] > 0) continue;
				for (int i = 0; i < 4; i++) {
					int next_row = r + dir_row[i];
					int next_col = c + dir_col[i];
					if (!chkRange(next_row, next_col)) continue;
					if (ice[next_row][next_col] == 0)continue;
					ice[next_row][next_col]--;
					if (ice[next_row][next_col] == 0) chkZero[next_row][next_col] = true;
				}
			}
		}
		ans++;
	}

	if (state == 1) 
		cout << ans << endl;
	else 
		cout << "0" << endl;
	return;
}