# LeetCode 658 - Find K Closest Elements

## Problem Description
給定一個 **已排序** 的整數陣列 `arr`，以及兩個整數 `k` 和 `x`。
請從中找出最接近 `x` 的 `k` 個整數。結果必須依 **升冪順序** 排列。

**判定標準 (Closer Than)：**
1. 距離較近者優先：$|a - x| < |b - x|$
2. 若距離相同，則數值較小者優先：$a < b$

[Link to problem](https://leetcode.com/problems/find-k-closest-elements/)

## Learning Objectives
- [x] 掌握 `std::stable_sort` 與 `std::sort` 的差異。
- [x] 練習使用 **Lambda 表達式** 擷取外部變數 (`[x]`)。
- [x] 理解 `vector` 的 **區間建構子 (Range Constructor)**。
- [x] 處理多重條件排序 (Multi-level Sorting)。

---

## Solution Approach

### Algorithm Logic: Custom Sorting
這個解法的核心是重新定義「大小」的含義：

1. **自定義比較規則**：
   我們不關心數字本身的大小，而是關心它與 $x$ 的距離。
   使用 Lambda 函式定義比較邏輯：`abs(a - x) < abs(b - x)`。

2. **為什麼使用 `stable_sort`？**
   - 題目規定：若距離相等，數值小者優先。
   - 原陣列 `arr` 已經是升冪排列。
   - `stable_sort` 會保留相等元素的相對位置。因此，當兩個數字與 $x$ 的距離一樣時，原本就在前面的（較小的）數字會被保留在前面。

3. **擷取與再排序**：
   - 排序後，陣列的前 $k$ 個元素即為最接近 $x$ 的數字。
   - 使用 `vector<int> result(begin, begin + k)` 快速建立結果。
   - 由於題目要求最終結果必須升冪，因此最後再對這 $k$ 個數字做一次標準排序。



### Key Insights
* **穩定排序的力量**：利用資料原始的有序性，可以簡化複雜的判斷邏輯。
* **語法糖**：Lambda 擷取 `[x]` 讓比較函式能動態存取目標值，這是現代 C++ 開發必備的技巧。

---

## 程式碼實作 (Code Structure)

```cpp
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 根據與 x 的距離進行排序
        // 使用 stable_sort 可以確保距離相等時，原本較小的元素仍在前面
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x);
        });

        // 取前 k 個最接近的元素
        vector<int> result(arr.begin(), arr.begin() + k);

        // 題目要求結果必須是升冪排列
        sort(result.begin(), result.end());

        return result;
    }
};
```



## Complexity Analysis
- **Time Complexity:** $O(n \log n)$  
  主要的效能開銷在於對整個 `arr` 進行 `stable_sort`。最後對 $k$ 個元素排序的時間為 $O(k \log k)$，通常 $k \le n$。
- **Space Complexity:** $O(k)$  
  需要額外的空間來儲存回傳的 `result` 向量。

---

## Notes & Reflection
- **效能考量**：雖然排序法 ($O(n \log n)$) 邏輯清晰，但在資料量極大時，效率不如 **雙指標收縮法 ($O(n)$)** 或 **二分搜尋法 ($O(\log(n-k) + k)$)**。
- **穩定性**：如果將 `stable_sort` 換成 `sort`，則比較邏輯必須改寫為 `(abs(a-x) < abs(b-x)) || (abs(a-x) == abs(b-x) && a < b)` 才能通過測試。



## References
- [LeetCode 658. Find K Closest Elements Official Page](https://leetcode.com/problems/find-k-closest-elements/)