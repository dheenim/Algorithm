#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int N;
int dir_row[4] = { 0,-1,0,1 };//xÁÂÇ¥ Áõ°¡, yÁÂÇ¥ °¨¼Ò,xÁÂÇ¥ °¨¼Ò, yÁÂÇ¥ Áõ°¡
int dir_col[4] = { 1,0,-1,0 };
bool visit[101][101];
int ans = 0;
vector<int> path;

void curve(int col, int row, int dir, int g);

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c, r, d, g;
		cin >> c >> r >> d >> g;
		curve(c, r, d, g);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (visit[i][j] && visit[i + 1][j] && visit[i][j + 1] && visit[i + 1][j + 1])
				ans++;
		}
	}
	cout << ans << endl;
}
void curve(int col, int row, int dir, int g) {
	path.clear();
	if (row <= 100 && row >= 0 && col <= 100 && col >= 0)
		visit[row][col] = true;
	//printf("row:%d col:%d\n", row, col);
	path.push_back((dir + 1) % 4);
	row += dir_row[dir];
	col += dir_col[dir];
	if (row <= 100 && row >= 0 && col <= 100 && col >= 0)
		visit[row][col] = true;
	//printf("row:%d col:%d\n", row, col);
	for (int i = 0; i < g; i++) {
		int path_size = path.size();
		for (int j = path_size - 1; j >= 0; j--) {
			row += dir_row[path[j]];
			col += dir_col[path[j]];
			//printf("row:%d col:%d\n", row, col);
			if (row <= 100 && row >= 0 && col <= 100 && col >= 0)
				visit[row][col] = true;
			path.push_back((path[j] + 1) % 4);
		}
	}
}