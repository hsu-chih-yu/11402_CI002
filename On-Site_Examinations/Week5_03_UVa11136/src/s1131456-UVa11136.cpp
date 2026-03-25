//Email: s1131456@email.yzu.edu.tw
#include <iostream>
#include <set>

using namespace std;

int main() {
    int days;
    // 讀取活動天數
    while (cin >> days && days != 0) {
        multiset<int> urn; // 使用 multiset 模擬裝帳單的箱子
        long long total_prize = 0; // 獎金可能很大，用 long long

        while (days--) {
            int n;
            cin >> n; // 今天投入幾張帳單
            for (int i = 0; i < n; i++) {
                int bill;
                cin >> bill;
                urn.insert(bill); // 插入帳單，自動排序 O(log N)
            }

            if (!urn.empty()) {
                // 取出最小值與最大值
                auto it_min = urn.begin();
                auto it_max = --urn.end();

                total_prize += (*it_max - *it_min);

                // 刪除這兩張帳單
                // 必須傳入迭代器，若直接傳入數值會刪除所有相同面額的帳單
                urn.erase(it_min);
                urn.erase(it_max);
            }
        }
        cout << total_prize << endl;
    }
    return 0;
}