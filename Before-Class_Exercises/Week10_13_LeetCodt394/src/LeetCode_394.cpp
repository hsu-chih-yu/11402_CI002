// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0; // 初始化全域進度指標
        return decode(s, i);
    }

private:
    // 使用 int& i 確保遞迴加深時，指標能同步推進
    string decode(const string& s, int& i) {
        string res = "";
        
        while (i < s.length() && s[i] != ']') {
            if (isdigit(s[i])) {
                // 處理倍數 k (考慮多位數)
                int k = 0;
                while (i < s.length() && isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                
                i++; // 跳過 '['
                
                // 遞迴取得括號內解碼後的內容
                string decodedString = decode(s, i);
                
                i++; // 跳過 ']'
                
                // 根據倍數 k 重複字串
                while (k-- > 0) {
                    res += decodedString;
                }
            } else {
                // 一般字母直接加入結果
                res += s[i++];
            }
        }
        return res;
    }
};