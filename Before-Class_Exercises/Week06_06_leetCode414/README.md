# LeetCode 414 - Third Maximum Number

## Problem Description
給你一個整數陣列 `nums`，傳回其中 **第三大** 的 **相異 (Distinct)** 數字。如果不存在第三大的數字，則傳回該陣列中 **最大** 的數字。

[Link to problem](https://leetcode.com/problems/third-maximum-number/)

## Learning Objectives
- [x] 練習使用 `long long` 極值 (`LLONG_MIN` / `LLONG_MAX`) 處理邊界條件。
- [x] 掌握排除法邏輯：透過多次迭代尋找特定的位次極值。
- [x] 應用 C++20 `std::erase` 或等價邏輯來處理重複元素。
- [x] 處理特殊邏輯：當相異元素不足三個時的回傳機制。



## Solution Approach

### Algorithm Logic: Iterative Elimination
本解法採用「逐次尋找並排除」的策略，這在尋找前 $K$ 個極值且 $K$ 較小時非常直覺：

1. **環境初始化**：
   - 使用 `long long` 型別的 `maxnow` 記錄上一次找到的最大值，初始設為 `LLONG_MAX`。
   - `maxi` 用於記錄全域最大值（當不足三個相異值時使用）。
2. **三輪迭代**：
   - 進行三次迴圈，每一輪尋找比 `maxnow` 小的最大值。
   - **第一輪**：找到陣列中真正的最大值。
   - **第二輪**：排除第一大的數字後，找到第二大的相異數字。
   - **第三輪**：排除前兩大的數字後，找到第三大的相異數字。
3. **動態清理**：
   - 每一輪找到最大值後，使用 `std::erase` 將陣列中所有等於該值的元素移除，確保下一輪找到的是「相異」的較小最大值。
4. **結果判斷**：
   - 使用計數器 `count` 追蹤成功找到幾次相異最大值。
   - 若 `count` 達到 3，回傳最後找到的 `maxnow`。
   - 若不足 3，則回傳第一輪存下的 `maxi`。



## 程式碼實作 (Code Structure)

```cpp
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // 使用 long long 防止與 INT_MIN 衝突
        long long maxnow = LLONG_MAX; 
        long long firstMax = LLONG_MIN;
        int count = 0;

        // 要找三次
        for (int i = 0; i < 3; i++) {
            long long currentMax = LLONG_MIN;
            bool found = false;

            // 在剩下的數字中找比上次最大值還要小的最大值
            for (int num : nums) {
                if (num < maxnow && num >= currentMax) {
                    currentMax = num;
                    found = true;
                }
            }

            if (found) {
                maxnow = currentMax;
                if (i == 0) firstMax = currentMax; // 紀錄真正的最大值
                count++;
            } else {
                break; // 如果找不到了，就提前結束
            }
        }

        // 若不足三個相異最大值，回傳最大的
        if (count < 3) {
            return (int)firstMax;
        }
        return (int)maxnow;
    }
};
```



## Complexity Analysis
- **Time Complexity:** $O(N)$  
  我們固定執行三輪迴圈，每輪包含一次遍歷尋找 ($O(N)$) 與一次刪除操作 ($O(N)$)。總複雜度為 $3 \times O(2N) = O(N)$。
- **Space Complexity:** $O(1)$  
  若原地修改 `nums` 則為 $O(1)$。若不希望破壞原陣列，則需 $O(N)$ 空間備份。



## Notes & Reflection
- **極值的陷阱**：題目中的數字範圍可能包含 `INT_MIN`。如果使用 `int` 來初始化最大值，會無法區分「初始值」與「陣列中的實質內容」。使用 `long long` 配合 `LLONG_MIN` 完美避開了這個問題。
- **相異值的定義**：透過 `std::erase` 刪除所有重複項，確保了處理的是「Distinct Maximums」。



## References
- [LeetCode 414. Third Maximum Number Official Page](https://leetcode.com/problems/third-maximum-number/)