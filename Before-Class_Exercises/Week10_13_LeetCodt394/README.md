# LeetCode 394 - Decode String

## 題目描述
給定一個經過編碼的字串，回傳它解碼後的字串。
編碼規則為：`k[encoded_string]`，表示其中方括號內部的 `encoded_string` 正好重複 `k` 次。注意 `k` 保證為正整數。

**範例：**
- 輸入：`s = "3[a]2[bc]"` -> 輸出：`"aaabcbc"`
- 輸入：`s = "3[a2[c]]"` -> 輸出：`"accaccacc"`

[題目連結](https://leetcode.com/problems/decode-string/)

## 學習重點
- [x] 理解 **遞迴 (Recursion)** 處理嵌套結構 (Nested Structure) 的方式。
- [x] 掌握 **傳址呼叫 (Pass by Reference)** 在遞迴中共享進度指標的技巧。
- [x] 練習字串與數字的轉換（處理多位數 `k`）。



## Solution Approach

### Algorithm Logic: DFS / Recursive Parsing
當字串中出現方括號嵌套（如 `3[a2[c]]`）時，最內層的括號必須先被解碼，這符合「遞迴」或「堆疊」的特性。

1. **共享指標**：
   - 使用一個引用變數 `int& i` 來追蹤目前掃描到的位置。這樣在進入下一層遞迴並回來後，指標能正確停在處理完的位置。
2. **處理倍數 `k`**：
   - 當遇到數字時，利用 `while` 迴圈將連續的數字字元轉換為整數 `k`。
3. **遞迴觸發**：
   - 遇到 `[` 時，跳過它並「開啟新的一層」遞迴來處理括號內的內容。
4. **結束條件與回傳**：
   - 遇到 `]` 或是字串結尾時，結束當前層級的讀取，將累積的 `res` 回傳給上一層。
   - 上一層拿到結果後，根據 `k` 值進行字串重複動作。

## Code Structure
```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0; // 初始化全域進度指標
        return decode(s, i);
    }

private:
    // 使用 int& i 確保遞迴加深時，指標能同步推進
    string decode(const string& s, int& i) {
        string res = "";
        
        while (i < s.length() && s[i] != ']') {
            if (isdigit(s[i])) {
                // 處理倍數 k (考慮多位數)
                int k = 0;
                while (i < s.length() && isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                
                i++; // 跳過 '['
                
                // 遞迴取得括號內解碼後的內容
                string decodedString = decode(s, i);
                
                i++; // 跳過 ']'
                
                // 根據倍數 k 重複字串
                while (k-- > 0) {
                    res += decodedString;
                }
            } else {
                // 一般字母直接加入結果
                res += s[i++];
            }
        }
        return res;
    }
};
```

## Complexity Analysis
- **Time Complexity:** $O(S)$
  - $S$ 是解碼後字串的長度。每個字元都會被掃描並加入結果字串中。
- **Space Complexity:** $O(D)$
  - $D$ 是遞迴的最大深度（即方括號嵌套的層數）。



## Notes & Reflection
- **指標同步**：這題最容易錯的地方在於跳過 `[` 與 `]` 的時機。使用 `int& i` 可以確保我們不會重複讀取或漏讀字元。
- **多位數處理**：記住 `k` 可能是 `100` 或更多位數，所以不能只讀取一個字元。