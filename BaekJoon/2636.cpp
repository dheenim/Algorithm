#include<iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;
int row, col;
bool cheese[101][101];
//bool chk[101][101];
bool visit[101][101];
bool allFalse = false;
int cnt;

queue<pair<int,int>> q;

void bfs();
bool possiblePos(int r, int c);
void doQueue(int r, int c);

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
		bfs();
		ans++;
		cnts.push_back(cnt);
		//printf("@@@@@@@@@@@@@@@@22ans:%d, cnt:%d\n", ans, cnt);
	}
	cout << ans-1<< '\n' <<cnts[cnts.size()-2] << endl;
}
void bfs() {
	memset(visit, 0, sizeof(visit));
	q.push(make_pair(1, 1));
	visit[1][1] = true;
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();
		//printf("row:%d, col:%d\n", pos.first, pos.second);
		//위
		int r = pos.first - 1;
		int c = pos.second;
		doQueue(r, c);
		//아래
		r = pos.first + 1;
		c = pos.second;
		doQueue(r, c);
		//오른쪽
		r = pos.first;
		c = pos.second + 1;
		doQueue(r, c);
		//왼쪽
		r = pos.first;
		c = pos.second - 1;
		doQueue(r, c);
	}
}
bool possiblePos(int r, int c) {
	if (r<1 || r>row || c<1 || c>col) return false;
	return true;
}

void doQueue(int r, int c) {
	if (possiblePos(r, c) && !visit[r][c]) {
		visit[r][c] = true;
		if (cheese[r][c]) {
			cheese[r][c] = false;
			allFalse = false;
			cnt++;
		}
		else {
			q.push(make_pair(r, c));
		}
	}
	return;
}