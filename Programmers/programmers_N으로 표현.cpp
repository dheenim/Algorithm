#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#include <iostream>
using namespace std;

set<int> nums[8];

int solution(int N, int number) {
    int answer = -1;
    if(N==number) return 1;
    nums[0].insert(N);
    
    string strN = to_string(N);
    string str = strN;
    for(int i=1; i<8; i++){
        str+=strN;
        int num = stoi(str);
        if(num==number && answer == -1) answer = i+1;
        nums[i].insert(num);
    }
    for(int i=1;i<8;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<i;k++){
                if(j+k+1 != i) continue;
                for(auto jNum=nums[j].begin(); jNum!=nums[j].end(); jNum++){
                    for(auto kNum=nums[k].begin(); kNum!=nums[k].end(); kNum++){
                        int newNum = (*jNum) + (*kNum);
                        if(newNum==number && (answer==-1 ||answer > i)){
                            return i+1;
                        }
                        if(newNum > 0) nums[i].insert(newNum);
                        
                        newNum = (*jNum) - (*kNum);
                        if(newNum==number && (answer==-1 ||answer > i)){
                            return i+1;
                        }
                        if(newNum > 0) nums[i].insert(newNum);
                        
                        newNum = (*jNum) * (*kNum);
                        if(newNum==number && (answer==-1 ||answer > i)){
                            return i+1;
                        }
                        if(newNum > 0) nums[i].insert(newNum);
                        
                        if((*kNum)!=0){
                        newNum = (*jNum) / (*kNum);
                            if(newNum==number && (answer==-1 ||answer > i)){
                                return i+1;
                            }
                            if(newNum > 0) nums[i].insert(newNum);
                        }
                    }
                }
            }
        }
        /*cout<<"i:"<<i<<endl;
        for(auto it=nums[i].begin();it!=nums[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<"\n\n";*/
    }
    return answer;
}
