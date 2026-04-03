# UVa 10107 - What is the Median?

## 題目描述
這題要求在一個不斷讀入數字的序列中，每當讀入一個新數字時，就即時計算出目前所有數字的「中位數 (Median)」。

**中位數定義：**
1. 如果目前的數字個數為 **奇數**：排序後最中間的那個數字即為中位數。
2. 如果目前的數字個數為 **偶數**：排序後最中間兩個數字的平均值（取整數部分）。

[題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1048)

## 學習重點
- [x] 掌握動態資料處理：隨著資料讀入即時更新結果。
- [x] 熟練 `std::vector` 的動態增長與 `std::sort` 的應用。
- [x] 處理不同數列長度下的中位數數學邏輯。



## 解法思路

### 演算法邏輯：動態排序法
本實作採用直覺的「讀取、排序、取值」流程：

1. **資料存儲**：使用 `vector<int> a` 作為容器。
2. **即時更新**：
   - 每讀入一個整數 `n`，立即將其 `push_back` 放入向量中。
   - 呼叫 `sort(a.begin(), a.end())` 對當前所有數字進行升冪排序，確保數列處於有序狀態。
3. **計算與輸出**：
   - 獲取目前數列長度 `leng`。
   - **奇數情況**：索引值 `leng / 2` 即為中位數位置。
   - **偶數情況**：取索引 `leng / 2` 與 `leng / 2 - 1` 兩處數值的平均值。


## 程式碼實作 (Code Structure)
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> a;
    
    // 持續讀入數字直到輸入結束 (EOF)
    while(cin >> n){
        // 1. 將新數字加入向量
        a.push_back(n);
        
        // 2. 重新排序以尋找中位數
        sort(a.begin(), a.end());
        
        int leng = a.size();
        
        // 3. 判斷長度為奇數或偶數
        if(leng % 2 == 0){
            // 偶數個：取中間兩個數的平均值
            int div = leng / 2;
            int ans = a[div] + a[div-1];
            ans /= 2;
            cout << ans << endl;
        } else {
            // 奇數個：直接取最中間的數
            int div = leng / 2;
            cout << a[div] << endl;
        }
    }

    return 0;
}
```

## 複雜度分析
- **時間複雜度**: $O(N^2 \log N)$  
  總共讀入 $N$ 個數字，每讀入一個新數字就進行一次 $O(N \log N)$ 的排序。雖然這不是最優解（最優解可使用兩個 Heap 達到 $O(N \log N)$），但針對此題測資規模已足以通過。
- **空間複雜度**: $O(N)$  
  需要一個向量來儲存所有已讀入的數字。



## 筆記與心得
- **即時性**：這類題目常見於串流資料處理，重點在於每次狀態改變後都要能產出正確的統計值。
- **輸出細節**：題目要求偶數個時取平均值的整數部分，在 C++ 中 `int / int` 的運算會自動捨去小數點，符合要求。