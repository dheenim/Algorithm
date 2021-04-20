#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define INF 2100000000
using namespace std;
int dir_row[4] = { 0,0,1,-1 };//¿À ¿Þ ¾Æ À§
int dir_col[4] = { 1,-1,0,0 };
int N, M;
int map[51][51];
bool visit[51][51];
vector<pair<int,int>> virus;

int bfs(vector<pair<int, int>> pickVirus);

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
			if (tmp == 2) virus.push_back({ i,j });
		}
	}
	sort(virus.begin(), virus.end());
	vector<int> pick;
	for (int i = 0; i < M; i++) {
		pick.push_back(1);
	}
	for (int i = 0; i < virus.size() - M; i++) {
		pick.push_back(0);
	}
	sort(pick.begin(), pick.end());
	int ans = INF;
	do {
		//cout << "------------------------------\n";
		vector<pair<int, int>> picks;
		for (int i = 0; i < pick.size(); i++) {
			if (pick[i] == 1) {
				//cout << virus[i].first << " " << virus[i].second << endl;
				picks.push_back(virus[i]);
			}
		}
		//memset(visit, 0, sizeof(virus));
		int newAns = bfs(picks);
		if (newAns < ans) ans = newAns;
	} while (next_permutation(pick.begin(), pick.end()));
	if (ans >= INF) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}

int bfs(vector<pair<int, int>> pickVirus) {
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	for (int i = 0; i < pickVirus.size(); i++) {
		//cout << "pick " << pickVirus[i].first << " " << pickVirus[i].second << endl;
		q.push(pickVirus[i]);
		visit[pickVirus[i].first][pickVirus[i].second] = true;
	}
	int time = 0;
	int chk = 0;
	int onlytwo = 0;
	while (!q.empty()) {
		//bool chk = false;
		int qsize = q.size();
		//cout << "qsize:" << qsize << endl;
		for (int i = 0; i < qsize; i++) {
			pair<int, int> cur = q.front();
			//if (map[cur.first][cur.second] == 0) chk = true;
			//cout << "cur: " << cur.first << " " << cur.second << endl;
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nextR = cur.first + dir_row[d];
				int nextC = cur.second + dir_col[d];
				if (nextR<1 || nextR>N || nextC<1 || nextC>N)continue;
				if (visit[nextR][nextC] || map[nextR][nextC] == 1) continue;
				if (map[nextR][nextC] == 0) chk = 1;
				visit[nextR][nextC] = true;
				q.push({ nextR,nextC });
			}
		}
		if (chk == 1) {
			time += onlytwo + 1;
			onlytwo = 0;
			chk = 0;
		}
		else if(chk==0){
			onlytwo++;
		}

		//cout << "curTime:" << time << endl;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1)continue;
			if (!visit[i][j]) time = INF;
		}
	}
	//cout << time << endl;
	return time;
}