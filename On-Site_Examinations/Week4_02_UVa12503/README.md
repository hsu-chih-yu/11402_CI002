# UVa 12503 - Robot Instructions

## Problem Description
一個機器人位於數線上的原點 0。它會接收到一系列指令：
1. `LEFT`：向左移動一單位（位置 -1）。
2. `RIGHT`：向右移動一單位（位置 +1）。
3. `SAME AS i`：執行與第 $i$ 條指令相同的動作。
要求計算在執行完所有指令後，機器人的最終位置。

[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=441&page=show_problem&problem=3947)

## Learning Objectives
- [x] 練習使用陣列作為「指令記憶體」來儲存過去的運算結果。
- [x] 掌握字串輸入處理（處理包含空格或多個單字的指令）。
- [x] 處理 1-based 指令索引與 0-based 陣列索引的轉換。



## Solution Approach

### Algorithm Logic
1. **指令儲存**：建立一個陣列 `ins[102]`。這裡不需要儲存原始字串（如 "LEFT"），而是儲存該指令代表的「位移值」（`LEFT` 存 `-1`，`RIGHT` 存 `1`）。
2. **處理指令**：
   - 如果輸入是 `LEFT`：`ins[i] = -1`。
   - 如果輸入是 `RIGHT`：`ins[i] = 1`。
   - 如果輸入是 `SAME AS i`：
     - 首先讀取 "SAME" 與 "AS" 這兩個關鍵字。
     - 接著讀取整數 $a$。
     - 將第 $i$ 條指令的值設為與第 $a$ 條指令相同：`ins[i] = ins[a-1]`。
3. **計算位置**：將 `ins` 陣列中所有儲存的位移值加總，即為最終位置。

### Key Insights
* **索引轉換**：題目給的 $i$ 是從 1 開始編號，但在 C++ 陣列中是從 0 開始，因此存取時必須使用 `ins[a-1]`。
* **字串處理技巧**：當遇到 `SAME AS i` 時，程式碼利用連續的 `cin >> temp` 來跳過 "SAME" 和 "AS" 這兩個單字，直接抓取後面的數字，這是非常簡潔的做法。



## 程式碼實作 (Code Structure)

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int cases;
    // 1. 讀取測試資料組數
    if (!(cin >> cases)) return 0;

    while (cases--) {
        int pos = 0; // 機器人的當前位置
        int num;     // 該組測試資料的指令數量
        cin >> num;

        int ins[102]; // 用來儲存每條指令產生的位移 (Memory)
        
        for (int i = 0; i < num; i++) {
            string temp;
            cin >> temp; // 讀取第一個單字

            if (temp == "LEFT") {
                ins[i] = -1; // 向左移動一格
            } else if (temp == "RIGHT") {
                ins[i] = 1;  // 向右移動一格
            } else {
                // 處理 "SAME AS a"
                // temp 此時是 "SAME"，我們需要再讀取一次 "AS" 和數字 a
                cin >> temp; // 讀入 "AS"
                int a;
                cin >> a;    // 讀入數字 a
                
                // 核心邏輯：將當前指令設為與第 a 個指令相同
                // 因為題目是 1-based，所以要用 a-1 存取陣列
                ins[i] = ins[a - 1];
            }
        }

        // 2. 將所有指令的結果累加，算出最終位置
        for (int i = 0; i < num; i++) {
            pos += ins[i];
        }

        // 3. 輸出結果並換行
        cout << pos << endl;
    }
    return 0;
}
```



## Complexity Analysis
- **Time Complexity:** $O(T \times N)$  
  $T$ 為測試資料組數，$N$ 為每組的指令數量。每一條指令只需要常數時間處理。
- **Space Complexity:** $O(N)$  
  需要一個陣列來紀錄 $N$ 條指令的位移結果。



## Notes & Reflection
- **容易出錯點**：
  - **指令索引偏移**：忘記 `a-1` 會導致抓錯指令。
  - **位置重置**：每一組測試資料開始前，`pos` 必須重置為 0。



## References
- [UVa Online Judge - 12503 Official Page](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=441&page=show_problem&problem=3947)