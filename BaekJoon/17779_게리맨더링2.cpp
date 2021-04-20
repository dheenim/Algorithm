#include <iostream>
#include <vector>
#define INF 2100000000
using namespace std;
int N;
int A[21][21];
int ans = INF;
void pickNums();
void divide(int x, int y, int d1, int d2);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	pickNums();
	cout << ans << endl;
}
void pickNums() {
	//(d1, d2 ≥ 1, 1 ≤ x < x + d1 + d2 ≤ N, 1 ≤ y - d1 < y < y + d2 ≤ N)
	int d1, d2, x, y;
	for (d1 = 1; d1 <= N - 3; d1++) {
		for (d2 = 1; d2 <= N - 3; d2++) {
			for (x = 1; x <= N - d1 - d2; x++) {
				for (y = 1 + d1; y <= N - d2; y++) {
					divide(x, y, d1, d2);
				}
			}
		}
	}
}
void divide(int x, int y, int d1, int d2) {
	//cout << "x:" << x << " y:" << y << " d1:" << d1 << " d2:" << d2 << endl;
	bool map[21][21] = { {false, }, };
	int dist[21][21] = { {0,}, };
	int district[6] = { 0, };
	int max_ = 0, min_ = INF;


	//1번 선거구 : 1 ≤ r < x + d1, 1 ≤ c ≤ y
	for (int r = 1; r < x + d1; r++) {
		for (int c = 1; c <= y; c++) {
			//district[1] += A[r][c];
			map[r][c] = true;
			dist[r][c] = 1;
		}
	}

	//2번 선거구 : 1 ≤ r ≤ x + d2, y < c ≤ N
	for (int r = 1; r <= x + d2; r++) {
		for (int c = y + 1; c <= N; c++) {
			//district[2] += A[r][c];
			map[r][c] = true;
			dist[r][c] = 2;
		}
	}

	//3번 선거구 : x + d1 ≤ r ≤ N, 1 ≤ c < y - d1 + d2
	for (int r = x + d1; r <= N; r++) {
		for (int c = 1; c < y - d1 + d2; c++) {
			//district[3] += A[r][c];
			map[r][c] = true;
			dist[r][c] = 3;
		}
	}

	//4번 선거구 : x + d2 < r ≤ N, y - d1 + d2 ≤ c ≤ N
	for (int r = x + d2 + 1; r <= N; r++) {
		for (int c = y - d1 + d2; c <= N; c++) {
			//district[4] += A[r][c];
			map[r][c] = true;
			dist[r][c] = 4;
		}
	}

	//경계선 1. (x, y), (x + 1, y - 1), ..., (x + d1, y - d1)
	//경계선 4. (x + d2, y + d2), (x + d2 + 1, y + d2 - 1), ..., (x + d2 + d1, y + d2 - d1)
	for (int i = 0; i <= d1; i++) {
		map[x + i][y - i] = true;
		map[x + d2 + i][y + d2 - i] = true;
		dist[x + i][y - i] = 6;
		dist[x + d2 + i][y + d2 - i] = 6;
	}
	//경계선 2. (x, y), (x + 1, y + 1), ..., (x + d2, y + d2)
	//경계선 3. (x + d1, y - d1), (x + d1 + 1, y - d1 + 1), ... (x + d1 + d2, y - d1 + d2)
	for (int i = 1; i <= d2; i++) {
		map[x + i][y + i] = true;
		map[x + d1 + i][y - d1 + i] = true;
		dist[x + i][y + i] = 6;
		dist[x + d1 + i][y - d1 + i] = 6;
	}
	for (int r = x + 1; r < x + d1 + d2; r++) {
		bool findbound = false;
		for (int c = 1; c <= N; c++) {
			if (!findbound && dist[r][c] == 6) {
				findbound = true;
				continue;
			}
			if (dist[r][c] == 6) break;
			if (!findbound) continue;
			dist[r][c] = 5;
		}
	}
	/*cout << "distMap-----------------------------\n";
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << dist[r][c] << " ";
		}
		cout << endl;
	}*/
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (dist[r][c] == 6) {
				district[5] += A[r][c];
			}
			else district[dist[r][c]] += A[r][c];
		}
	}
	for (int i = 1; i <= 5; i++) {
		//cout << "district " << i << ":" << district[i] << endl;
		if (max_ < district[i]) max_ = district[i];
		if (min_ > district[i]) min_ = district[i];
	}
	//cout << "max-min:" << max_ - min_ << endl;
	if (ans > max_ - min_) ans = max_ - min_;
	return;
}