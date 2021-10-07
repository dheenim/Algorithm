#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
int N, K, L;
int curDir = 0;//0:오른쪽, 1:아래, 2:왼쪽, 3:위 =>D나오면 +1, L나오면 +3
int dirRow[4] = { 0,1,0,-1 };
int dirCol[4] = { 1,0,-1,0 };
int maps[101][101];
queue<pair<int, char>> dirInfo;
deque<pair<int, int>> snake;


bool chkRange(int r, int c) {
	if (r<1 || c<1 || r>N || c>N) return false;
	return true;
}
bool playing(int sec);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int r, c; cin >> r >> c;
		maps[r][c] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t; char dir;
		cin >> t >> dir;
		dirInfo.push({ t,dir });
	}
	maps[1][1] = 1;//시작
	int sec = 1;
	snake.push_front({ 1,1 });
	while (playing(sec)) {
		/*cout << sec << "\n";
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << maps[i][j] << " ";
			}
			cout << endl;
		}*/
		sec++;
	}
	cout << sec;
}
bool playing(int sec) {
	
	//cout << "curDir: " << curDir << endl;
	int nr = snake.front().first + dirRow[curDir];
	int nc = snake.front().second + dirCol[curDir];
	if (!chkRange(nr, nc)) {
		return false;
	}
	if (maps[nr][nc] == 1) return false;
	if (maps[nr][nc] == 0) {
		maps[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}
	maps[nr][nc] = 1;
	snake.push_front({ nr,nc });

	if (dirInfo.front().first == sec) {
		if (dirInfo.front().second == 'D') {
			curDir = (curDir + 1) % 4;
		}
		else {
			curDir = (curDir + 3) % 4;
		}
		dirInfo.pop();
	}

	return true;
}