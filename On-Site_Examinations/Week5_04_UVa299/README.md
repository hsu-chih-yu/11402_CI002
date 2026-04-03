# UVa 299 - Train Swapping

## Problem Description
有一列火車有 $L$ 節車廂，編號為 $1$ 到 $L$。現在這些車廂順序是亂的，我們可以使用一個旋轉橋來交換「相鄰」的兩節車廂。
請計算出最少需要進行幾次相鄰交換（Swaps），才能將所有車廂依照編號 $1, 2, ..., L$ 排好序。

[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=235)

## Learning Objectives
- [x] 掌握基礎排序演算法：泡沫排序 (Bubble Sort)。
- [x] 理解「逆序對 (Inversion Pair)」的概念與交換次數的關係。
- [x] 練習處理多組測試資料 (Test Cases)。



## Solution Approach

### Algorithm Logic
這題的核心在於「只能交換相鄰元素」這個限制。
1. **排序選擇**：在演算法中，每次只交換相鄰元素且能完成排序的代表就是 **泡沫排序 (Bubble Sort)**。
2. **交換次數**：題目要求的「最少交換次數」其實就是該序列中的 **逆序對數量**。
3. **實作步驟**：
   - 使用兩層迴圈遍歷陣列。
   - 若前一個元素大於後一個元素 ($a[j] > a[j+1]$)，則進行交換。
   - 每交換一次，計數器 `ans` 就加一。


### Key Insights
* **為什麼是泡沫排序？** 雖然像快速排序或歸併排序更快，但它們包含非相鄰的交換。題目明確要求使用旋轉橋（只能動相鄰兩節），因此泡沫排序的總交換次數就是該題的標準答案。

---

## 程式碼實作 (Code Structure)

```cpp
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


int main() {
    int cases;
    // 讀取測試資料組數
    if (!(cin >> cases)) return 0;

    while (cases--) {
        int n;
        cin >> n;
        vector<int> a;
        int num, ans = 0;

        // 讀取車廂初始順序
        for (int i = 0; i < n; i++) {
            cin >> num;
            a.push_back(num);
        }

        // 執行泡沫排序 (Bubble Sort)
        // 外層代表已經排好序的元素個數
        for (int i = 0; i < n - 1; i++) {
            // 內層進行相鄰元素比較與交換
            for (int j = 0; j < n - 1 - i; j++) {
                if (a[j] > a[j+1]) {
                    // 交換相鄰元素
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    // 累加交換次數
                    ans++;
                }
            }
        }

        // 依照題目要求的格式輸出
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }

    return 0;
}
```



## Complexity Analysis
- **Time Complexity:** $O(L^2)$  
  其中 $L$ 為車廂長度（最大為 50）。由於使用了兩層巢狀迴圈，總比較次數約為 $L^2 / 2$。在 $L=50$ 的情況下，運算量極小。
- **Space Complexity:** $O(L)$  
  使用了一個 `vector` 來儲存車廂編號。



## Notes & Reflection
- **輸出格式**：這題對輸出格式要求嚴格，必須精確符合 `Optimal train swapping takes S swaps.`。
- **資料範圍**：由於 $L \le 50$，即使是 $O(L^2)$ 的暴力排序也能在 0.000s 內通過測資。



## References
- [UVa Online Judge - 299 Official Page](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=235)