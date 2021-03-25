#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<string> listen;
vector<string> see;
vector<string> ans;
int cnt = 0;
int main() {
	cin >> N >> M;
	string word;
	for (int i = 0; i < N; i++) {
		cin >> word;
		listen.push_back(word);
	}
	for (int i = 0; i < M; i++) {
		cin >> word;
		see.push_back(word);
	}
	sort(listen.begin(), listen.end());

	for (int i = 0; i < M; i++) {
		int low = 0;
		int high = N - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			//cout << listen[mid] << ' ' << see[i] << endl;
			if (see[i].compare(listen[mid]) == 0) {
				cnt++;
				ans.push_back(see[i]);
				break;
			}
			else if (see[i].compare(listen[mid]) > 0) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
	}
	cout << cnt << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}