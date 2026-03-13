#include <iostream>
#include <string>

using namespace std;
    int maximumSwap(int num) {
        // 1. 將整數轉為字串方便處理各個數位
        string s = to_string(num);
        int len = s.length();
        
        // 2. 從左至右掃描每一個數位 i
        for (int i = 0; i < len; i++) {
            int max_idx = i;
            
            // 在 i 的右側尋找最大的數位
            // 這裡採用從後往前掃描，能確保找到的是「最後出現」的最大值
            for (int j = len - 1; j > i; j--) {
                if (s[j] > s[max_idx]) {
                    max_idx = j;
                }
            }
            
            // 3. 如果右側存在比目前 s[i] 更大的數位
            if (max_idx != i) {
                // 執行唯一一次的交換
                swap(s[i], s[max_idx]);
                
                // 交換後立即轉換回整數並結束函式
                return stoi(s);
            }
        }
        
        // 如果遍歷完都沒交換，代表原數字已是最大組合
        return num;
    }

int main(){
    int num;
    while(cin >> num){
        int ans = maximumSwap(num);
        cout << ans << endl;
    }
    return 0;
}

