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
        /*cout << "push ok" << "\nop���� : \n";
        for (int i = 0; i < op.size(); i++) {
            cout << op[i] << " ";
        }cout << endl;*/
        for (int i = 0; i < op.size(); i++) {//������ ������� check
            //cout << "curop:" << op[i] << endl;
            int usingidx;
            if (q_num[1].empty()) {
                usingidx = 0;
            }
            else {
                usingidx = 1;
            }
            if (q_op[usingidx].empty()) {//���Ϸ�
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
                if (op[i] == chkop) {//�ش� ���� ������ �߰��ϸ� ���, �ѹ��� ����ϸ� ��� ���ɶ����� �ݺ�
                    //cout << "same op" << endl;
                    for (int k = popCnt; k > 0; k--) {//����� ��ġ�� ���� ã��
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
                    popCnt = -1;//�Ʒ� +1���ֱ� ������ �ƹ��͵� �Ȼ������� �����ؾ��ϱ⿡
                    oppsiteidx = usingidx;
                    usingidx = (oppsiteidx + 1) % 2;
                }
                else {//�߰߸������� pop�Ѱ� �ٽ� �־������
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