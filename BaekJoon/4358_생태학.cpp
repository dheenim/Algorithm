#include <iostream>
#include <vector>
#include <string>
#include <map>
#define SP 10000
#define TREE 1000000
using namespace std;
map<string, double> m;
int main() {
	int inputNum = 0;
	string s;
	while (getline(cin, s)) {
		inputNum++;
		m[s]++;
		s.clear();
	}

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << fixed;
		cout.precision(4);
		cout << it->first << " " << ((it->second) / inputNum)*100 << "\n";
	}
}