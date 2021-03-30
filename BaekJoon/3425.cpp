#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector<string> imple;
vector<long long> input;
stack<long long> stkProg;

vector<string> ans;

bool getImple();
void doProg();

int main() {
	while (1) {
		imple.clear();
		while(getImple());
		//cout << imple[0] << endl;
		if (imple.size()>0&&imple[0].compare("QUIT")==0) {
			break;
		}
		long long N;
		cin >> N;
		input.clear();
		for (long long i = 0; i < N; i++) {
			long long tmp;
			cin >> tmp;
			input.push_back(tmp);
		}
		for (long long i = 0; i < N; i++) {
			stkProg.push(input[i]);
			doProg();
			if (stkProg.size() == 1) {
				ans.push_back(to_string(stkProg.top()));
				//cout << stkProg.top() << endl;
			}
			else {
				ans.push_back("ERROR");
				//cout << "ERROR" << endl;
			}
			while (!stkProg.empty())stkProg.pop();
		}
		ans.push_back("\n");
		//cout << endl;
	}
	for (long long i = 0; i < ans.size()-1; i++) {
		if (ans[i].compare("\n") == 0) {
			cout << ans[i];
			continue;
		}
		cout << ans[i] << endl;
	}
}
bool getImple() {
	string str;
	getline(cin, str);
	while (str[0] == '\0') {
		str.clear();
		getline(cin, str);
	}
	//if (str[0] == '\0') {
	//	str.clear();
	//	getline(cin, str);
	//}
	if (str.compare("QUIT") == 0) {
		imple.push_back(str);
		return false;
	}
	if (str.compare("END") == 0) {
		return false;
	}
	imple.push_back(str);
	return true;
}

void doProg() {
	for (long long i = 0; i < imple.size(); i++) {
		if (imple[i].find("NUM") != -1) {
			/*if (atoi(&imple[i][4]) > 1e9 || atoi(&imple[i][4]) < 0) {
				stkProg.push(1);
				stkProg.push(1);
				return;
			}*/
			stkProg.push(atoi(&imple[i][4]));
			continue;
		}
		if (stkProg.size() == 0) {
			return;
		}
		if (imple[i].compare("POP")==0) {
			stkProg.pop();
			continue;
		}
		if (imple[i].compare("INV")==0) {
			long long top = stkProg.top();
			stkProg.pop();
			stkProg.push(-top);
			continue;
		}
		if (imple[i].compare("MUL")==0) {
			long long fst = stkProg.top();
			stkProg.pop();
			if (stkProg.size() == 0) {
				return;
			}
			long long sec = stkProg.top();
			stkProg.pop();
			if (llabs(fst * sec) > 1e9 ) {
				stkProg.push(1);
				stkProg.push(1);
				return;
			}
			stkProg.push(fst*sec);
			continue;
		}
		if (imple[i].compare("ADD")==0) {
			long long fst = stkProg.top();
			stkProg.pop();
			if (stkProg.size() == 0) {
				return;
			}
			long long sec = stkProg.top();
			stkProg.pop();
			if (llabs(fst + sec) > 1e9) {
				stkProg.push(1);
				stkProg.push(1);
				return;
			}
			stkProg.push(fst + sec);
			continue;
		}
		if (imple[i].compare("SUB")==0) {
			long long fst = stkProg.top();
			stkProg.pop();
			if (stkProg.size() == 0) {
				return;
			}
			long long sec = stkProg.top();
			stkProg.pop();
			if (llabs(sec - fst) > 1e9) {
				stkProg.push(1);
				stkProg.push(1);
				return;
			}
			stkProg.push(sec - fst);
			continue;
		}
		if (imple[i].compare("DIV")==0) {
			long long fst = stkProg.top();
			stkProg.pop();
			if (stkProg.size() == 0) {
				return;
			}
			long long sec = stkProg.top();
			stkProg.pop();
			if (fst == 0) {
				stkProg.push(1);
				stkProg.push(1);
				return;
			}
			long long put;
			if (sec * fst < 0) {
				put = -1*(llabs(sec) / llabs(fst));
				//cout << "put: "<<put << endl;
			}
			else {
				put = abs(sec) / abs(fst);
			}
			stkProg.push(put);
			continue;
		}
		if (imple[i].compare("MOD")==0) {
			long long fst = stkProg.top();
			stkProg.pop();
			if (stkProg.size() == 0) {
				return;
			}
			long long sec = stkProg.top();
			stkProg.pop();
			if (fst == 0) {
				stkProg.push(1);
				stkProg.push(1);
				return;
			}
			long long put;
			if (sec > 0) {
				put = llabs(sec) % llabs(fst);
			}
			else {
				put = -1*(llabs(sec) % llabs(fst));
			}
			stkProg.push(put);
			continue;
		}
		if (imple[i].compare("DUP")==0) {
			stkProg.push(stkProg.top());
			continue;
		}
		if (imple[i].compare("SWP")==0) {
			long long fst = stkProg.top();
			stkProg.pop();
			if (stkProg.size() == 0) {
				return;
			}
			long long sec = stkProg.top();
			stkProg.pop();
			stkProg.push(fst);
			stkProg.push(sec);
			continue;
		}
	}
}