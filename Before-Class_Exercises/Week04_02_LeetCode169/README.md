# LeetCode 169 - Majority Element

## Problem Description
給定一個大小為 $n$ 的陣列 `nums`，傳回其中的多數元素。多數元素是指在陣列中出現次數大於 $\lfloor n/2 \rfloor$ 的元素。你可以假設陣列是非空的，且給定的陣列總是存在多數元素。
[Link to problem](https://leetcode.com/problems/majority-element/)

## Learning Objectives
- [x] 理解 **Boyer-Moore Voting Algorithm** 的核心邏輯。
- [x] 練習使用 C++11 的 **Range-based for loop** 遍歷容器。
- [x] 學習如何在空間複雜度限制為 $O(1)$ 的情況下解決統計問題。



## Solution Approach

### Algorithm Logic
本解法採用「抵銷」的概念。因為多數元素出現的次數超過一半，如果我們讓不同的數字兩兩抵銷，最後剩下的那個數字一定就是多數元素。

1. **候選人初始化**：設定 `candidate`（目前候選人）和 `count`（計數器，初始為 0）。
2. **走訪陣列**：
   - 如果 `count` 為 0，表示之前的票數已經抵銷完畢，則將當前數字 `num` 設為新的 `candidate`。
   - 接下來比較 `num` 與 `candidate`：
     - 若相同，`count` 加 1（代表支持票）。
     - 若不同，`count` 減 1（代表反對票，兩者抵銷）。
3. **得出結果**：迴圈結束後，剩下的 `candidate` 即為出現次數過半的數字。

### Key Insights
* **空間優勢**：當輸入的數值範圍極大（例如 $\pm 10^9$）時，使用陣列計數會導致記憶體崩潰。投票演算法不需要儲存所有數字的出現次數，只需紀錄一個候選人與其淨票數，因此非常省空間。
* **適用條件**：此演算法僅在「確定存在一個出現次數 > n/2 的元素」時保證正確。



## 程式碼實作 (Code Structure)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 使用 Boyer-Moore Voting Algorithm
        int candidate = 0; // 儲存目前的候選數字
        int count = 0;     // 儲存候選人的淨票數 (支持票 - 反對票)

        // 使用 Range-based for loop 遍歷所有數字
        for(int num : nums){
            // 如果目前的票數抵銷完了，就換一個人當候選人
            if(count == 0){
                candidate = num;
            }
            // 進行投票邏輯
            if(num == candidate){
                // 如果目前的數字等於候選人，票數加 1
                count++;
            } else {
                // 如果不同，則與候選人抵銷，票數減 1
                count--;
            }
        }
        // 題目保證一定存在多數元素，故最後留下的 candidate 必為答案
        return candidate;
    }
};
```



## Complexity Analysis
- **Time Complexity:** $O(n)$  
  只需要遍歷陣列一次，時間與陣列長度成正比。
- **Space Complexity:** $O(1)$  
  僅使用兩個變數（`candidate` 和 `count`），與輸入規模無關。



## Notes & Reflection
- **容易出錯點**：
  - **計數器檢查順序**：必須先檢查 `count == 0` 來決定是否更換候選人，再進行票數加減。
  - **範圍基礎迴圈**：使用 `for(int num : nums)` 既安全又簡潔，不需要擔心索引 `i` 越界。
- **心得**：學習到了這個演算法，將原本需要 $O(n)$ 空間的統計問題，簡化到了 $O(1)$。



## References
- [LeetCode 169. Majority Element Official Page](https://leetcode.com/problems/majority-element/)
