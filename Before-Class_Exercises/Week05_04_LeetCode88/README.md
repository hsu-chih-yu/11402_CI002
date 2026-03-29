# LeetCode 88 - Merge Sorted Array

## Problem Description
給兩個按 **非遞減順序** 排列的整數陣列 `nums1` 和 `nums2`，以及兩個整數 `m` 和 `n`，分別表示兩個陣列中的有效元素數量。
請你將 `nums2` 合併到 `nums1` 中，使合併後的陣列同樣按 **非遞減順序** 排列。

[Link to problem](https://leetcode.com/problems/largest-number/)

## Learning Objectives
- [x] 練習使用 `vector` 的 `push_back` 進行資料遷移。
- [x] 實作基礎排序演算法：選擇排序 (Selection Sort)。
- [x] 理解如何尋找陣列中的最小值及其索引 (min & position)。
- [x] 處理 `vector` 的賦值與覆蓋操作。


## Solution Approach

### Algorithm Logic
本解法採用「先合併後排序」的直覺策略：
1. **資料收集**：
   - 建立一個暫存的 `vector<int> ans`。
   - 將 `nums1` 的前 $m$ 個有效數字推入 `ans`。
   - 將 `nums2` 的前 $n$ 個數字推入 `ans`。
2. **選擇排序 (Selection Sort)**：
   - 使用兩層迴圈：外層 `i` 決定當前要放置最小值的格子。
   - 內層 `j` 從 `i` 往後找，搜尋整個剩餘區間中的最小值並記錄其位置 `pos`。
   - 找到後，將 `ans[i]` 與 `ans[pos]` 進行交換 (Swap)。
3. **回填結果**：
   - 將排序完成的 `ans` 向量直接賦值給 `nums1`，完成原地 (In-place) 修改。

### Key Insights
* **排序的本質**：雖然這題可以利用「雙指標」達成更高效的合併，但透過「選擇排序」能幫助我們複習基礎演算法中「穩定尋找極值」並進行「元素交換」的觀念。



## 程式碼實作 (Code Structure)

```cpp
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
```

## Complexity Analysis
- **Time Complexity:** $O((m+n)^2)$  
  選擇排序法包含兩層巢狀迴圈，對於長度為 $L$ 的陣列，比較次數約為 $L^2 / 2$ 次。
- **Space Complexity:** $O(m + n)$  
  建立了一個額外的向量 `ans` 來儲存合併後的元素。



## Notes & Reflection
- **邏輯嚴謹性**：在實作選擇排序時，`pos` 的初始值必須設定為 `i`，以防止在當前位置就是最小值的情況下發生錯誤。
- **改進思考**：
  - 選擇排序在數據量大時效率較低，後續可嘗試直接呼叫 `sort(ans.begin(), ans.end())`。
  - 最優解法其實是利用「由後往前填入」的雙指標法，空間複雜度可降至 $O(1)$。

---

## References
- [LeetCode 88. Merge Sorted Array Official Page](https://leetcode.com/problems/merge-sorted-array/)