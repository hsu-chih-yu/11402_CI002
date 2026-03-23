// Email: s1131456@email.yzu.edu.tw
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        
        // 將兩個陣列的有效元素放入暫存向量 ans
        for(int i = 0; i < m; i++){
            ans.push_back(nums1[i]);
        }
        for(int i = 0; i < n; i++){
            ans.push_back(nums2[i]);
        }

        // 使用選擇排序法對合併後的陣列進行排序
        int length = m + n;
        for(int i = 0; i < length - 1; i++){
            int minVal = ans[i];
            int pos = i;
            
            for(int j = i + 1; j < length; j++){
                if(ans[j] < minVal){
                    minVal = ans[j];
                    pos = j;
                }
            }
            
            // 交換元素位置
            int temp = ans[i];
            ans[i] = ans[pos];
            ans[pos] = temp;
        }

        // 將最終結果複製回 nums1
        nums1 = ans;
    }
};