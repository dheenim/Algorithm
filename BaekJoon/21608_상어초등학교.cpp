#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, pair<int, int>> alloc;
vector<vector<int>> seat;
vector<vector<int>> likes;
vector<int> order;
int dirRow[4] = { -1,1,0,0 };//상하좌우
int dirCol[4] = { 0,0,-1,1 };
int N;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

bool cmp2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first) {
			return a.second.second < b.second.second;
		}
		return a.second.first < b.second.first;
	}
	return a.first > b.first;
}

bool posChk(int r, int c) {
	if (r<1 || c < 1 || r>N || c>N) return false;
	if (seat[r][c] != -1) return false;
	return true;
}

bool posPossi(int r, int c) {
	if (r<1 || c < 1 || r>N || c>N) return false;
	return true;
}

vector<pair<int,int>> step1(int stu) {
	vector<pair<int, int>> pos;
	map<pair<int, int>, int> cnt;
	for (int i = 0; i < 4; i++) {
		if (alloc.find(likes[stu][i]) != alloc.end()) {
			pair<int, int> pos = alloc[likes[stu][i]];
			for (int dir = 0; dir < 4; dir++) {
				if (posChk(pos.first + dirRow[dir], pos.second + dirCol[dir])) {
					cnt[{pos.first + dirRow[dir], pos.second + dirCol[dir]}]++;
				}
			}
		}
	}
	int maxCnt = -1;
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		if (it->second > maxCnt) maxCnt = it->second;
	}

	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		if (maxCnt == it->second) {
			pos.push_back(it->first);
		}
	}

	return pos;
}

vector<pair<int, int>> step2(vector<pair<int, int>> candi) {
	vector<pair<int, pair<int,int> > > newCandi;
	vector<pair<int, int>> cand;
	int maxEmpt = 0;
	if (candi.size() == 0) {
		//cout << "siz=0\n";
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				int cnt = 0;
				if (seat[r][c] != -1) continue;
				for (int dir = 0; dir < 4; dir++) {
					int newRow = r + dirRow[dir], newCol = c + dirCol[dir];
					if (posChk(newRow, newCol)) {
						cnt++;
					}
				}
				if (cnt >= maxEmpt && cnt >0) {
					maxEmpt = cnt;
					newCandi.push_back({ cnt,{r,c} });
				}
			}
		}
	}
	else {
		for (int i = 0; i < candi.size(); i++) {
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int newRow = candi[i].first + dirRow[dir], newCol = candi[i].second + dirCol[dir];
				if (posChk(newRow, newCol)) {
					cnt++;
				}
			}
			if (cnt >= maxEmpt) {
				maxEmpt = cnt;
				newCandi.push_back({ cnt, candi[i]});
			}
		}
	}
	sort(newCandi.begin(), newCandi.end(), cmp2);
	for (int i = 0; i < newCandi.size(); i++) {
		if (newCandi[i].first == maxEmpt) {
			cand.push_back(newCandi[i].second);
		}
	}

	return cand;
}

void allocSeat(int stu) {
	//1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
	vector<pair<int, int>> candidate = step1(stu);
	//cout << "\nstep1\n";
	if (candidate.size() == 1) {
		alloc[stu] = candidate[0];
		seat[candidate[0].first][candidate[0].second] = stu;
		//cout << candidate[0].first << "," << candidate[0].second << endl;
		return;
	}
	//cout << "\nstep2\n";
	//2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
	vector<pair<int, int>> candidate2 = step2(candidate);
	candidate.clear();
	if (candidate2.size() == 1) {
		alloc[stu] = candidate2[0];
		seat[candidate2[0].first][candidate2[0].second] = stu;
		//cout << candidate2[0].first << "," << candidate2[0].second << endl;
		return;
	}
	//cout << "\nstep3\n";
	//3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로,
	//그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
	if(candidate2.size() < 1 )
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (seat[r][c] == -1) {
					alloc[stu] = {r,c};
					seat[r][c] = stu;
					//cout << r << "," << c << endl;
					return;
				}
			}
		}
	sort(candidate2.begin(), candidate2.end(), cmp);
	alloc[stu] = candidate2[0];
	seat[candidate2[0].first][candidate2[0].second] = stu;
	//cout << candidate2[0].first << "," << candidate2[0].second << endl;
}

void getSatis() {
	//cout << "satis:";
	//학생의 만족도를 구하려면 그 학생과 인접한 칸에 앉은 좋아하는 학생의 수를 구해야 한다. 
	//그 값이 0이면 학생의 만족도는 0, 1이면 1, 2이면 10, 3이면 100, 4이면 1000이다.
	int satis = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nr = r + dirRow[dir], nc = c + dirCol[dir];
				if (posPossi(nr, nc)) {
					/*for (int lk = 0; lk < 4; lk++) {
						if (seat[nr][nc] == likes[seat[r][c]][lk]) cnt++;
					}*/
					
					if (find(likes[seat[r][c]].begin(), likes[seat[r][c]].end(), seat[nr][nc]) != likes[seat[r][c]].end()) {
						cnt++;
					}
				}
			}
			//cout << "\n"<<r<<","<<c<<endl;
			switch (cnt) {
				case 0 :
					break;
				case 1 :
					satis += 1;
					break;
				case 2 :
					satis += 10;
					break;
				case 3 :
					satis += 100;
					break;
				default :
					satis += 1000;
					break;
			}
			//cout << seat[r][c] << " ";
		}
		//cout << endl;
	}
	cout << satis << endl;
}

int main() {
	cin >> N;
	likes.resize(N*N+1, vector<int>(4, 0));
	seat.resize(N*N + 1, vector<int>(N + 1, -1));
	for (int i = 0; i < N * N; i++) {
		int student;
		cin >> student;
		order.push_back(student);
		for (int j = 0; j < 4; j++) {
			int lk;
			cin >> lk;
			likes[student][j] = lk;
		}
	}
	
	//alloc[order[0]] = { 2,2 };
	//seat[2][2] = order[0];

	for (int i = 0; i < N * N; i++) {
		//cout << order[i] << "@@@\n";
		allocSeat(order[i]);
	}

	getSatis();
}
