#include <string>
#include <vector>
using namespace std;

int solution(vector<int> stones, int k) {
    //int answer = 2100000000;
    int low = 1;
    int high = 200000000;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] - mid < 0) {
                cnt++;
                if (cnt == k) {
                    flag = true;
                    break;
                }
            }
            else {
                cnt = 0;
            }
        }
        if (flag) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return high;
}