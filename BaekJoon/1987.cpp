#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void dfs(int cur_r, int cur_c, int cnt);

int dir_row[4] = { -1, 1, 0, 0 };//À§ ¾Æ·¡ ¿Þ ¿À
int dir_col[4] = { 0, 0, 1, -1 };
int R, C;
int answer = 0;
char board[21][21];
bool alphabet[26];
bool visit[21][21];

int main() {
	memset(board, 0, sizeof(board));
	memset(alphabet, 0, sizeof(alphabet));
	memset(visit, 0, sizeof(visit));
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			board[i + 1][j + 1] = str[j];
		}
	}
	alphabet[board[1][1] - 65] = true;
	visit[1][1] = true;
	dfs(1, 1, 1);
	cout << answer << endl;
}

void dfs(int cur_r, int cur_c, int cnt) {
	bool movechk = false;
	for (int i = 0; i < 4; i++) {
		int next_row = cur_r + dir_row[i];
		int next_col = cur_c + dir_col[i];
		if (next_row > R || next_row < 1 || next_col > C || next_col < 1) {
			continue;
		}
		if (visit[next_row][next_col]) continue;
		char nextAlpha = board[next_row][next_col];
		if (alphabet[nextAlpha - 65]) continue;
		movechk = true;
		alphabet[nextAlpha - 65] = true;
		visit[next_row][next_col] = true;
		dfs(next_row, next_col, cnt + 1);
		alphabet[nextAlpha - 65] = false;
		visit[next_row][next_col] = false;
	}
	if (!movechk) {
		if (answer < cnt) answer = cnt;
		return;
	}
}