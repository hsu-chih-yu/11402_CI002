# UVa 10170 - The Hotel with Infinite Rooms

## Problem Description
某旅館有一套特殊的入住規則：一組人數為 $S$ 的團體會入住 $S$ 天，接著人數為 $S+1$ 的團體會入住 $S+1$ 天，以此類推。給定初始團體人數 $S$ 以及一個目標天數 $D$，要求計算在第 $D$ 天時，入住旅館的團體人數是多少。
[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1111)

## Learning Objectives
- [x] 練習使用 `while` 迴圈進行數值模擬。
- [x] 理解大數處理，掌握 `long long` 資料型態的使用時機。
- [x] 練習處理連續輸入。



## Solution Approach

### Algorithm Logic
1. **讀取輸入**：使用 `while(cin >> s >> d)` 持續讀取起始人數 $S$ 與目標天數 $D$。
2. **模擬入住過程**：
   - 建立一個迴圈，條件為目標天數 $D > 0$。
   - 在每一輪中，從 $D$ 扣除當前團體的人數 $S$（因為該團體會待 $S$ 天）。
   - 每扣除一次，代表時間往後推進，下一組團體的人數會增加 1 ($S = S + 1$)。
3. **終止條件**：當 $D \le 0$ 時，表示目標天數落在了最後一組入住的團體期間。
4. **輸出結果**：由於迴圈最後一次執行時 $S$ 仍做了自增運算，因此最終結果需減 1 ($S - 1$) 才是當時在旅館內的人數。

### Key Insights
* **資料範圍**：題目給定的 $D$ 最高可達 $10^{15}$，遠超 `int` 的範圍，因此必須使用 `long long` 來儲存 $S$ 與 $D$ 以避免溢位。
* **數學本質**：這題本質上是尋找一個最小的 $n$，使得 $\sum_{i=S}^{n} i \ge D$。



## 程式碼實作 (Code Structure)

```cpp
#include <iostream>

using namespace std;

int main() {
    // 使用 long long 以處理高達 10^15 的數據
    long long s, d;

    // 持續讀取起始人數 s 與目標天數 d
    while (cin >> s >> d) {

        // 當 d 還大於 0，代表還沒抵達目標天數
        while (d > 0) {
            // 從剩餘天數中扣除當前團體入住的天數
            d -= s;
            
            // 下一組團體的人數比前一組多 1
            s++;
        }

        // 輸出結果
        cout << s - 1 << endl;
    }
    return 0;
}
```



## Complexity Analysis
- **Time Complexity:** $O(\sqrt{D})$  
  由於人數是線性遞增的，總天數的增長速度接近 $S + (S+1) + ... + (S+n) \approx n^2$，因此迴圈執行次數大約是 $D$ 的平方根層級。
- **Space Complexity:** $O(1)$  
  僅使用固定的變數進行運算，不需要額外的記憶體空間。



## Notes & Reflection
- **容易出錯點**：
  - **資料型態**：若使用 `int` 會因為無法處理 $10^{15}$ 而導致 Wrong Answer 或無限迴圈。
  - **結果修正**：注意迴圈內 `s++` 的順序。若先扣除天數再加人數，最後輸出時要校正回來。
- **改進思考**：對於極大的資料量，可以使用等差級數求和公式 $D \le \frac{(S + S+n-1) \times n}{2}$ 配合二分搜尋法來達到 $O(\log \sqrt{D})$ 的效率，但在本題限制下模擬法已足夠快。



## References
- [UVa Online Judge - 10170 Official Page](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1111)