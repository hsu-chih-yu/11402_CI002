// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    // 使用 getline 讀取每一行，包含可能的空行
    while (getline(cin, s1) && getline(cin, s2)) {
        int countA[26] = {0};
        int countB[26] = {0};

        // 1. 統計第一個字串的字母頻率
        for (char c : s1) {
            if (c >= 'a' && c <= 'z') {
                countA[c - 'a']++;
            }
        }

        // 2. 統計第二個字串的字母頻率
        for (char c : s2) {
            if (c >= 'a' && c <= 'z') {
                countB[c - 'a']++;
            }
        }

        // 3. 按字典序 (a-z) 比較並輸出共同字元
        for (int i = 0; i < 26; i++) {
            // 取兩者出現次數的較小值
            int common = min(countA[i], countB[i]);
            while (common--) {
                printf("%c", i + 'a');
            }
        }
        printf("\n");
    }
    return 0;
}