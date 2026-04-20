// Email: s1131456@mail.yzu.edu.tw
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();

        int right = 0, left = 0;

        // 初始化：計算除了第一個元素以外的所有右側總和
        for(int i = 1; i < len; i++){
            right += nums[i];
        }

        // 遍歷每一個可能的中心索引
        for(int i = 0; i < len; i++){
            // 判斷左側是否等於右側
            if(left == right){
                return i;
            }

            // 動態更新：準備將中心點往右移一位
            left += nums[i]; // 當前點變為左側的一部分
            
            if(i < len - 1) {
                right -= nums[i + 1]; // 下一個點從右側總和中移出
            }
        }

        return -1;
    }
};