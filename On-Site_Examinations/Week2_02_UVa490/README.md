# UVa 490 - Rotating Sentences

## Problem Description
要求將給定的多行字串進行「順時針旋轉 90 度」的處理。原本輸入的第一行會變成旋轉後的最右側一列，而最後輸入的一行則會變成旋轉後最左側的第一列。[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=431)


## Learning Objectives
- [x] 理解二維陣列旋轉 90 度的索引變化邏輯。
- [x] 使用 `std::vector<string>` 處理不固定行數的輸入。
- [x] 處理各行長度不一時所需的「空白字元填充」。
- [x] 掌握 EOF 的讀取與終端機測試技巧。


## Solution Approach

### Algorithm Logic
1. 讀取輸入：利用 `while (getline(cin, input))` 讀入每一行文字，並將其存入 `vector<string> lines` 中。
2. 計算寬度：在讀取的過程中，同時尋找所有字串中最長的一行（`maxlen`），決定旋轉後輸出的總行數。
3. 執行旋轉：
   - 外層迴圈 $i$ 從 0 跑到 `maxlen - 1`處理每一行要輸出的字元位置。
   - 內層迴圈 $j$ 從 `lines.size() - 1` 倒著跑到 0，從最後一行開始往前讀取。
4. 填充空格：如果當前處理的索引 $i$ 超過了某行字串的長度，必須輸出空格 `" "`，否則會導致輸出格式錯誤。


### Key Insights
* 旋轉公式：若輸入為 $N$ 行，最長長度為 $M$，則輸出將會是 $M$ 行，每行包含 $N$ 個字元。
* EOF 測試：在 Windows 終端機測試時需按下 `Ctrl+Z` 然後 `Enter`。



## 程式碼實作 (Code Structure)

```cpp
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    vector<string> lines; // 儲存所有的輸入句子
    string input;
    size_t maxlen = 0;    // 紀錄最長句子的長度

    // 1. 讀取輸入直到 EOF
    while (getline(cin, input)) {
        lines.push_back(input);
        
        // 同步更新最大長度
        if (input.length() > maxlen) {
            maxlen = input.length();
        }
    }

    int row_count = lines.size(); 

    // 2. 進行 90 度旋轉輸出
    // 外層迴圈控制「旋轉後的行」（原字串的字元索引位置）
    for (size_t i = 0; i < maxlen; i++) {
        
        // 內層迴圈控制「旋轉後的列」（從最後一行的句子開始讀取）
        for (int j = row_count - 1; j >= 0; j--) {
            
            // 檢查當前句子是否有這個位置的字元
            if (i < lines[j].length()) {
                cout << lines[j][i];
            } else {
                // 若句子較短，則輸出空格補齊
                cout << " ";
            }
        }
        
        // 完成一列的輸出後換行
        cout << endl;
    }

    return 0;
}
```

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$  
  其中 $N$ 為輸入的總行數，$M$ 為所有字串中最長的長度。因為程式必須走訪並輸出一個完整的 $M \times N$ 矩陣空間，所以時間複雜度與矩陣面積成正比。
- **Space Complexity:** 使用 `vector<string>` 儲存了所有的輸入字元，在最壞情況下（所有字串長度皆接近 $M$），佔用的記憶體空間為 $O(M \times N)$。。


## Notes & Reflection
- **容易出錯點**：
  - **迴圈方向**：在撰寫 `for` 迴圈時，內層迴圈 `j` 必須由大到小（從最後一行往第一行）讀取，這點在邏輯轉換時容易出錯。
  - **最大長度判斷**：必須確保 `maxlen` 是「所有輸入行」中的最大值，否則輸出的列數會不足。


## References
- [UVa Online Judge - 490 Official Page](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=431)