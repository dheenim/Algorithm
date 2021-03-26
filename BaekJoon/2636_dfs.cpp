#include<iostream>
#include <cstring>
#include <vector>

using namespace std;
int row, col;
bool cheese[101][101];
bool visit[101][101];
bool allFalse = false;
int cnt;

void dfs(int r, int c);
bool possiblePos(int r, int c);
void doDFSCheck(int r, int c);

int main() {
	memset(cheese, 0, sizeof(cheese));
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			int tmp;
			cin >> tmp;
			if (tmp) cheese[i][j] = true;
			else cheese[i][j] = false;
		}
	}
	int ans = 0;
	vector<int> cnts;
	while (!allFalse) {
		cnt = 0;
		allFalse = true;
		memset(visit, false, sizeof(visit));
		visit[1][1] = true;
		dfs(1,1);
		ans++;
		cnts.push_back(cnt);
	}
	cout << ans - 1 << '\n' << cnts[cnts.size() - 2] << endl;
}
void dfs(int r_, int c_) {
	//위
	int r = r_- 1;
	int c = c_;
	doDFSCheck(r, c);
	//아래
	r = r_ + 1;
	c = c_;
	doDFSCheck(r, c);
	//오른쪽
	r = r_;
	c = c_ + 1;
	doDFSCheck(r, c);
	//왼쪽
	r = r_;
	c = c_ - 1;
	doDFSCheck(r, c);
}

bool possiblePos(int r, int c) {
	if (r<1 || r>row || c<1 || c>col) return false;
	return true;
}

void doDFSCheck(int r, int c) {
	if (possiblePos(r, c) && !visit[r][c]) {
		visit[r][c] = true;
		if (cheese[r][c]) {
			cheese[r][c] = false;
			allFalse = false;
			cnt++;
		}
		else {
			dfs(r, c);
		}
	}
	return;
}