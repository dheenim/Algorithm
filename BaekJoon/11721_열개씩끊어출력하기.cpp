#include<iostream>
#include <string>

using namespace std;

int main() {
	string input;
	cin >> input;
	int idx = 0;
	while (idx < input.length()) {
		cout << input.substr(idx, 10) << "\n";
		idx += 10;
	}
}