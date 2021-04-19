#include <iostream>
#include <deque>
#include <cstring>
#include <cmath>
using namespace std;

int k;
deque<bool> dq[4];
bool visit[4];
void rotation(int num, int direction);
void rot(int num, int dir);
int main() {
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '1') {
				dq[i].push_back(true);
			}
			else {
				dq[i].push_back(false);
			}
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num, dir_;
		cin >> num >> dir_;
		memset(visit, 0, sizeof(visit));
		visit[num-1] = true;
		rotation(num-1, dir_);
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (dq[i].front()) ans += pow(2, i);
	}
	cout << ans << endl;
}
void rot(int num, int dir) {
	if (dir == 1) {//시계
		dq[num].push_front(dq[num].back());
		dq[num].pop_back();
	}
	else {//반시계
		dq[num].push_back(dq[num].front());
		dq[num].pop_front();
	}
}
void rotation(int num, int direction) {
	if (num == 0) {
		if (!visit[num + 1] && dq[num][2] != dq[num + 1][6]) {
			visit[num + 1] = true;
			rotation(num + 1, -direction);
		}
	}
	else if (num == 3) {
		if (!visit[num - 1] && dq[num][6] != dq[num - 1][2]) {
			visit[num - 1] = true;
			rotation(num - 1, -direction);
		}
	}
	else {
		if (!visit[num - 1] || !visit[num + 1]) {
			if (!visit[num - 1] && dq[num][6] != dq[num - 1][2]) {
				visit[num - 1] = true;
				rotation(num - 1, -direction);
			}
			if (!visit[num + 1] && dq[num][2] != dq[num + 1][6]) {
				visit[num + 1] = true;
				rotation(num + 1, -direction);
			}
		}
	}
	
	rot(num, direction);
}