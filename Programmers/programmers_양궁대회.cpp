#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> appeach;
vector<int> lion(11,0);
vector<int> ans;
int score = -1;
int N;
void dfs(int shoots,int idx){
    if(idx == 11 || shoots == N){
        int lionSc = 0, appSc = 0;
        for(int i=0;i<11;i++){
            if(appeach[i] == 0 && lion[i] == 0) continue;
            if(appeach[i]>lion[i]) appSc += (10-i);
            else lionSc += (10-i);
        }
        int diff = lionSc - appSc;
        if(diff > 0 && diff>=score){
            if(score == diff){
                lion[10] = N-shoots;
                for(int i=10;i>=0;i--){
                    if(lion[i]==ans[i])continue;
                    if(lion[i]>ans[i]){
                        ans.clear();
                        ans = lion;
                        break;
                    }
                    if(lion[i]<ans[i]) break;
                }
            }
            else if(score < diff){
                score = diff;
                lion[10] = N-shoots;
                ans.clear();
                ans = lion;
            }
        }
        return;
    }
    if(appeach[idx]+1+shoots <= N){
        lion[idx] += (appeach[idx]+1);
        dfs(appeach[idx]+1+shoots,idx+1);
        lion[idx] -= (appeach[idx]+1);
    }
    dfs(shoots,idx+1);

}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    appeach = info; N = n;
    dfs(0,0);
    if(score == -1){
        answer.push_back(-1);
    }
    else{
        answer = ans;
    }
    return answer;
}
