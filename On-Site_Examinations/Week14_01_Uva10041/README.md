# UVa 10041 - Vito's Family (中位數應用)

## 題目描述
維托大叔有很多親戚住在同一條街上，他想找一個地點居住，使得他家到所有親戚家的「總距離」最小。街道上的位置以整數表示，且維托大叔可以住在他親戚家。

[題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=982)

## 學習重點
- [x] 理解 **中位數 (Median)** 的幾何意義：數線上各點到中位數的距離和為最小。
- [x] 掌握 `std::sort` 對動態陣列進行排序。
- [x] 練習處理多組測試資料與 `abs()` 絕對值運算。

---

## 解法思路：中位數最優化

### 1. 核心數學原理
給定數線上的一組點 $x_1, x_2, ..., x_n$，要找一點 $P$ 使得 $\sum |x_i - P|$ 最小，則 $P$ 必須是這組資料的**中位數**。
- 若 $n$ 為奇數，中位數唯一。
- 若 $n$ 為偶數，則中位數為中間兩個數之間的任何值（程式通常取其中一個）。

### 2. 實作步驟
1. **資料讀取**：讀取測試資組數與每組的親戚人數 $n$。
2. **排序**：將親戚的位置進行排序，以便輕易找到中間的位置。
3. **選定中位數**：選取 `list[n / 2]` 作為維托大叔居住的位置。
4. **計算總距離**：遍歷所有位置，累加每個位置與中位數的差值絕對值 `abs(list[i] - list[count])`。

## Code Structure
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int cases;
    if (!(cin >> cases)) return 0;
    
    // 忽略掉讀取 cases 之後的換行符
    cin.ignore(); 

    while(cases--) {
        vector<int> list;
        int n;
        cin >> n; // 讀取親戚數量
        
        for(int i = 0; i < n; i++) {
            int t;
            cin >> t;
            list.push_back(t);
        }

        // 1. 排序以尋找中位數
        sort(list.begin(), list.end());

        // 2. 選定中位數索引 (n/2)
        int count = n / 2;
        int ans = 0;

        // 3. 計算所有親戚家到中位數位置的總距離
        for(int i = 0; i < n; i++) {
            ans += abs(list[i] - list[count]);
        }

        // 4. 輸出最小總距離
        cout << ans << endl;
    }
    return 0;
}
```

## 複雜度分析
- **時間複雜度**: $O(N \log N)$
  主要消耗在 `sort` 排序過程。後續的總距離計算僅需 $O(N)$。
- **空間複雜度**: $O(N)$
  需要一個 `vector` 儲存所有親戚的位置。

---

## 筆記與心得
- **中位數 vs 平均值**：
  - 最小化「距離絕對值之和」($\sum |x_i - P|$) $\rightarrow$ 使用 **中位數**。
  - 最小化「距離平方之和」($\sum (x_i - P)^2$) $\rightarrow$ 使用 **平均值**。
- **輸入處理**：程式中使用了 `cin.ignore()`，這是為了處理讀取 `cases` 之後留在緩衝區的換行符，確保後續讀取不受影響。