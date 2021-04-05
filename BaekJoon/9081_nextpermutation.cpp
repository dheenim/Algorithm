#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<string> input;
//string input[10];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		input.push_back(str);
	}
	for (int k = 0; k < T; k++) {
		vector<char> a;
		for (int i = 0; i < input[k].length(); i++) {
			a.push_back(input[k][i]);
		}
		if (next_permutation(a.begin(), a.end())) {
			for (int i = 0; i < a.size(); i++) {
				cout << a[i];
			}
		}
		else {
			cout << input[k];
		}
		cout << endl;
	}
}