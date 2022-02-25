#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int map[9][9];
bool chkmap[9][9];
int answer;
int cctvNum;
vector<pair<int, pair<int,int>>> cctvPos;
void dfs(int depth);

int main() {
	cin >> N >> M;
	answer = N * M;

	memset(chkmap, false, sizeof(chkmap));
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
			if (input == 0) continue;
			chkmap[i][j] = true;
			if (input != 6) {
				cctvPos.push_back({ input, { i,j } });
			}
		}
	}
	cctvNum = cctvPos.size();
	if (cctvNum == 0) {
		answer = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!chkmap[i][j]) answer++;
			}
		}
		cout << answer;
		return 0;
	}
	dfs(0);
	cout << answer;
}
void dfs(int depth) {
	/*cout << "d:" << depth << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << chkmap[i][j] << " ";
		}
		cout << endl;
	}*/
	if (depth >= cctvNum) {
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!chkmap[i][j]) ans++;
			}
		}
		if (answer > ans) answer = ans;
		//cout << answer << ", " << ans << endl;
		return;
	}
	queue<pair<int, int>> q;
	int row, col;
	switch (cctvPos[depth].first) {
	case 1:
		//위
		row = cctvPos[depth].second.first;
		while (--row > 0) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		dfs(depth + 1);
		while(!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}
		
		//아래
		row = cctvPos[depth].second.first;
		while (++row <= N) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}

		//왼쪽
		col = cctvPos[depth].second.second;
		while (--col > 0) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}

		//오른쪽
		col = cctvPos[depth].second.second;
		while (++col <= M) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}
		break;

	case 2:
		//위아래
		//위
		row = cctvPos[depth].second.first;
		while (--row > 0) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//아래
		row = cctvPos[depth].second.first;
		while (++row <= N) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}

		//좌우
		//좌
		col = cctvPos[depth].second.second;
		while (--col > 0) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		//우
		col = cctvPos[depth].second.second;
		while (++col <= M) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}
		break;

	case 3:
		//위 오
		//위
		row = cctvPos[depth].second.first;
		while (--row > 0) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//오
		col = cctvPos[depth].second.second;
		while (++col <= M) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}

		//위 왼
		//위
		row = cctvPos[depth].second.first;
		while (--row > 0) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//왼
		col = cctvPos[depth].second.second;
		while (--col > 0) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}

		//아래 왼
		//아래
		row = cctvPos[depth].second.first;
		while (++row <= N) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//왼
		col = cctvPos[depth].second.second;
		while (--col > 0) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}

		//아래 오
		//아래
		row = cctvPos[depth].second.first;
		while (++row <= N) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//오
		col = cctvPos[depth].second.second;
		while (++col <= M) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}
		break;

	case 4:
		//위오왼
		//위
		row = cctvPos[depth].second.first;
		while (--row > 0) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//오
		col = cctvPos[depth].second.second;
		while (++col <= M) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		//왼
		col = cctvPos[depth].second.second;
		while (--col > 0) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}
		//위왼아
		//위
		row = cctvPos[depth].second.first;
		while (--row > 0) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//아
		row = cctvPos[depth].second.first;
		while (++row <= N) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//왼
		col = cctvPos[depth].second.second;
		while (--col > 0) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}
		//위오아
		//위
		row = cctvPos[depth].second.first;
		while (--row > 0) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//아
		row = cctvPos[depth].second.first;
		while (++row <= N) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//오
		col = cctvPos[depth].second.second;
		while (++col <= M) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}
		//아왼오
		//아
		row = cctvPos[depth].second.first;
		while (++row <= N) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//왼
		col = cctvPos[depth].second.second;
		while (--col > 0) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		//오
		col = cctvPos[depth].second.second;
		while (++col <= M) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}
		break;

	default:
		//위오왼아
		//위
		row = cctvPos[depth].second.first;
		while (--row > 0) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		//오
		col = cctvPos[depth].second.second;
		while (++col <= M) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		//왼
		col = cctvPos[depth].second.second;
		while (--col > 0) {
			if (map[cctvPos[depth].second.first][col] == 6) break;
			if (chkmap[cctvPos[depth].second.first][col]) continue;
			chkmap[cctvPos[depth].second.first][col] = true;
			q.push({ cctvPos[depth].second.first, col });
		}
		//아
		row = cctvPos[depth].second.first;
		while (++row <= N) {
			if (map[row][cctvPos[depth].second.second] == 6) break;
			if (chkmap[row][cctvPos[depth].second.second]) continue;

			chkmap[row][cctvPos[depth].second.second] = true;
			q.push({ row,cctvPos[depth].second.second });
		}
		dfs(depth + 1);
		while (!q.empty()) {
			chkmap[q.front().first][q.front().second] = false;
			q.pop();
		}
		break;
	}
	return;
}
