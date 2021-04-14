#include <iostream>
#include <cstring>
#include <stack>
#include <utility>
using namespace std;

string str1, str2, mix;
int n;
bool can;

void dfs(int oneidx, int twoidx, int mixidx);
bool possiblestr();
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		str1.clear(); str2.clear(); mix.clear();
		cin >> str1 >> str2 >> mix;
		can = false;
		if (possiblestr()) {
			dfs(0, 0, 0);
		}
		if (can) {
			cout << "Data set " << i << ": yes" << endl;
		}
		else {
			cout << "Data set " << i << ": no" << endl;
		}
	}
}
bool possiblestr() {
	int alphabet[26];
	memset(alphabet, 0, sizeof(alphabet));
	for (int i = 0; i < str1.length(); i++) {
		alphabet[str1[i] - 'a']++;
	}
	for (int i = 0; i < str2.length(); i++) {
		alphabet[str2[i] - 'a']++;
	}
	for (int i = 0; i < mix.length(); i++) {
		alphabet[mix[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] < 0) return false;
	}
	return true;
}
void dfs(int oneidx, int twoidx, int mixidx) {
	stack<pair<pair<int, int>, int>> s;
	s.push({ {oneidx,twoidx},mixidx });
	while (!s.empty()) {
		pair<pair<int, int>, int> cur = s.top();
		s.pop();
		if (cur.second == mix.length()) {
			if (cur.first.first == str1.length() && cur.first.second == str2.length()) {
				can = true; 
				return;
			}
		}
		if (str1[cur.first.first] == mix[cur.second]) {
			s.push({ {cur.first.first + 1,cur.first.second},cur.second + 1});
		}
		if (str2[cur.first.second] == mix[cur.second]) {
			s.push({ {cur.first.first, cur.first.second + 1},cur.second + 1});
		}
	}
}