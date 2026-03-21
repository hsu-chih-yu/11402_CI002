// Email: s1131456@mail.yzu.edu.tw
#include <iostream>

using namespace std;

int main() {
    int n;
    // 讀取可樂數量n
    while (cin >> n) {
        // 一開始先喝n瓶
        int ans = n;
        
        while (n >= 3) {
            int new_cola = n / 3;   // 3個空瓶換1瓶新可樂
            ans += new_cola;        // 喝掉新換來的可樂
            // 更新空瓶數
            n = new_cola + (n % 3);
        }
        
        // 借瓶子
        if (n == 2) {
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}