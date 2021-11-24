#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        int start = commands[i][0];
        int end = commands[i][1];
        int pos = commands[i][2];
        vector<int> v;
        for(int j=start-1;j<end;j++){
            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[pos-1]);
    }
    return answer;
}
