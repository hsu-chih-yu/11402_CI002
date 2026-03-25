# UVa 10008 - What's Cryptanalysis?

## Problem Description
給定一段文字，統計其中每個英文字母（A-Z）出現的次數。輸出時必須遵循以下規則：
1. **主要排序**：依照出現次數由大到小（降冪）排列。
2. **次要排序**：若次數相同，則依照字母在字典中的順序（升冪）排列。
3. **過濾規則**：非英文字母的字元（如數字、標點符號、空格）不予統計。

[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949)

## Learning Objectives
- [x] 練習處理多行輸入並使用 `getline` 讀取含空格字串。
- [x] 掌握 `cin.ignore()` 的使用時機，避免換行符號干擾讀取。
- [x] 學習字元大小寫轉換邏輯與 ASCII 碼應用。
- [x] 實作「尋找最大值並排除」的排序策略。



## Solution Approach

### Algorithm Logic
1. **初始化統計表**：建立一個大小約 150 的整數陣列（足以涵蓋 ASCII 碼範圍），初始化為 0。
2. **讀取與正規化**：
   - 先讀取總行數，並用 `cin.ignore()` 跳過剩餘的換行符。
   - 逐行讀取字串後，將小寫字母轉換為大寫字母（透過 ASCII 差值或 `toupper`）。
   - 僅對 A-Z 區間的字元進行計數。
3. **輸出排序 (Iterative Max)**：
   - 由於英文字母只有 26 個，我們可以使用巢狀迴圈：
   - 外層執行次數等於總字母種類。
   - 內層從 ASCII 65 ('A') 遍歷到 90 ('Z')，尋找目前次數最大的字母。
   - **關鍵點**：使用 `if(maxi < c[j])`。當次數相同時，因為我們是從 A 開始往後掃描，後面的字母不會蓋掉前面的字母，這自然地完成了「次數相同時，字母序小者優先」的要求。
4. **輸出並清除**：印出最大者後，將該位置歸零，進入下一輪尋找。

## 程式碼實作 (Code Structure)
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    int lines;
    if (!(cin >> lines)) return 0;
    cin.ignore(); // 吃掉讀入行數後的換行符

    int counts[150] = {0}; // 儲存 ASCII 頻率
    int uniqueLetters = 0;

    while (lines--) {
        string s;
        getline(cin, s);
        
        for (char ch : s) {
            // 轉大寫處理
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - 'a' + 'A';
            }
            
            // 僅統計 A-Z
            if (ch >= 'A' && ch <= 'Z') {
                if (counts[(int)ch] == 0) {
                    uniqueLetters++;
                }
                counts[(int)ch]++;
            }
        }
    }

    // 輸出排序：每次找出當前最大頻率者
    for (int i = 0; i < uniqueLetters; i++) {
        int maxFreq = -1;
        int targetChar = 0;
        
        // 從 A 掃到 Z，確保頻率相同時，字母序小的優先被輸出
        for (int j = 'A'; j <= 'Z'; j++) {
            if (counts[j] > maxFreq) {
                maxFreq = counts[j];
                targetChar = j;
            }
        }
        
        if (maxFreq > 0) {
            printf("%c %d\n", targetChar, maxFreq);
            counts[targetChar] = 0; // 歸零以便找出下一個最大值
        }
    }

    return 0;
}
```

## Complexity Analysis
- **Time Complexity:** $O(L + 26^2)$  
  其中 $L$ 是所有文字的總長度。統計過程為 $O(L)$，排序輸出部分為常數時間 $O(26^2)$。
- **Space Complexity:** $O(1)$  
  使用固定的陣列儲存 ASCII 頻率，不隨輸入規模增加而膨脹。



## Notes & Reflection
- **ASCII 範圍**：直接操作 `int c[150]` 是很方便的做法，省去了對應 index 0-25 的換算。
- **輸入陷阱**：本題必須統計所有行，包含空格，因此 `getline` 是唯一的選擇。


## References
- [UVa Online Judge - 10008 Official](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=949)