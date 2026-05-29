// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int cases;
    if (!(cin >> cases)) return 0;
    
    // 忽略掉讀取 cases 之後的換行符
    cin.ignore(); 

    while(cases--) {
        vector<int> list;
        int n;
        cin >> n; // 讀取親戚數量
        
        for(int i = 0; i < n; i++) {
            int t;
            cin >> t;
            list.push_back(t);
        }

        // 1. 排序以尋找中位數
        sort(list.begin(), list.end());

        // 2. 選定中位數索引 (n/2)
        int count = n / 2;
        int ans = 0;

        // 3. 計算所有親戚家到中位數位置的總距離
        for(int i = 0; i < n; i++) {
            ans += abs(list[i] - list[count]);
        }

        // 4. 輸出最小總距離
        cout << ans << endl;
    }
    return 0;
}