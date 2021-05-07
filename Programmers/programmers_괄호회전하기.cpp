#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool chkCor(string s){
    //cout<< "s:"<<s<<endl;
    stack<char> stk;
    if(s[0]==']'||s[0]=='}'||s[0]==')') return false;
    stk.push(s[0]);
    for(int i=1;i<s.length();i++){
        //cout<<"top:"<<stk.top()<<" s[i]:"<<s[i]<<endl;
        if(s[i]==')'){
            if(stk.empty()) return false;
            if(stk.top()!='(') return false;
            stk.pop();
        }
        else if(s[i]=='}'){
            if(stk.empty()) return false;
            if(stk.top()!='{') return false;
            stk.pop();
        }
        else if(s[i]==']'){
            if(stk.empty()) return false;
            if(stk.top()!='[') return false;
            stk.pop();
        }
        else{
            stk.push(s[i]);
        }
    }
    if(stk.empty()) return true;
    else return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    for(int x=0;x<s.length();x++){
        if(chkCor(s)) answer++;
        s.push_back(s[0]);
        s.erase(s.begin());
    }
    return answer;
}
