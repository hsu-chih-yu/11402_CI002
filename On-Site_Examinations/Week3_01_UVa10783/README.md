# UVa 10783 - Odd Sum

## Problem Description
給定一個整數區間 $[a, b]$，要求計算並輸出該區間內所有奇數的總和。每一組測試資料都需要按照 `Case X: Sum` 的格式進行輸出。
[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1724)

## Learning Objectives
- [x] 練習使用巢狀迴圈處理多組測試資料。
- [x] 掌握基礎的條件判斷（奇數判定：`i % 2 != 0`）。
- [x] 熟悉格式化輸出要求（特定的 `Case X:` 前綴）。



## Solution Approach

### Algorithm Logic
1. **讀取測資數量**：首先讀入一個整數 `cases`，代表接下來會有幾組區間需要計算。
2. **處理每一組 Case**：
   - 使用 `for` 迴圈跑 `cases` 次，並紀錄當前是第幾組。
   - 讀入區間的起點 `a` 與終點 `b`。
   - 初始化總和變數 `sum = 0`。
3. **區間累加**：
   - 遍歷從 `a` 到 `b` 的每一個整數（包含端點）。
   - 利用取餘數運算子 `%` 判斷當前整數是否為奇數（`i % 2 != 0`）。
   - 若為奇數，則累加至 `sum`。
4. **格式化輸出**：依照題目要求的 `Case j: sum` 格式印出結果並換行。

### Key Insights
* **區間包含性**：題目要求的是閉區間 $[a, b]$，因此迴圈的範圍必須包含 `a` 與 `b`。
* **奇數判定**：使用 `i % 2 != 0` 來判定奇數，這在處理包含負數的系統中比 `i % 2 == 1` 更為穩健。



## 程式碼實作 (Code Structure)

```cpp
#include <iostream>

using namespace std;

int main() {
    int cases;
    // 讀取總共有幾組測試資料
    if (!(cin >> cases)) return 0;

    // 利用迴圈處理每一組案例，j 用來紀錄目前的案例編號
    for (int j = 1; j <= cases; j++) {
        int a, b, sum = 0;
        
        // 讀取區間範圍
        cin >> a >> b;

        // 遍歷區間內的所有數字並判斷奇偶
        for (int i = a; i <= b; i++) {
            // 如果 i 除以 2 的餘數不為 0，則 i 是奇數
            if (i % 2 != 0) {
                sum += i; // 累加奇數
            }
        }
        
        // 依照格式輸出
        cout << "Case " << j << ": " << sum << endl;
    }

    return 0;
}
```



## Complexity Analysis
- **Time Complexity:** $O(T \times N)$  
  其中 $T$ 為測試資料組數，$N$ 為區間 $[a, b]$ 的長度。
- **Space Complexity:** $O(1)$  
  僅使用固定數量的變數儲存狀態。



## Notes & Reflection
- **容易出錯點**：
  - **輸出格式**：`Case` 後方的空格與冒號後的空格必須精確，否則會導致系統判別為錯誤。
  - **累加變數重置**：每一組 Case 開始前，`sum` 必須重新歸零。
- **心得**：這是一道經典的基礎題目，非常適合用來練習基本的控制流程與格式化輸出。



## References
- [UVa Online Judge - 10783 Official Page](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1724)