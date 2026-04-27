// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            // 1. 如果是左括號，直接入棧
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            } else {
                // 2. 如果是右括號，先檢查堆疊是否為空
                if(st.empty()){
                    return false; // 右括號前面沒有任何左括號，無效
                }
                
                char top = st.top();
                // 3. 檢查棧頂左括號是否與當前右括號配對
                if((c == ')' && top == '(') || 
                   (c == ']' && top == '[') ||
                   (c == '}' && top == '{')){
                    st.pop(); // 配對成功，移除棧頂
                } else {
                    return false; // 類型不匹配，無效
                }
            }
        }
        
        // 4. 最後檢查堆疊是否全數清空（避免如 "((" 的情況）
        return st.empty();
    }
};