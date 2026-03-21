// Email: s1131456@mail.yzu.edu.tw
#include <iostream>

using namespace std;

int main() {
    long long i, j;
    
    // 讀取輸入，直到 i 與 j 同時為 0
    while (cin >> i >> j && (i != 0 || j != 0)) {
        int count = 0; // 進位次數
        int last = 0;  // 儲存進位值 (0 或 1)
        
        while (i > 0 || j > 0) {
            int a = i % 10;
            int b = j % 10;
            
            // 判斷當前位數相加是否產生進位
            if (a + b + last >= 10) {
                count++;
                last = 1;
            } else {
                last = 0;
            }
            // 移至下一位
            i /= 10;
            j /= 10;
        }

        // 根據進位次數輸出對應的字串
        if (count == 0) {
            cout << "No carry operation." << endl;
        } else if (count == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << count << " carry operations." << endl;
        }
    }
    return 0;
}