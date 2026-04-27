// Email: s1131456@mail.yzu.edu.tw
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 建立一個差分陣列，多給空間方便處理 last + 1 的情況
        // diff[i] 代表第 i 個航班與第 i-1 個航班的座位差值
        vector<int> diff(n + 2, 0); 
        
        // 處理所有區間加值請求
        for (auto& b : bookings) {
            int first = b[0];
            int last = b[1];
            int seats = b[2];
            
            diff[first] += seats;       // 起點增加：從此處開始往後都加 seats
            diff[last + 1] -= seats;    // 終點隔位減少：從此處開始往後抵銷掉 seats
        }
        
        // 透過前綴和還原差分陣列為原始數據
        vector<int> ans(n);
        int curr = 0;
        for (int i = 1; i <= n; i++) {
            curr += diff[i];
            ans[i - 1] = curr; // 題目要求回傳 0-indexed 的陣列
        }
        
        return ans;
    }
};