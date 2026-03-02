# UVa 10035 - Primary Arithmetic

## Problem Description
要求給定兩個非負整數，計算這兩個數字在相加過程中一共發生了幾次進位。 [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=976)

## Learning Objectives
- [x] 練習數值的位數拆解 (使用 `% 10` 與 `/ 10`)
- [x] 理解進位邏輯的傳遞性
- [x] 處理 C++ 中的多條件輸入判斷與複數型態輸出

## Solution Approach

### Algorithm Logic
1. **讀取輸入**：使用 `while (cin >> i >> j && (i != 0 || j != 0))` 讀取兩個數字，當兩者皆為 0 時停止。
2. **逐位計算**：
    * 使用 `% 10` 分別取出兩個數字的最末位數 $a$ 與 $b$。
    * 將 $a + b + \text{last}$（前一次的進位）相加。
    * 若總和 $\ge 10$，則進位計數器 `count` 加 1，並將 `last` 設為 1；否則 `last` 歸零。
3. **數字位移**：將 $i$ 與 $j$ 除以 10，繼續處理下一位，直到兩個數字都變為 0。
4. **格式化輸出**：
    * 無進位：`No carry operation.`
    * 1 次進位：`1 carry operation.`
    * 多次進位：`X carry operations.` 


### Key Insights
* 進位累加：進位不只是看 $a+b$，還必須加上從「上一位」傳過來的進位值。
* 大數處理：雖然輸入範圍標註為 10 位數，但使用 `long long` 可以確保在某些極端測資下不會發生溢位問題。

## Code Structure
```cpp
#include <iostream>

using namespace std;

int main() {
    long long i, j;
    
    // 讀取輸入，直到 i 與 j 同時為 0
    while (cin >> i >> j && (i != 0 || j != 0)) {
        int count = 0; // 進位次數
        int last = 0;  // 儲存進位值 (0 或 1)
        
        while (i > 0 || j > 0) {
            int a = i % 10;
            int b = j % 10;
            
            // 判斷當前位數相加是否產生進位
            if (a + b + last >= 10) {
                count++;
                last = 1;
            } else {
                last = 0;
            }
            // 移至下一位
            i /= 10;
            j /= 10;
        }

        // 根據進位次數輸出對應的字串
        if (count == 0) {
            cout << "No carry operation." << endl;
        } else if (count == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << count << " carry operations." << endl;
        }
    }
    return 0;
}
```

## Complexity Analysis
- **Time Complexity:**  $O(\log_{10} N)$，其中 $N$ 是較大的那個數字。計算次數取決於數字的位數。
- **Space Complexity:** $O(1)$，僅使用固定數量的變數。

## Notes & Reflection
- 挑戰：一開始容易忘記最後一位如果還有進位要如何處理，但透過 `last` 變數成功解決了狀態傳遞問題。
- 改進：這題也可以先將數字讀取為字串，由後往前遍歷，這在處理大整數時會更有彈性。
- 體會到 C++ `cout` 在處理變數與字串混合輸出時比 `printf` 更直觀且不容易寫錯格式符號。

## References
- [Problem Link](https://onlinejudge.org/)