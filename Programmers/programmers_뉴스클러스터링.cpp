#include <string>
#include <cctype>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    for (int i=0; i<str1.size(); i++){
        str1[i]=toupper(str1[i]);
    }
    for (int i=0; i<str2.size(); i++){
        str2[i]=toupper(str2[i]);
    }
    map<string,int> s1, s2;
    for(int i=0;i<str1.length()-1;i++){
        if(isalpha(str1[i]) && isalpha(str1[i+1])){
            string tmp;
            tmp.push_back(str1[i]); tmp.push_back(str1[i+1]);
            s1[tmp]++;
        }
    }
    for(int i=0;i<str2.length()-1;i++){
        if(isalpha(str2[i]) && isalpha(str2[i+1])){
            string tmp;
            tmp.push_back(str2[i]); tmp.push_back(str2[i+1]);
            s2[tmp]++;
        }
    }
    int union_=0, inter=0;
    for(auto it=s1.begin();it!=s1.end();it++){
        //cout << "*it:"<<it->first<<" val:"<<it->second<<endl;
        bool chk = true;
        auto it2 = s2.begin();
        for(;it2!=s2.end();it2++){
            if(it->first == it2->first){
                //cout << "it2:"<<it2->first<<" val:"<<it2->second<<endl;
                chk = false;
                break;
            }
        }
        if(chk){
            union_+=it->second;
        }
        else{
            union_ += max(it->second, it2->second);
            inter += min(it->second, it2->second);
        }
    }
    for(auto it=s2.begin();it!=s2.end();it++){
        //cout << "*it:"<<it->first<<" val:"<<it->second<<endl;
        bool chk = true;
        auto it2 = s1.begin();
        for(;it2!=s1.end();it2++){
            if(it->first == it2->first){
                //cout << "it2:"<<it2->first<<" val:"<<it2->second<<endl;
                chk = false;
                break;
            }
        }
        if(chk){
            union_+=it->second;
        }
    }
    //cout << union_<< ", "<<inter<<endl;
    if(inter==0&&union_==0) return 65536;
    int answer = ((double)inter/(double)union_)*65536;
    return answer;
}
