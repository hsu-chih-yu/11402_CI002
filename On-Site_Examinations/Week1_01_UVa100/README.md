# UVa 100 - The 3n+1 Problem

## Problem Description
針對任何正整數 $n$，若 $n$ 為奇數則令 $n = 3n + 1$，若 $n$ 為偶數則令 $n = n / 2$。不斷重複此動作直到 $n = 1$ 為止。在過程中產生的數字個數（包含 1）稱為該數的 Cycle Length。本題要求給定一個區間 $[i, j]$，找出該區間內所有數字中最大的 Cycle Length。 [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36)

## Learning Objectives
- [x] 掌握 3n+1 猜想的邏輯分支與收斂特性。
- [x] 精確運用 while 與 for 進行複雜邏輯迭代。
- [x] 學習在極端數值下選擇正確的資料型態（如 long long）以確保運算正確。

## Solution Approach

### Algorithm Logic
1. 讀取輸入：使用 `while(cin >> a >> b)` 持續讀間端點。
2. 保留原始序：立即輸出 `a` 與 `b`，因為題目要求輸出須維持原始輸入順序。
3. 區間調整：若 $a > b$，則將兩者交換以確保 `for` 迴圈能從小到大正確執行。
4. 計算 Cycle Length：
    * 對區間內的每個整數，使用 `long long` 以防止 $3n+1$ 計算過程中溢位。
    * 使用 `while` 迴圈模擬 3n+1 過程直到數字變為 1。
5. 更新最大值：比較並記錄該區間內出現過的最高 `num`。
6. 輸出結果：輸出最終的最大 Cycle Length。

### Key Insights
* 輸出順序：必須先印出原始的 $a, b$ 再進行區間整理。若直接交換 $a, b$，最後輸出的數值順序可能會與輸入相反。
* 數值溢位：在計算 $3n+1$ 的過程中，中間值可能會瞬間爆過 `int` 上限，要使用 `long long`。
* 變數隔離：計算過程須使用暫存變數（如 `temp`），不可更動到 `for` 迴圈的控制變數 `i`。

## Code Structure
```cpp
#include <iostream>

using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        cout << a << ' ' << b << ' ' ;

        // 確保範圍是從小到大，避免 a > b 時迴圈不跑
        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }

        int max = -1;

        for(int i = a; i <= b; i++){
            long long temp = i;  // 使用 long long 防止 3n+1 運算溢位
            int num = 1;

            // 執行 3n+1 邏輯直到變為 1
            while(temp != 1){
                if(temp % 2 == 1){
                    temp = temp * 3 + 1;
                }else{
                    temp /= 2;
                }
                num++;
            }

            // 更新最大長度
            if(num > max) max = num;
        }
        cout << max << endl;
    }
    return 0;
}
```

## Complexity Analysis
- **Time Complexity:** $O(N \cdot L)$，其中 $N$ 為區間長度， $L$ 為平均 Cycle Length。
- **Space Complexity:** $O(1)$，僅使用常數空間進行計算。

## Notes & Reflection
- 一開始忽略了 $a > b$ 的輸入情況，且變數命名與 std::count 衝突導致編譯錯誤。
- 未來若遇到更大量請有重複的測資，可以考慮建立陣列存儲已算過的數字。

## References
- [Problem Link](https://onlinejudge.org/)