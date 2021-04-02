#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[9][9];
bool visit[9][9];
int dir_row[4] = { -1,1,0,0 };//À§ ¾Æ·¡ ¿Þ ¿À
int dir_col[4] = { 0,0,-1,1 };
vector<pair<int,int>> blank;
vector<pair<int, int>> wall;
vector<pair<int, int>> virus;
int ans = 0;

void bfs();

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			map[i + 1][j + 1] = tmp;
			if (tmp == 0) {
				blank.push_back({ i + 1,j + 1 });
			}
			else if (tmp == 1) {
				wall.push_back({ i + 1,j + 1 });
			}
			else {
				virus.push_back({ i + 1,j + 1 });
			}
		}
	}
	visit[1][1] = true;
	for (int i = 0; i < blank.size(); i++) {
		for (int j = i + 1; j < blank.size(); j++) {
			for (int k = j + 1; k < blank.size(); k++) {
				pair<int, int> one = blank[i];
				pair<int, int> two = blank[j];
				pair<int, int> three = blank[k];
				map[one.first][one.second] = 1;
				map[two.first][two.second] = 1;
				map[three.first][three.second] = 1;
				bfs();
				map[one.first][one.second] = 0;
				map[two.first][two.second] = 0;
				map[three.first][three.second] = 0;
			}
		}
	}
	cout << ans << endl;
}

void bfs() {
	memset(visit, 0, sizeof(visit));
	int vir = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		if (visit[virus[i].first][virus[i].second]) continue;
		q.push(virus[i]);
		visit[virus[i].first][virus[i].second] = true;
		vir++;
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int next_row = cur.first + dir_row[j];
				int next_col = cur.second + dir_col[j];
				if (next_row<1 || next_row>N || next_col<1 || next_col>M) {
					continue;
				}
				if (visit[next_row][next_col])continue;
				if (map[next_row][next_col]==1) continue;
				vir++;
				visit[next_row][next_col] = true;
				q.push({ next_row,next_col });
			}
		}
	}
	ans = ans > (N * M - wall.size()-3 - vir) ? ans : (N * M - wall.size()-3 - vir);
}