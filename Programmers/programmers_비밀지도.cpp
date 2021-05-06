#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int idx=0;idx<arr1.size();idx++){
        string ans="";
        for(int i=0;i<n;i++){
            if(((arr1[idx]|arr2[idx])&(1<<i))){
                ans = "#"+ans;
            }
            else ans = " "+ans;
        }
        answer.push_back(ans);
    }
    return answer;
}
