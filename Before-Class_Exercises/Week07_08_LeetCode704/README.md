# LeetCode 704 - Binary Search

## Problem Description
給定一個 **升冪排序** 的整數陣列 `nums` 和一個目標值 `target`。
如果 `target` 存在於陣列中，請回傳它的索引（Index）；否則，請回傳 `-1`。

[Link to problem](https://leetcode.com/problems/binary-search/)

## Learning Objectives
- [x] 理解二分搜尋法 (Binary Search) 的分治思想 (Divide and Conquer)。
- [x] 掌握搜尋區間的閉區間寫法 (`left <= right`)。
- [x] 學習預防整數溢位 (Integer Overflow) 的 `mid` 計算方式。
- [x] 處理搜尋失敗時的回傳邏輯。



## Solution Approach

### Algorithm Logic
二分搜尋法透過不斷將搜尋範圍縮減一半，來達成極高的搜尋效率：

1. **初始化指針**：`left` 指向 0，`right` 指向 `nums.size() - 1`（閉區間 `[left, right]`）。
2. **中間值比較**：
   - 計算 `mid = left + (right - left) / 2`。
   - 若 `nums[mid] == target`，搜尋成功，回傳 `mid`。
   - 若 `nums[mid] > target`，代表目標在左半邊，縮減右邊界：`right = mid - 1`。
   - 若 `nums[mid] < target`，代表目標在右半邊，縮減左邊界：`left = mid + 1`。
3. **終止條件**：
   - 當 `left > right` 時，代表搜尋區間已空，目標不存在。
4. **回傳結果**：若跳出迴圈仍未找到，回傳 `-1`。



### Key Insights
* **防止溢位**：使用 `left + (right - left) / 2` 而非 `(left + right) / 2` 是為了避免當 `left` 與 `right` 皆極大時，相加結果超過 `int` 最大範圍。
* **閉區間 vs 半開區間**：本解法採用閉區間 `[left, right]`，因此迴圈條件必須包含等號 `left <= right`。



## 程式碼實作 (Code Structure)

```cpp
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
```



## Complexity Analysis
- **Time Complexity:** $O(\log n)$  
  每次比較後都會排除掉一半的資料量，搜尋時間隨資料量呈對數增長。
- **Space Complexity:** $O(1)$  
  僅使用常數個變數進行指標移動，不佔用額外記憶體。

---

## Notes & Reflection
- **先決條件**：使用二分搜尋的前提是陣列 **必須已經排序**。
- **錯誤地方**：忘記處理 `target` 不在陣列中的情況（漏掉 `return -1`），或在計算 `mid` 時未考慮溢位風險。

---

## References
- [LeetCode 704. Binary Search Official Page](https://leetcode.com/problems/binary-search/)