#include <iostream>
#include <string>
using namespace std;

string ans = "";
string input;
int len;
void eighttotwo(int pos);

int main() {
	cin >> input;
	len = input.length();

	int num_0 = input[0] - '0';
	bool chk = false;
	if (num_0 / 4) {
		ans += "1";
		num_0 -= 4;
		chk = true;
	}
	if (num_0 / 2) {
		ans += "1";
		num_0 -= 2;
		chk = true;
	}
	else if (chk) {
		ans += "0";
	}
	if (num_0 != 0) {
		ans += "1";
	}
	else {
		ans += "0";
	}
	for (int i = 1; i < input.length(); i++) {
		eighttotwo(i);
	}
	cout << ans << endl;
}

void eighttotwo(int pos) {
	string newStr = "";
	int num = input[pos] - '0';
	if (num / 4 != 0) {
		newStr += "1";
		num -= 4;
	}
	else {
		newStr += "0";
	}
	if (num / 2 != 0) {
		newStr += "1";
		num -= 2;
	}
	else {
		newStr += "0";
	}
	if (num != 0) {
		newStr += "1";
	}
	else {
		newStr += "0";
	}
	ans += newStr;
	return;
}