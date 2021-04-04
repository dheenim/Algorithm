#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
using namespace std;

int chess[1001][1001];//queen:1,knight:2,pawn:3
int row, col;
vector<pair<int, int>> queen;
vector<pair<int, int>>knight;
vector<pair<int, int>>pawn;
int queenNum, knightNum, pawnNum;

void queenMoving();
void knightMoving();

int main() {
	cin >> row >> col;
	
	cin >> queenNum;
	for (int i = 0; i < queenNum; i++) {
		int r, c;
		cin >> r >> c;
		queen.push_back({ r,c });
		//chess[r][c] = 1;
	}
	cin >> knightNum;
	for (int i = 0; i < knightNum; i++) {
		int r, c;
		cin >> r >> c;
		knight.push_back({ r,c });
		chess[r][c] = 2;
	}
	cin >> pawnNum;
	for (int i = 0; i < pawnNum; i++) {
		int r, c;
		cin >> r >> c;
		pawn.push_back({ r,c });
		chess[r][c] = 3;
	}

	queenMoving();
	knightMoving();
	int ans = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			//cout << chess[i][j] << ' ';
			if (!chess[i][j]) ans++;
		}
		//cout << '\n';
	}
	cout << ans << endl;
}

void queenMoving() {
	for (int i = 0; i < queen.size(); i++) {
		pair<int, int> pos = queen[i];
		//printf("row:%d col:%d\n", pos.first, pos.second);
		chess[pos.first][pos.second] = 1;
		//위로
		for (int r = pos.first - 1; r > 0; r--) {
			if (chess[r][pos.second] == 3 || chess[r][pos.second] == 2) break;
			chess[r][pos.second] = 1;
		}
		//아래
		for (int r = pos.first + 1; r <= row; r++) {
			if (chess[r][pos.second] == 3 || chess[r][pos.second] == 2) break;
			chess[r][pos.second] = 1;
		}
		//오른쪽
		for (int c = pos.second + 1; c <= col; c++) {
			if (chess[pos.first][c] == 3 || chess[pos.first][c] == 2) break;
			chess[pos.first][c] = 1;
		}
		//왼쪽
		for (int c = pos.second - 1; c > 0; c--) {
			if (chess[pos.first][c] == 3 || chess[pos.first][c] == 2) break;
			chess[pos.first][c] = 1;
		}

		//왼위 대각
		int leftup_cross = -1;
		for (int r = pos.first - 1; r > 0; r--) {
			if (pos.second + leftup_cross < 1)break;
			if (chess[r][pos.second + leftup_cross] == 3 || chess[r][pos.second + leftup_cross] == 2) break;
			chess[r][pos.second + leftup_cross] = 1;
			leftup_cross--;
		}
		//오른위 대각
		int rightup_cross = 1;
		for (int r = pos.first - 1; r > 0; r--) {
			if (pos.second + rightup_cross > col)break;
			if (chess[r][pos.second + rightup_cross] == 3 || chess[r][pos.second + rightup_cross] == 2) break;
			chess[r][pos.second + rightup_cross] = 1;
			rightup_cross++;
		}
		//왼아래 대각
		int leftdown_cross = -1;
		for (int r = pos.first + 1; r <= row; r++) {
			if (pos.second + leftdown_cross < 1)break;
			if (chess[r][pos.second + leftdown_cross] == 3 || chess[r][pos.second + leftdown_cross] == 2) break;
			chess[r][pos.second + leftdown_cross] = 1;
			leftdown_cross--;
		}
		//오른아래 대각
		int rightdown_cross = 1;
		for (int r = pos.first + 1; r <= row; r++) {
			if (pos.second + rightdown_cross > col)break;
			if (chess[r][pos.second + rightdown_cross] == 3 || chess[r][pos.second + rightdown_cross] == 2) break;
			chess[r][pos.second + rightdown_cross] = 1;
			rightdown_cross++;
		}
	}
}
void knightMoving() {
	for (int i = 0; i < knight.size(); i++) {
		int r = knight[i].first;
		int c = knight[i].second;
		//왼위
		if (r - 2 > 0 && c - 1 > 0) {
			chess[r - 2][c - 1] = 2;
		}
		if (r - 1 > 0 && c - 2 > 0) {
			chess[r - 1][c - 2] = 2;
		}
		//오위
		if (r - 2 > 0 && c + 1 <= col) {
			chess[r - 2][c + 1] = 2;
		}
		if (r - 1 > 0 && c + 2 <= col) {
			chess[r - 1][c + 2] = 2;
		}
		//왼아
		if (r + 1 <= row && c - 2 > 0) {
			chess[r + 1][c - 2] = 2;
		}
		if (r + 2 <= row && c - 1 > 0) {
			chess[r + 2][c - 1] = 2;
		}
		//오아
		if (r + 1 <= row && c + 2 <= col) {
			chess[r + 1][c + 2] = 2;
		}
		if (r + 2 <= row && c + 1 <= col) {
			chess[r + 2][c + 1] = 2;
		}
	}
}
