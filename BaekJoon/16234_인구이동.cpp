#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dir_row[4] = { 0,0,1,-1 };//¿À ¿Þ ¾Æ À§
int dir_col[4] = { 1,-1,0,0 };
int N,L,R;
int A[51][51];
bool visit[51][51];
vector<pair<int,int>> pick;
int bfs(int startR, int startC);

int main() {
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	bool chk = true;
	int ans = 0;
	while (chk) {
		chk = false;
		memset(visit, 0, sizeof(visit));
		//cout << "-------------------------------------\n";
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visit[i][j]) continue;
				pick.clear();
				int sum = bfs(i, j);
				if (pick.size() <= 1) continue;
				int unionSize = pick.size();
				for (int k = 0; k < pick.size(); k++) {
					//cout << "pick " << pick[k].first << " " << pick[k].second << endl;
					A[pick[k].first][pick[k].second] = sum / unionSize;
				}
				chk = true;
			}
		}
		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << A[i][j] << " ";
			}
			cout << endl;
		}*/
		if (chk) ans++;
	}
	cout << ans << endl;
}

int bfs(int startR, int startC) {
	int sum = A[startR][startC];
	queue<pair<int, int>> q;
	q.push({ startR,startC });
	visit[startR][startC] = true;
	pick.push_back({ startR,startC });
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextR = cur.first + dir_row[i];
			int nextC = cur.second + dir_col[i];
			if (nextR > N || nextR < 1 || nextC < 1 || nextC > N) continue;
			if (visit[nextR][nextC]) continue;
			if (abs(A[cur.first][cur.second] - A[nextR][nextC]) >= L && abs(A[cur.first][cur.second] - A[nextR][nextC]) <= R) {
				q.push({ nextR,nextC });
				visit[nextR][nextC] = true;
				sum += A[nextR][nextC];
				pick.push_back({ nextR,nextC });
			}
		}
	}
	return sum;
}