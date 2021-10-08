#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

bool chkOneDiff(string a, string b){
    int diff = 0;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]){
            diff++;
            if(diff>1) return false;
        }

    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string,int>> q;
    vector<bool> visited(words.size(),false);
    q.push({begin,0});
    while(!q.empty()){
        int qsize = q.size();
        //cout<<"qsize:"<<qsize<<endl;
        for(int i=0;i<qsize;i++){
            string before = q.front().first;
            int change = q.front().second;
            //cout << "before:"<<before<<" cnt:"<< change<<endl;
            q.pop();
            for(int j=0;j<words.size();j++){
                
                if(visited[j]) continue;cout<<words[j]<<endl;
                if(chkOneDiff(before, words[j])){
                    //cout<<"can change : "<<words[j]<<endl;
                    visited[j] = true;
                    if(words[j]==target){
                        return change+1;
                    }
                    q.push({words[j], change+1});
                }
            }
        }
    }
    
    return answer;
}
