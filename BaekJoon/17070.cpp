#include <iostream>
#include <utility>
#define HORIZONTAL 1
#define VERTICAL 2
#define DIAGONAL 3
using namespace std;

int map[17][17];
int N;
int ans = 0;

void dfs(pair<int, int> left, pair<int, int> right);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	dfs({ 1,1 }, { 1,2 });
	cout << ans << endl;
}
void dfs(pair<int, int> left, pair<int, int> right) {
	if (right.first == N && right.second == N) {
		ans++;
		return;
	}
	int curState = (right.first - left.first) * 2 + (right.second - left.second);

	switch (curState) {
	case HORIZONTAL://가로 형태
		if (right.second + 1 <= N && !map[right.first][right.second + 1]) {
			dfs(right, { right.first,right.second + 1 });
		}
		if (right.second + 1 <= N && right.first + 1 <= N && !map[right.first + 1][right.second + 1] && !map[right.first+1][right.second] && !map[right.first][right.second+1]) {
			dfs(right, { right.first + 1,right.second + 1 });
		}
		break;
	case VERTICAL://세로 형태
		if (right.first + 1 <= N && !map[right.first + 1][right.second]) {
			dfs(right, { right.first + 1,right.second });
		}
		if (right.first + 1 <= N && right.second + 1 <= N && !map[right.first + 1][right.second + 1] && !map[right.first+1][right.second] && !map[right.first][right.second+1]) {
			dfs(right, { right.first + 1,right.second + 1 });
		}
		break;
	default://대각선 형태
		if (right.second + 1 <= N && !map[right.first][right.second + 1]) {
			dfs(right, { right.first, right.second + 1 });
		}
		if (right.first + 1 <= N && !map[right.first + 1][right.second]) {
			dfs(right, { right.first + 1,right.second });
		}
		if (right.first + 1 <= N && right.second + 1 <= N && !map[right.first][right.second + 1] && !map[right.first + 1][right.second] && !map[right.first + 1][right.second + 1]) {
			dfs(right, { right.first + 1,right.second + 1 });
		}
		break;
	}
}