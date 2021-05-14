#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dir_row[4] = { 0,0,-1,1 };//¿Þ ¿À À§ ¾Æ·¡
int dir_col[4] = { -1,1,0,0 };
int row, col;
int arr[1001][1001];
bool visit[1001][1001];
vector<pair<int,int>> ones;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> col >> row;
	for (int i = 1; i <= row; i++) 
		for (int j = 1; j <= col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				ones.push_back({ i,j });
			}
		}
	if (ones.size() == 0) {
		cout << -1 << "\n";
		return 0;
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < ones.size(); i++) {
		q.push(ones[i]);
		visit[ones[i].first][ones[i].second] = true;
	}
	int ans = 0;
	while (!q.empty()) {
		ans++;
		int qsize = q.size();
		//cout << "qsize: " << qsize << endl;
		for (int i = 0; i < qsize; i++) {
			pair<int, int> cur = q.front();
			//cout << "cur: " << cur.first << "," << cur.second << endl;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				pair<int, int> next = { cur.first + dir_row[dir], cur.second + dir_col[dir] };
				if (next.first > row || next.first<1 || next.second>col || next.second < 1) continue;
				if (visit[next.first][next.second]) continue;
				if (arr[next.first][next.second] == -1 || arr[next.first][next.second] == 1) continue;
				visit[next.first][next.second] = true;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (!visit[i][j] && arr[i][j] == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans - 1 << endl;
}