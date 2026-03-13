# LeetCode 326 - Power of Three

## Problem Description
給定一個整數 $n$，若 $n$ 是 3 的冪次方（即存在整數 $x$ 使得 $n = 3^x$），則回傳 `true`；否則回傳 `false`。
[Link to problem](https://leetcode.com/problems/power-of-three/)

## Learning Objectives
- [x] 練習使用迴圈處理數值的連續除法。
- [x] 理解冪次方的數學特性與判斷邏輯。
- [x] 強化對邊界條件（如負數與零）的處理能力。



## Solution Approach

### Algorithm Logic
1. **排除非正整數**：3 的任何整數次方都不可能小於或等於 0，因此若 $n \le 0$，直接回傳 `false`。
2. **連續除以 3**：
   - 使用 `while` 迴圈，條件是當 $n$ 能被 3 整除時（`n % 3 == 0`）。
   - 在迴圈內，不斷將 $n$ 除以 3。
3. **最終判定**：
   - 當迴圈結束（$n$ 不再能被 3 整除）時，檢查 $n$ 是否等於 1。
   - 若等於 1，代表原本的數字完全由 3 的連乘組成，回傳 `true`。
   - 若不等於 1，則回傳 `false`。

### Key Insights
* **基數特性**：與 2 的冪次方不同，3 是奇數，因此無法簡單地透過位元運算來判斷。
* **數學解法（進階）**：由於 $n$ 是整數且有最大值（$2^{31}-1$），在該範圍內 3 的最大冪次方是 $3^{19} = 1,162,261,467$。若 $3^{19} \% n == 0$，則 $n$ 必為 3 的冪次方。這可以達成 $O(1)$ 的效率。





## 程式碼實作 (Code Structure)

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1. 處理邊界條件：3 的冪次方必定是正整數
        if (n <= 0) {
            return false;
        }

        // 2. 當 n 能被 3 整除時，持續縮小 n
        while (n % 3 == 0) {
            n /= 3;
        }

        // 3. 檢查最後剩下的值是否為 1
        // 若 n 原本是 3 的冪次方，最後一定會除到剩下 1
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};
```



## Complexity Analysis
- **Time Complexity:** $O(\log_3 n)$  
  每次迴圈都會將 $n$ 除以 3，迴圈次數與 $n$ 的 3 進位位數成正比。
- **Space Complexity:** $O(1)$  
  僅使用常數空間，不隨輸入規模增加。



## Notes & Reflection
- **容易出錯點**：
  - **忽略 0 或負數**：若未在開頭排除 $n \le 0$，可能會進入邏輯錯誤或死迴圈（雖然這題除以 3 會收斂，但判斷會出錯）。
  - **邏輯簡化**：最後的 `if-else` 判斷也可以簡寫為 `return n == 1;`。



## References
- [LeetCode 326. Power of Three Official Page](https://leetcode.com/problems/power-of-three/)