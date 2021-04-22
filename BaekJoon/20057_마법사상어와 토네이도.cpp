#include <iostream>
#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

using namespace std;

int dir_row[4] = { 0,1,0,-1 };//왼 아 오 위
int dir_col[4] = { -1,0,1,0 };
int N;
int A[500][500];
int ans = 0;

void sandMove(int curR, int curC, int dir);
void windMove(int curR, int curC);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	windMove(N / 2 + 1, N / 2 + 1);
	cout << ans << endl;
}
void windMove(int curR, int curC) {
	int dir = 0;
	for (int i = 1; i < N; i++) {
		for (int k = 0; k < 2; k++) {
			for (int move = 0; move < i; move++) {
				curR += dir_row[dir];
				curC += dir_col[dir];
				sandMove(curR, curC, dir);
			}
			dir = (dir + 1) % 4;
		}
	}
	for (int move = 0; move < N; move++) {
		curR += dir_row[dir];
		curC += dir_col[dir];
		sandMove(curR, curC, dir);
	}
}
void sandMove(int curR, int curC, int dir) {
	int nextR, nextC;
	int sand = A[curR][curC];
	int sum = 0;
	int newSand = 0;
	//5%
	nextR = curR + dir_row[dir];
	nextC = curC + dir_col[dir];
	nextR = nextR + dir_row[dir];
	nextC = nextC + dir_col[dir];
	newSand = (int)((double)sand * 0.05);
	sum += newSand;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}


	//2%
	nextR = curR + dir_row[(dir + 1) % 4];
	nextC = curC + dir_col[(dir + 1) % 4];
	nextR += dir_row[(dir + 1) % 4];
	nextC += dir_col[(dir + 1) % 4];
	newSand = (int)((double)sand * 0.02);
	sum += newSand;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}
	//2% 반대쪽
	nextR = curR + dir_row[(dir + 3) % 4];
	nextC = curC + dir_col[(dir + 3) % 4];
	nextR += dir_row[(dir + 3) % 4];
	nextC += dir_col[(dir + 3) % 4];
	newSand = (int)((double)sand * 0.02);
	sum += newSand;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}


	//7%
	nextR = curR + dir_row[(dir + 1) % 4];
	nextC = curC + dir_col[(dir + 1) % 4];
	newSand = (int)((double)sand * 0.07);
	sum += newSand;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}
	//7% 반대쪽
	nextR = curR + dir_row[(dir + 3) % 4];
	nextC = curC + dir_col[(dir + 3) % 4];
	newSand = (int)((double)sand * 0.07);
	sum += newSand;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}


	//1%
	nextR = curR + dir_row[(dir + 2) % 4];
	nextC = curC + dir_col[(dir + 2) % 4];
	nextR += dir_row[(dir + 1) % 4];
	nextC += dir_col[(dir + 1) % 4];
	newSand = (int)((double)sand * 0.01);
	sum += newSand;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}
	//1% 반대쪽
	nextR = curR + dir_row[(dir + 2) % 4];
	nextC = curC + dir_col[(dir + 2) % 4];
	nextR += dir_row[(dir + 3) % 4];
	nextC += dir_col[(dir + 3) % 4];
	newSand = (int)((double)sand * 0.01);
	sum += newSand;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}


	//10%
	nextR = curR + dir_row[dir];
	nextC = curC + dir_col[dir];
	nextR += dir_row[(dir + 1) % 4];
	nextC += dir_col[(dir + 1) % 4];
	newSand = (int)((double)sand * 0.1);
	sum += newSand;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}
	//10% 반대쪽
	nextR = curR + dir_row[dir];
	nextC = curC + dir_col[dir];
	nextR += dir_row[(dir + 3) % 4];
	nextC += dir_col[(dir + 3) % 4];
	newSand = (int)((double)sand * 0.1);
	sum += newSand;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}


	//alpha
	A[curR][curC] = 0;
	nextR = curR + dir_row[dir];
	nextC = curC + dir_col[dir];
	newSand = sand - sum;
	if (nextR <= N && nextR >= 1 && nextC <= N && nextC >= 1) {
		A[nextR][nextC] += newSand;
	}
	else {
		ans += newSand;
	}
}
