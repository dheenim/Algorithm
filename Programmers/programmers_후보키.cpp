#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int col = relation[0].size();
    int row = relation.size();
    vector<string> picks;

    for(int i=1;i<=col;i++){
        cout << i<<"개 뽑음\n";
        vector<int> ind;
        for(int j=0; j<i; j++){
            ind.push_back(1);
        }
        for(int j=0; j<col-i; j++){
            ind.push_back(0);
        }
        sort(ind.begin(), ind.end());
        set<string> s;
        do{
            string* str = new string[row];

            string p = "";
            for(int c=0; c<ind.size(); c++){
                if(ind[c] == 1){
                    p+="1";
                    for(int r=0;r<row;r++){
                        str[r] += relation[r][c];
                    }
                }
                else p+="0";
            }
            cout << p <<endl;
            bool chk = true;
            for(int ck=0;ck<picks.size();ck++){
                int cnt = 0;
                int pcnt = 0;
                for(int pos=0;pos<p.size();pos++){
                    if(picks[ck][pos] == '1'){
                        cnt++;
                        if(p[pos] == '1') pcnt++;
                    }
                }
                if(cnt == pcnt){
                    chk = false;
                    break;
                }
            }
            if(chk){
                set<string> s;
                bool pushok = true;
                for(int r=0;r<row;r++){
                    cout<<"str[r]:"<<str[r]<<endl;
                    auto ret = s.insert(str[r]);
                    if(!ret.second){
                        pushok = false;
                    }
                }
                if(pushok){
                    answer++;
                    picks.push_back(p);
                }
                cout << "answer: "<<answer<<endl;
            }
        }while(next_permutation(ind.begin(), ind.end()));
    }
    return answer;
}
