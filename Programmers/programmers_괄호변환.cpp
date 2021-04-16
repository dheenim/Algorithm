#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool chkCorrect(string chk) {
    //cout << chk << endl;
    int cnt = 0;
    int idx = 0;
    while (idx < chk.length()) {
        if (chk[idx] == ')')
            if (cnt == 0) return false;
            else cnt--;
        else cnt++;
        idx++;
    }
    return true;
}

int balancedIdx(string s) {//몇번째 index까지 균형잡힌지 체크
    int lcnt = 0, rcnt = 0, idx = 0;
    
    while (idx < s.length()) {
        if (s[idx] == '(') lcnt++;
        else rcnt++;
        if (lcnt == rcnt) return idx;
        idx++;
    }
    return 0;//0이 반환되면 자를 수 없다. u는 빈문자열
}

string solution(string p) {
    if (p == "") return p;//1.입력 빈문자열이면 그대로 반환
    string answer = "";
    int bIdx = balancedIdx(p);
    string u, v;
    if (bIdx == 0) {
        u = "";
        v = p;
    }
    else {
        u = p.substr(0, bIdx + 1);
        v = p.substr(bIdx + 1, p.length() - bIdx - 1);
    }
    //cout << u << "  " << v << endl;
    if (chkCorrect(u)) {
        //cout << "corret\n";
        answer += u;
        //cout << answer << endl;
        answer += solution(v);
    }
    else {
        string vtmp = "(";
        vtmp += solution(v); vtmp += ")";
        string utmp = "";
        for (int i = 1; i < u.length() - 1; i++) {
            if (u[i] == '(')
                utmp += ")";
            else utmp += "(";
        }
        answer += vtmp + utmp;
    }
    //cout << "before return answer : " << answer << endl;
    return answer;
}
int main() {
    string str;
    cin >> str;
    cout << solution(str);
}