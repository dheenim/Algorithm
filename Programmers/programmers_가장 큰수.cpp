#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    return a+b>b+a;
}


string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for(int i=0;i<numbers.size();i++)
        nums.push_back(to_string(numbers[i]));
    sort(nums.begin(), nums.end(), cmp);
    if(nums[0].find("0")==0) return "0";
    for(int i=0;i<nums.size();i++){
        answer+=nums[i];
    }
    
    return answer;
}
