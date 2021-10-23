#include <iostream>
#include <vector>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<int> input(w);
	for (int i = 0; i < w; i++) {
		cin >> input[i];
	}
	int answer = 0;
	for (int i = 0; i <= h; i++) {
		int rain = 0;
		int left = -1;
		for (int j = 0; j < w; j++) {
			if (left == -1) {
				if (input[j] >= i) {
					left = j;
				}
				continue;
			}
			if (input[j] >= i) {
				rain = rain + (j - left - 1);
				left = j;
			}
		}
		cout << "rain:" << rain << "\n";
		answer += rain;
	}
	cout << answer;
}