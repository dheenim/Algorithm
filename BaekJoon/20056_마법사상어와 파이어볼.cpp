#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
typedef struct Fireball {
	int dir;
	int mass;
	int speed;
};

int dirRow[8] = { -1, - 1,0,1,1,1,0, - 1 };
int dirCol[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<Fireball> map[51][51];
int N, startNum, Ksec;

void moveFb() {
	vector<Fireball> newMap[51][51];
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (map[r][c].size() == 0) continue;
			for (Fireball fb : map[r][c]) {
				int nr = r + dirRow[fb.dir]*fb.speed;
				nr = nr % N;
				if (nr < 0) nr = N + nr;
				int nc = c + dirCol[fb.dir]*fb.speed;
				nc = nc % N;
				if (nc < 0) nc = N + nc;
				newMap[nr][nc].push_back(fb);
			}
		}
	}
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			map[r][c].clear();
			map[r][c] = newMap[r][c];
			newMap[r][c].clear();
		}
	}
}

void divFb() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (map[r][c].size() < 2) continue;
			bool chkDir = true;
			int mass = 0, speed = 0, dir = map[r][c][0].dir % 2;
			int size = map[r][c].size();
			for (Fireball fb : map[r][c]) {
				mass += fb.mass;
				speed += fb.speed;
				if (fb.dir % 2 != dir) chkDir = false;
			}
			mass = mass / 5;
			speed = speed / size;
			map[r][c].clear();
			if (mass < 1) {
				continue;
			}
			Fireball fb;
			fb.mass = mass; fb.speed = speed;
			if (chkDir) {//dir->0,2,4,6
				for (int i = 0; i < 8; i += 2) {
					fb.dir = i;
					map[r][c].push_back(fb);
				}
			}
			else {//dir->1,3,5,7
				for (int i = 1; i < 8; i += 2) {
					fb.dir = i;
					map[r][c].push_back(fb);
				}
			}
		}
	}
}

int main() {
	cin >> N >> startNum >> Ksec;
	for (int i = 0; i < startNum; i++) {
		Fireball fb;
		int r, c;
		cin >> r >> c >> fb.mass >> fb.speed >> fb.dir;
		r--; c--;
		map[r][c].push_back(fb);
	}
	while (Ksec-- > 0) {
		moveFb();
		divFb();
	}
	int ans = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (map[r][c].size() == 0)continue;
			for (Fireball fb : map[r][c]) {
				ans += fb.mass;
			}
		}
	}
	cout << ans << endl;
}