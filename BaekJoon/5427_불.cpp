#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int map[1001][1001];
pair<int, int> start;
int dirRow[4] = { -1,0,0,1 };
int dirCol[4] = { 0,-1,1,0 };
bool visit[1001][1001];

int main() {
	int tc, w, h;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cin >> w >> h;
		queue<pair<int, int>> qfire;
		for (int r = 1; r <= h; r++) {
			string str;
			cin >> str;
			for (int c = 0; c < w; c++) {
				if (str[c] == '.') {
					map[r][c + 1] = 1;
				}
				else if (str[c] == '*') {
					map[r][c + 1] = 4;
					qfire.push({ r,c + 1 });
				}
				else if (str[c] == '@') {
					map[r][c + 1] = 3;
					start.first = r;
					start.second = c + 1;
				}
				else
					map[r][c + 1] = 2;
			}
		}
		int ans = 99999999;
		int time = 0;
		queue<pair<int, int>> q;
		q.push(start);
		while (!q.empty()) {
			int qfiresize = qfire.size();
			for (int k = 0; k < qfiresize; k++) {
				pair<int, int> pos = qfire.front();
				qfire.pop();
				for (int ii = 0; ii < 4; ii++) {
					int nr = pos.first + dirRow[ii];
					int nc = pos.second + dirCol[ii];
					if (nr<1 || nc<1 || nr>h || nc>w) continue;
					if (map[nr][nc] == 1) {
						qfire.push({ nr,nc });
						map[nr][nc] = 4;
					}
				}
			}
			int qsize = q.size();
			bool flag = false;
			for (int k = 0; k < qsize; k++) {
				pair<int, int> pos = q.front();
				//cout << "cur:" << pos.first << "," << pos.second << endl;
				q.pop();
				if (pos.first == 1 || pos.second == 1 || pos.first == h || pos.second == w) {
					flag = true;
					ans = time + 1;
					break;
				}
				for (int ii = 0; ii < 4; ii++) {
					int nr = pos.first + dirRow[ii];
					int nc = pos.second + dirCol[ii];
					if (map[nr][nc] == 1 && (nr == 1 || nc == 1 || nr == h || nc == w)) {
						ans = time + 2;
						flag = true;
						break;
					}
					if (visit[nr][nc]) continue;
					if (map[nr][nc] == 1) {
						q.push({ nr,nc });
						visit[nr][nc] = true;
					}
				}
				if (flag) break;
			}
			time++;
			if (flag) break;
		}
		if (ans >= 99999999) cout << "IMPOSSIBLE\n";
		else cout << ans << endl;
		
	}
}