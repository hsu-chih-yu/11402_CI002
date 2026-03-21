# UVa 10242 - Parallelogram

## Problem Description
給定一個平行四邊形相鄰兩條邊的四個端點座標（其中一個點會重複出現，作為兩邊的共同頂點），求出該平行四邊形第四個頂點的座標。

[Link to problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1183)

## Learning Objectives
- [x] 練習幾何座標的向量運算。
- [x] 處理浮點數輸入與精確度控制 (`fixed`, `setprecision`)。
- [x] 學習如何從輸入中識別「重複點」並提取對應頂點。



## Solution Approach

### Algorithm Logic
平行四邊形的幾何特性：若 $A$、$C$ 是相對於共同頂點 $B$ 的另外兩個頂點，則第四個點 $D$ 滿足：
$$D_x = A_x + C_x - B_x$$
$$D_y = A_y + C_y - B_y$$

1. **識別重複點**：輸入的四個點中，有兩個座標是完全相同的，這就是共同頂點 $B$。
2. **找出非重複點**：另外兩個座標分別是 $A$ 和 $C$。
3. **計算與輸出**：利用向量加法找出 $D$，並輸出至小數點後四位。



## 程式碼實作 (Code Structure)

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

int main() {
    Point p[4];
    
    // 持續讀取四個點的座標 (x1, y1, x2, y2, x3, y3, x4, y4)
    while (cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y) {
        double resX, resY;

        // 判斷哪兩個點是重複的（共同頂點 B）
        // 情況 1: p[0] 是共同點
        if (p[0].x == p[2].x && p[0].y == p[2].y) {
            resX = (p[1].x + p[3].x) - p[0].x;
            resY = (p[1].y + p[3].y) - p[0].y;
        }
        else if (p[0].x == p[3].x && p[0].y == p[3].y) {
            resX = (p[1].x + p[2].x) - p[0].x;
            resY = (p[1].y + p[2].y) - p[0].y;
        }
        // 情況 2: p[1] 是共同點
        else if (p[1].x == p[2].x && p[1].y == p[2].y) {
            resX = (p[0].x + p[3].x) - p[1].x;
            resY = (p[0].y + p[3].y) - p[1].y;
        }
        else { // p[1] == p[3]
            resX = (p[0].x + p[2].x) - p[1].x;
            resY = (p[0].y + p[2].y) - p[1].y;
        }

        // 格式化輸出到小數點後三位
        cout << fixed << setprecision(3) << resX << " " << resY << endl;
    }

    return 0;
}
```

## Complexity Analysis
- **Time Complexity:** $O(1)$  
  每一組測試資料只需進行常數次的比較與加減運算。
- **Space Complexity:** $O(1)$  
  只需儲存 4 個點的座標。



## Notes & Reflection
- **浮點數處理**：座標包含小數，應使用 `double` 確保精確度。
- **輸入格式**：題目保證每組有四個點，但要注意兩條邊的順序可能不同，因此需要檢查哪兩個點是重複的。。


## References
- [UVa Online Judge - 10242 Official Page](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1183)