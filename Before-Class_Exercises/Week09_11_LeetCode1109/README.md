# LeetCode 1109 - Corporate Flight Bookings

## 題目描述
這裡有 `n` 個航班，編號從 `1` 到 `n`。
給你一個預訂紀錄列表 `bookings`，其中 `bookings[i] = [first, last, seats]`，代表從航班 `first` 到 `last`（包含兩端）的每個航班都預訂了 `seats` 個座位。

請回傳一個長度為 `n` 的陣列，表示每個航班總共預訂的座位數。

[Link to problem](https://leetcode.com/problems/corporate-flight-bookings/)

## 學習重點
- [x] 理解 **差分陣列 (Difference Array)** 的核心原理。
- [x] 掌握區間修改優化：將 $O(N)$ 的區間加值轉化為 $O(1)$ 的端點修改。
- [x] 練習透過 **前綴和 (Prefix Sum)** 還原差分陣列。
- [x] 處理 1-based 索引與 0-based 索引的轉換。



## Solution Approach

### Algorithm Logic: Difference Array (差分陣列)
如果直接對每個預訂區間進行遍歷加值，最壞情況下的複雜度會達到 $O(Bookings \times N)$。使用差分陣列可以極大優化效能：

1. **建立差分陣列 (`diff`)**：
   - 建立一個大小為 `n + 2` 的陣列（多預留空間以防止 `last + 1` 越界）。
2. **區間操作轉換**：
   - 對於每個預訂 `[i, j, k]`：
     - 在 `diff[i]` 加上 `k`（表示從 `i` 開始之後的元素都增加了 `k`）。
     - 在 `diff[j + 1]` 減去 `k`（表示從 `j + 1` 開始之後的元素抵銷掉剛才增加的 `k`）。
3. **還原結果**：
   - 遍歷 `diff` 陣列並累加前綴和。
   - `curr_sum[i] = curr_sum[i-1] + diff[i]`。
   - 將計算結果填入回傳陣列 `ans`。

## 程式碼實作 (Code Structure)
```cpp
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
```

## Complexity Analysis
- **Time Complexity:** $O(N + \text{Bookings})$  
  只需要遍歷一次預訂列表進行端點修改，最後遍歷一次航班總數還原結果。
- **Space Complexity:** $O(N)$  
  需要一個額外的差分陣列來存儲變化量。

---

## Notes & Reflection
- **適用場景**：當題目涉及「頻繁的區間修改」但「極少或最後才進行單點查詢」時，差分陣列是首選。
- **邊界細節**：由於航班編號是 1 到 n，使用大小為 `n + 2` 的 `diff` 陣列可以讓我們直接用編號當索引，寫法更直覺且安全。