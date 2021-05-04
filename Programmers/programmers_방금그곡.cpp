#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> splitInfo(string str){
    vector<string> svec;
    string start,end,title,info;
    stringstream ss(str);
    getline(ss,start,','); svec.push_back(start);
    getline(ss,end,','); svec.push_back(end);
    getline(ss,title,','); svec.push_back(title);
    getline(ss,info,','); svec.push_back(info);
    return svec;
}
int getPlayTime(string start, string end){
    int startHour, endHour, startMin, endMin;
    string tmp;
    for(int i=0;i<start.length();i++){
        if(start[i]==':'){
            startHour = stoi(tmp);
            tmp.clear();
        }
        else{
            tmp.push_back(start[i]);
        }
    }
    startMin = stoi(tmp);
    tmp.clear();
    for(int i=0;i<end.length();i++){
        if(end[i]==':'){
            endHour = stoi(tmp);
            tmp.clear();
        }
        else{
            tmp.push_back(end[i]);
        }
    }
    endMin = stoi(tmp);
    return (endHour*60 + endMin)-(startHour*60+startMin);
}
bool cmp(pair<string,pair<int,int>> a,pair<string,pair<int,int>> b){
    if(a.second.first == b.second.first){
        return a.second.second<b.second.second;
    }
    else{
        return a.second.first>b.second.first;
    }
}
string solution(string m, vector<string> musicinfos) {
    vector<pair<string, pair<int,int>>> ans;
    for(int i=0;i<musicinfos.size();i++){
        //cout<<"i:"<<i<<endl;
        vector<string> info = (splitInfo(musicinfos[i]));
        //for(int k=0;k<info.size();k++)
            //cout<< info[k]<<" ";
        //cout<<endl;
        int time = getPlayTime(info[0],info[1]);
        string melody="";
        int mod = info[3].length();
        for(int idx=0;idx<time;idx++){
            melody+=(info[3][idx%mod]);
            if(info[3][(idx+1)%mod]=='#'){
                idx++;
                time++;
                melody+= info[3][(idx)%mod];
            }
        }
        //cout<<"melody:"<<melody<<endl;
        if(melody.length()<m.length()){
            if(info[3].length()<m.length()) continue;
            melody.clear();
            melody = info[3];
        }
        for(int idx=0;idx<melody.length();idx++){
            bool chk = true;
            for(int midx=0;midx<m.length();midx++){
                if(melody[idx+midx]==m[midx]){
                    if(idx+midx+1<melody.length()&&midx+1<m.length()&&melody[idx+midx+1]=='#'&&m[midx+1]!='#'){
                        idx++; midx++;
                        chk = false;
                        break;
                    }
                    if(idx+midx+1<melody.length()&&melody[idx+midx+1]=='#'&&midx==m.length()-1){
                        idx++;
                        chk = false;
                        break;
                    }
                }
                if(melody[idx+midx]!=m[midx]){
                    chk = false;
                    break;
                }
            }
            if(chk){
                //cout<<info[2]<<endl;
                //cout<<"time:"<<time<<endl;
                ans.push_back({info[2],{time,i}});
                break;
            }
        }
    }
    //for(int i=0;i<ans.size();i++)
        //cout<<ans[i].first<<" ";
    sort(ans.begin(),ans.end(),cmp);
    if(ans.size()==0) return "(None)";
    return ans[0].first;
}
