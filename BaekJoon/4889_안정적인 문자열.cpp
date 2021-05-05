#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int tc = 1;
void cal(string input) {
	int ans = 0;
	int left = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '{') left++;
		else {
			if (left == 0) {
				ans++;
				left++;
			}
			else {
				left--;
			}
		}
	}
	ans += (left / 2);
	cout << tc << ". " << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1) {
		string input;
		getline(cin, input);
		if (input[0] == '-') break;
		cal(input);
		tc++;
	}
}