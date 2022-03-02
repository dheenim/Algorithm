#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cant_recog = 0;
    int same = 0;
    for(auto num:lottos){
        if(num==0){
            cant_recog++; continue;
        }
        for(auto winNum:win_nums){
            if(winNum==num){
                same++; break;
            }
        }
    }
    int best = 7-(cant_recog+same);
    int worst = 7-(same);
    if(best>=6) answer.push_back(6);
    else answer.push_back(best);
    if(worst>=6) answer.push_back(6);
    else answer.push_back(worst);
    return answer;
}
