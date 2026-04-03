# LeetCode 74 - Search a 2D Matrix

## 題目描述
給你一個 $m \times n$ 的整數矩陣 `matrix`，具備以下特性：
1. 每列中的整數從左到右按 **升冪順序** 排序。
2. 每列的第一個整數大於前一列的最後一個整數。

請判斷目標值 `target` 是否在矩陣中。

[題目連結](https://leetcode.com/problems/search-a-2d-matrix/)

## 學習目標
- [x] 掌握 2D `vector` 的基本維度獲取（Row 與 Column）。
- [x] 實作 **剪枝 (Pruning)** 策略：利用列首元素快速排除無效搜尋範圍。
- [x] 練習嵌套迴圈的邊界控制與反向遍歷。

---

## 解法思路：列剪枝線性搜尋
本解法利用了矩陣「每行首位元素」的有序性來進行優化搜尋：

1. **維度計算**：
   - 使用 `matrix.size()` 取得總列數。
   - 使用 `matrix[0].size()` 取得每列的長度（欄數）。
2. **反向列篩選**：
   - 從矩陣的 **最後一列** 開始向上遍歷。
3. **剪枝邏輯 (Row Pruning)**：
   - **核心判斷**：`if(matrix[i][0] > target)`。
   - 因為每一列的首位都是該列最小的數，如果首位就比目標大，代表整列都不可能存在目標，直接跳過該列。
4. **細部搜尋**：
   - 一旦鎖定可能包含目標的列，則進入內層迴圈進行線性搜尋。



## 程式碼實作 (Code Structure)
```cpp
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 取得矩陣的欄數與列數
        int len = matrix[0].size();
        int row = matrix.size();

        // 從最後一列開始向上遍歷
        for (int i = row - 1; i >= 0; i--) {
            // 如果該列第一個數字就大於target，則整列都不可能包含目標
            if (matrix[i][0] > target) {
                continue;
            }
            
            // 在鎖定的列中進行線性搜尋
            for (int j = 0; j < len; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        // 未找到回傳 false
        return false;
    }
};

```

## 複雜度分析
- **時間複雜度**: $O(M \times N)$
  雖然加入了列剪枝邏輯，但在最壞情況下仍接近線性複雜度。這是一個從暴力法進化到二分搜尋法的過渡邏輯。
- **空間複雜度**: $O(1)$
  僅使用常數個變數，不佔用額外記憶體空間。

---

## 課後反思
- **優化潛力**：目前的內層搜尋是線性的。在 Week 7 的學習中，我們可以進階將整張矩陣視為「一維有序陣列」，並將複雜度優化至 $O(\log(M \times N))$。
- **邊界處理**：在處理 2D vector 時，習慣先檢查 `matrix.empty()` 是一種更安全的程式風格。