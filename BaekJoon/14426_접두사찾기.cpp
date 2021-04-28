#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> str;
	//vector<string> head;
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		str.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		string head; cin >> head;
		for (int j = 0; j < n; j++) {
			//cout << "head:" << head << " str:" << str[j].substr(0, head.length()) << endl;
			if (str[j].compare(0, head.length(), head)==0) {
				ans++;
				break;
			}
			/*if (head == str[j].substr(0, head.length())) {
				ans++;
				break;
			}*/
			//cout << "ans:" << ans << endl;
		}
	}

	cout << ans << endl;
}