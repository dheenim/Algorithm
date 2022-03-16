#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, h;
int ans = 2000000000;
bool cross[31][11];
bool chkPossi() {
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int r = 1; r <= h; r++) {
			if (cross[r][cur]) cur++;//오른쪽으로
			else if (cross[r][cur - 1]) cur--;//왼쪽으로
		}
		if (cur != i) return false;
	}
	return true;
}

void dfs(int height, int cnt) {
	if (cnt > 3) {
		return;
	}
	if (chkPossi()) {
		if (ans > cnt) ans = cnt;
		return;
	}
	for (int r = 1; r <= h; r++) {
		for (int c = 1; c <= n; c++) {
			if (cross[r][c]) continue;
			if (cross[r][c-1]) continue;
			if (cross[r][c + 1]) continue;
			cross[r][c] = true;
			dfs(r, cnt + 1);
			cross[r][c] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cross[a][b] = true;
	}
	dfs(1,0);
	if (ans > 3 || ans > 2000000000) cout << -1;
	else cout << ans << endl;
}