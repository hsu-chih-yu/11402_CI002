//Email: s1131456@email.yzu.edu.tw
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    int lines;
    if (!(cin >> lines)) return 0;
    cin.ignore(); // 吃掉讀入行數後的換行符

    int counts[150] = {0}; // 儲存 ASCII 頻率
    int uniqueLetters = 0;

    while (lines--) {
        string s;
        getline(cin, s);
        
        for (char ch : s) {
            // 轉大寫處理
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - 'a' + 'A';
            }
            
            // 僅統計 A-Z
            if (ch >= 'A' && ch <= 'Z') {
                if (counts[(int)ch] == 0) {
                    uniqueLetters++;
                }
                counts[(int)ch]++;
            }
        }
    }

    // 輸出排序：每次找出當前最大頻率者
    for (int i = 0; i < uniqueLetters; i++) {
        int maxFreq = -1;
        int targetChar = 0;
        
        // 從 A 掃到 Z，確保頻率相同時，字母序小的優先被輸出
        for (int j = 'A'; j <= 'Z'; j++) {
            if (counts[j] > maxFreq) {
                maxFreq = counts[j];
                targetChar = j;
            }
        }
        
        if (maxFreq > 0) {
            printf("%c %d\n", targetChar, maxFreq);
            counts[targetChar] = 0; // 歸零以便找出下一個最大值
        }
    }

    return 0;
}