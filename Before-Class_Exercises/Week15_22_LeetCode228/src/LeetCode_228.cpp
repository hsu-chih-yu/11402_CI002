// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        
        for(int i = 0; i < n; i++){
            // 1. 記錄區間的起點
            int start = nums[i];

            // 2. 當下一個數字與當前數字連續時，不斷往後推進指標
            // 注意：這裡直接使用 nums[i] + 1 可能會有 INT_MAX 溢位風險，
            // 若遇極端測資，可改為 (long)nums[i] + 1 == nums[i+1]
            while(i + 1 < n && nums[i] + 1 == nums[i+1]){
                i++;
            }

            // 3. 根據區間內包含的數字數量，格式化並加入解答陣列
            if(start == nums[i]){
                // 只有單一數字
                ans.push_back(to_string(start));
            } else {
                // 包含連續數字區間
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        
        return ans;
    }
};