# LeetCode 231. Power of Two

## Problem Description
給定一個整數 $n$，若 $n$ 是 2 的冪次方（即存在整數 $x$ 使得 $n = 2^x$），則回傳 `true`；否則回傳 `false`。[Link to problem](https://leetcode.com/problems/power-of-two/)

## Learning Objectives
- [x] 練習基本迴圈與條件判斷的邏輯處理。
- [x] 理解如何處理邊界條件（如負數或零的特殊情況）。
- [x] 建立數值拆解的概念（重複除以固定基數）。



## Solution Approach

### Algorithm Logic
1. **排除非正整數**：2 的冪次方（$2^x$）結果必定是大於 0 的正整數。因此，若輸入的 $n < 1$，直接回傳 `false`。
2. **重複除以 2**：
   - 使用 `while` 迴圈，當 $n > 1$ 時持續執行。
   - 在每一輪中，檢查 $n$ 是否能被 2 整除（`n % 2 == 0`）。
   - 若可以整除，則將 $n$ 除以 2，進入下一輪檢查。
   - 若在過程中發現不能被 2 整除，代表該數含有 2 以外的質因數，回傳 `false`。
3. **判定結果**：若迴圈順利結束且 $n$ 最終等於 1，代表它是 2 的冪次方，回傳 `true`。

### Key Insights
* **2 的冪次方特性**：在二進位表示法中，2 的冪次方只有一個位元是 `1`（例如：$4 = 100_2, 8 = 1000_2$）。
* **進階思考**：此題亦可使用位元運算 `(n > 0) && ((n & (n - 1)) == 0)` 在 $O(1)$ 時間內完成判斷。



## 程式碼實作 (Code Structure)

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 1. 2 的冪次方必定是正整數，若為負數或 0 則回傳 false
        if (n < 1) return false;

        // 2. 持續檢查 n 是否能被 2 整除，直到 n 變為 1
        while (n > 1) {
            if (n % 2 == 0) {
                // 如果是偶數，就除以 2 繼續檢查下一位
                n /= 2;
            } else {
                // 一旦出現奇數（且不為 1），代表不是 2 的冪次方
                return false;
            }
        }

        // 3. 若能一路除到 1，則代表它是 2 的冪次方
        return true;
    }
};
```

## Complexity Analysis
- **Time Complexity:** $O(\log n)$  
  每次迴圈都會將 $n$ 除以 2，因此迴圈執行的次數與 $n$ 在二進位下的位數成正比，即為對數時間複雜度。
- **Space Complexity:** $O(1)$  
  僅使用固定數量的變數（常數空間），空間使用量不會隨著輸入數值 $n$ 的增加而改變。

---

## Notes & Reflection
- **容易出錯點**：
  - **$n \le 0$ 的處理**：如果忘記判斷負數或零，可能會導致邏輯錯誤。特別是在位元運算解法中，負數的補數表示法可能會產生誤判。




## References
- [LeetCode 231. Power of Two Official Page](https://leetcode.com/problems/power-of-two/)
