# UVa 11150 - Cola

## Problem Description
手上有 $n$ 瓶可樂。每 3 個空瓶可以換 1 瓶新的可樂。此外，題目允許向朋友「借」空瓶，只要最後能換回足夠的空瓶還給他即可。目標是計算在最優策略下，最多能喝到幾瓶可樂。
[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2091)

## Learning Objectives
- [x] 練習基礎的數值模擬（Simulation）。
- [x] 理解整數除法 (`/`) 與取餘數 (`%`) 在資源分配中的應用。
- [x] 掌握簡單的貪心策略：利用「借貸」機制極大化收益。



## Solution Approach

### Algorithm Logic
1. **初始狀態**：一開始就喝掉了 $n$ 瓶可樂，所以總喝掉瓶數 `ans` 初始化為 `n`，此時手上也有 `n` 個空瓶。
2. **循環換購**：
   - 只要手上的空瓶 `n >= 3`，就執行換購。
   - 換得的新可樂數量為 `n / 3`，將其累加進 `ans`。
   - 喝完這些新可樂後，手上的空瓶總數更新為：「新換的數量 + 剛才換剩的（`n % 3`）」。
3. **借瓶策略**：
   - 這是本題最關鍵的優化點。當換到最後，如果手上剛好剩下 **2 個空瓶**，可以向朋友借 1 個空瓶。
   - 湊齊 3 個後換得 1 瓶新可樂，喝完後剩下的 1 個空瓶剛好還給朋友。
   - 因此，若最後剩 2 個空瓶，`ans` 可以額外再加 1。

[Image of cola bottle recycling logic flowchart showing the 3-for-1 swap and the borrow-1-return-1 scenario]

### Key Insights
* **資源循環**：每一次「換購並喝完」的過程，實質上是消耗了 2 個空瓶（3 個換出去，1 個喝完回來）。
* **邊界條件**：若最後只剩 1 個空瓶，無法進行借瓶換購，因為喝完後無法歸還借來的瓶子。



## 程式碼實作 (Code Structure)

```cpp
#include <iostream>

using namespace std;

int main() {
    int n;
    // 讀取可樂數量n
    while (cin >> n) {
        // 一開始先喝n瓶
        int ans = n;
        
        while (n >= 3) {
            int new_cola = n / 3;   // 3個空瓶換1瓶新可樂
            ans += new_cola;        // 喝掉新換來的可樂
            // 更新空瓶數
            n = new_cola + (n % 3);
        }
        
        // 借瓶子
        if (n == 2) {
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
```



## Complexity Analysis
- **Time Complexity:** $O(\log_3 n)$  
  每次循環空瓶數量都會減少約三分之二，執行次數與 $n$ 的對數成正比。
- **Space Complexity:** $O(1)$  
  僅使用常數個變數存儲可樂與空瓶數量。



## Notes & Reflection
- **容易出錯點**：
  - **重複計數**：在更新 `n` 的時候，必須同時考慮「新喝完的」與「上次剩下來的」空瓶。
  - **借瓶判斷**：借瓶子的行為是最後一次性的判斷，不需要放進迴圈執行。



## References
- [UVa Online Judge - 11150 Official Page](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2091)