#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m; cin >> m;
	unsigned int s = 0;
	unsigned int all_ = 0;
	for (int i = 0; i <= 20; i++) {
		all_ = all_ | (1 << i);
	}
	for (int i = 0; i < m; i++) {
		string op; int num;
		cin >> op;
		if (op == "all") {
			s = all_;
			continue;
		}
		else if (op == "empty") {
			s = 0;
			continue;
		}
		cin >> num;
		if (op == "add") {
			s = s | (1 << (num - 1));
			
		}
		else if (op == "remove") {
			unsigned int tmp = 1 << (num - 1);
			tmp = all_ ^ tmp;
			s = s & tmp;
		}
		else if (op == "check") {
			unsigned int tmp = 1 << (num - 1);
			if (s & tmp) cout << 1<<'\n';
			else cout << 0<<'\n';
		}
		else {//toggle
			s = s ^ (1<<(num-1));
		}
		//cout << "s:" << s << endl;;
	}
}