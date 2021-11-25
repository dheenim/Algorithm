#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> ct) {
    int answer = ct.size();
    sort(ct.begin(), ct.end());
    int idx =0;
    while(idx<ct.size()){
        if(ct[idx]>=answer){
            break;
        }
        else{
            answer--;
            idx++;
        }
    }

    return answer;
}
