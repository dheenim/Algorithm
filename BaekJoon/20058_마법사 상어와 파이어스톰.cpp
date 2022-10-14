#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N, Q;
vector<vector<int>> ices;


int dirRow[4] = { -1,1,0,0 };//상하좌우
int dirCol[4] = { 0,0,-1,1 };

void rotate90(int startR, int startC, int L) {
	vector<vector<int>> tmp(L, vector<int>(L));
	for (int r = 0; r < L; r++) {
		for (int c = 0; c < L; c++) {
			tmp[c][L - r - 1] = ices[startR + r][startC + c];
		}
	}
	for (int r = 0; r < L; r++) {
		for (int c = 0; c < L; c++) {
			ices[startR + r][startC + c] = tmp[r][c];
		}
	}
}

void melt() {
	vector<vector<int>> tmp(N + 1, vector<int>(N + 1));
	//vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
	copy(ices.begin(), ices.end(), tmp.begin());
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (ices[r][c] == 0) continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nr = r + dirRow[dir];
				int nc = c + dirCol[dir];
				if (nr<1 || nr>N || nc<1 || nc>N) continue;
				if (ices[nr][nc] > 0) cnt++;
			}
			if (cnt < 3) {
				tmp[r][c]--;
			}
		}
	}
	copy(tmp.begin(), tmp.end(), ices.begin());
	tmp.clear();
}

void answer() {
	int sum = 0;
	int biggest = 0;
	vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (ices[r][c] == 0) continue;
			sum += ices[r][c];
			if (visit[r][c]) continue;
			int cnt = 0;
			queue<pair<int, int>> q;
			q.push({ r,c });
			cnt++; visit[r][c] = true;
			while (!q.empty()) {
				pair<int, int> pos = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int nr = pos.first + dirRow[i];
					int nc = pos.second + dirCol[i];
					if (nr<1 || nr>N || nc<1 || nc>N) continue;
					if (visit[nr][nc] || ices[nr][nc] == 0) continue;
					q.push({ nr,nc });
					cnt++;
					visit[nr][nc] = true;
				}
			}
			if (cnt > biggest) biggest = cnt;
		}
	}
	cout << sum << "\n" << biggest;
}

void fireStorm(int L) {
	L = (int)pow(2, L);
	for (int r = 1; r <= N; r += L) {
		for (int c = 1; c <= N; c += L) {
			rotate90(r, c, L);
		}
	}

	melt();
}

int main() {
	cin >> N >> Q;
	N = (int)pow(2, N);
	ices.resize(N + 1, vector<int>(N + 1));
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> ices[r][c];
		}
	}
	queue<int> spell;
	for (int i = 0; i < Q; i++) {
		int spl; cin >> spl;
		spell.push(spl);
	}

	while (!spell.empty()) {
		fireStorm(spell.front());
		spell.pop();
	}
	answer();
}
