# LeetCode 1046 - Last Stone Weight

## 題目描述
有一堆石頭，每塊石頭都有一個正整數重量。
每一回合，從中選出 **最重的兩塊** 石頭 `x` 和 `y`（假設 `x <= y`）進行碰撞：
- 如果 `x == y`，兩塊石頭都會被粉碎。
- 如果 `x != y`，重量為 `x` 的石頭被粉碎，而重量為 `y` 的石頭重量變為 `y - x`。

最後，最多只會剩下一塊石頭。回傳這塊石頭的重量；如果沒有石頭剩下，回傳 `0`。

[題目連結](https://leetcode.com/problems/last-stone-weight/)

## 學習重點
- [x] 掌握 **優先權佇列 (Priority Queue)** 的基本操作：`push`, `pop`, `top`。
- [x] 理解 **最大堆 (Max-Heap)** 如何在 $O(\log N)$ 時間內取得最大值。
- [x] 練習模擬演算法的終止條件處理。

---

## 解法思路：最大堆模擬法

### 1. 資料結構選用
我們需要每次都能快速找到「目前最重的兩顆石頭」。
- **`std::priority_queue<int>`**：預設為大頂堆，保證堆頂元素永遠是最大值。

### 2. 模擬步驟
- **入堆**：將所有石頭重量放入 `pq`。
- **碰撞迴圈**：只要 `pq` 中還有至少兩顆石頭：
  1. 取出最重的石頭 `y`。
  2. 取出第二重的石頭 `x`。
  3. 若 `x != y`，將剩餘重量 `y - x` 重新推入 `pq`。
- **結果回傳**：若 `pq` 為空回傳 `0`，否則回傳 `pq.top()`。

## Code Structure
```cpp
#include <vector>
#include <queue>

using namespace std;

/**
 * LeetCode 1046 - Last Stone Weight
 * 邏輯：利用 Priority Queue (Max-Heap) 始終獲取兩顆最重的石頭進行模擬。
 */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 1. 初始化優先權佇列 (預設為最大堆)
        priority_queue<int> pq;

        for(int s : stones){
            pq.push(s);
        }

        // 2. 當石頭數量大於 1 時持續進行碰撞
        while(pq.size() > 1){
            int y = pq.top(); // 最重
            pq.pop();
            int x = pq.top(); // 第二重
            pq.pop();

            // 3. 若重量不等，產生新碎石並放回堆中
            if(x != y){
                pq.push(y - x);
            }
        }

        // 4. 回傳最後一顆石頭重量或 0
        return pq.empty() ? 0 : pq.top();
    }
};
```

## 複雜度分析
- **時間複雜度**: $O(N \log N)$
  - 建立堆：$O(N)$ 或 $O(N \log N)$。
  - 碰撞操作：最多進行 $N-1$ 次碰撞，每次取出與插入皆為 $O(\log N)$。
- **空間複雜度**: $O(N)$，需儲存 $N$ 顆石頭。

---

## 筆記與心得
- **高效動態排序**：如果這題使用 `sort` 每次碰撞後重新排序，複雜度會飆升至 $O(N^2 \log N)$。優先權佇列是處理這類「動態取極值」問題的神兵利器。
- **邊界處理**：最後回傳時使用 `pq.empty() ? 0 : pq.top()` 是很穩健的寫法，避免了在空堆上呼叫 `top()` 的錯誤。