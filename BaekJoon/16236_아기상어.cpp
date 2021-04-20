#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

class cmp {
public:
	bool operator()(pair<pair<int,int>, pair<int, int>> pq1, pair<pair<int,int>, pair<int, int>> pq2) {
		if (pq1.first.second == pq2.first.second) {
			if (pq1.second.first == pq2.second.first) {
				return pq1.second.second > pq2.second.second;
			}
			else return pq1.second.first > pq2.second.first;
		}
		else {
			return pq1.first.second > pq2.first.second;
		}
	}
};

int dir_row[4] = { -1,0,0,1 };//À§,¿Þ,¿À,¾Æ·¡
int dir_col[4] = { 0,-1,1, 0 };
int n;
vector<pair<int,int>> fish[7];
int map[21][21];
bool visit[21][21];
int start_r, start_c;
int ans = 0;
void findFish(int cur_r, int cur_c, int sharkSize, int eat);
bool callMother = false;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			map[i][j] = num;
			if (num >= 1 && num <= 6) {
				fish[num].push_back({ i,j });
			}
			if (num == 9) {
				map[i][j] = 0;
				start_r = i; start_c = j;
			}
		}
	}
	findFish(start_r, start_c, 2, 0);
}
void findFish(int cur_r, int cur_c, int cur_size, int eat) {
	//cout << "startR:" << cur_r << "  startC:" << cur_c << " size:" << cur_size << " eat:" << eat << endl;
	memset(visit, 0, sizeof(visit));
	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {cur_r,cur_c},{cur_size,eat} });
	visit[cur_r][cur_c] = true;
	int dist = 0;
	bool find = false;
	priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>, pair<int, int>>>, cmp> pq;
	while (!q.empty()) {
		int q_size = q.size();
		//cout << "qsize:" << q_size << endl;
		//cout << "dist:" << dist << "@@@@@@@@@@@@\n";
		for (int cap = 0; cap < q_size; cap++) {
			//cout << "cap:" << cap << endl;
			pair<pair<int, int>, pair<int, int>> cur = q.front();
			//cout << "curR:" << cur.first.first << " curC:" << cur.first.second << endl;
			q.pop();
			if (map[cur.first.first][cur.first.second] != 0) {
				bool chk = false;
				for (int i = 1; i <= cur_size - 1; i++) {
					if (fish[i].size() != 0) {


						for (auto it = fish[i].begin(); it != fish[i].end(); it++) {
							//cout << "finding, *it.first: " << (*it).first << " second : " << (*it).second << endl;
							if ((*it).first == cur.first.first && (*it).second == cur.first.second) {
								//cout << "find@@@@@@@@@@@@@@@@@@@@\n";
								pq.push({ {i, dist}, {cur.first.first, cur.first.second} });
								find = true;
								chk = true;
								break;
							}
						}
					}
					if (chk) break;
				}
			}
			if (!find) {
				for (int i = 0; i < 4; i++) {
					int next_row = cur.first.first + dir_row[i];
					int next_col = cur.first.second + dir_col[i];
					//cout << "next_r:" << next_row << " next_col:" << next_col << endl;
					if (next_row > n || next_row < 1 || next_col < 1 || next_col > n) continue;
					if (visit[next_row][next_col]) continue;
					if (map[next_row][next_col] > cur.second.first) continue;
					visit[next_row][next_col] = true;
					q.push({ { next_row,next_col }, { cur.second.first,cur.second.second } });
				}
			}
		}
		dist++;
	}
	if (!pq.empty()) {
		eat++;
		if (eat == cur_size) {
			eat = 0;
			cur_size++;
		}
		ans += pq.top().first.second;
		//cout << "ans:" << ans << endl;
		//cout << "pq :" << pq.top().second.first << ", " << pq.top().second.second << endl;
		pair<int, int> tt = pq.top().second;
		for (auto it = fish[pq.top().first.first].begin(); it != fish[pq.top().first.first].end(); it++) {
			if (tt.first == (*it).first && tt.second == (*it).second) {
				fish[pq.top().first.first].erase(it);
				break;
			}
		}
		map[pq.top().second.first][pq.top().second.second] = 0;
		findFish(pq.top().second.first, pq.top().second.second, cur_size, eat);
		return;
	}
	else cout << ans << endl;
}