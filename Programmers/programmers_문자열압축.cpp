#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

int solution(string s) {
    int answer = 1000000000;
    int cut = 1;
    if (s.length() == 1) return 1;
    while (cut <= (int)(s.length() / 2)) {
        string cmpStr = s.substr(0, cut);
        //cout << cmpStr << endl;
        int cnt = 0;
        int len = 0;
        //cout << "len:"<<len << "\n";
        for (int i = 0; i < s.length(); i += cut) {
            if (i + cut > s.length()) {
                len += s.length() - i;
                break;
            }
            string curStr = s.substr(i, cut);
            //cout << "curcomStr:" << cmpStr << "\t";
            //cout << "curStr:" << curStr << endl;
            if (curStr == cmpStr) {
                cnt++;
            }
            else {
                if (cnt != 1) {
                    //len++;
                    len+=to_string(cnt).length();
                }
                len += cmpStr.length();
                cnt = 1;
                cmpStr.clear();
                cmpStr = curStr;
            }
            //cout << "curlen:" << len << endl;
        }
        if (cnt != 1) {
            len += cmpStr.length() + to_string(cnt).length();
        }
        else {
            len += cmpStr.length();
        }
        //cout << len << endl;
        cut++;
        if (answer > len) answer = len;
    }
    return answer;
}
int main() {
    string str;
    cin >> str;
    cout << solution(str);
}