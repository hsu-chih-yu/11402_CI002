# LeetCode 20 - Valid Parentheses

## 題目描述
給定一個只包含字元 `(`，`)`，`{`，`}`，`[`，`]` 的字串 `s`，判斷該字串是否有效。
有效字串需滿足：
1. 左括號必須用相同類型的右括號閉合。
2. 左括號必須以正確的順序閉合。
3. 每個右括號都有一個對應的相同類型的左括號。

[Link to problem](https://leetcode.com/problems/valid-parentheses/)

## 學習重點
- [x] 掌握 **Stack** 的 LIFO 特性。
- [x] 理解如何利用堆疊處理「對稱性」與「嵌套結構」問題。
- [x] 練習處理邊界條件：如字串開頭即為右括號，或左括號過多的情況。



## Solution Approach

### Algorithm Logic: Stack-Based Matching
括號匹配的核心在於「最後一個進入的左括號，必須第一個被匹配」。這與堆疊的運作方式完美契合：

1. **遇左括號入棧**：
   - 當遍歷到 `(`、`{` 或 `[` 時，將其推入堆疊 (`st.push(c)`)。
2. **遇右括號檢查**：
   - 首先檢查堆疊是否為空。若為空，代表此右括號沒有對應的左括號，回傳 `false`。
   - 取得堆疊頂部元素 (`st.top()`)。
   - 若目前的右括號與棧頂的左括號類型相符，則將棧頂元素彈出 (`st.pop()`)；否則，代表順序錯誤，回傳 `false`。
3. **結尾判斷**：
   - 遍歷完成後，檢查堆疊是否為空。
   - 若堆疊為空，代表所有括號都已正確配對；若不為空，代表還有剩餘的左括號未閉合，回傳 `false`。

## Code Structure
```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            // 如果是左括號，直接入棧
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            } else {
                // 如果是右括號，先檢查堆疊是否為空
                if(st.empty()){
                    return false; // 右括號前面沒有任何左括號，無效
                }
                
                char top = st.top();
                // 檢查棧頂左括號是否與當前右括號配對
                if((c == ')' && top == '(') || 
                   (c == ']' && top == '[') ||
                   (c == '}' && top == '{')){
                    st.pop(); // 配對成功，移除棧頂
                } else {
                    return false; // 類型不匹配，無效
                }
            }
        }
        
        // 最後檢查堆疊是否全數清空（避免如 "((" 的情況）
        return st.empty();
    }
};
```

## Complexity Analysis
- **Time Complexity:** $O(n)$  
  只需遍歷一次字串，每個字元的入棧與出棧操作均為常數時間。
- **Space Complexity:** $O(n)$  
  最壞情況下（例如字串全為左括號），堆疊需要存儲所有字元。

---

## Notes & Reflection
- **邊界陷阱**：在呼叫 `st.top()` 之前一定要先檢查 `st.empty()`，否則會導致 Runtime Error。
- **代碼優化**：可以使用 `switch-case` 或 `unordered_map` 來儲存括號對應關係，讓程式碼更簡潔美觀。