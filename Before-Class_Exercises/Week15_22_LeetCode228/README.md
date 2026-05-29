# LeetCode 228 - Summary Ranges

## 題目描述
給定一個**無重複元素**且**已排序**的整數陣列 `nums`。
請回傳一個字串陣列，將陣列中的連續數字區間總結出來。
陣列中的每個數字都必須恰好被某一個區間覆蓋。

**輸出格式規定：**
- 如果區間 `[a, b]` 包含多個數字（即 `a != b`），輸出 `"a->b"`。
- 如果區間 `[a, b]` 只有一個數字（即 `a == b`），則僅輸出 `"a"`。

[題目連結](https://leetcode.com/problems/summary-ranges/)

## 學習重點
- [x] 掌握陣列的線性走訪（Linear Traversal）。
- [x] 練習外層 `for` 迴圈搭配內層 `while` 迴圈的「區間滑動」技巧。
- [x] 熟悉 C++ 字串處理與 `to_string()` 函式的應用。

---

## 解法思路：線性掃描與區間尋找

### 1. 區間起點標記
- 遍歷陣列時，首先將當前的數字記錄為區間的起點 `start = nums[i]`。

### 2. 探索連續數字
- 使用 `while` 迴圈向後探索：只要確保索引不越界（`i + 1 < n`），且下一個數字剛好比當前數字大 1（`nums[i] + 1 == nums[i+1]`），就將指標 `i` 往後移動。
- 這個步驟確保了我們能一次跳過所有連續的數字，避免多餘的運算。

### 3. 區間格式化與推入結果
- 當 `while` 迴圈結束時，代表連續區間中斷了。
- 檢查 `start` 是否等於最後停下的 `nums[i]`：
  - 若相等：代表這是一個獨立的數字，沒有連續區間，直接將 `start` 轉為字串。
  - 若不相等：代表這是一個連續區間，組合成 `start->nums[i]` 的格式。
- 將組合好的字串推入結果陣列 `ans` 中。

## Code Structure
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        
        for(int i = 0; i < n; i++){
            // 1. 記錄區間的起點
            int start = nums[i];

            // 2. 當下一個數字與當前數字連續時，不斷往後推進指標
            // 注意：這裡直接使用 nums[i] + 1 可能會有 INT_MAX 溢位風險，
            // 若遇極端測資，可改為 (long)nums[i] + 1 == nums[i+1]
            while(i + 1 < n && nums[i] + 1 == nums[i+1]){
                i++;
            }

            // 3. 根據區間內包含的數字數量，格式化並加入解答陣列
            if(start == nums[i]){
                // 只有單一數字
                ans.push_back(to_string(start));
            } else {
                // 包含連續數字區間
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        
        return ans;
    }
};
```

## 複雜度分析
- **時間複雜度**: $O(N)$
  雖然看似有兩層迴圈（`for` 裡面包著 `while`），但實際上陣列中的每一個元素最多只會被訪問兩次，屬於線性時間複雜度。
- **空間複雜度**: $O(1)$
  除了用來存放解答的 `ans` 陣列外，僅使用了常數個變數 `start` 和 `i`。

---

## 筆記與心得
- **溢位陷阱 (Overflow Trap)**：在寫 `nums[i] + 1 == nums[i+1]` 時，如果 `nums[i]` 剛好是整數的最大值 `INT_MAX`，加 1 會導致 Integer Overflow。在更嚴格的測試環境中，可以改寫為 `nums[i+1] - nums[i] == 1` 或強制轉型成 `long` 來避免這個問題。
- **程式碼優雅性**：這套邏輯讓 `i` 指標在內層迴圈推進，外層迴圈的 `i++` 剛好銜接下一個新區間的開頭，是非常簡潔漂亮的寫法。