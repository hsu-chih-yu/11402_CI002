// Email: s1131456@mail.yzu.edu.tw
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // 使用 long long 防止與 INT_MIN 衝突
        long long maxnow = LLONG_MAX; 
        long long firstMax = LLONG_MIN;
        int count = 0;

        // 要找三次
        for (int i = 0; i < 3; i++) {
            long long currentMax = LLONG_MIN;
            bool found = false;

            // 在剩下的數字中找比上次最大值還要小的最大值
            for (int num : nums) {
                if (num < maxnow && num >= currentMax) {
                    currentMax = num;
                    found = true;
                }
            }

            if (found) {
                maxnow = currentMax;
                if (i == 0) firstMax = currentMax; // 紀錄真正的最大值
                count++;
            } else {
                break; // 如果找不到了，就提前結束
            }
        }

        // 若不足三個相異最大值，回傳最大的
        if (count < 3) {
            return (int)firstMax;
        }
        return (int)maxnow;
    }
};