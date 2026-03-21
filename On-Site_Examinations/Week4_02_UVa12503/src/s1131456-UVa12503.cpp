// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int cases;
    // 1. 讀取測試資料組數
    if (!(cin >> cases)) return 0;

    while (cases--) {
        int pos = 0; // 機器人的當前位置
        int num;     // 該組測試資料的指令數量
        cin >> num;

        int ins[102]; // 用來儲存每條指令產生的位移 (Memory)
        
        for (int i = 0; i < num; i++) {
            string temp;
            cin >> temp; // 讀取第一個單字

            if (temp == "LEFT") {
                ins[i] = -1; // 向左移動一格
            } else if (temp == "RIGHT") {
                ins[i] = 1;  // 向右移動一格
            } else {
                // 處理 "SAME AS a"
                // temp 此時是 "SAME"，我們需要再讀取一次 "AS" 和數字 a
                cin >> temp; // 讀入 "AS"
                int a;
                cin >> a;    // 讀入數字 a
                
                // 核心邏輯：將當前指令設為與第 a 個指令相同
                // 因為題目是 1-based，所以要用 a-1 存取陣列
                ins[i] = ins[a - 1];
            }
        }

        // 2. 將所有指令的結果累加，算出最終位置
        for (int i = 0; i < num; i++) {
            pos += ins[i];
        }

        // 3. 輸出結果並換行
        cout << pos << endl;
    }
    return 0;
}