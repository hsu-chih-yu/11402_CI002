// Email: s1131456@email.yzu.edu.tw
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        
        // 先將所有 int 轉為 string，方便接合比較
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        
        // 使用 Lambda 運算式處理比較邏輯：判斷誰放在前面接起來比較大
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a; // 降冪排序
        });

        // 第一個數字是 "0" 代表全部都是 0
        if (strs[0] == "0") return "0";

        // 將排序後的字串依序拼湊起來
        string result = "";
        for (const string& s : strs) {
            result += s;
        }

        return result;
    }
};