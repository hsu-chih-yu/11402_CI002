# UVa 10252 - Common Permutation

## 題目描述
給定兩個小寫字母組成的字串 $a$ 和 $b$，找出一個最長的字串 $x$，使得 $x$ 是 $a$ 的排列（Permutation），且 $x$ 也是 $b$ 的排列。如果有多個符合條件的 $x$，請輸出字母順序最小（字典序）的那一個。

簡單來說：找出兩個字串中「共同擁有」的字元，並按 `a-z` 順序印出。

[題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1193)

## 學習重點
- [x] 使用 **頻率陣列 (Frequency Array)** 統計字元出現次數。
- [x] 理解如何取兩組資料的 **交集 (Intersection)**。
- [x] 處理 `getline` 與 `cin.get` 在讀取空行時的邊界狀況。

---

## 解法思路

### 1. 統計頻率
我們建立兩個大小為 26 的整數陣列（對應 `a-z`），分別紀錄兩個字串中每個字母出現的次數。
- `countA[char - 'a']++`
- `countB[char - 'a']++`

### 2. 取交集與排序
由於題目要求輸出必須按字母順序排列，我們只需從索引 `0` (a) 遍歷到 `25` (z)：
- 對於每個字母，它在兩個字串中「共同擁有」的次數，就是兩個頻率陣列中的 **較小值**：`min(countA[i], countB[i])`。
- 依照這個次數印出該字母。



## Code Structure
```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    // 使用 getline 讀取每一行，包含可能的空行
    while (getline(cin, s1) && getline(cin, s2)) {
        int countA[26] = {0};
        int countB[26] = {0};

        // 1. 統計第一個字串的字母頻率
        for (char c : s1) {
            if (c >= 'a' && c <= 'z') {
                countA[c - 'a']++;
            }
        }

        // 2. 統計第二個字串的字母頻率
        for (char c : s2) {
            if (c >= 'a' && c <= 'z') {
                countB[c - 'a']++;
            }
        }

        // 3. 按字典序 (a-z) 比較並輸出共同字元
        for (int i = 0; i < 26; i++) {
            // 取兩者出現次數的較小值
            int common = min(countA[i], countB[i]);
            while (common--) {
                printf("%c", i + 'a');
            }
        }
        printf("\n");
    }
    return 0;
}
```

## 複雜度分析
- **時間複雜度**: $O(N)$
  每組測試資料只需遍歷兩次字串進行統計（$N$ 為字串長度），以及一次常數級別（26次）的迴圈輸出。
- **空間複雜度**: $O(1)$
  僅使用固定大小為 26 的陣列，不隨輸入規模增加。

---

## 筆記與心得
- **空行處理**：這題最容易出錯的地方在於輸入可能包含空行。使用 `getline(cin, s)` 是比 `cin.get(c)` 更穩健的做法，因為 `getline` 能完整處理一整列（包含空字串）。
- **初始化**：每處理完一組測資，頻率陣列務必清空（Reset to zero）。