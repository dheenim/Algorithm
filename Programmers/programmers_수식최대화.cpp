#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> input_op;
    queue<long long> q_num[2];
    queue<char> q_op[2];
    int idx = 0;
    string readStr = "";
    while (idx < expression.length()) {
        if (expression[idx] <= '9' && expression[idx] >= '0') {
            readStr += expression[idx];
        }
        else {
            //q_num[0].push(stoll(readStr));
            //q_op[0].push(expression[idx]);
            nums.push_back(stoll(readStr));
            readStr.clear();
            input_op.push_back(expression[idx]);
        }
        idx++;
    }
    //q_num[0].push(stoll(readStr));
    nums.push_back(stoll(readStr));

    //for (int i = 0; i < nums.size(); i++) {
    //    cout << nums[i] << " ";
    //}cout << endl;
    //for (int i = 0; i < input_op.size(); i++) {
    //    cout << input_op[i] << " ";
    //}cout << endl;

    vector<char> op;
    op.push_back('*');
    op.push_back('-');
    op.push_back('+');
    sort(op.begin(), op.end());

    do {
        for (int i = 0; i < nums.size(); i++) {
            q_num[0].push(nums[i]);
        }
        for (int i = 0; i < input_op.size(); i++) {
            q_op[0].push(input_op[i]);
        }
        /*cout << "push ok" << "\nop순서 : \n";
        for (int i = 0; i < op.size(); i++) {
            cout << op[i] << " ";
        }cout << endl;*/
        for (int i = 0; i < op.size(); i++) {//연산자 순서대로 check
            //cout << "curop:" << op[i] << endl;
            int usingidx;
            if (q_num[1].empty()) {
                usingidx = 0;
            }
            else {
                usingidx = 1;
            }
            if (q_op[usingidx].empty()) {//계산완료
                if (q_num[usingidx].empty()) continue;
                answer = answer > abs(q_num[usingidx].front()) ? answer : abs(q_num[usingidx].front());
                q_num[usingidx].pop();
                //cout << "answer: " << answer << endl;
                continue;
            }
            int oppsiteidx = (usingidx + 1) % 2;
            int popCnt = 0;
            while (!q_op[usingidx].empty()) {
                char chkop = q_op[usingidx].front();
                //cout << "chkop:" << chkop << endl;
                q_op[usingidx].pop();
                if (op[i] == chkop) {//해당 순위 연산자 발견하면 계산, 한번만 계산하며 모두 계산될때까지 반복
                    //cout << "same op" << endl;
                    for (int k = popCnt; k > 0; k--) {//계산할 위치의 숫자 찾기
                        q_num[oppsiteidx].push(q_num[usingidx].front());
                        q_num[usingidx].pop();
                    }
                    long long a = q_num[usingidx].front(); q_num[usingidx].pop();
                    long long b = q_num[usingidx].front(); q_num[usingidx].pop();
                    //cout << "a:" << a << "  b:" << b << endl;
                    if (chkop == '+') {
                        q_num[oppsiteidx].push(a + b);
                    }
                    else if (chkop == '-') {
                        q_num[oppsiteidx].push(a - b);
                    }
                    else {//*
                        q_num[oppsiteidx].push(a * b);
                    }
                    while (!q_num[usingidx].empty()) {
                        q_num[oppsiteidx].push(q_num[usingidx].front());
                        q_num[usingidx].pop();
                    }
                    while (!q_op[usingidx].empty()) {
                        q_op[oppsiteidx].push(q_op[usingidx].front());
                        q_op[usingidx].pop();
                    }
                    popCnt = -1;//아래 +1해주기 때문에 아무것도 안뺀것으로 시작해야하기에
                    oppsiteidx = usingidx;
                    usingidx = (oppsiteidx + 1) % 2;
                }
                else {//발견못했을땐 pop한거 다시 넣어줘야함
                    q_op[oppsiteidx].push(chkop);
                }
                popCnt++;
            }
            while (!q_num[usingidx].empty()) {
                q_num[oppsiteidx].push(q_num[usingidx].front());
                q_num[usingidx].pop();
            }
            while (!q_op[usingidx].empty()) {
                q_op[oppsiteidx].push(q_op[usingidx].front());
                q_op[usingidx].pop();
            }
            if (i == op.size() - 1) i--;
        }
    } while (next_permutation(op.begin(), op.end()));


    return answer;
}

int main() {
    cout << solution("50*6-3*2");
}