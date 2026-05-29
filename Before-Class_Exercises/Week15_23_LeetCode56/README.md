# LeetCode 56 - Merge Intervals

## 題目描述
給定一個包含多個區間的陣列 `intervals`，其中 `intervals[i] = [start_i, end_i]`。
請合併所有重疊的區間，並回傳一個不重疊的區間陣列，該陣列需涵蓋輸入中的所有區間。

**範例：**
- 輸入：`intervals = [[1,3],[2,6],[8,10],[15,18]]`
- 輸出：`[[1,6],[8,10],[15,18]]`
- 解釋：區間 `[1,3]` 和 `[2,6]` 重疊，將它們合併為 `[1,6]`。

[題目連結](https://leetcode.com/problems/merge-intervals/)

## 學習重點
- [x] 掌握 **區間重疊 (Interval Overlap)** 的判斷邏輯：`last_end >= current_start`。
- [x] 熟悉 C++ `std::sort` 在二維 `vector` 上的預設行為（依照每一列的第一個元素排序）。
- [x] 練習使用 **貪心演算法 (Greedy)** 策略，透過局部最優解尋找全域最優解。

---

## 解法思路：排序與線性合併

### 1. 預先排序 (Sorting)
要處理區間重疊，最怕的就是區間順序錯亂。
呼叫 `sort(intervals.begin(), intervals.end())` 會自動將所有區間依照**起始時間 (start time)** 由小到大排列。這保證了如果兩個區間要重疊，它們在陣列中一定是相鄰的。

### 2. 建立合併結果陣列
建立一個新的二維陣列 `merged`，並先將排序後的第一個區間放入，作為比較的基準。

### 3. 線性掃描與貪心合併
從第二個區間開始遍歷 `intervals`，並比較當前區間與 `merged` 陣列中**最後一個區間**的關係：
- **發生重疊**：如果 `merged` 中最後一個區間的結束時間 $\ge$ 當前區間的起始時間，代表兩者重疊。
  - **合併動作**：更新 `merged` 最後一個區間的結束時間，取兩者的最大值 `max(last_end, current_end)`。（例如 `[1, 4]` 與 `[2, 3]` 合併會變成 `[1, 4]`）。
- **無重疊**：如果結束時間 $<$ 當前區間的起始時間，代表區間斷開了。
  - **新增動作**：直接將當前區間 `push_back` 到 `merged` 陣列中，成為新的比較基準。

## Code Structure
```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 安全檢查：若為空陣列則直接回傳
        if(intervals.empty()) return {};

        // 1. 依照起始時間進行升冪排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        // 先將第一個區間放入作為初始比較基準
        merged.push_back(intervals[0]);
        
        int n = intervals.size();
        for(int i = 1; i < n; i++){
            // 取得前一個合併區間的結束點，與當前區間的起迄點
            int last_end = merged.back()[1];
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];

            // 2. 判斷是否重疊
            if(last_end >= current_start){
                // 若重疊，將前一個區間的結束點向右延展（取兩者最大值）
                merged.back()[1] = max(last_end, current_end);
            } else {
                // 若未重疊，則將當前區間作為新的獨立區間加入
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};
```

## 複雜度分析
- **時間複雜度**: $O(N \log N)$
  - 排序需要 $O(N \log N)$ 的時間。
  - 後續的線性掃描只需遍歷陣列一次，耗時 $O(N)$。
  - 總時間複雜度由排序主導。
- **空間複雜度**: $O(\log N)$ 或 $O(N)$
  - 除了回傳的解答陣列外，C++ `std::sort` 本身會消耗 $O(\log N)$ 的遞迴呼叫疊空間。

---

## 筆記與心得
- **空陣列防呆**：最前面的 `if(intervals.empty()) return {};` 是很好的習慣，防止後續存取 `intervals[0]` 時發生越界錯誤 (Segfault)。
- **二維 Vector 的排序**：這題展示了 C++ STL 的強大，不需要自定義比較函式，`sort` 預設就會幫我們把 `start_time` 乖乖排好。