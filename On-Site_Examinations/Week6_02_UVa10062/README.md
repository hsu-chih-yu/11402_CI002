# UVa 10062 - Tell me the frequencies!

## 題目描述
給定一行文字，統計其中每個字元（ASCII 碼介於 32 到 128 之間）出現的頻率。輸出時必須符合以下排序規則：
1. **頻率升冪排序**：出現次數越少的字元排在越前面。
2. **ASCII 碼降冪排序**：如果出現次數相同，則 ASCII 碼較大的字元排在前面。

[題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1003)

## 學習重點
- [x] 掌握 `getline(cin, s)` 讀取包含空白字元的整行字串。
- [x] 使用陣列（Frequency Array）進行字元頻率統計。
- [x] 實作多重條件排序邏輯：本程式採用「嵌套迴圈篩選法」達成排序效果。



## 解法思路

### 演算法邏輯：嵌套迴圈篩選法
本程式沒有使用 `std::sort` 與自定義比較函式，而是透過兩層迴圈的遍歷順序來達成題目要求的排序邏輯：

1. **統計階段**：
   - 使用 `int a[130]` 陣列紀錄 ASCII 碼對應的出現次數。
   - 遍歷字串 `s`，同步更新 `maxi`（紀錄出現最多次的次數）。
2. **輸出與排序階段**：
   - **外層迴圈**：從 `t = 1` 跑向 `maxi`。這保證了輸出的 **頻率是升冪排列**。
   - **內層迴圈**：從 `i = 128` 跑向 `32`。這保證了當頻率 `t` 相同時，**ASCII 碼是降冪排列**。
3. **格式處理**：
   - 題目要求測資之間需有空行。本程式在每組測資後輸出 `\n`。

## 程式碼實作 (Code Structure)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    // 使用 getline 讀取含空白的完整列
    while(getline(cin, s)){
        int a[130] = {0};
        int maxi = 0;
        int length = s.length();

        // 統計每個字元的出現次數
        for(int i = 0; i < length; i++){
            a[s[i]]++;
            if(a[s[i]] > maxi){
                maxi = a[s[i]];
            }
        }

        // 依照排序規則輸出
        // 外層迴圈控制頻率
        for(int t = 1; t <= maxi; t++){
            // 內層迴圈控制 ASCII 碼
            for(int i = 128; i >= 32; i--){
                if(a[i] == t){
                    cout << i << " " << t << "\n";
                }
            }
        }
        // 每組測資後輸出一個額外換行
        cout << "\n";
    }

    return 0;
}
```

## 複雜度分析
- **時間複雜度**: $O(N + F \times A)$
  - $N$ 為字串長度。
  - $F$ 為最大頻率（`maxi`）。
  - $A$ 為處理的 ASCII 範圍（約 96 個字元）。
  對於每組字串長度約 1000 的測資，此法運行速度極快。
- **空間複雜度**: $O(A)$
  - 固定使用大小為 130 的整數陣列。

---

## 筆記與心得
- **ASCII 範圍**：題目提到的是可列印字元，通常介於 32（空白）到 127 之間。
- **排序技巧**：這題展示了如果不使用 `sort()` 函式，如何透過迴圈的「遍歷順序」來達成複雜