# UVa 10420 - List of Conquests

## Problem Description
給定一系列的征服紀錄，每行包含一個國家名稱以及該國的一位美女姓名。
請統計每個國家出現的總次數，並依照**國家名稱的字母順序 (Alphabetical Order)** 輸出統計結果。

[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1361)

## Learning Objectives
- [x] 掌握 `std::map` 的自動排序特性（紅黑樹實作）。
- [x] 練習處理「讀取部分字串並忽略剩餘行」的輸入技巧。
- [x] 理解 $O(N \log K)$ 的時間複雜度優勢。



## Solution Approach

### Algorithm Logic
1. **結構選擇**：使用 `std::map<string, int>`。
   - `string` (Key)：儲存國家名稱。
   - `int` (Value)：儲存該國出現的次數。
2. **輸入處理**：
   - 由於每行的第一個單字是國家，後面是名字。我們只需要用 `cin >> country` 讀取第一個單字。
   - 剩下的名字部分對統計沒有意義，使用 `getline(cin, dummy)` 直接跳過整行剩下的內容。
3. **統計**：
   - 每讀到一個國家，直接執行 `counts[country]++`。如果國家尚未存在，`map` 會自動建立並初始化為 0 後再加 1。
4. **輸出**：
   - 遍歷 `map`。因為 `map` 內部的資料結構會確保 Key 始終處於排序狀態，我們不需要額外手動排序，直接依序印出即可。



### Key Insights
* **自動排序**：`std::map` 預設就是升冪排序 (Ascending)，這完全符合題目要求的 "Alphabetical order"。
* **空間效率**：相比於手動開大陣列（如 `c[2000]`），`map` 只會針對有出現的國家分配記憶體，更加節省空間。



## 程式碼實作 (Code Structure)

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int cases;
    if (!(cin >> cases)) return 0;
    
    vector<string> countries;
    string country, name;

    while (cases--) {
        cin >> country;
        getline(cin, name); // 讀完剩下的部分
        countries.push_back(country);
    }

    // 先把所有國家按字典序排好
    sort(countries.begin(), countries.end());

    // 遍歷排好序的 vector 進行計數輸出
    int len = countries.size();
    for (int i = 0; i < len; i++) {
        int count = 1;
        // 檢查後面是否有相同的國家
        while (i + 1 < len && countries[i] == countries[i + 1]) {
            count++;
            i++;
        }
        cout << countries[i] << " " << count << endl;
    }

    return 0;
}
```



## Complexity Analysis
- **Time Complexity:** $O(N \log K)$  
  其中 $N$ 是總行數（最大 2000），$K$ 是不同國家的數量。每次插入 `map` 的複雜度為 $O(\log K)$。
- **Space Complexity:** $O(K \cdot L)$  
  需要儲存 $K$ 個長度平均為 $L$ 的國家名稱。



## Notes & Reflection
- **輸入陷阱**：原本的程式碼使用 `vector` 進行線性搜尋，時間複雜度會達到 $O(N \cdot K)$，在資料量大時效率較差。




## References
- [UVa Online Judge - 10420 Official](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1361)