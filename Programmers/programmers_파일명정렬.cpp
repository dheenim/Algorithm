#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct FilePart{
    string head;
    string num;
    string tail;
};

FilePart splitFiles(string file){
    FilePart ret;
    string tmp="";
    int hnt=0;
    for(int i=0;i<file.length();i++){
        if(hnt==0 && file[i]>='0' && file[i]<='9'){
            hnt++;
            ret.head = tmp;
            tmp.clear();
            tmp+=file[i];
        }
        else if(hnt==0) tmp+=file[i];
        else if(hnt==1 && (file[i]<'0' || file[i]>'9')){
            hnt++;
            ret.num = tmp;
            tmp.clear();
            tmp+=file[i];
        }
        else if(hnt==1){
            tmp+=file[i];
        }
        else{
            tmp+=file[i];
        }
    }
    if(hnt==1){
        ret.num = tmp;
    }
    else ret.tail = tmp;
    return ret;
}
bool cmp(pair<FilePart,int> a, pair<FilePart,int> b){
    for(int i=0;i<a.first.head.length();i++)
        a.first.head[i]=toupper(a.first.head[i]);
    for(int i=0;i<b.first.head.length();i++)
        b.first.head[i]=toupper(b.first.head[i]);
    if(a.first.head==b.first.head){
        if(stoi(a.first.num)==stoi(b.first.num)){
            return a.second < b.second;
        }
        else return stoi(a.first.num) < stoi(b.first.num);
    }
    else return a.first.head<b.first.head;
}
vector<string> mergeFile(vector<pair<FilePart,int>> files){
    vector<string> ans;
    for(int i=0;i<files.size();i++){
        string tmp = "";
        tmp+=files[i].first.head;
        tmp+=files[i].first.num;
        tmp+=files[i].first.tail;
        ans.push_back(tmp);
    }
    return ans;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<FilePart,int>> filesSplit;
    for(int i=0;i<files.size();i++){
        filesSplit.push_back({splitFiles(files[i]),i});
    }
    sort(filesSplit.begin(),filesSplit.end(),cmp);

    return mergeFile(filesSplit);
}
