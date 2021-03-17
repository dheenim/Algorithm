#include <cstdio>
#include <iostream>
using namespace std;

void solve();
void dfs(int usingPlayer);
void calcScore();

int N;
int arr[51][10];
int answer;
int order[10];
bool used[10];

int main() {
	answer = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
		}
	}

	solve();

	printf("%d\n", answer);
}

void solve() {
	for (int i = 1; i <= 9; i++) used[i] = false;
	order[4] = 1;
	used[4] = true;//1번 플레이어는 항상 4번타자
	dfs(2);
}

void dfs(int usingPlayer) {

	if (usingPlayer == 10) {
		calcScore();
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (used[i] == true) continue;//이미 검사중이면 pass
		order[i] = usingPlayer;
		used[i] = true;
		dfs(usingPlayer+1);
		used[i] = false;
	}
}

void calcScore() {
	
	int Score = 0;
	int j = 1;

	for (int i = 1; i <= N; i++) {
		bool state[4] = { false,false,false,false };//1,2,3루 상태
		int outCount = 0;
		bool fin = false;
		while (!fin) {
			if (j == 10) j = 1;
				if (outCount == 3) {
					fin = true;
					break;
				}
				int curScore = arr[i][order[j]];

				if (curScore == 0) {
					outCount++;
				}
				else if (curScore == 1) {
					if (state[3]) {//3루 있을 때
						Score++;
						state[3] = false;
					}
					if (state[2]) {//2루 있을 때 
						state[3] = true;
						state[2] = false;
					}
					if (state[1]) {//1루 있을 때
						state[1] = false;
						state[2] = true;
					}
					state[1] = true;
				}
				else if (curScore == 2) {
					if (state[3]) {//3루 있을 때
						Score++;
						state[3] = false;
					}
					if (state[2]) {//2루 있을 때
						Score++;
						state[2] = false;
					}
					if (state[1]) {//1루 있을 때
						state[1] = false;
						state[3] = true;
					}
					state[2] = true;
				}
				else if (curScore == 3) {
					if (state[3]) {//3루 있을 때
						Score++;
						state[3] = false;
					}
					if (state[2]) {//2루 있을 때
						Score++;
						state[2] = false;
					}
					if (state[1]) {//1루 있을 때
						Score++;
						state[1] = false;
					}
					state[3] = true;
				}
				else if (curScore == 4) {
					if (state[3]) {//3루 있을 때
						Score++;
						state[3] = false;
					}
					if (state[2]) {//2루 있을 때
						Score++;
						state[2] = false;
					}
					if (state[1]) {//1루 있을 때
						Score++;
						state[1] = false;
					}
					Score++;
				}
				j++;
		}
	}
	answer = answer < Score ? Score : answer;
}
