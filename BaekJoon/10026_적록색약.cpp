#include <iostream>
using namespace std;
int N, norm, handi;
char map[101][101];
bool visit[101][101];
bool visit_handi[101][101];
int dir_row[4] = { -1,1,0,0 };//À§ ¾Æ ¿Þ ¿À
int dir_col[4] = { 0,0,-1,1 };
void dfs_norm(int r, int c);
void dfs_handi(int r, int c);
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string input; cin >> input;
		for (int k = 0; k < N; k++) {
			map[i][k+1] = input[k];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//if (visit[i][j] && visit_handi[i][j]) continue;
			if (!visit[i][j]) {
				dfs_norm(i, j);
				norm++;
			}
			if (!visit_handi[i][j]) {
				dfs_handi(i, j);
				handi++;
			}
		}
	}
	cout << norm << " " << handi;
}
void dfs_norm(int r, int c) {
	cout << r << ", " << c << endl;
	visit[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int n_row = r + dir_row[i];
		int n_col = c + dir_col[i];
		if (n_row > N || n_row<1 || n_col>N || n_col < 1) continue;
		if (visit[n_row][n_col]) continue;
		if(map[r][c] == map[n_row][n_col])
			dfs_norm(n_row, n_col);
	}
}
void dfs_handi(int r, int c) {
	visit_handi[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int n_row = r + dir_row[i];
		int n_col = c + dir_col[i];
		if (n_row > N || n_row<1 || n_col>N || n_col < 1) continue;
		if (visit_handi[n_row][n_col]) continue;
		if (map[r][c] == map[n_row][n_col] || (map[r][c] == 'R' && map[n_row][n_col] == 'G') || (map[r][c] == 'G' && map[n_row][n_col] == 'R'))
			dfs_handi(n_row, n_col);
	}
}