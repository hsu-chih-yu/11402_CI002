// Email: s1131456@mail.yzu.edu.tw
#include <set>

using namespace std;


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