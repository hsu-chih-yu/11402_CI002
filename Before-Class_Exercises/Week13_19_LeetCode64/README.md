# LeetCode 64 - Minimum Path Sum

## 題目描述
給定一個包含非負整數的 $m \times n$ 網格 `grid`，請走出一條從左上角到右下角的路徑，使得路徑上的數字總和為最小。
**說明：** 每次只能向下或向右移動一步。

[題目連結](https://leetcode.com/problems/minimum-path-sum/)

## 學習重點
- [x] 掌握 **動態規劃 (Dynamic Programming)** 的基本轉移方程。
- [x] 練習處理矩陣的 **邊界條件**（第一列與第一行）。
- [x] 學習 **空間優化**：利用原始矩陣進行原地更新，節省額外空間。

---

## 解法思路：動態規劃

### 1. 狀態定義
令 `dp[i][j]` 為抵達座標 $(i, j)$ 的最小路徑和。

### 2. 轉移方程
由於只能向右或向下移動，抵達 $(i, j)$ 的路徑只可能來自上方 $(i-1, j)$ 或左方 $(i, j-1)$：
$$dp[i][j] = grid[i][j] + \min(dp[i-1][j], dp[i][j-1])$$

### 3. 邊界初始化
- **起點**：`grid[0][0]` 保持不變。
- **第一列 (Top Row)**：只能從左邊走過來，因此 `grid[0][j] += grid[0][j-1]`。
- **第一行 (Left Column)**：只能從上面走下來，因此 `grid[i][0] += grid[i-1][0]`。

### 4. 填表順序
從左上角往右下角逐一計算。

## Code Structure
```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. 初始化第一列（只能從左邊來）
        for(int j = 1; j < n; j++){
            grid[0][j] += grid[0][j-1];
        }

        // 2. 初始化第一行（只能從上面來）
        for(int i = 1; i < m; i++){
            grid[i][0] += grid[i - 1][0];
        }

        // 3. 填充剩餘格子的 DP 值
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                // 抵達 (i, j) 的成本 = 當前值 + min(上方來源, 左方來源)
                grid[i][j] += min(grid[i - 1][j], grid[i][j-1]);
            }
        }

        // 4. 右下角即為最終解答
        return grid[m - 1][n - 1];
    }
};
```

## 複雜度分析
- **時間複雜度**: $O(M \times N)$，需遍歷整個矩陣一次。
- **空間複雜度**: $O(1)$，直接修改輸入的 `grid` 矩陣，未開啟額外空間。

---

## 筆記與心得
- **原地修改 (In-place)**：在面試或考試中，若題目允許修改輸入數據，原地更新是展現空間優化意識的好機會。
- **防止溢位**：雖然這題規定是非負整數，但在處理類似問題（如有負數或需要求路徑數）時，要注意整數溢位問題。