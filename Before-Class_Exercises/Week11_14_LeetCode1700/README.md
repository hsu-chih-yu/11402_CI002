# LeetCode 1700 - Number of Students Unable to Eat Lunch

## 題目描述
學校的自助餐廳午餐提供圓形和方形三明治，分別用數字 `0` 和 `1` 表示。所有學生排成一個佇列，每個學生也有各自喜歡的食物類型（`0` 或 `1`）。

三明治堆疊在一個堆疊（Stack）中，遵循以下規則：
1. 如果佇列中最前面的學生喜歡堆疊頂部的三明治，他會拿走三明治並離開佇列。
2. 如果不喜歡，該學生會走到佇列的最末端。
3. 如果佇列中沒有任何一個學生喜歡頂部的三明治，則整個過程停止。

請回傳無法吃到午餐的學生數量。

[題目連結](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/)

## 學習重點
- [x] 掌握 **佇列 (Queue)** 的 FIFO (First In, First Out) 操作。
- [x] 學習如何模擬循環佇列以處理學生的移動。
- [x] 練習處理終止條件（當輪過一遍沒有人想拿三明治時跳出）。



## 解法思路

### 演算法邏輯：佇列模擬法
本解法直接透過 `std::queue` 模擬學生的排隊行為：

1. **初始化佇列**：
   - 將所有 `students` 推入佇列 `q` 中。
2. **模擬過程**：
   - 使用 `while` 迴圈檢查條件是否成立，循環條件為 `count < s`（`count` 為未更動隊伍的連續失敗人數，`s` 為目前剩餘的學生數）。
3. **比對元素**：
   - 若佇列前端的學生喜歡當前三明治（`q.front() == sandwiches[i]`），則讓學生吃三明治離開佇列，三明治指針 `i++`，同時重置連續失敗計數器 `count = 0`。
   - 若不喜歡，則將該學生從佇列前端移出並推入佇列尾端，連續失敗計數器 `count++`。
4. **結束與結果**：
   - 當佇列中沒有學生想吃當前三明治，或佇列為空時停止，回傳佇列剩餘的學生數。

## Code Structure
```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i = 0;
        int s = students.size();
        int count = 0;
        queue<int> q;
        
        // 將所有學生加入佇列
        for(int k : students) {
            q.push(k);
        }
        
        // 持續模擬取三明治的過程
        while (count < s && !q.empty()) {
            if (q.front() == sandwiches[i]) {
                // 學生喜歡當前三明治
                i++;
                q.pop();
                s--;
                count = 0; // 重置計數
            } else {
                // 學生不喜歡當前三明治，移至隊尾
                count++;
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
        
        // 剩餘無法拿到三明治的學生數
        return q.size();
    }
};
```

## 複雜度分析
- **時間複雜度**: $O(N^2)$ (最壞情況下，每次都必須將學生移到隊尾)。
- **空間複雜度**: $O(N)$，需要一個佇列儲存學生陣列。



## 課後反思
- **簡化思考**：雖然模擬法最直覺，但在面試中，這題也可以使用簡單的計數陣列（計算 0 和 1 的數量）來解，時間複雜度只需 $O(N)$。