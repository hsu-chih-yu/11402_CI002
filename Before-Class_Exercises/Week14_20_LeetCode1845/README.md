# LeetCode 1845 - Seat Reservation Manager

## 題目描述
設計一個管理 `n` 個座位的系統，座位編號從 `1` 到 `n`。
你需要實作 `SeatManager` 類別：
1. **`SeatManager(int n)`**：初始化物件，管理 `1` 到 `n` 的所有座位。
2. **`int reserve()`**：找出當前 **最小編號** 的空位，將其預約並回傳編號。
3. **`void unreserve(int seatNumber)`**：將指定的座位編號改為未預約狀態。

[題目連結](https://leetcode.com/problems/seat-reservation-manager/)

## 學習重點
- [x] 掌握 **關聯式容器 (Associative Containers)** 的自動排序特性。
- [x] 理解 `std::set` 的底層結構（紅黑樹）及其操作複雜度。
- [x] 比較 `set` 與 `priority_queue` 在處理極值問題上的差異。



## 解法思路：利用 Set 的排序特性

### 1. 資料結構選用
我們需要一個容器來存放「目前所有可用的座位」。為了快速拿到最小編號，容器必須能自動排序。
- **`std::set<int>`**：插入、刪除、尋找最小值皆為 $O(\log N)$。

### 2. 操作實作
- **初始化**：將 $1$ 到 $n$ 的整數全部推入 `set`。
- **預約 (Reserve)**：
  - 最小值永遠位在 `st.begin()`。
  - 取出值後，使用 `st.erase(st.begin())` 將其從可用清單中移除。
- **取消預約 (Unreserve)**：
  - 直接將編號 `insert` 回 `set`。由於 `set` 具備自動排序功能，該編號會回到正確的順序位置。

## Code Structure
```cpp
#include <set>

using namespace std;

/**
 * LeetCode 1845 - Seat Reservation Manager
 * 邏輯：利用 std::set 自動維持排序的特性，始終從 begin() 取得最小座位。
 */
class SeatManager {
    set<int> st; // 存儲所有可用的座位編號
public:
    // 初始化：將 1 到 n 放入 set
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            st.insert(i);
        }
    }
    
    int reserve() {
        // 1. set 的第一個元素 (begin) 永遠是當前最小的可用座位
        int seat = *st.begin();
        
        // 2. 將該座位從可用集合中移除
        st.erase(st.begin());
        
        return seat;
    }
    
    void unreserve(int seatNumber) {
        // 3. 插入退還的座位，set 會自動依序排列，確保下次 reserve 仍能拿到最小編號
        st.insert(seatNumber);
    }
};
```

## 複雜度分析
- **時間複雜度**:
  - **初始化**: $O(N \log N)$。
  - **reserve**: $O(\log N)$。
  - **unreserve**: $O(\log N)$。
- **空間複雜度**: $O(N)$，需要空間儲存 $n$ 個座位的狀態。

---

## 筆記與心得
- **效能優化建議**：如果 $N$ 非常大，初始化 $1$ 到 $N$ 可能會變慢。另一種做法是只用一個變數 `min_seat` 紀錄尚未被碰過的最小位子，並用 `priority_queue` 存儲被「退還」的位子。
- **Set vs Priority Queue**：這題也可以用 `std::priority_queue<int, vector<int>, greater<int>>`（小頂堆）來完成，邏輯完全一致。