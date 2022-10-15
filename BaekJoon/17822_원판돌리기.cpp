#include <iostream>
#include <vector>
#include <queue>
#define EMPT 0
using namespace std;

int N, M, T;
vector<deque<int>> circle;
//deque<int> circle[51];
vector<pair<int, pair<int, int>>> rot;

void rotate(int x, int d, int k) {
	//cout << "rotate!\n";
	int p = 1;
	int cnt = k;
	if (d == 0) {//시계방향
		while (x * p <= N) {
			while (cnt-- > 0) {
				circle[x * p].push_front(circle[x * p].back());
				circle[x * p].pop_back();
			}
			p++;
			cnt = k;
		}
	}
	else {//반시계방향
		while (x * p <= N) {
			while (cnt-- > 0) {
				circle[x * p].push_back(circle[x * p].front());
				circle[x * p].pop_front();
			}
			p++;
			cnt = k;
		}
	}
	/*for (int r = 1; r <= N; r++) {
		for (int c = 0; c < M; c++) {
			cout << circle[r][c] << " ";
		}
		cout << endl;
	}*/
}

void erase2() {
	//평균 구하기
	int cnt = 0, sum = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 0; c < M; c++) {
			if (circle[r][c] != EMPT) {
				cnt++;
				sum += circle[r][c];
			}
		}
	}
	double avg = (double)sum / (double)cnt;
	//cout << "sum:" << sum << " cnt:" << cnt << " avg:" << avg << endl;
	for (int r = 1; r <= N; r++) {
		for (int c = 0; c < M; c++) {
			if (circle[r][c] == EMPT) continue;
			if (circle[r][c] > avg) circle[r][c]--;
			else if (circle[r][c] < avg) circle[r][c]++;
		}
	}
}

void erase() {
	//cout << "erase\n";
	vector<vector<bool>> visit(N + 1, vector<bool>(M, false));
	int dirRow[4] = { -1,1,0,0 };//상하좌우
	int dirCol[4] = { 0,0,-1,1 };
	bool sameNum = false;
	for (int r = 1; r <= N; r++) {
		for (int c = 0; c < M; c++) {
			if (visit[r][c] || circle[r][c] == EMPT) continue;
			int searchNum = circle[r][c];
			//cout << "r:" << r << " c:" << c << " search:" << searchNum << endl;
			queue<pair<int,int>> q;
			q.push({ r,c }); visit[r][c] = true;
			//circle[r][c] = EMPT;
			bool same = false;
			while (!q.empty()) {
				pair<int, int> pos = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nr = pos.first + dirRow[dir];
					int nc = pos.second + dirCol[dir];
					if (nr<1 || nr > N) continue;
					if (nc == -1) nc = M - 1;
					else if (nc == M) nc = 0;
					if (visit[nr][nc] || circle[nr][nc] == EMPT) continue;
					if (circle[nr][nc] != searchNum) continue;
					q.push({ nr,nc }); visit[nr][nc] = true;
					circle[nr][nc] = EMPT;
					sameNum = true;
					same = true;
					//cout << "nr:" << nr << " nc:" << nc << endl;
				}
			}
			if (same) circle[r][c] = EMPT;
		}
	}

	if (!sameNum) {
		//cout << "no same\n";
		erase2();
	}
	/*for (int r = 1; r <= N; r++) {
		for (int c = 0; c < M; c++) {
			cout << circle[r][c] << " ";
		}
		cout << endl;
	}*/
	return;
}

int main() {
	cin >> N >> M >> T;
	circle.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			circle[i].push_back(num);
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		rot.push_back({ x,{d,k} });
	}
	
	for (int i = 0; i < T; i++) {
		//cout << "rotate " << i << endl;
		rotate(rot[i].first, rot[i].second.first, rot[i].second.second);
		erase();

	}
	int ans = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 0; c < M; c++) {
			ans += circle[r][c];
		}
	}
	cout << ans;
	return 0;
}
