#include <string>
#include <vector>
#include <cstring>
#define MAX_INT 2100000000
using namespace std;
bool visit[51];
int wordNum;
int ans;
vector<string> wrds;
string tgt;
bool chkPoss(string next, string cur){
    int len = next.length();
    int dif = 0;
    for(int i=0;i<len;i++){
        if(next[i] != cur[i]) dif++;
        if(dif>1) break;
    }
    if(dif>1) return false;
    else return true;
}

void dfs(int depth, string curStr){
    if(curStr == tgt){
        if(ans>depth) ans = depth;
        return;
    }
    if(depth>=wordNum) return;
    
    for(int i=0;i<wordNum;i++){
        if(visit[i]) continue;
        if(!chkPoss(wrds[i],curStr)) continue;
        visit[i] = true;
        dfs(depth+1, wrds[i]);
        visit[i] = false;
    }
}



int solution(string begin, string target, vector<string> words) {
    bool possi=false;
    for(int i=0;i<words.size();i++){
        if(words[i] == target){
            possi = true; break;
        }
    }
    if(!possi) return 0;
    
    ans = MAX_INT;
    wordNum = words.size();
    tgt = target;
    wrds = words;
    
    dfs(0,begin);
    
    return ans;
}
