# UVa 272 - TEX Quotes

## Problem Description
在 TeX 系統中，左雙引號使用兩個反引號 ` `` ` 表示，右雙引號則使用兩個單引號 `''` 表示。本題要求將輸入文字中成對出現的雙引號 `"` 依序轉換為 TeX 格式輸出。 [Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=208)


## Learning Objectives
- [x] 練習字元流處理，使用 `cin.get(c)` 讀取包含空白與換行的字元。
- [x] 運用布林旗標（Boolean Flag）進行簡單的二元狀態切換。
- [x] 理解如何將單一字元根據狀態替換為不同長度的字串輸出。


## Solution Approach

### Algorithm Logic
1. **建立狀態**：宣告一個布林變數 `first` 並初始化為 `true`，代表目前遇到的下一個雙引號應視為「左雙引號」。
2. **逐字讀取**：使用 `while (cin.get(c))` 迴圈，從輸入流中一個一個字元抓取。這能確保文件中的空格、製表符與換行符號都被原封不動地讀入。
3. **判斷邏輯**：
   - 如果字元為 `"`：
     - 若 `first` 為 `true`，輸出 ` `` ` 並將 `first` 改為 `false` 。
     - 若 `first` 為 `false`，輸出 `''` 並將 `first` 改為 `true`  。
   - 如果字元不是 `"`：直接輸出該字元。
4. **結束條件**：當 `cin.get(c)` 讀到 EOF 時，迴圈自動結束。

### Key Insights
* **狀態切換**：不需記錄位置，只需紀錄當前次數是奇數還是偶數。
* **輸入完整性**：必須使用 `get()` 而非 `>>`，因為 `>>` 會自動跳過空白字元，導致輸出格式錯誤。


## 程式碼實作 (Code Structure)

```cpp
#include <iostream>

using namespace std;

int main() {
    char c;
    // first 用於紀錄當前的引號是「一對中的第一個」還是「第二個」
    bool first = true; 

    // 使用 cin.get(c) 逐一讀取字元，包含空格與換行
    while (cin.get(c)) {
        // 檢查是否遇到雙引號
        if (c == '"') {
            if (first) {
                // 第一次遇到：替換為左引號，並更新狀態
                cout << "``";
                first = false;
            } else {
                // 第二次遇到：替換為右引號，並更新狀態
                cout << "''";
                first = true;
            }
        } else {
            // 非引號字元，直接原樣輸出
            cout << c;
        }
    }

    return 0;
}
```

## Complexity Analysis
- **Time Complexity:** $O(N)$  
  其中 $N$ 為輸入檔案的總字元數。程式僅需線性掃描所有字元一次即可完成替換，每個字元處理時間均為常數時間。
- **Space Complexity:** $O(1)$  
  使用一個 `char` 與一個 `bool` 變數來存儲當前狀態，不需要儲存整個字串或檔案，因此空間複雜度不隨輸入大小改變。


## Notes & Reflection
- **容易出錯點**：
  - **輸入方式：** 若使用 `cin >> c` 會導致所有空白與換行被過濾，造成格式全毀。
  - **狀態初始化：** 必須確保 `first` 的初始值為 `true`，否則第一組引號會被錯誤地轉換為右引號。
- **心得：** 一開始思考方向是讀取整行，再從中找雙引號，但後來想到可以一個字元一個字元輸入判斷，也比較好實現。

## References
- [UVa Online Judge - 272 Official Page](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=208)