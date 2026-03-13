# LeetCode 670 - Maximum Swap

## Problem Description
給定一個非負整數 `num`，你最多可以交換其中的兩個數位（Digits）一次，目標是獲得並回傳交換後能達到的最大數值。
[Link to problem](https://leetcode.com/problems/maximum-swap/)

## Learning Objectives
- [x] 練習將整數轉換為字串進行數位操作。
- [x] 理解貪心演算法：如何透過一次局部交換達到全域最大值。
- [x] 掌握在搜尋最大值時處理「最後出現位置」的技巧。



## Solution Approach

### Algorithm Logic
1. **型別轉換**：使用 `to_string(num)` 將整數轉換為字串 `s`，以便進行索引存取與數位交換。
2. **尋找交換點**：從左至右遍歷字串（索引 `i`）。
   - 對於每個位置 `i`，在它右側的所有數位中尋找最大值（索引 `max_idx`）。
   - **關鍵規則**：如果右側有數個相同的最大數位，應選擇**最後出現（最右邊）**的那一個。這能確保在交換後，較大的數字被換到高位，而較小的數字被換到儘可能低的位。
3. **執行交換**：
   - 如果在 `i` 的右側找到一個比 `s[i]` 還要大的數位，則將兩者交換。
   - 因為限制「最多交換一次」，完成交換後立即將字串轉回整數並回傳。
4. **回傳原值**：如果整個字串都符合由大到小的排列（無法透過交換變大），則回傳原始數字。

### Key Insights
* **優先權概念**：高位數（左邊）對數值的影響力最大。因此，我們優先檢查最左邊的數位是否能被換成更大的數字。
* **選擇最右側最大值**：例如 `1993`，若將 `1` 與第一個 `9` 交換得到 `9193`；若與第二個 `9` 交換得到 `9913`。顯然後者更大。



## 程式碼實作 (Code Structure)

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        // 將整數轉為字串方便處理各個數位
        string s = to_string(num);
        int len = s.length();
        
        // 從左至右掃描每一個數位 i
        for (int i = 0; i < len; i++) {
            int max_idx = i;
            
            // 在 i 的右側尋找最大的數位
            // 這裡採用從後往前掃描，能確保找到的是「最後出現」的最大值
            for (int j = len - 1; j > i; j--) {
                if (s[j] > s[max_idx]) {
                    max_idx = j;
                }
            }
            
            // 如果右側存在比目前 s[i] 更大的數位
            if (max_idx != i) {
                // 執行唯一一次的交換
                swap(s[i], s[max_idx]);
                
                // 交換後立即轉換回整數並結束函式
                return stoi(s);
            }
        }
        // 如果遍歷完都沒交換，代表原數字已是最大組合
        return num;
    }
};
```

## Complexity Analysis
- **Time Complexity:** $O(L^2)$  
  其中 $L$ 為數位的長度。由於整數範圍內 $L$ 最大僅為 9 或 10，雙層迴圈的執行次數極少，效能優異。
- **Space Complexity:** $O(L)$  
  需要額外的字串空間來儲存數位的字元表示。



## Notes & Reflection
- **容易出錯點**：
  - **最大值重複**：搜尋右側最大值時，必須包含「等於」的情況以鎖定最後一個出現的位置（或是像本程式碼由後往前掃描）。
  - **提早結束**：一旦完成一次交換，必須立刻 `return`，不可再進行後續交換。




## References
- [LeetCode 670. Maximum Swap Official Page](https://leetcode.com/problems/maximum-swap/)