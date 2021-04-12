#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<char> input[51];
int ans = 0;
vector<char> alphabet;
vector<int> comb;
vector<char> selected;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 4; j <= str.length()-5; j++) {
			if (str[j]=='a' || str[j] == 'n' || str[j] == 't' || str[j] == 'i' || str[j] == 'c') continue;
			input[i].push_back(str[j]);
		}
	}
	for (char i = 'b'; i <= 'z'; i++) {
		if (i == 'n' || i == 't' || i == 'i' || i == 'c') continue;
		alphabet.push_back(i);
	}
	if (M - 5 < 0) {
		cout << ans << endl;
		return 0;
	}
	//21Cm-5 구하기
	for (int i = 0; i < M - 5; i++) {
		comb.push_back(1);
	}
	for (int i = 0; i < alphabet.size() - (M - 5); i++) {
		comb.push_back(0);
	}
	sort(comb.begin(), comb.end());
	sort(alphabet.begin(), alphabet.end());
	do {
		selected.clear();
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i] == 1) {
				selected.push_back(alphabet[i]);
			}
		}
		//21개중 M-5개 뽑음
		int newAns = 0;
		for (int i = 0; i < N; i++) {
			bool chkPos = true;
			for (int j = 0; j < input[i].size(); j++) {
				if (find(selected.begin(), selected.end(), input[i][j]) == selected.end()) {
					chkPos = false;
					break;
				}
			}
			if (chkPos) newAns++;
		}
		ans = max(newAns, ans);
	} while (next_permutation(comb.begin(), comb.end()));
	cout << ans << endl;
}