# UVa 12149 - Feynman

## Problem Description
理查·費曼（Richard Feynman）曾提出一個問題：在一個由 $n \times n$ 個小方格組成的網格中，總共包含多少個不同大小的正方形？例如，$1 \times 1$ 的網格有 1 個正方形，$2 \times 2$ 的網格則有 5 個（4 個 $1 \times 1$ 與 1 個 $2 \times 2$）。
[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3301)

## Learning Objectives
- [x] 練習將幾何規律轉化為數學公式。
- [x] 掌握平方和的計算邏輯。
- [x] 練習處理以 0 作為結束標誌的多組輸入。


## Solution Approach

### Algorithm Logic
1. **觀察規律**：
   - 在 $n \times n$ 的網格中：
     - 邊長為 1 的正方形有 $n^2$ 個。
     - 邊長為 2 的正方形有 $(n-1)^2$ 個。
     - ...
     - 邊長為 $n$ 的正方形有 $1^2$ 個。
2. **公式總結**：總正方形數等於 $\sum_{i=1}^{n} i^2 = 1^2 + 2^2 + 3^2 + ... + n^2$。
3. **實作方式**：
   - 讀入 $n$ 直到 $n=0$ 為止。
   - 使用迴圈從 1 迭代到 $n$，計算每個數字的平方並累加至 `sum`。
   - 輸出最終的 `sum`。

### Key Insights
* **幾何概念**：在一個 $n \times n$ 網格中，放置一個 $k \times k$ 正方形時，其左上角可以在寬度方向移動 $n-k+1$ 個位置，高度方向亦同。因此，$k \times k$ 的正方形總數為 $(n-k+1)^2$。
* **數學公式**：雖然本題使用迴圈即可過關，但此問題亦可用平方和公式 $S = \frac{n(n+1)(2n+1)}{6}$ 在 $O(1)$ 時間內算出結果。



## 程式碼實作 (Code Structure)

```cpp
#include <iostream>

using namespace std;

int main() {
    int n;
    // 1. 讀取輸入 n，當 n 不等於 0 時持續執行
    while (cin >> n && n != 0) {
        int sum = 0; // 用於儲存正方形總數

        // 2. 利用迴圈計算從 1^2 到 n^2 的累加和
        for (int i = 1; i <= n; i++) {
            // 計算邊長為 i 的正方形在 n*n 網格中出現的次數
            // 例如當 i=1 時，代表計算 n*n 個 1x1 正方形
            int left = n - i;
            int row = 1 + left; // 每一列可放置的正方形數量
            
            sum += row * row;   // 累加該大小的正方形總數 (數量 = row 的平方)
        }
        
        // 3. 輸出該 n 網格的總正方形數
        cout << sum << endl;
    }
    return 0;
}
```


## Complexity Analysis
- **Time Complexity:** $O(N)$  
  對於每個測試案例，程式會執行一次長度為 $n$ 的迴圈來累加平方值。
- **Space Complexity:** $O(1)$  
  僅使用常數空間儲存 `sum` 與 `n`，不隨輸入規模增加記憶體開銷。



## Notes & Reflection
- **容易出錯點**：
  - **資料型態**：雖然 $n \le 100$ 時 $n^2$ 的總和不會超過 `int` 的範圍（約 338,350），但養成檢查數值上限的習慣很重要。
  - **迴圈範圍**：確保迴圈從 1 正確執行到 $n$。
- **心得**：一開始看到題目沒有發現可以用平方和公式，就一個一個算可以放下幾個方形。

---

## References
- [UVa Online Judge - 12149 Official Page](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3301)