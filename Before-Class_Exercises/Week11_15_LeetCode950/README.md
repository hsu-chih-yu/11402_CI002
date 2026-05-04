# LeetCode 950 - Reveal Cards In Increasing Order

## 題目描述
有一副包含許多不同正整數的牌組，每張牌都有一個唯一的整數。可以用任意順序將這些牌排成一個隊列。
現在可以執行以下操作，直到牌組為空：
1. 將牌組最上面的一張牌翻開並放到桌面上。
2. 如果牌組中還有牌，將最上面的一張牌放到牌組的最底部。

給定一個遞增順序的目標桌上牌組內容（即最終翻開的順序應為遞增），請反推出原本應該以什麼順序排列手牌。

[題目連結](https://leetcode.com/problems/reveal-cards-in-increasing-order/)

## 學習重點
- [x] 掌握 **佇列 (Queue)** 的進階模擬技巧。
- [x] 理解如何將「順序操作」反過來模擬 (Reverse Simulation)。
- [x] 練習結合排序與佇列來建立映射關係。

---

## 解法思路：佇列模擬法

此解法並非從頭模擬，而是透過「反向操作」來決定最終每個位置應該放哪一張牌：

1. **排序手牌**：
   - 先將原本的牌組進行遞增排序。因為桌上翻開的順序必須是遞增的，最小的牌一定會先翻開。
2. **建立索引佇列**：
   - 將所有位置的索引（`0` 到 `n-1`）推入佇列中。
3. **反向賦值**：
   - 走訪排序好的牌組，每次將隊首索引對應的答案設為目前的牌。
   - 將隊首元素彈出。
   - 如果佇列中還有剩餘元素，將下一個隊首元素移到佇列的最尾端（即 `q.push(q.front()); q.pop();`），用來模擬反向的放牌到底部動作。

## Code Structure
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        // 將卡牌從小到大排序
        sort(deck.begin(), deck.end());

        // 建立索引佇列
        queue<int> q;
        for(int i = 0; i < n; i++) {
            q.push(i);
        }

        vector<int> ans(n);
        for(int c : deck) {
            // 將對應的卡牌放到正確的位置
            ans[q.front()] = c;
            q.pop();

            // 模擬將頂部的卡牌移到底部
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};
```

## 複雜度分析
- **時間複雜度**: $O(N \log N)$
  由於包含對數組的排序，排序佔用了主要時間，而佇列操作的時間複雜度為 $O(N)$。
- **空間複雜度**: $O(N)$
  使用佇列與答案陣列分別佔用 $N$ 的空間。

---

## 課後反思
- **模擬的藝術**：當正向模擬過於複雜或無法逆推時，通常可以嘗試將操作反過來思考。這題展示了如何利用 Queue 將複雜的洗牌動作還原。