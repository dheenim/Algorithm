//(100+1+ | 01)+ ã��
#include <iostream>

using namespace std;

bool chkpattern(string input);

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string input;
		cin >> input;
		if (chkpattern(input)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}
bool chkpattern(string input) {
	int idx = 0;
	int len = input.length();
	bool before;
	while (idx < len) {
		before = (input[idx] == '1');
		//�տ� ������ ���(100+1+)
		if (before && idx + 3 >= len) return false;
		if (before && idx + 3 < len) {
			if (input[idx + 1] == '1' || input[idx + 2] == '1') return false;
			idx += 3;
			//1�� ��������
			if (idx >= len) return false;
			while (input[idx] == '0') {
				idx++;
				//1�� ���� ��������
				if (idx >= len) return false;
			}
			int oneNum = 0;
			while (input[idx] == '1') {
				idx++;
				oneNum++;
				if (idx >= len) return true;
			}
			//���⼭ input[idx]�� '0'
			if (oneNum < 2) {//1�� 1���� �ִٸ� (01)�� �Ǿ����
				continue;
			}
			/*1
			10001101*/
			if (idx + 1 < len && input[idx + 1] == '1') {
				idx += 2;
				continue;
			}
			//�ڿ� (01)�� �ƴ϶�� 100+1+ �� �Ǿ����
			idx--;
			continue;
		}
		//���� ������ ���(01)
		//���� �� input[idx]�� '0'
		if (!before && idx + 1 >= len) return false;
		if (input[idx + 1] == '0') return false;
		idx += 2;
	}
	return true;
}