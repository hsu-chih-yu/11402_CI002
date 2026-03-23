# LeetCode 179 - Largest Number

## Problem Description
給定一組非負整數 `nums`，請將它們重新排列，拼湊出一個最大的整數。由於結果可能非常大，因此請回傳字串而非整數。

[Link to problem](https://leetcode.com/problems/largest-number/)

## Learning Objectives
- [x] 練習將 `int` 向量轉換為 `string` 向量。
- [x] 掌握 `std::sort` 的自定義比較函式（Custom Comparator）與 Lambda 表達式。
- [x] 理解字串串接排序的貪心策略（Greedy Strategy）。
- [x] 處理特殊邊界情況（Corner Case）：多個零的處理。



## Solution Approach

### Algorithm Logic
這題的核心不在於數字的大小，而在於「接合後的影響力」。
1. **型別轉換**：為了方便串接與比較，先將所有數字轉為 `string`。
2. **自定義排序規則**：
   - 傳統排序：`"30" > "3"`（錯誤，因為 `330` 比 `303` 大）。
   - 本題邏輯：比較 `a + b` 與 `b + a` 的大小。
   - 範例：`a = "3"`, `b = "30"`。
     - `a + b = "330"`
     - `b + a = "303"`
     - 因為 `"330" > "303"`，所以 `"3"` 應該排在 `"30"` 前面。
3. **處理全零情況**：
   - 如果排序後的第一個字串是 `"0"`，代表後續也全是 `"0"`（例如輸入 `[0, 0]`）。
   - 此時應直接回傳 `"0"`，而非 `"00"`。
4. **字串串接**：依序將排序後的字串加總。



### Key Insights
* 如果 $A$ 接 $B$ 比較大，且 $B$ 接 $C$ 比較大，那麼 $A$ 接 $C$ 也一定比較大。透過這種排序，能確保最終串出來的數字是全域最優解。


## 程式碼實作 (Code Structure)

```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        
        // 先將所有 int 轉為 string，方便接合比較
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        
        // 使用 Lambda 運算式處理比較邏輯：判斷誰放在前面接起來比較大
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a; // 降冪排序
        });

        // 第一個數字是 "0" 代表全部都是 0
        if (strs[0] == "0") return "0";

        // 將排序後的字串依序拼湊起來
        string result = "";
        for (const string& s : strs) {
            result += s;
        }

        return result;
    }
};
```

## Complexity Analysis
- **Time Complexity:** $O(n \log n \cdot k)$  
  其中 $n$ 為數字個數，$k$ 為平均位數。排序需要 $O(n \log n)$ 次比較，每次比較字串接合與對比需要 $O(k)$ 時間。
- **Space Complexity:** $O(n \cdot k)$  
  需要額外的空間來儲存轉換後的字串向量。



## Notes & Reflection
- **容易出錯點**：
  - **"0" 的特殊處理**：在面試中，這是一個很容易被漏掉的細節。
  - **字串加法順序**：在比較時，順序絕對不能寫反，`a + b > b + a` 才是降冪排序。


## References
- [LeetCode 179. Largest Number Official Page](https://leetcode.com/problems/largest-number/)