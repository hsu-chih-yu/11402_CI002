# LeetCode 48 - Rotate Image

## Problem Description
給定一個 $n \times n$ 的二維矩陣 `matrix`，請將其順時針旋轉 90 度。你必須在「原地」修改輸入的矩陣，這意味著你不應該額外分配另一個二維矩陣來完成旋轉（雖然初學者可先從使用額外空間開始練習）。
[Link to problem](https://leetcode.com/problems/rotate-image/)

## Learning Objectives
- [x] 掌握二維矩陣的座標變換邏輯。
- [x] 練習二維 `vector` 的複製與賦值。
- [x] 理解順時針旋轉的規律：原本的列（Row）會變成旋轉後的行。



## Solution Approach

### Algorithm Logic 
1. **備份矩陣**：利用 `vector` 的特性，直接透過 `copy = matrix` 複製一份完整的原始資料。
2. **座標映射**：觀察旋轉 90 度後的規律。
   - 原始矩陣的第一列，旋轉後變成最後一行。
   - 原始矩陣的最後一列，旋轉後變成第一行。
   - 規律公式：`matrix[j][n - 1 - i] = copy[i][j]`。
3. **覆寫回原矩陣**：利用雙層迴圈，根據映射規則將 `copy` 的數值填入 `matrix`。

### Key Insights
* **逗號運算子陷阱**：在 `for` 迴圈的條件判斷中，例如 `i >= 0, k < row`，C++ 只會以「最後一個」表達式的結果作為判斷基準。為了保證安全，建議使用 `&&` 邏輯運算子。




## 程式碼實作 (Code Structure)

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // 複製原始矩陣 (利用 vector 的賦值運算子進行深拷貝)
        vector<vector<int>> copy = matrix;
        
        // 進行座標轉換
        // 規則：旋轉 90 度後，原本位於 [i][j] 的元素會跑到 [j][n - 1 - i]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 將 copy 中的舊值填入 matrix 的新位置
                // 原始的第一列 (i=0) 會填入最後一行 (Column = n-1)
                matrix[j][n - 1 - i] = copy[i][j];
            }
        }
    }
};
```


## Complexity Analysis
- **Time Complexity:** $O(n^2)$  
  其中 $n$ 為矩陣的邊長。我們需要遍歷矩陣中的每一個元素兩次（一次複製，一次填值）。
- **Space Complexity:** $O(n^2)$  
  因為建立了一個與原矩陣大小相同的 `copy` 矩陣。


## Notes & Reflection
- **容易出錯點**：
  - **迴圈邊界**：旋轉時索引容易算錯，建議在紙上畫一個 $3 \times 3$ 矩陣來推導座標。
  - **原地修改**：若題目嚴格要求 $O(1)$ 空間，則不能使用 `vector copy = matrix`。




## References
- [LeetCode 48. Rotate Image Official Page](https://leetcode.com/problems/rotate-image/)