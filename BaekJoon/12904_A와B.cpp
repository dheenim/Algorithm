#include <iostream>
#include <vector>
#include <string>
using namespace std;

string S, T;

void Bop() {
	T.pop_back();
	reverse(T.begin(), T.end());
	return;
}

void Aop() {
	T.pop_back();
	return;
}

void chkOP() {
	int lastIdx = T.length() - 1;
	if (T[lastIdx] == 'A') {
		Aop();
	}
	else Bop();
	return;
}

int main() {
	cin >> S;
	cin >> T;
	while (S.length() < T.length()) {
		chkOP();
	}
	if (S.compare(T) == 0) cout << 1 << endl;
	else cout << 0 << endl;
}