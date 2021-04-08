//°ÅÁþ¸»
#include <iostream>
#include <set>

using namespace std;

set<int> partyPeople[51];
set<int> know;
int peopleNum, partyNum;
bool partyCheck[51];
int ans = 0;

int main() {
	cin >> peopleNum >> partyNum;
	int startKnow;
	cin >> startKnow;
	for (int i = 0; i < startKnow; i++) {
		int tmp;
		cin >> tmp;
		know.insert(tmp);
	}
	for (int i = 0; i < partyNum; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int tmp;
			cin >> tmp;
			partyPeople[i].insert(tmp);
		}
	}
	for (int i = 0; i < partyNum; i++) {
		if (partyCheck[i]) continue;
		bool chkContain = false;
		set<int>::iterator iter;
		for (iter = partyPeople[i].begin(); iter != partyPeople[i].end(); iter++) {
			int findNum = *iter;
			if (know.end() == know.find(findNum)) {
				continue;
			}
			else {
				chkContain = true;
				break;
			}
		}
		if (chkContain) {
			for (iter = partyPeople[i].begin(); iter != partyPeople[i].end(); iter++) {
				int findNum = *iter;
				know.insert(findNum);
			}
			partyCheck[i] = true;
			i = -1;
		}
	}
	for (int i = 0; i < partyNum; i++) {
		if (!partyCheck[i]) ans++;
	}
	cout << ans << endl;
}