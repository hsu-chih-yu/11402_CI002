# UVa 11136 - Hoax or what?

## Problem Description
有一個促銷活動：每天客戶會把帳單投入箱子。每天結束時，主辦方會從箱子裡找出面額**最高**和**最低**的兩張帳單。
- 獎金 = 最高面額 - 最低面額
- 這兩張帳單會被銷毀，剩下的帳單則保留到隔天。
請計算活動結束後，主辦方總共要發出多少獎金。

[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2077)

## Learning Objectives
- [x] 掌握 `std::multiset` 的應用（自動排序且允許重複值）。
- [x] 理解為什麼在動態取極值的場景下，`multiset` 比 `vector` 更高效。
- [x] 處理大數累加問題，避免 `int` 溢位。



## Solution Approach

### Algorithm Logic
這題的核心是一個「動態維護的有序集合」。
1. **容器選擇**：使用 `std::multiset<int>`。
   - 它會自動將帳單從小到大排好。
   - 插入、尋找極值、刪除極值的時間複雜度皆為 $O(\log N)$。
2. **每日流程**：
   - 將當天投入的所有帳單 `insert` 進 `multiset`。
   - 最小值為 `*urn.begin()`。
   - 最大值為 `*(--urn.end())` 或 `*urn.rbegin()`。
   - 累加差值到 `ans`。
   - 刪除這兩個元素（注意：刪除時要使用迭代器，否則會把所有相同面額的帳單都刪掉）。
3. **資料型態**：總金額 `ans` 宣告為 `long long`。

---

## 程式碼實作 (Code Structure)

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {
    int days;
    // 讀取活動天數
    while (cin >> days && days != 0) {
        multiset<int> urn; // 使用 multiset 模擬裝帳單的箱子
        long long total_prize = 0; // 獎金可能很大，用 long long

        while (days--) {
            int n;
            cin >> n; // 今天投入幾張帳單
            for (int i = 0; i < n; i++) {
                int bill;
                cin >> bill;
                urn.insert(bill); // 插入帳單，自動排序 O(log N)
            }

            if (!urn.empty()) {
                // 取出最小值與最大值
                auto it_min = urn.begin();
                auto it_max = --urn.end();

                total_prize += (*it_max - *it_min);

                // 刪除這兩張帳單
                // 必須傳入迭代器，若直接傳入數值會刪除所有相同面額的帳單
                urn.erase(it_min);
                urn.erase(it_max);
            }
        }
        cout << total_prize << endl;
    }
    return 0;
}
```



## Complexity Analysis
- **Time Complexity:** $O(T \cdot \log T)$  
  其中 $T$ 是帳單的總數。每次插入與刪除的操作都是對數等級。
- **Space Complexity:** $O(T)$  
  需要儲存箱子中剩餘的所有帳單。



## Notes & Reflection
- **為何不用 vector？**：當資料量來到 $10^6$ 時，$O(N^2)$ 的暴力搜尋絕對會超時。
- **為何不用 priority_queue？**：一般的優先佇列只能快速取一端（最大或最小），這題需要同時操作兩端，因此 `multiset` 或兩個 `priority_queue` 是更好的選擇。



## References
- [UVa Online Judge - 11136 Official](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2077)