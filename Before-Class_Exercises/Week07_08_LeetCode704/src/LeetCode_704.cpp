// Email: s1131456@mail.yzu.edu.tw
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // 找到目標，直接回傳索引
            } 
            else if (nums[mid] > target) {
                // 目標在左半部，調整右邊界
                right = mid - 1;
            } 
            else {
                // 目標在右半部，調整左邊界
                left = mid + 1;
            }
        }

        // 若未找到回傳 -1
        return -1;
    }
};