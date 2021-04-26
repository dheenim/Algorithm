#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<string, int>> input;
int N, M;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		input.push_back({ s,i + 1 });
	}
	vector<pair<string,int>> ordered = input;
	sort(ordered.begin(), ordered.end());
	for (int i = 0; i < M; i++) {
		string q;
		cin >> q;
		int num = atoi(q.c_str());
		if (num == 0) {
			int low = 0;
			int high = N - 1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (q.compare(ordered[mid].first) == 0) {
					high = mid;
					break;
				}
				else if (q.compare(ordered[mid].first) < 0) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			cout << ordered[high].second << endl;
		}
		else {
			cout << input[num - 1].first << endl;
		}
	}
}