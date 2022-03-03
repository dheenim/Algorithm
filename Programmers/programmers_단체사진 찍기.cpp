#include <string>
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int answer;
int N;
vector<string> Data;
char elements[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
bool chk[8];
char line[8];

void dfs(int haveNum){
    if(haveNum == 8){
        for(int i=0; i<N; i++){
            char first = Data[i][0];
            char second = Data[i][2];
            char condition = Data[i][3];
            int val = Data[i][4] - '0';
            val++;
            int firstIdx, secondIdx;
            for(int j=0;j<8;j++){
                if(first == line[j]) firstIdx = j;
                if(second == line[j]) secondIdx = j;
            }
            if(condition=='=' && abs(firstIdx-secondIdx) != val) return;
            if(condition=='>' && abs(firstIdx-secondIdx) <= val) return;
            if(condition=='<' && abs(firstIdx-secondIdx) >= val) return;
        }
        answer++;
        return;
    }
    for(int i=0; i<8; i++){
        if(chk[i]) continue;
        chk[i] = true;
        line[haveNum] = elements[i];
        dfs(haveNum+1);
        chk[i] = false;
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    N = n;
    Data = data;
    dfs(0);
    return answer;
}
