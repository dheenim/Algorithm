#include <string>
#include <vector>
#include <map>
using namespace std;
multimap<string,pair<string,bool>> mm;
vector<string> answer;
vector<string> newAns;
int totPass;
void answerChk(){
    if(answer.size()==0){
        answer = newAns;
        return;
    }
    for(int i=1;i<=totPass;i++){
        if(answer[i] == newAns[i]) continue;
        if(answer[i] > newAns[i]){
            answer.clear();
            answer = newAns;
            return;
        }
        else return;
    }
    
}

void dfs(int useTkt, string curCty){
    if(totPass == useTkt){
        answerChk();
        return;
    }
    for(auto it = mm.equal_range(curCty).first; it!= mm.equal_range(curCty).second; it++){
        if(it->second.second) continue;
        it->second.second = true;
        newAns.push_back(it->second.first);
        dfs(useTkt+1, it->second.first);
        newAns.pop_back();
        it->second.second = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for(int i=0;i<tickets.size();i++){
        mm.insert({tickets[i][0], {tickets[i][1], false}});
    }
    totPass = tickets.size();
    newAns.push_back("ICN");

    dfs(0,"ICN");
    
    return answer;
}
