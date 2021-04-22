#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dir_row[4] = { 0,0,1,-1 };//오 왼 아 위
int dir_col[4] = { 1,-1,0,0 };
int R, C, T;
int map[2][51][51];
int usingIdx = 0;
pair<int,int> cleaner[2];


void dust();
void WorkCleaner();

int main() {
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[0][i][j];
			if (map[0][i][j] == -1) {
				map[1][i][j] = -1;
				if (cleaner[0].first == 0) {
					cleaner[0].first = i;
					cleaner[0].second = j;
				}
				else {
					cleaner[1].first = i;
					cleaner[1].second = j;
				}
			}
		}
	}

	while (--T >= 0) {
		dust();
		/*cout << "-------afterDust\n";
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cout << map[usingIdx][i][j] << " ";
			}
			cout << "\n";
		}*/
		WorkCleaner();
		/*cout << "--------------------------afterCleaner\n";
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cout << map[usingIdx][i][j] << " ";
			}
			cout << "\n";
		}*/
	}
	int ans = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[usingIdx][i][j] == -1) continue;
			ans += map[usingIdx][i][j];
		}
	}
	cout << ans << endl;
}
void dust() {
	int emptyIdx = (usingIdx + 1) % 2;
	for (int row = 1; row <= R; row++) {
		for (int col = 1; col <= C; col++) {
			if (map[usingIdx][row][col] == -1 || map[usingIdx][row][col] == 0) continue;
			int cnt = 0;
			//cout << "curR:" << row << " curC:" << col << endl;
			map[emptyIdx][row][col] += map[usingIdx][row][col];
			for (int i = 0; i < 4; i++) {
				int nR = row + dir_row[i];
				int nC = col + dir_col[i];
				if (nR > R || nR < 1 || nC < 1 || nC > C) continue;
				if (map[emptyIdx][nR][nC] == -1) continue;
				cnt++;
				//cout << "NR:" << nR << " NC:" << nC << " map:" << map[usingIdx][row][col] / 5 << endl;
				map[emptyIdx][nR][nC] += map[usingIdx][row][col] / 5;
				map[emptyIdx][row][col] -= map[usingIdx][row][col] / 5;
			}
			//cout << "cnt:" << cnt << endl;
			//map[emptyIdx][row][col] += (int)((double)map[usingIdx][row][col] * ((double)1 - (double)((double)cnt / 5)));
			//cout << "emptyrowcol:" << map[emptyIdx][row][col] << " -?:" << (1 - (double)((double)cnt / 5)) << endl;
			map[usingIdx][row][col] = 0;

		}
	}
	usingIdx = emptyIdx;
	return;
}
void WorkCleaner() {
	//위쪽
	int curR = cleaner[0].first - 1;
	int curC = cleaner[0].second;
	int nextR = curR - 1;
	int nextC = curC;
	while (nextR > 0) {
		map[usingIdx][curR][curC] = map[usingIdx][nextR][nextC];
		nextR--;
		curR--;
	}
	nextR = 1; nextC = 2;
	while (nextC <= C) {
		map[usingIdx][curR][curC] = map[usingIdx][nextR][nextC];
		nextC++;
		curC++;
	}
	nextR = 2; nextC = C;
	while (nextR <= cleaner[0].first) {
		map[usingIdx][curR][curC] = map[usingIdx][nextR][nextC];
		nextR++;
		curR++;
	}
	nextR--; nextC = C - 1;
	while (nextC > cleaner[0].second) {
		map[usingIdx][curR][curC] = map[usingIdx][nextR][nextC];
		nextC--;
		curC--;
	}
	map[usingIdx][curR][curC] = 0;

	//아래
	curR = cleaner[1].first + 1; curC = cleaner[1].second;
	nextR = curR + 1; nextC = curC;
	while (nextR <= R) {
		map[usingIdx][curR][curC] = map[usingIdx][nextR][nextC];
		nextR++;
		curR++;
	}
	nextR = R; nextC = 2;
	while (nextC <= C) {
		map[usingIdx][curR][curC] = map[usingIdx][nextR][nextC];
		nextC++;
		curC++;
	}
	nextR = R - 1; nextC = C;
	while (nextR >= cleaner[1].first) {
		map[usingIdx][curR][curC] = map[usingIdx][nextR][nextC];
		nextR--;
		curR--;
	}
	nextR = cleaner[1].first; nextC = C - 1;
	while (nextC > cleaner[1].second) {
		map[usingIdx][curR][curC] = map[usingIdx][nextR][nextC];
		nextC--;
		curC--;
	}
	//cout << "nextR:" << nextR << " nextC:" << nextC << endl;
	//cout << "curR:" << curR << " curC:" << curC << endl;
	map[usingIdx][curR][curC] = 0;
	return;
}