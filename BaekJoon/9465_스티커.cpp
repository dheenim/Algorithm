#include <iostream>
#include <vector>
#define MAX(a,b) ((a)>(b))?(a):(b)
using namespace std;

int tc;
int n;
vector<int> score[2];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				int num; cin >> num;
				score[j].push_back(num);
			}
		}
		if (n == 1) {
			int ans = MAX(score[0][0], score[1][0]);
			cout << ans << endl;
		}
		else if (n == 2) {
			int ans = MAX(score[0][0] + score[1][1], score[1][0] + score[0][1]);
			cout << ans << endl;
		}
		else {
			score[0][1] += score[1][0]; score[1][1] += score[0][0];
			for (int col = 2; col < n; col++) {
				int upMax = MAX(score[1][col - 2], score[1][col - 1]);
				int downMax = MAX(score[0][col - 2], score[0][col - 1]);
				//cout << "col:" << col << " " << upMax << ", " << downMax << endl;
				score[0][col] = score[0][col] + upMax;
				score[1][col] = score[1][col] + downMax;
			}
			int ans = MAX(score[0][n - 1], score[1][n - 1]);
			cout << ans << endl;
		}
		score[0].clear(); score[1].clear();
	}
}