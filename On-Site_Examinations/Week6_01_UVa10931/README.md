# UVa 10931 - Parity

## 題目描述
給定一個正整數 $I$，要求計算其二進位表示法中數字 `1` 的總個數（稱為 Parity），並依照指定格式輸出其二進位字串與計數值。

**輸出格式範例：**
`The parity of 1011 is 3 (mod 2).`

[題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1872)

## 學習重點
- [x] 掌握十進位轉二進位的演算法（除二取餘數法）。
- [x] 練習使用 `vector` 儲存並反向輸出序列。
- [x] 理解二進位位元計數（Popcount）的基礎邏輯。


## 解法思路

### 演算法邏輯：短除法轉換
1. **二進位轉換**：
   - 使用 `while(n > 0)` 迴圈，透過 `n % 2` 取得當前最低位元的數值（0 或 1）。
   - 將取得的數值存入 `vector<int> a` 中。
   - 執行 `n /= 2` 繼續計算下一位元。
2. **計算 Parity**：
   - 在轉換過程中，若 `n % 2 == 1`，則計數器 `c` 加一。
3. **格式化輸出**：
   - **反向輸出**：由於短除法取得的餘數是從「低位元到高位元」，輸出二進位字串時必須從 `vector` 的尾端往前跑迴圈輸出。
   - 嚴格遵守 `The parity of B is P (mod 2).` 的字串格式。



## 程式碼實作 (Code Structure)
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    // 讀入 n，當 n 為 0 時停止
    while(cin >> n && n != 0){
        vector<int> a;
        int c = 0; // 用於計算 1 的個數 (Parity)
        
        // 十進位轉二進位
        while(n > 0){
            int ans = n % 2;
            a.push_back(ans);
            if(ans == 1){
                c++;
            }
            n /= 2;
        }
        
        // 輸出指定格式
        cout << "The parity of ";
        int s = a.size();
        // 反向輸出 vector 內容以呈現正確的二進位順序
        for(int i = s - 1; i >= 0; i--){
            cout << a[i];
        }
        printf(" is %d (mod 2).\n", c);
    }

    return 0;
}
```

## 複雜度分析
- **時間複雜度**: $O(\log_2 I)$  
  二進位轉換的次數取決於數值的大小，對於 32 位元整數，最多只需執行約 31 次迴圈。
- **空間複雜度**: $O(\log_2 I)$  
  需要一個空間來存放二進位的每一位數字。



## 筆記與心得
- **結束條件**：題目要求輸入為 `0` 時結束程式，因此使用 `while(cin >> n && n != 0)` 進行判定。
- **反向遍歷**：這題是練習 `for(int i = s - 1; i >= 0; i--)` 這種反向遍歷邏輯的絕佳機會，因為直接輸出的話二進位會是反過來的。